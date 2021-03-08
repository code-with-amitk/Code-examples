## Features / Characteristics
- **1. TCP+[TLS](https://sites.google.com/site/amitinterviewpreparation/networking/layer5/ssl) need 2 seperate handshakes. QUIC does in 1 message**
  - QUIC does Connection Establishment in just 1 packet.
  - TCP Handshake(3 packets) + TLS Handshake(4 packets)

<img src=QUIC_over_TCP-3-way-handshake.JPG width=500 />

- **2. 0-RTT connection latency**
  - Clients those have previously communicated with a server can start a new session without a three-way handshake, using limited state stored at clients and servers.
  - This happens 75% the time
- *2.* Connections are handled by QUIC
  - Since UDP is connectionless, all connections are handled by QUIC.
- *3.* Improved Congestion control wrt TCP
- *4.* Improved Forward Error Correction.
