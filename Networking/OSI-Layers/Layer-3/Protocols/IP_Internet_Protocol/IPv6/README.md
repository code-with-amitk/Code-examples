## IPv6
- [IPv6 Header](IPv6_Header)
- [IPv6 Characteristics, Advantages](IPv6_Characteristics)
- [Why IPv6 is not deployed yet worldwide](Why_IPv6_not_deployed_yet_worldwide)
- [Addressing Modes](IPv6_Addressing_Modes): unicast, multicast, anycast
- [IPv6 Address Notation & Rules of shrinking IPv6 Address](Address_Notation)
- **IPV6 Subnet Mask:**
  - IPv6 has fixed mask `/64`. Means from 128 bits. 64 are given to hosts(Enough hosts) and 64 to networks. But providers can again provide a smaller mask to organization.
```c
  Example: 2001:0DB8:0000:CD30:0000:0000:0000:0000/60      Means 60 Bits from Left are considered as Network Address[same as IPv4]
  Equivalent to    2001:DB8:0:CD30::/60
```
- **IPv6 URI:** In resource identifiers like URIs and URLs, the colon (:) character is used to separate the IP address from the port number. IPv6 addresses contains colon characters, this might cause conflicts. Because of this, literal IPv6 addresses are enclosed in square brackets. Example:
```c
  http://[2001:db8:a0b:12f0::1]:80/index.html 
  http://[2001:db8:a0b:12f0::1]/index.html 
```  
