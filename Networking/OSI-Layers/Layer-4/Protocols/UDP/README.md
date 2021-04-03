### UDP / User Datagram Protcol
- **Header**
```html
|source port (2byte)|	dst port(2 byte)| Total length (2 byte)|Checksum(2 bytes)|
 
Total Len = (UDP Header + Data)	chksum (2 bytes) 
Checksum = Same as TCP Header checksum. Pseudo IP Header+UDP Header+App Data
```
- [Advantages, Disadvatanges of UDP](Advantages_Disadv_of_UDP.md)
- [Applications](UDP_Applications.md)
- **Features**
  - Hole Punching
