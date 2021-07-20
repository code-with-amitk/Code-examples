- IPv4
- IPv6
- [IPv4 vs IPv6](#vs)
- IPV4 Addressing Scheme
  - [1. Classful Addressing](#ful)
  - [2. Classless Addressing](#les)

### [IPv4](IPv4)

### [IPv6](IPv6)

<a name=vs></a>
### IPv4 vs IPv6

||IPv4|IPv6(not backward compatible with IPv4)|
|---|---|---|
|IP_Address|32bit = 4 byte|128 bit = 16bytes|
|No of Distinct Addresses| 2<sup>32</sup> = 4294967296 = 4x10^9 = 4 Billion | 2<sup>128</sup> = 340 trillion trillion trillion |
||[Addresses getting exhausted](IPv4/IPv4_Disadvantages_Problems/)|[Will never Exhaust](IPv6/IPv6_Characteristics)|
|Bytes seperation represented by| Dot . | Colon : |
|Header | IPv4 Header, MaxLen=60bytes | IPv6 Header, MaxLen=39bytes |
|Checksum | Header has checksum feild | Does not have |
|QOS Support | Does not have  | Header has QOS Support |
|Broadcast | Supported | Not Supported |
|Mapping to MAC Address|Use ARP |Used NDP (Neighbour Discovery Protocol)|

## IPV4 Addressing Scheme
<a name=ful></a>
### 1. Classful Addressing
- Each IP Address is assigned to a class
- 0.0.0.0 - Invalid Address(N/W ID), 255.255.255.255 - Broadcast Address
- class A, B addresses are exhausted. Class C addresses are given to new organizations
```console
    Class             A                       B                   C               D(MULTICAST)              E(experimental)
  N/W part            a                       a.b                 a.b.c           224.0.0.0-239.255.255.255
  Host part           b.c.d                   c.d                 d
    Range           0-127.x.x.x               128-191.x.x.x       192-223.x.x.x   224-239.x.x.x             240-255.x.x.x     
  No of hosts      2pow24=1677716-2           2pow16=65536-2      2pow8=256-2
                  N/W ID,broadcast removed
  Suitable For        Large Org                    medium Org        Small Org
```
