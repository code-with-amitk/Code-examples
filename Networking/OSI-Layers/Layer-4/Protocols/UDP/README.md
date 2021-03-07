## UDP / User Datagram Protcol
- **Header**
```c
|source port (2byte)|	dst port(2 byte)| Total length (2 byte)|Checksum(2 bytes)|
 
Total Len = (UDP Header + Data)	chksum (2 bytes) 
Checksum = Same as TCP Header checksum. Pseudo IP Header+UDP Header+App Data
```
