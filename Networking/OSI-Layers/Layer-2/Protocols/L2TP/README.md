## L2TP / Layer 2 Tunneling Protocol
- Since [Layer 2](../../) is used to deliver packet within a LAN. L2TP is used to securely transfer packet within a LAN.
- IPSec and L2TP
  - Sending encrypted packet from Gateway to gateway -> IPSec
  - Securely delivering packet in remote LAN(private network) -> L2TP
```c
-|-------|-LAN------|                            |-----------|---------|--
Host1   Host2       |                            |        Host3      Host4
                    |                            |
                  Gateway1     Internet      Gateway2
                    <-------    ipsec   -------->
```
