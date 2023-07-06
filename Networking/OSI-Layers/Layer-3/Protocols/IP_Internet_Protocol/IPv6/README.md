- [Why IPv6](#why)
- [Advantages of IPv6](#adv)
- [Why IPv6 is not deployed yet worldwide](#whynot)
- [Addressing modes](#modes)
- [IPv6 Header](#hdr)
- [IPv6 Address Notation](#not)
  - [Rules of Shrinking IPv6 Address](#shrink)
- IPv6 Addressing Scheme
  - [Subnet Mask](#smask)
- [IPv6 URI](#uri)
- [Configuring IPv6 on Node](#conf)


<a name=why></a>
### Why IPv6
- There are no new IPv4 addresses which can be allocated to new orgnizations.
- As of January 31, 2011, IANA allocated all of its space to regional internet registries (RIRs).
  - These RIR's have already ran out addresses for [/8 networks(ie all class A)](Networking/OSI-Layers/Layer-3/Protocols/IP_Internet_Protocol/IP_Addressing_Scheme). APNIC (Asia/Pacific), RIPE (Europe), and LACNIC (Latin America and Caribbean).

<a name=adv></a>
### Advantages
- *1. LARGER ADDRESS SPACE:* 2<sup>128</sup> = 340 trillion trillion trillion. This number is so large that around 1534 addresses can be allocated to every square meter of this earth
- *2. SIMPLIFIED HEADER:* All necessary information + options are moved to End of IPv6 header
- *3. END-TO-END CONNECTIVITY:* NAT will not be required specifically
- *4. FAST FORWARDING/ROUTING:* Simplified headers allows to fast forward packet
- *5. IPSEC:* Optional in IPv6
- *6. ANYCAST SUPPORT:* Broadcast removed. 3 Modes are present: unicast, anycast, multicast

<a name=whynot></a>
## Why IPv6 is not deployed yet worldwide
- **1. Vast majority(pvt companies, home users) have no need to deploy IPv6**
  - We are out of public IPv4 address space. Companies are using NAT.
- **2. Learning curve is steep** 
- **3. Deploying is difficult**
  -  Most devices worlwide does not support IPv6 seamleesly. ie Does not support Dual-Stack. Since **IPv6 not backward compatbile with IPv4.**
  -  Whole IPv4 network communication will go for a change.

<a name=modes></a>
## Addressing modes
- *1. [Unicast(same as IPv4)](/Networking/IP_Address_Types)*
- *2. [Multicast(same as IPv4)](/Networking/IP_Address_Types)*
- *3. Anycast(new to IPv6):*
  - anycast addresss is assigned to a set of interfaces that belong to different nodes. Syntax of Anycast address is same as unicast addresses.

<a name=hdr></a>
## IPv6 Header
 - Header Length: 39 bytes
 ```c
 |version=6 (4 bit) | packet priority/Traffic class (1 byte) | QOS Management/Flow Label (20 bit) | Payload length (1 byte) | Next header (1 byte) | TTL/Hop Limit (1 byte) | SrcIP(16 byte) | DstIP(16 byte) |
 ```
- *VERSION=6:*
  - But this field has a limited use because IPv4 and IPv6 packets are not distinguished based on the value in the version field but by the protocol type present in the layer 2 envelope
- *PACKET PRIORITY:* Assigning priorities to different packets
- *FLOW LABEL:*     Flow = srcIP + Flow Label
  - Used by source to mark packets belonging to same flow. Traffic that is not associated with any flow has flow label=0. Packets belonging to same flow should be treated same by IPv6 Routers
- *PAYLOAD LENGTH:* Length of data field. data=TCP+Appdata. So Max data can be 2<sup>16</sup> =  65535 bytes = 64Kilobytes.
  - When Application want to send packet > 64kilo. **Jumbo packet(Jumbogram)** is created. Now payload Length=0.  And new jumbo Payload extension header is provided
- *NEXT HEADER:* Transport Layer Header. TCP(6), UDP(17)
- *TTL/Hop Limit:*  This is decremented by 1 as each node sends the packet. If it reaches 0, packet is discarded. 28 =  256. So max nodes that can fall between 2 IPv6 nodes are 255

<a name=not></a>
## IPv6 Address Notation
- 128/8 = 16 bytes. IPv6 has 8 blocks seperated by colon(:). Each block contains 2 bytes(16 bits). 4 bits create 1 character.
- Example:
```c
//4 bits create 1 decimal representation.
0010000000000001 0000000000000000 0011001000111000 1101111111100001 0000000001100011 0000000000000000 0000000000000000 1111111011111011 
  2001          :        0000    :      3238      :     DFE1       :    0063        :    0000        :   0000         :    FEFB         //hex format
```                

<a name=shrink></a>
### Rules of Shrinking IPv6 Address
- Despite conversion to Hex format, IPv6 remains bit longer these rules can be applied to shorten the IPv6 address.
  - *1.* Discard Leading Zeros: Example: discard 00 from front of 0063.
```c
2001:0000:3238:DFE1:0063:0000:0000:FEFB
shrinks to
2001:0000:3238:DFE1:63:0000:0000:FEFB 
```
  - *2.* Omit consecutive blocks that have all Zeros, Replace with (::).
```c
2001:0000:0000:0000:0000:0000:0001:d456
shrinks to
2001::1:d456
```
  - *3.* Shrink to 1 0: If all digits are Zero in block, It can be shrunk to 0. 2nd block shrunken to 0. 
```c
2001:0000:3238:DFE1:63::FEFB 
to
2001:0:3238:DFE1:63::FEFB 
```

## IPv6 Addressing Scheme
<a name=smask></a>
### Subnet Mask
- IPv6 has fixed mask `/64` (ie 64 bits). 64 are given to hosts, and 64 to networks. We can do subnetting/supernetting.
```c
  Example: 2001:0DB8:0000:CD30:0000:0000:0000:0000/60      Means 60 Bits from Left are considered as Network Address[same as IPv4]
  Equivalent to    2001:DB8:0:CD30::/60
```

<a name=uri></a>
## IPv6 URI
- In resource identifiers like URIs and URLs, the colon (:) character is used to separate the IP address from the port number. IPv6 addresses contains colon characters, this might cause conflicts. Because of this, literal IPv6 addresses are enclosed in square brackets. Example:
```c
  http://[2001:db8:a0b:12f0::1]:80/index.html 
  http://[2001:db8:a0b:12f0::1]/index.html 
```

<a name=conf></a>
## Configuring IPv6 on Node
- There are 2 methods:
- **1. Static configuration**
- **2. Dynamic/DHCPv6 Configuration:** In DHCP there are 2 methods
  - **a. Using ff002 :: 1 : 2** This is All DHCP Server Link Local Multicast Group. All DHCP Servers on LAN are members of this multicast group. Now DHCP server will send reply on 546/UDP port on which client must be listening.
  - **b. SLAAC(Stateless Address Auto Configuration):**             radvd package in RHEL 7 provides SLACC
```c
                      - Host brings LL address on fe80 :: /64
                      - Sends Router Solicitation message to ff02 :: 1 : 2
                      - DHCP routers responds with N/W prefix and other information.
                      - Host uses N/W prefix with N/W ID to construct IPv6 address.
``` 
