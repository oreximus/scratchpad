# Class #1

## Network

- Network: Net + Work

### Types of Network

#### LAN (Local Area Network):

- `device` Switch

- `range`: 4m-100m

- `devices supported`: 2 to 100PCs

#### CAN (Campus Area Network):

- `device`: L3 Switch, work on Layer 3 (Network Layer)

- `range`: 4m - 1km

- `devices supported`: 2 to 100 PC

#### MAN (Metropolitan Area Network):

- `device`: Router, organization own router

- `range`: 4m - city wide

- `devices supported`: 2 or more locations

#### WAN (Wide Area Network):

- `device`: Router, by ISPs, ISPs involved in the network

- `range`: 4m-worldwide

- `devices supported`: 2 or more locations

#### PAN (Personal Area Network):

- `device`: using your own device for sharing data

- `range`: Up to 10m

- `devices supported`: 1 to few devices

#### WLAN (Wireless Local Area Network):

- `device`: Wi-Fi Router

- `range`: 20m-50m

- `devices supported`: 2 or more points

#### WCAN (Wireless CAN)

- `device`: Wi-Fi Access Point (AP)

- `range`: 20m-1km

- `devices supported`: 2 to 250 PCs

#### WMAN (Wireless MAN)

- `device`: Wi-Fi CPE

- `range`: 20m - 15km

- `devices supported`: 2 or more points

#### WWAN (Wireless WAN)

- `device`:

- `range`: 15km - 1000s of Km, (approximate)

- `devices supported`: Cellular devices, IoT, etc.

> Lease Line

# Class #2

## IP Address

- IP address is the unique idenfier in the network.

- Versions of IP:
  1. IPv4
  2. IPv6

### IPv4

- `Size`: It's a 32bit address.
- `Structure`: Divided into four sections (octets), each containing 8 bits.
- `Range`: from 0 to 255,
- `Total Possible Address`: 4.3billion (4,294,967,296 unique)

### IPv6

- 128bit address,
- Divided into eight sections, 16bits

# Class 03

## Classful and Classless IP addressing

### Class A:

OFF0000000.00000000.00000000.00000000
to
OFF1111111.11111111.11111111.11111111

0.0.0.0 to 127.255.255.255

network bit:
host bit:

calculating total number of networks: (2^7-2)
hosts per networks: (2^24-2)
**resserved for**: large networks, such as governments, ISPs and large organization

**calculation**:

- by adding all of the rest bits value
- or subtracting off bit from 255

### Class B

ONOFF000000.00000000.00000000.00000000
to
ONOFF111111.11111111.11111111.11111111

128.0.0.0 to 191.255.255.255

N.H.H.H

calculating total number of networks: (2^7-2)
hosts per networks: (2^24-2)
**resserved for**: large networks, such as governments, ISPs and large organization

- by adding all of the rest bits value
- or subtracting off bit from 255

### Class C

ONONOFF00000.00000000.00000000.00000000
to
ONONOFF11111.11111111.11111111.11111111

192.0.0.0 to 223.255.255.255

- by adding all of the rest bits value
- or subtracting off bit from 255

### Class D

ONONONOFF0000.00000000.00000000.00000000
to
ONONONOFF1111.11111111.11111111.11111111

224.0.0.0 to 239.255.255.255

- by adding all of the rest bits value
- or subtracting off bit from 255

### Class E

ONONONON000.00000000.00000000.00000000
to
ONONONON111.11111111.11111111.11111111

240.0.0.0 to 255.255.255.255

- by adding all of the rest bits value
- or subtracting off bit from 255

# Class 04

## IANA

- IP Address Management
- DNS Management
- Protocol Assignment

> `GOI`: around 90-80,

from `IANA` to `GOI`, we got the connection, that's `T1`.

- where it reaches that's `Gateway of India`.
- we have a `submarine cables` connected physically to get the IP from IANA.

from `GOI` to `Distribution in Country` via ISP (i.e. BSNL/JIO): `T2`

from ISP to City (i.e. Indore): `T3`

> `Public IP`: which ISP provide us.
> `Private IP`: which we assign internal in our private network.

- Public/Private IP is the solution to overcome the shortage of IPv4.

- Reserved IPs range:

  - Class A: 10.0.0.0 to 10.255.
  - Class B: 175.16.0.0 to 10.255.
  - Class A: 192.168.0.0 to 10.255.
  - Special Ranges: 100.64.0.0 to 100.127.

- Loopback Address: 127.0.0.1 to 127.255.

### Conflicts:

- You can't out of the network if you have same network IP,

# Class 05

##

- Network first IP always allocate to the Gateway.
- When assigning IPs network should be same, and the IP should be unique.
- when IP is different from the current network, it take the finding IP to the `Gateway`.
- Finding the IP in other network (which could be of the ISP), then it goes further to its gateway.
- When we find the system, then we get back the request from the server (source becomes destination and destination becomes source i.e. vice-versa for
  communication)

### Example for accessing data or communicating betweeen IPs

- communicating IPv4 to different network IPv4:

  - the process of transferring the Public comming request to the private network host is `Port forwarding`.

- Public-Private IP work with NATTING and Port Forwarding.

> `Internet`: Public network that's available for everyone.
> `Intranet`: Private network is also known as `Intranet`.

## Class 06

## Subnetting:

### Subnet Mask

- 32 bit address
- 4 sections
- Network bit on and host bit off.

**Class A**:

- `Format`: N.H.H.H
- `Binary`: 111111111.00000000.00000000.00000000
- `Default Subnet Mask`: 255.0.0.0, 8 bits of network, rest 24 bit of host

// same with all Classes

- Example: Class A IP Address + Class A Default Net Mask = Class Full

- Example: Class A IP Address + Any Net Mask = Class Less

### Subnetting:

- A `subnetwork` is a logical subdivision of an IP address.

### Subnetting Example:

- `Subnet Mask`: 11111111.11111111.11111111.1000000
- This subnet mask adds 1 more bit to the network portion, resulting to:
  - `Network Bits` 25 -`Host bits` 7
  - `Subnets`: 2^7 - 2

## Classless Inter-Domain Routing (CIDR)

-

# Class 07

## : Rules for assigning IP Addresses to a Device

1. `Uniqueness`: maintaining uniqueness of IP address in a network. (If it's allocated to more than two
   devices, will configure the IP on the first device, and else will not be configured).
2. `Correct Network`: The IP network segment should be same on the network or subnet.
3. `Valid IP Range`.
4. `Avoiding Reserved IP Address while IP allocation`.
5. `Consistend with Subnet Mask`.
6. `Avoid Conflicts with DHCP`.
7. `Consistent Gateway Network`.

> If all of the networks bits are on and all of the hosts bits are off, they create the `network address`.
> If all of the networks bits are off and all of the hosts bits are on, they create the `broadcast address`.

# Class 08

## IP Address Practical

- We can't set the IP by setting the first octet bit on
- And can't leave the host bit with the 0
- also neither all of the host bit in the network can be 1 (reserved for broadcast address)
- while configuring IP you'll get the subnet mask auto for that IPv4 class.
- Jio gateway: 192.168.29.1
- Airtel gateway: 192.168.0.1

## Errors:

- Host unreachable in the case same nework IP but not present in the network.
- Trasmit failed, in the case of the different network IP.
-

## Example for allotting the Class C IP:

- from 192.168.1.2 to 192.168.1.254

# Class 09

## Topologies

- Topologies by generation:

  - `line topology`: devices connected in a line series. -`data transferring`: data flow can be done through every devices comes between the source and destination device.

    - `data security`: every device from where the data goes can see the data.
    - `in use`: not in practical use nowdays.
    - `examples`: use in the decoration lights.

  - `Bus Topology`: transferring data between devices through a common network line.

    - `data transferring`: data flow between devices does pass along through the connected devices, and if any device
      fails the network still works and devices can share the data to other devices.
    - `failing situation`: when the main network line breaks.

  - `Ring Topology`: all of the devices connected in the ring manner.

  - `Mesh Topology`: can build network by connecting devices in any random manner, connecting any device to any.
    (i.e. combination of multiple topologies)

  - `Full Connected Topology`: all devices are connected to a single devices and sharing data through that.

  - `Star Topology`: sharing data between devices through a centered placed hub device, and devices are connected
    to this hub.

## Networking Devices and Transmission Media

1. Unshielded Twisted Pair Cable (UTP)

   - CAT5e support speeds upto 5GB
   - CAT6 Higher performance speeds upto 10GBps
   - CAT6a Improved performance for longer distance
   - cannot folded and neither can be used for very long distance.
   - `for 100Mbps Ethernet (Fast Ethernet)`:
     - `transmit`:
       - Pin 1: Orange/White
       - Pin 2: Orange
     - `receive`:
       - Pin 3: White/Green
       - Pin 4: Blue

> Wires color coding:

    -

# Class 10

### MAC Address:

- unique address assign to device while manufacturing, especially devices that's used for communication.
- Wired and Wireless: they can be either wire based or wireless based.
- Speeds: Available in various speeds, ranging from 10 Mbps (older) to 10 Gbps (modern high speed devices)
- Wake on Lan: Some NICs supports remote power up of the device, a useful feature for remote management.

###

- RJ45 used in the PCs for ethernet connection.
- RJ11 used in telephones.

### Characteristics MAC Address:

- Common representation:

  - Colon Separated
  - Dash Separated
  - No Separation

- 48 bit address
  - First 24 bit: OUI - Identifies the manufacturer.
  - Last 24 bit: Manufacture assigned unique identifier.

3. Static Assignment:
   - MAC addresses are `burned into` the NIC during manifacturing.
   - Network Testing
   - Mac Address Spoofing

### OUI Range

- Smallest address: 00:A0:C9:00:00:00
- Largest address: 00:A0:C9:FF:FF:FF

### Multicast Mac Address:

- Types:
  - `Unicast`
  - `Multicast`
  - `Broadcast`

### Tracing MAC Address:

-
-

### Example

# Class 12 - I

## Linux

- Developed in 1991 by Linus Torvalds

## Shell

- Literal meaning: outer layer of something is a shell.
- In technical meaning: user used this interact with kernal --> which operates hardware.

## Features of Linux

- Open Source (GPL License)
- Multitasking
- Multiuser
- Portability
- Security (because of its open source nature the vulnerabilities can be easily found and patched)
- Stability and Reliability
- Community Support
- Performance: max utilization of your hardware.
- Unix Compatibility

# Class 12 - II

## Windows

## Computer Management Tools (MMC: Microsoft Management Console)

- Shortcut to open this: Window + X then press `g`, or in run dialog: `compmgmt.msc`

- `System Tools`: (Explore the apps in this!)
  - Task Scheduling: Scheduling tasks (i.e. updates, night mode, etc.)
    - for performing tasks on particular time.
    - You can observe the scheduled task in task scheduler library.
  - Event Viewer: contains logs related to the activities in our windows pc.

## Practicals to do:

- provide the simple IPv4 with the same network and try to communicate with the same network IP devices.
- provide the IPv4 with a subnet mask, in both manner classless and classful

# Class 13

## Distributions and Package Managers:

1. `Debian Based`: is a free open source Linux Distibution, Developed in 1993.

   - package: deb
   - availability: in the compact form, contains only the core packages.
   - associated distribution: Ubuntu, developed in 2004, first version was desktop version, (target was to replace Windows XP).

2. `Red Hat Enterprise Linux`: developed in 1993
   - beta version or testing version: Fedora OS, CentOS (free version of RHEL)

# Class 13 - II

### Windows Server Roles and Features:

- contains various roles for various purposes.
- that enhances the server functionalities, so the clients can take the advantages of it.

# Class 14

## Windows File System

- Unhide all of the files and folders in C drive to see the actual files of the Windows

  - Hidden Files option
  - System Hidden Files from the properties

- cmd command to all of the hidden in the drive:

```
dir \a
```

- `C:`, it's the root drive of the windows important files and folders.

- Folders and Files Purposes:
  - `Program Files`: contains installed programs, default folder for 64bit apps.
  - `Program Files (x86)`: contains installed programs, default folder for 32bit apps.
  - `Program Data`: contain the data of the programs in here, application data shared across all users.
  - `Recovery`:
  - `System Volume Information`:
  - `Users`: contains **user profiles** in this folder.
  - `Windows`:
    - `System32`
    - `WinSxs`
    - `Temp`
    - `Logs`
  - `Recycle Bin`
  - `PerfLogs`
  - `Recovery`
  - `pagefile`
  - `swapfile`
  - `Dump Stack Log file`

### Linux File System

- `/`: this the root folder location in Linux, contains all files and directory present in the system.
- `/bin`: Essential user binaries (e.g. ls, cp, mv), Needed for booting and single user-mode.
- `/sbin`: Essential system binaries (e.g. init, fsck, reboot), Mainly for system administration.
- `lib`: Libraries needed for /bin and /sbin binaries.
- `lib64`: 64-bit specific libraries.
- `/etc`: system wide configuration files and startup scripts
- `/dev`: contains device information
- `/proc`: Virtual filesystem for kernel and process information.
- `/var`: Variable data
- `/tmp`: contains temporary files.
- `/usr`: secodary hierarchy for user application, lib and all.
- `/boot`: contains booting related files and grub
- `/opt`: software installed otherwise from package manager need to kept here.
- `/srv`: Service Data
- `/home`: user profiles, user data
- `/root`: contains superuser or root user home data.
- `/mnt`: mouting point for devices

### CentOS Installation

- choose `Standard Partition` installation
- 1 GB to the `/boot` partition
- In case of 8GB RAM (we are using 4GB of Swap Storage)
- Then Create `/` Linux Partition
- Then click on `Done`

# Class 14 - II

## Windows Server

- `Server Manager`: It's a tool used to manage servers.
- `Service`: used to start, stop the services.

  - `Startup Type`:
    - Automatic
    - Automatic (Delayed Start)
    - Enable
    - Window Startup
    - Disable

- `Lanman` server,

- `Roles and Features`:

  - from the roles the clients can take advantage from this.
  - from the features server will have the new functionality or power to work on.

- `Local Server`:

  - Change the server name to some memorable name.
  - `WORKGROUP`: represent a particular department.
  - `WINRM`:
  - Allow the remote connection to windows server, with allowing it access via any windows client.
  - Changing the IP of the server from the Dynamic IP to Static IP.
    (i.e 192.168.1.51, 255.255.255.0, 192.168.1.1) IP, Subnet, and Gateway accordingly.

- Turn off the windows firewall, for our experiments.

# Class 15

- Init run levels, (make a common init levels list)
- Checking Runlevels command

# Class 15 - II

### Windows Server

#### DHCP Configuration:

- `DHCP Server`:
  - The Server should be `unique`
  - The `Lease Time` configuration
  - The firewall use port 67 for DHCP, (allow it from there if you're using a firewall).
  - The `Gateway` and `DNS` configuration needed for this.
  - Configuration Steps:
    1. Installation via `Roles and Features in Windows Server Manager`:
       - Select Server: DHCP
       - Then later follow the steps with the default setting
       - A Overview of the server.
       - Then Install it, with restart the server or do as your wish.
  - the DHCP configuration files and server files are located: `C:/Windows/System32/dhcp`.

> Checking if the Network Contains a DHCP server, `By Selection Auto Obtain IP in Network Configuration Setting in Windows`
> If it provides the
> In One LAN there can't be more than one DHCP Server.

- If there is a DHCP Server Present in your network, for your custom configuration disable the dhcp server from the router conf.

#### Role and Feature

# Class 16 - I

## Linux Server Fundamentals

> Connect the server with the ssh to interact with it.

1. Basics Commands:

- for checking kerenel version:

- for checking disk space

- for checking your hostname

localhost.localdomain

- checking current working directory:

pwd

- help command, running it only will brings-out help for terminal.

- man command, is used to look for the manual for the particular command.

- when you don't provide the IP to system nor provided by the DHCP Server, the link-local IP got allocated to
  the system.

2. Terminal Prompt Information:

root@localhost ---> before @ the user name is mentioned and at the other side is the hostname
~ : this signs means the user's home directory
$ : normal user (non-root users)

# : root user (superuser)

## DHCP Configuration

1. Create a Scope first
   - name the scope
   - provide the IP range (stating IP and ending IP)
   - lease time for the IP (timing to be able reserve the IP for the PC)
   - two options to configure DHCP (with or without the Gateway)
   - active the DHCP

### DORA Process in DHCP

(Discover, Offer, Request

- open the wireshark filter the traffic with UDP port 67.
- discover contains the information of the client, like mac-address.
- client side we use: 67 and at the server we use 68.
- in the details of the offering IP
- once we get the IP of the

# Class 16 - II

## Linux

### Basic Commands in Linux

1. `touch` command: to create empty files

```
// example
touch filename
```

```
// example for creating files containing space
touch "Armour Infosec"
```

2. cat command: to view the content of a file.

```
// viewing content via cat
cat filename
```

```
// putting content inside a file using cat
cat > f1.txt
// then you can type something to insert
```

3. mkdir command: to create directories via cli

```
mkdir d1
```

```
// creating multiple directory
mkdir d1 d2 d3
```

```
// creating directories recursively
mkdir -p d1/d2/d3/d4/d5
```

4. rmdir and rm command:

```
// using rmdir to delete empty directories only
rmdir dirName
```

```
// deleting folders recursively using rmdir
rmdir -p d1/d2/d3/d4
```

```
// deleting files using rm
rm filename
```

```
// deleting files using rm without confirmation
rm -f filename
```

```
// deleting files with verbose mode and forcedly
rm -vf filename
```

```
// removing files using wildcard, in example matching A[pattern]
rm -vf A*
```

## Domain Name Structure

1. Root Domain (.)

- The highest level in the DNS hierarchy
- Represent by a dot (.), usually implied and not typed in URLs.

2. Top Level Domain (TLD)

- Directly below the root domain.
- Example
  - Generic TLDs (gTLDs): .com, .org, .net, .edu, .gov
  - Country-Code TLDs (ccTLDs) .in (india), .us(United States), .uk(United Kingdom)
- Types of TLDs
  1.  Generic Top-Level Domains (gTLDs)
      - Used for general purposes, not specific to any country
      - Open to individuals and organizations globally.
      - Example
        .com, .org, .net, .info, .biz, .xyz
  2.  Sponsored Top-Level Domains (sTLDs)
      - Managed by private organizations or agencies with established rules for eligibility.
      - Often restricted to specific communication or purposes.
      - Examples:
        .edu (education), .gov(U.S. government), .mil(U.S. military)

www.google.com

## Tools

`Wireshark`: Protocol analyzer tool.

## Cli

`getmac`: for fetching mac-address

# Class 18 - I

## Linux Basic Commands:

- rm command:

```
// leaving file file1 and delete rest of the files
rm -rf file[!1]
```

- ls with pattern matching:

```
ls {*.txt, *.pdf}
```

## Windows Server

### Domain Name Valuation

#### Domain Appraisals: Estimating the Value of a Domain Name

1. TLD (Top-Level Domain)

2. Domain Length and Simplicity

3. Keyword Value and Search Volume

4. Brandability

5. Market Trends and Niche Popularity

6. Existing Traffic and SEO Metrics

7. Past Sales of Similar Domains

## Whois

- Domain Name and Status
- Register Information
- Registrant Details
- Registration and Expiry Dates
- Name Servers
- Technical and Administrative Contacts

# Class 18 - II

## DNS Server

### How DNS Server works?

- `Root DNS` Servers and in 13 in numbers, operated by various organization. - what does these server stores: - they do not stores actual domains-to-IP mapping (like example.com --> 10.10.4.5) Instead
  they stores and server the information about the location of Top-Level Domain (TLD) Name Server. - so they have the list of the TLDs servers (like of .com servers etc.) - they stores the `names and IPs` of the TLDs nameservers.

  > In the May 2025 survey we received responses from 1,227,232,638 sites across 277,546,948 domains and 13,470,692 web-facing computers. This reflects an increase of 8.9 million sites, 47,981 domains, and 29,625 web-facing computers. (from: https://www.netcraft.com/blog/may-2025-web-server-survey)

- `TLD Name Server`: servers used to manage the TLD domains records.

  - again this does not store the IP, it only provide the nameserver IP/Information.A

- `Authoritative Name Server` (Domain's Name Servers)
  - The `Authoritative Nameserver` holds the actual domains IP address.

# Class 19 - I

# Complete Domain Name System (DNS) Study Notes

## Table of Contents

1. [Domain Name Structure](#domain-name-structure)
2. [Top-Level Domains (TLD)](#top-level-domains-tld)
3. [Second-Level Domains (SLD)](#second-level-domains-sld)
4. [Subdomains](#subdomains)
5. [Domain Registration](#domain-registration)
6. [DNS Hierarchy](#dns-hierarchy)
7. [Key Terminology](#key-terminology)

---

## Domain Name Structure

### Complete Domain Anatomy

```
subdomain.second-level.top-level.root
    │         │           │      │
    │         │           │      └── Root (invisible .)
    │         │           └───────── TLD
    │         └───────────────────── SLD
    └─────────────────────────────── Subdomain/Hostname
```

### Real Example: www.example.com

- **Root:** . (implicit)
- **TLD:** .com
- **SLD:** example
- **Subdomain:** www

### Reading Direction

Domain names are read **right to left** in terms of hierarchy:

- Rightmost = Highest level in DNS
- Leftmost = Lowest level in DNS

---

## Top-Level Domains (TLD)

### 1. Generic Top-Level Domains (gTLD)

#### Unsponsored gTLDs (Open Registration)

- **.com** - Commercial (most popular)
- **.net** - Network infrastructure
- **.org** - Organizations
- **.info** - Information sites
- **.biz** - Business

#### Restricted gTLDs

- **.gov** - US Government only
- **.edu** - Educational institutions
- **.mil** - US Military
- **.int** - International organizations

### 2. Sponsored Top-Level Domains (sTLD)

Operated by private agencies with specific communities:

- **.aero** - Aviation industry
- **.museum** - Museums
- **.travel** - Travel industry
- **.coop** - Cooperatives
- **.jobs** - Job-related sites

### 3. Country Code Top-Level Domains (ccTLD)

Two-letter codes for countries/territories:

- **.us** - United States
- **.uk** - United Kingdom
- **.ca** - Canada
- **.de** - Germany
- **.in** - India
- **.jp** - Japan
- **.au** - Australia

#### Special ccTLD Considerations

- Some have residency requirements
- May offer third-level registrations (.co.uk, .ac.uk)
- Can be repurposed (.tv for Tuvalu used for television)

### 4. Infrastructure TLD

- **.arpa** - Address and Routing Parameter Area (technical use)

### 5. New gTLD Program

Since 2012, ICANN has approved hundreds of new gTLDs:

- **.google** - Google Inc.
- **.apple** - Apple Inc.
- **.amazon** - Amazon
- **.blog** - Blogging
- **.tech** - Technology

---

## Second-Level Domains (SLD)

### Definition

The part of the domain name that sits directly to the left of the TLD.

### Examples

- **google**.com - "google" is the SLD
- **wikipedia**.org - "wikipedia" is the SLD
- **github**.io - "github" is the SLD

### Registration Process

- You register the SLD with a chosen TLD
- SLD must be unique within that TLD
- Cannot exceed 63 characters
- Can contain letters, numbers, and hyphens (not at start/end)

### Types of SLD Registration

#### Open Registration

- Anyone can register
- Most .com, .net, .org domains

#### Restricted Registration

- Eligibility requirements
- .edu requires educational status
- .gov requires government status

#### Premium/Reserved Names

- Higher cost for desirable names
- Dictionary words, short names
- Previously owned valuable domains

---

## Subdomains

### Definition

Additional levels created under the SLD to organize content or services.

### Common Examples

- **www**.example.com - World Wide Web service
- **mail**.google.com - Email service
- **blog**.company.org - Blog section
- **api**.service.com - API endpoint
- **cdn**.website.net - Content delivery network

### Technical Details

- Can create unlimited subdomains
- No additional registration required
- Controlled by domain owner
- Can point to different servers/services

### Subdomain Hierarchy

```
fourth.third.second.first.example.com
  │     │      │      │       │
  │     │      │      │       └── SLD
  │     │      │      └────────── First subdomain
  │     │      └───────────────── Second subdomain
  │     └──────────────────────── Third subdomain
  └────────────────────────────── Fourth subdomain
```

---

## Domain Registration

### Registration Process

1. Choose available SLD + TLD combination
2. Register through accredited registrar
3. Pay registration fee (typically annual)
4. Provide contact information (WHOIS)
5. Configure DNS settings

### Important Concepts

#### Domain Registrar

- Companies authorized to sell domain names
- Examples: GoDaddy, Namecheap, Google Domains
- Must be ICANN accredited

#### Domain Registry

- Organizations that maintain TLD databases
- Verisign manages .com registry
- Different registries for different TLDs

#### WHOIS Database

- Public database of domain ownership
- Contains registrant contact information
- Privacy protection services available

### Pricing Factors

- **Standard domains:** $10-15/year typically
- **Premium domains:** $100-$1000s/year
- **Aftermarket domains:** Can cost millions
- **New gTLDs:** Vary widely in price

---

## DNS Hierarchy

### Root Level

- Managed by 13 root servers worldwide
- Contains information about TLD servers
- Represented by a dot (.)

### TLD Level

- Each TLD has authoritative name servers
- Maintains records for all SLDs in that TLD
- Operated by registries

### SLD Level

- Your domain's authoritative name servers
- Can be registrar's servers or your own
- Contains all DNS records for your domain

### Subdomain Level

- Additional records under your domain
- Can delegate to other name servers
- Unlimited depth possible

---

## Key Terminology

### FQDN (Fully Qualified Domain Name)

Complete domain name including all levels from root to subdomain.
Example: www.example.com. (note the trailing dot)

### Hostname

- Name of a specific computer/server
- Often used interchangeably with subdomain
- www is the most common hostname

### URL vs Domain Name

- **Domain Name:** example.com
- **URL:** https://www.example.com/page.html
- URL includes protocol and path

### DNS Record Types

- **A Record:** Points to IPv4 address
- **AAAA Record:** Points to IPv6 address
- **CNAME Record:** Canonical name (alias)
- **MX Record:** Mail exchange server
- **NS Record:** Name server
- **TXT Record:** Text information

### Domain vs Subdomain

- **Domain:** The registered name (example.com)
- **Subdomain:** Additional level under domain (blog.example.com)
- Root domain = apex domain = bare domain

---

## Brand and Geographic Considerations

### Brand Protection

- Companies register multiple TLDs for same SLD
- Prevents competitors from using similar names
- Trademark law applies to domain names

### Geographic Domains

- ccTLDs often have local preferences in search
- Some countries restrict registration
- Can indicate local presence to users

### Internationalized Domain Names (IDN)

- Support for non-Latin characters
- Uses Punycode for DNS compatibility
- Enables domains in local languages

---

## Best Practices

### Domain Selection

- Choose memorable, brandable names
- Avoid hyphens and numbers if possible
- Consider multiple TLD registration
- Check trademark issues

### DNS Management

- Use reliable DNS providers
- Implement proper TTL values
- Monitor DNS propagation
- Keep DNS records updated

### Security Considerations

- Enable domain locking
- Use strong registrar passwords
- Consider DNS security extensions (DNSSEC)
- Monitor for unauthorized changes

---

## Summary

The Domain Name System is a hierarchical structure that translates human-readable
names into IP addresses. Understanding the relationship between TLDs, SLDs, and
subdomains is crucial for web development, system administration, and digital marketing.
The system enables the organized distribution of internet resources while providing
flexibility for organizations to structure their online presence effectively.

# Class 20

# Windows DHCP Configuration and Linux Commands - Corrected Notes

## DHCP Configuration Options

### Backup Options

- **So backup**: To backup DHCP server
- **Snap series**: DHCP snapshots and backup series

### Policies

1. **Allow list**
2. **Deny**: We can use this to avoid fixing IP to particular client
3. **Ignore**: If DHCP client ignores the IP, server gives IP to that client

### Policies Configuration (Windows)

- **Policies**: Based on configuring and based on conditions
- **How DNS server works**: DNS server manages IP addresses, structure of the server

## Windows Server Configuration

### HTTP Windows Server

**HTTP** - Hypertext Transfer Protocol

1. **Client discovers DHCP server in the network**
2. **DHCP server after the IP**
3. **Client accepts the IP**
4. **Server acknowledges the client with the selected IP**

### Exclusion Range

- **Purpose**: To exclude some IPs that will not assign to anyone

### Reservation

- **Purpose**: Every time allocate the same IP to the same device
- **Usage**: For gateway, DNS, etc.

### Lease Expiration

- **Contains reservation tag**: ARP command to capture all MAC addresses from the server

### Scope Options

- **Purpose**: To separately provide the additional network info to the client
- **Examples**: Gateway, DNS, etc.

### Server Options

- **Purpose**: If you have more than one scope, the server can be applied from here

## Linux Commands

### Basic Navigation Commands

#### ls Command

**Purpose**: List files and directories

**Options**:

- `-h` - For human readable (converts the bytes to KB or human readable format)
- `-l` - Long list format
- `-a` - For hidden files
- `-la` - Combines long format and hidden files

**Note**: For making hidden files, add "." (dot) at the start of file name from (.) onwards

#### cd Command

**Purpose**: Change directory

**Usage**:

- `cd` - Navigate to home directory
- `cd ..` - Navigate to Linux filesystem root
- `cd ../..` - Go back two directories back

**Advanced Options**:

1. `-h` - For human readable
2. `-l` - Long list format
3. `-a` - For hidden files

**Note**: We can combine the options together

**Examples**:

- `ls -h` - For human readable
- `ls -l` - Converts the bytes to KB or human readable format
- `ls -a` - Long list format
- `ls -la` - For reading files
- `ls -r` - For reverse sorting
- `ls -t` - For time stamp sorting (lastly updated files will be at top)
- `ls -rt` - For creating showing directory data
- `ls -l` - For listing data without files and directories info
- `ls -1` - Combine wildcard for listing data

**File Operations**:

- `# file name`
- `$ any pattern`

# Class 21 - I

## Creating Links

- we have two ways to create links:
  1.  hard links: points directly to file content
  2.  soft links (symbolic): points to the path

```
ln /var/log/messages my_hard_link
```

```
ln -s /var/log/messages my_soft_link
```

- `hard links`: these are the mirrors of the files, even if the actual file get
  deleted the hard linked file will get the updates into it, treated as the actual file
  wherever it was located.

- `soft links`: these are also the mirrors of the linked file, but if the actual
  files get deleted the link will failed and the content of the file will not be
  accessed.

## less and more commands:

- simple navigation:
  - page_up: changing changing pages
  - space: changing pages
  - arrows keys for directional movements.

## User and System Identification

- id command:

```
id

// output
uid=0(root) gid=0(root) groups=0(root) context=unconfined_u:unconfined_r:unconfined_t:s0-s0:c0.c1023
```

- tty command: terminal time

```
tty

// output
/dev/pts/1
```

> tty (teletype), and pts (psuedo-terminal slave)

- actual terminals are `tty` and other terminals are denoted as `pts`

- whoami command

```
whoami

// output
username
```

- who -a command

```
           system boot  2025-06-03 18:14
           run-level 5  2025-06-03 18:14
guest    ? seat0        2025-06-03 18:15   ?          1952 (login screen)
guest    + tty2         2025-06-03 18:15 00:16        1952 (tty2)
root     + pts/1        2025-06-03 18:16   .          2651 (192.168.2.119)
```

- w command

```
 18:30:29 up 15 min,  3 users,  load average: 0.03, 0.03, 0.02
USER     TTY        LOGIN@   IDLE   JCPU   PCPU WHAT
guest    seat0     18:15    0.00s  0.00s  0.00s /usr/libexec/gdm-wayland-session --register-session gnome-session
guest    tty2      18:15   16:09   0.03s  0.03s /usr/libexec/gnome-session-binary
root     pts/1     18:16    2.00s  0.23s  0.01s w
```

## Host Information commands:

- hostname command:

```
hostname

//output
localhost.localdomain
```

- hostname with `-a` option

```
hostname -a

//output
localhost.localdomain localhost4 localhost4.localdomain4 localhost.localdomain localhost6 localhost6.localdomain6
```

- hostname with `-i` option, for the configured IP

```
hostname -i
// output
::1 127.0.0.1
```

- hostname with `-I

- uname command `-r`

- uname command with `-mrs`

## Date and Time commands:

- cal command

```
cal <date> <year>
```

- date command

```
date
// output
Tuesday 03 June 2025 06:36:51 PM IST
```

## System Information commands

- for os release information

```
cat /etc/os-release

// ouput
NAME="CentOS Stream"
VERSION="9"
ID="centos"
ID_LIKE="rhel fedora"
VERSION_ID="9"
PLATFORM_ID="platform:el9"
PRETTY_NAME="CentOS Stream 9"
ANSI_COLOR="0;31"
LOGO="fedora-logo-icon"
CPE_NAME="cpe:/o:centos:centos:9"
HOME_URL="https://centos.org/"
BUG_REPORT_URL="https://issues.redhat.com/"
REDHAT_SUPPORT_PRODUCT="Red Hat Enterprise Linux 9"
REDHAT_SUPPORT_PRODUCT_VERSION="CentOS Stream"
```

- specific for redhat family OSes

```
cat /etc/redhat-release

// output
```

- lscpu command

```
lscpu

// output
Architecture:             x86_64
  CPU op-mode(s):         32-bit, 64-bit
  Address sizes:          39 bits physical, 48 bits virtual
  Byte Order:             Little Endian
CPU(s):                   4
  On-line CPU(s) list:    0-3
Vendor ID:                GenuineIntel
  Model name:             13th Gen Intel(R) Core(TM) i7-13650HX
    CPU family:           6
    Model:                183
    Thread(s) per core:   1
    Core(s) per socket:   4
    Socket(s):            1
    Stepping:             1
    BogoMIPS:             5606.40
    Flags:                fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant
                          _tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 sse4_1 sse4_2 movbe popcnt aes rdrand hyper
                          visor lahf_lm abm 3dnowprefetch ibrs_enhanced fsgsbase bmi1 bmi2 invpcid rdseed adx clflushopt sha_ni arat md_clear flush_l1d arch
                          _capabilities
Virtualization features:
  Hypervisor vendor:      KVM
  Virtualization type:    full
Caches (sum of all):
  L1d:                    192 KiB (4 instances)
  L1i:                    128 KiB (4 instances)
  L2:                     5 MiB (4 instances)
  L3:                     96 MiB (4 instances)
NUMA:
  NUMA node(s):           1
  NUMA node0 CPU(s):      0-3
Vulnerabilities:
  Gather data sampling:   Not affected
  Itlb multihit:          Not affected
  L1tf:                   Not affected
  Mds:                    Not affected
  Meltdown:               Not affected
  Mmio stale data:        Not affected
  Reg file data sampling: Vulnerable: No microcode
  Retbleed:               Mitigation; Enhanced IBRS
  Spec rstack overflow:   Not affected
  Spec store bypass:      Vulnerable
  Spectre v1:             Mitigation; usercopy/swapgs barriers and __user pointer sanitization
  Spectre v2:             Mitigation; Enhanced / Automatic IBRS; RSB filling; PBRSB-eIBRS SW sequence; BHI SW loop, KVM SW loop
  Srbds:                  Not affected
  Tsx async abort:        Not affected
```

- lsusb command

```
lsusb

// output
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 002 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 002 Device 002: ID 80ee:0021 VirtualBox USB Tablet
```

- lspci command

```
lspci

// output
00:00.0 Host bridge: Intel Corporation 440FX - 82441FX PMC [Natoma] (rev 02)
00:01.0 ISA bridge: Intel Corporation 82371SB PIIX3 ISA [Natoma/Triton II]
00:01.1 IDE interface: Intel Corporation 82371AB/EB/MB PIIX4 IDE (rev 01)
00:02.0 VGA compatible controller: VMware SVGA II Adapter
00:03.0 Ethernet controller: Intel Corporation 82540EM Gigabit Ethernet Controller (rev 02)
00:04.0 System peripheral: InnoTek Systemberatung GmbH VirtualBox Guest Service
00:05.0 Multimedia audio controller: Intel Corporation 82801AA AC'97 Audio Controller (rev 01)
00:06.0 USB controller: Apple Inc. KeyLargo/Intrepid USB
00:07.0 Bridge: Intel Corporation 82371AB/EB/MB PIIX4 ACPI (rev 08)
00:0b.0 USB controller: Intel Corporation 82801FB/FBM/FR/FW/FRW (ICH6 Family) USB2 EHCI Controller
00:0d.0 SATA controller: Intel Corporation 82801HM/HEM (ICH8M/ICH8M-E) SATA Controller [AHCI mode] (rev 02)
```

- lsblk command

```
lsblk

// output

```

- free -h command

- demidecode --type 17 command

## Networking Commands

- ifconfig command

```
ifconfig

// output
enp0s3: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.2.121  netmask 255.255.255.0  broadcast 192.168.2.255
        inet6 fe80::a00:27ff:fe91:1c40  prefixlen 64  scopeid 0x20<link>
        ether 08:00:27:91:1c:40  txqueuelen 1000  (Ethernet)
        RX packets 2824  bytes 250785 (244.9 KiB)
        RX errors 0  dropped 1  overruns 0  frame 0
        TX packets 1925  bytes 1211606 (1.1 MiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        inet6 ::1  prefixlen 128  scopeid 0x10<host>
        loop  txqueuelen 1000  (Local Loopback)
        RX packets 16  bytes 1831 (1.7 KiB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 16  bytes 1831 (1.7 KiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

```

- for hidden interfaces: ifconfig -a

- ip a: to list of all network interfaces and their IP addresses

  - same: ip a
  - same: ip address
  - same: ip addr

- route -n: for gateway settings

- cat /etc/resolve.conf : for DNS settings

## History commands

- history: shows all of the bash history of commands

- cat ~/.bash_history: contains our all bash history

- current login session command deletion:

```
history -c
```

- running the last command:

```
!!
```

- running the last second command:

```
!2
```

- run the command matches with if

```
!if
```

- run the command start with cat

```
!cat
```

## Shutdown command

- for shutdown system immediatly

```
shutdown -P now
```

- for shutdown system after 1 minute

```
shutdown -P
```

- for shutdown using halt

```
shutdown -h now
```

- for cancelling shutdown

```
shutdown -c
```

# Class 21 - II

## Windows Server

## DNS Server

- recap:

  - 1.  Root Domain Servers
  - 2.  TLD Nameservers: manages domains extensions (like, .com, .in, etc.), we'll get nameservers details from these extensions.
    - stores: delegation information for domains within their TLD.
    - holds ns records: the authoritative nameservers for a given domain.
    - glue records
  - 3.  Authoritative Nameservers: hold the actual DNS records for a domain

- DNS Resolution Process (How Query Works)
  - your browser
  - DNS cache check
  - /etc/hosts or hosts file
  - Public DNS Server
  - Root Domain Server (13 Root Servers from A to M)
  - TLD Nameserver
  - Authoritative Nameserver
  - Browser Connect to the Website (finally)

# Class 22 - I

- Multiple command at once:

```
ifconfig; date; ls
```

> In SSH console usually we can't go up when clear screen with clear command, but with
> Ctrl+L we can.

- running multiple command using &&.

```
ifconfig && date && id
```

- running multiple command using || (OR logical state)

```
ifconfig || date || id
```

- running commands in the background:

```
ping 8.8.8.8 &
```

- putting background command in the foreground:

```
fg
```

- putting command into background without showing it's output on
  the terminal

```
ping 8.8.8.8 >/dev/null &
```

- jobs command to show the background processes:

```
jobs
```

> on `fg` the last ran command will get foreground.

- Pipes Command

  - Take one command output as a Input for second command.

- example combining the ls -l with less command using pipe command:

```
ls -l /etc/ | less
```

- example sorting using pipe

```
ls -l /etc/ | sort
```

- example of pipe command using grep

```
cat /etc/passwd | grep root
```

- counting total lines of a file:

```
cat /etc/passwd | wl -n
```

- ps aux with sorting using -nrk 3 |

```

```

- using proper chaining of command from pipes:

```
cat /etc/passwd | grep "root" | sort | uniq
```

# Class 22 - II

## DNS Records

- DNS Records are saved into authoritative nameservers.

- `A Record` maps the domain to the public IPv4.

- `AAAA Record` maps the domain to the public IPv6.

- `CNAME Record` (Canonical Name Record): creates an alias for another domain name.

  - useful for pointing multiple subdomains to a single domain.

- `MX Record`: the sending mail server queries DNS for MX records for example.com.

- `TXT Record`: this is comments for the DNS server, but we'll use this for the Domain
  verification, for example to verify the or to make the mail server works we maintains these
  information in TXT records in DNS Server Records: - SPF: sender policy framework (protects from email spoofing) - DMARC: Domain Based Message Authentication, Reporting and Conformance. (These ensures authentication for your emails) - DKIM: DomainKeys Identified Mail, it's a digital signature for your emails.

- `NS Record`: These contains the records or the information for the Authoritative Nameservers.

- `SOA Record`: Start of Authority Record: contains administrative information about the domain.

- `PTR Record`: Used for reverse DNS lookup (IP --> Domain)

- `SRV Record`: (Service Record)

- `CAA Record`: (Certification Record)

- example record information:

  - blog.example.com
  - 3600: TTL (Time to live, how the long the DNS will keep this in cache)
  - IN
  - CNAME
  - myblog.example.com

- example and working of nslookup:

```
nslookup armourinfosec.com

// output
Server:  dns.google
Address:  8.8.8.8

Non-authoritative answer:
Name:    armourinfosec.com
Addresses:  2606:50c0:8002::153
          2606:50c0:8003::153
          2606:50c0:8000::153
          2606:50c0:8001::153
          185.199.111.153
          185.199.108.153
          185.199.109.153
          185.199.110.153
```

- testing nslookup with A record details

```
nslookup -type=A armourinfosec.com

// output
Server:  dns.google
Address:  8.8.8.8

Non-authoritative answer:
Name:    armourinfosec.com
Addresses:  185.199.108.153
          185.199.111.153
          185.199.109.153
          185.199.110.153
```

- testing nslookup with AAAA record details:

```
nslookup -type=AAAA armourinfosec.com

// output
Server:  dns.google
Address:  8.8.8.8

Non-authoritative answer:
Name:    armourinfosec.com
Addresses:  2606:50c0:8002::153
          2606:50c0:8000::153
          2606:50c0:8001::153
          2606:50c0:8003::153
```

- testing nslookup with MX record details:

```
nslookup -type=MX armourinfosec.com

// output
Server:  dns.google
Address:  8.8.8.8

Non-authoritative answer:
armourinfosec.com       MX preference = 10, mail exchanger = mail.armourinfosec.io
```

- testing nslookup with TXT record details:

```
nslookup -type=TXT armourinfosec.com

// output
Server:  dns.google
Address:  8.8.8.8

Non-authoritative answer:
armourinfosec.com       text =

        "v=spf1 ip4:155.133.27.166 ip6:2a02:c206:2112:8075:0000:0000:0000:0001 -all"
```

- testing nslookup with SOA record details:

```
nslookup -type=SOA armourinfosec.com

// output
Server:  dns.google
Address:  8.8.8.8

Non-authoritative answer:
armourinfosec.com
        primary name server = ns45.domaincontrol.com
        responsible mail addr = dns.jomax.net
        serial  = 2024061100
        refresh = 28800 (8 hours)
        retry   = 7200 (2 hours)
        expire  = 604800 (7 days)
        default TTL = 600 (10 mins)
```

- nslookup example querying with a specific DNS Server:

```
nslookup armourinfosec.com 64.6.64.6

// output
Server:  rec1pubns1.ultradns.net
Address:  64.6.64.6

Non-authoritative answer:
Name:    armourinfosec.com
Addresses:  2606:50c0:8001::153
          2606:50c0:8002::153
          2606:50c0:8003::153
          2606:50c0:8000::153
          185.199.108.153
          185.199.109.153
          185.199.110.153
          185.199.111.153
```

> whatever you do with nslookup that doesn't goes into the DNS cache.

- DNS cache Management
  - ipconfig /displaydns: to show the dns cache
  - ipconfig /flushdns: to remove the dns cache

## Resource and HomeWork

### To study:

1. Internet
2. Intranet
3. VPN (Virtual Private Network)
4. Classful/Classless IP
5. Reserved IP
   - Private and Public IP
6. DHCP (Again)
7. Network Mask / Net Mask / Subnet Mask / Classless (again)
8. Network Address Translation, NAT (NATTING, router uses this)
9. Network Devices/ Network Topologies/ OSI-TCP IP Model
10. Linux Distributors and Package Managers
11. Linux Directory Structure
12. DORA Process (for Monday)
13. Host File and NetBIOS
14. Types of DNS Servers
15. DNS Records
16. Redirection

### To study (P):

1. Link Local Addressing
2. Wires purpose in the cables
3. Startlink network distribution and DDH
4. Quick Pinout Table
5. 91 CRPC
6. Registeries in Windows
7. Search about the TLDs server and the real functioning all system works.

### Practical:

1. test `traceroute` (linux)
2. test `tracert` (window)
3. use `subnet calculator`
4. in run dialog: `ncpa.cpl` (for IP configuration)

## Abbreviation:

- `POE`: Power On Ethernet

## How to study

1. Why do we need it, on what protocol it works on?
2. Why it was created

## Resources:

- masgrave.dev: For Downloading windows versions
- domain appraisal checking website: estibot.com
- netcraft.com: survey website for doamin information
- iana.org (root domain reference): https://www.iana.org/domains/root/db
