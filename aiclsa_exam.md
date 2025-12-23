To centralize authentication and hosting on a single **CentOS 9 Stream** server with the domain **armour.local**, we will use a "minimal essential" approach. This configuration includes **OpenLDAP** as the source of truth, **Apache** as a reverse proxy for Moodle and Jenkins, **VSFTPD** for file sharing, and **SSSD** to tie the system authentication (SSH/FTP) to LDAP.

---

## Part 1: Server Configuration (`armour.local`)

### 1. System Preparation & Repositories

Set the hostname and enable the EPEL repository, which is required for OpenLDAP and other essential tools.

```bash
# Set Hostname
hostnamectl set-hostname server.armour.local

# Install EPEL and basic tools
dnf install -y epel-release dnf-plugins-core
dnf config-manager --set-enabled crb
dnf install -y openldap-servers openldap-clients sssd sssd-ldap oddjob-mkhomedir certmonger

```

### 2. OpenLDAP Setup

Centralize user management. Replace `[PASSWORD]` with your desired admin secret.

```bash
# Start and enable LDAP
systemctl enable --now slapd

# Generate encrypted password
SLAP_PW=$(slappasswd -s "[PASSWORD]")

# Configure Base DN (armour.local) and Admin
cat <<EOF > db.ldif
dn: olcDatabase={2}mdb,cn=config
changetype: modify
replace: olcSuffix
olcSuffix: dc=armour,dc=local

dn: olcDatabase={2}mdb,cn=config
changetype: modify
replace: olcRootDN
olcRootDN: cn=admin,dc=armour,dc=local

dn: olcDatabase={2}mdb,cn=config
changetype: modify
add: olcRootPW
olcRootPW: $SLAP_PW
EOF

ldapmodify -Y EXTERNAL -H ldapi:/// -f db.ldif

# Create basic structure (Users/Groups)
cat <<EOF > structure.ldif
dn: dc=armour,dc=local
objectClass: top
objectClass: dcObject
objectClass: organization
o: Armour Local
dc: armour

dn: ou=Users,dc=armour,dc=local
objectClass: organizationalUnit
ou: Users

dn: ou=Groups,dc=armour,dc=local
objectClass: organizationalUnit
ou: Groups
EOF

ldapadd -x -D cn=admin,dc=armour,dc=local -w "[PASSWORD]" -f structure.ldif

```

### 3. Moodle Installation (HTTPS via Apache)

Moodle requires a LAMP stack. We will use a self-signed certificate for the `.local` domain.

```bash
# Install PHP 8.x and MariaDB
dnf install -y httpd mariadb-server php php-mysqlnd php-gd php-xml php-mbstring php-intl php-soap php-zip php-opcache mod_ssl

# Configure MariaDB
systemctl enable --now mariadb
mysql -e "CREATE DATABASE moodle DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;"
mysql -e "GRANT ALL ON moodle.* TO 'moodleuser'@'localhost' IDENTIFIED BY 'Moodle@123';"

# Download Moodle
cd /var/www/html
curl -L https://download.moodle.org/download.php/direct/stable404/moodle-latest-404.tgz | tar -xz
mkdir /var/www/moodledata
chown -R apache:apache /var/www/html/moodle /var/www/moodledata

# Apache VirtualHost for moodle.armour.local
cat <<EOF > /etc/httpd/conf.d/moodle.conf
<VirtualHost *:80>
    ServerName moodle.armour.local
    Redirect permanent / https://moodle.armour.local/
</VirtualHost>

<VirtualHost *:443>
    ServerName moodle.armour.local
    DocumentRoot /var/www/html/moodle
    SSLEngine on
    SSLCertificateFile /etc/pki/tls/certs/localhost.crt
    SSLCertificateKeyFile /etc/pki/tls/private/localhost.key
    <Directory /var/www/html/moodle>
        AllowOverride All
        Require all granted
    </Directory>
</VirtualHost>
EOF
systemctl enable --now httpd

```

### 4. Jenkins with LDAP Integration

Jenkins runs on port 8080 by default; we proxy it to `jenkins.armour.local`.

```bash
# Install Java and Jenkins
dnf install -y java-17-openjdk
wget -O /etc/yum.repos.get/jenkins.repo https://pkg.jenkins.io/redhat-stable/jenkins.repo
rpm --import https://pkg.jenkins.io/redhat-stable/jenkins.io-2023.key
dnf install -y jenkins
systemctl enable --now jenkins

# Apache Proxy for jenkins.armour.local
cat <<EOF > /etc/httpd/conf.d/jenkins.conf
<VirtualHost *:80>
    ServerName jenkins.armour.local
    ProxyPreserveHost On
    ProxyPass / http://127.0.0.1:8080/
    ProxyPassReverse / http://127.0.0.1:8080/
</VirtualHost>
EOF
systemctl restart httpd

```

*Note: To finish Jenkins LDAP, log in to the UI, go to **Manage Jenkins > Security**, select **LDAP**, and point it to `server.armour.local` with search base `ou=Users,dc=armour,dc=local`.*

### 5. FTP & SSH LDAP Authentication (SSSD)

Configure the server to use LDAP for its own system accounts (SSH and FTP).

```bash
# Configure SSSD
cat <<EOF > /etc/sssd/sssd.conf
[sssd]
services = nss, pam
domains = armour.local

[domain/armour.local]
id_provider = ldap
auth_provider = ldap
ldap_uri = ldap://localhost
ldap_search_base = dc=armour,dc=local
cache_credentials = True
ldap_tls_reqcert = allow
EOF
chmod 600 /etc/sssd/sssd.conf

# Enable SSSD authentication
authselect select sssd with-mkhomedir --force
systemctl enable --now sssd oddjobd

# Configure VSFTPD
dnf install -y vsftpd
sed -i 's/anonymous_enable=YES/anonymous_enable=NO/' /etc/vsftpd/vsftpd.conf
echo "local_enable=YES" >> /etc/vsftpd/vsftpd.conf
echo "write_enable=YES" >> /etc/vsftpd/vsftpd.conf
echo "chroot_local_user=YES" >> /etc/vsftpd/vsftpd.conf
systemctl enable --now vsftpd

```

### 6. Firewall & SELinux

Open the necessary ports and set booleans to allow services to interact.

```bash
# Firewall
firewall-cmd --permanent --add-service={http,https,ldap,ldaps,ftp,ssh}
firewall-cmd --permanent --add-port=8080/tcp
firewall-cmd --reload

# SELinux Booleans
setsebool -P httpd_can_network_connect 1     # For Jenkins Proxy
setsebool -P httpd_can_connect_ldap 1        # For Moodle LDAP
setsebool -P allow_ftpd_full_access 1        # For FTP Home Dirs
chcon -R -t httpd_sys_rw_content_t /var/www/moodledata

```

---

## Part 2: Client Configuration

To allow a client (Linux) to use these services, it must trust the server's LDAP and DNS.

### 1. Host File (DNS Simulation)

On the client machine, map the local domains:

```bash
echo "SERVER_IP moodle.armour.local jenkins.armour.local server.armour.local" >> /etc/hosts

```

### 2. Join LDAP (SSSD)

Install the same SSSD packages on the client and point the `ldap_uri` in `/etc/sssd/sssd.conf` to the server's IP.

```bash
# Repeat the SSSD config from Part 1.5, changing 'localhost' to 'server.armour.local'
authselect select sssd with-mkhomedir --force
systemctl restart sssd

```

---

## Part 3: Testing & Verification

### Test 1: LDAP User Presence

Create a test user on the server:

```bash
# Add a test user 'techuser' to LDAP
# (Use an LDIF or a tool like LDAP Admin)
# Then check on server/client:
getent passwd techuser

```

### Test 2: SSH Login

```bash
ssh techuser@server.armour.local
# Success: Should prompt for LDAP password and create /home/techuser automatically.

```

### Test 3: Moodle HTTPS

Open a browser and navigate to `https://moodle.armour.local`.

* **Validation:** Ensure the SSL lock icon appears (accept the self-signed warning).
* **LDAP Auth:** Go to Site Admin > Plugins > Authentication > LDAP and enable it.

### Test 4: FTP Access

```bash
ftp server.armour.local
# Log in with techuser. You should be locked into /home/techuser.

```
