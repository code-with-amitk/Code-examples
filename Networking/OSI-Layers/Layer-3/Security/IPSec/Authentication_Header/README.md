## Authentication Header
- **Provides**
  - Authentication & Integrity
- **Does not provide**
  - Encryption
- **Header and Fields**
```c
  |IP Header | Authentication_Header | TCP/UDP/IDMP | Application
             |                       |
  -----------                         ----------------------------------------------------------------------------------
 |                                                                                                                      |
 | Next Hdr(1 byte) | AH Len(4 byte) | Reserved | SPI(4 byte) | Seq No(4 byte) | ICV/HMAC/Authentication Data(variable) |
```

- *1. Next Header:* IP
- *2. Payload Length:* length of the Authentication Header
- *3. Security Parameters Index (SPI):* This is connection identifier. Receiver will search this SPI in SPD and find matching SA.
- *4. Sequence Number:* 
  - Seq no of all the packets sent on an SA. Every packet gets a unique sqe no, even retransmissions. This detects reply attacks.
  -  If all 2<sup>32</sup> are exhausted, a new SA must be established to continue communication.
- *5. ICV(Integrated check value)/Authentication Data:*  
  - This is HMAC(keyed Hash) calculated on complete packet (|AH|Original-IP-Hdr|TCP|Application|)
  - **How ICV is calculated?**
```c
 Shared key(k1) is established during ISAKMP phase.
    
             \/ k1
Magic No1 > |XOR| > aaa

             \/ k1
Magic No2 > |XOR| > bbb
  
  |AH|Original-IP-Hdr|TCP|APP| + aaa > |HASH| > ccc
  
  ccc + aaa > |HASH| > ICV
```
