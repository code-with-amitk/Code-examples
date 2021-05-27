## Byte Order
- [Little Endian](/Languages/Programming_Languages/C/Bitwise) = N/W byte order
- [Big Endian](/Languages/Programming_Languages/C/Bitwise) = Host Byte Order
- **Why required?** 
  - All computers store data differently. Internet Protocols says All data should be sent using N/W byte on internet then can be converted as per computer's storage endianess.
- **APIs** htons(), htonl(), ntohl(), ntohs()
