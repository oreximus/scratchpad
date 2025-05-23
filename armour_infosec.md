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

### To study (P):

1. Link Local Addressing
2. Wires purpose in the cables
3. Startlink network distribution and DDH
4. Quick Pinout Table
5. 91 CRPC
6. Registeries in Windows

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
