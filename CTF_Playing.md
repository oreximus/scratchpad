## CTF PLAYING APPROACH

### Web App Testings

- Network Scan

    - required IP of the Host!

    - Tools Used:
        - NMAP
        - ZENMAP
        - Rustscan

- Directory Enumeration
    
    - Required domain name

    - tools used:
        - feroxbuster
        - dirbuster
        - gobuster
        - ffuf

- Subdomain Enumeration
    
    - Require Domain name

    - tools used:
        - sublist3r
        - ffuf
        - ferobuster

- In case of Wordpress Site

    - Require Domain Name
    
    - tools used:
        - wpscan

- If any vulnerability related to SQL

    - require vulnerability

    - tools used:
        - sqlmap;


#### Web Common Vulnerabilities and Exploit

- Login Page can vulnerable
    - Nosql attack
    - default ID/pass
    - Check if something is revealed on the source code.

- If get Authentication
    - Look for any file upload/ Reverse can be uploaded;
    - Look for any command injection/ If this CMS; can execute our command by modifying templates.

### Common Attacks

- PATH Traversal/File Inclusion
