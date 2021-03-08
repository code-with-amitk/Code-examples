## Features / Characteristics
- *1.* Reduced number of packet exchanged wrt TCP+[TLS](https://sites.google.com/site/amitinterviewpreparation/networking/layer5/ssl).
  - QUIC does Connection Establishment(TCP takes 3 packets)+TLS Handshake(4 packets) in just 1 message.
- *2.* Connections are handled by QUIC
  - Since UDP is connectionless, all connections are handled by QUIC.
- *3.* Improved Congestion control wrt TCP
- *4.* Improved Forward Error Correction.
