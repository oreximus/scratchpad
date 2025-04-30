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
- `Total Possible Address`: 4.3billion

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

ONONONONO000.00000000.00000000.00000000
to
ONONONONO111.11111111.11111111.11111111

240.0.0.0 to 255.255.255.255

- by adding all of the rest bits value
- or subtracting off bit from 255

### To study:

1. Internet
2. Intranet
3. VPN (Virtual Private Network)
4. Classful/Classless IP
5. Reserved IP
   - Private and Public IP
