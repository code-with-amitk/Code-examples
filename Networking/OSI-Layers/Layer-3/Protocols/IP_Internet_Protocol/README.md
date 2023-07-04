- [IPv4 vs IPv6](#vs)
- [IPv4](IPv4)
- [IPV4 Addressing Scheme: Classless, classful addressing, subnettting, supernetting](IP_Addressing_Scheme)
- [IPv6](IPv6)

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
