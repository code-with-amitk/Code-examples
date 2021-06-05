## ESP(Encapsulating Security Payload)
- **Provides**
  - Encryption
  - Integrity
  - Authentication: With ESP Header & Trailer, Authentication Data Tailor is also added to message.
- **Header**
```c
|New IP | ESP Hdr | Old IP | TCP | App | ESP Trailor | Auth Data/ICV |
        |         |                    |             |
      --           -                  -               -------------
     |              |                |                             |
     | SPI | Seq no |                |Padding | Pad Len | Next Hdr |
```
- *1. SPI:*  same as in AH
- *2. Seq No:* same as in AH
- *3. Next Hdr:* same as AH
- *4. ICV:* Same as AH But does not included in Header of Trailer but comes after trailer.
  - **Why ICV is placed at end?**
    - Advantage in a hardware implementation: HMAC can be calculated as the bits are going out over the network interface and appended to the end. This is why Ethernet and other LANs have their CRCs in a trailer, rather than in a header.
    - With AH, the packet has to be buffered and the signature computed before the packet can be sent, potentially reducing the number of packets/sec that can be sent.
  
