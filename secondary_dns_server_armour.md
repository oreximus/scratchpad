# Class Notes

## Secondary DNS Server configuration in Windows Server

- In the secondary server start the wireshark and set the filter:

```
ip.addr = client-ip && (udp.port == 53 || tcp.port == 53)
```

-

> nslookup always use the master DNS Server by default, so for the practical
> querying or testing from the client, you can use `ping` from the client.
> that'll use the secondary DNS Server.

- for making nslookup to query from the secondary DNS Server, so mention the IP
  of it:

**example**:

```
nslookup facebook.com 192.168.2.32
```

- for testing serial number changes between master and secondary server, then it'll
  exchange the records using IXFR from master to secondary DNS server.

**wireshark filter**:

```
ip.addr == secondary-dns-ip && (udp.port == 53 || tcp.port == 53)
```

## Forwarder Nameserver and NetBIOS

- It take the queries and forward them to the next DNS Servers (configured ones).

- Configuring the forwarder DNS Server:
  - remove the Existing zone from the secondary DNS server.
  - on the Main Server (i.e. NS2), you'll have a file `Forwarders`.

**Testing the practical scenario**:

- Run the wireshark on the forwarder DNS server.

## Conditional Forwarder

- Conditional forwarder will take the particular query to the configured value.
  - example: configuring google.com with 8.8.8.8

## Dynamic DNS Server:

- In case of changed IPs of the devices (where IPs are dynamically allocated) and their existing entries in our DNS server need to be updated dynamically according to it, in that case we use this `Dynamic DNS Server`, only in the case of `fixed hostname`.

**In your DNS Zone properties**:

- While creating zone, select the non secure and secure both option.
  - in the existing, from properties you'll

**In your DHCP Scope properties**: - Dynamic Updates and Enable Dynamic Updates.

**In your client**:

- Also add the domain suffix from the Change PC names.
- From the Advanced Setting from the IP address configuration:
  - check the option to register suffix and all.

# To Study:

- NetBIOS name
