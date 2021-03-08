## Features / Characteristics / Improvement over TCP
- **1. TCP+[TLS](https://sites.google.com/site/amitinterviewpreparation/networking/layer5/ssl) need 2 seperate handshakes. QUIC does in 1 message**
  - QUIC does Connection Establishment in just 1 packet.
  - TCP Handshake(3 packets) + TLS Handshake(4 packets)

<img src=QUIC_over_TCP-3-way-handshake.JPG width=500 />

- **2. 0-RTT connection latency**
  - Clients those have previously communicated with a server can start a new session without a three-way handshake, using limited state stored at clients and servers.
  - This happens 75% the time

- **[3. Head of line blocking issue in TCP](../../TCP/Advantages_Disadv_of_TCP)*

- **[4. Improved Congestion Control wrt TCP](../../TCP/Characteristics/Flow_and_Congestion_Control):** 
  - Since UDP is connectionless, all connections are handled by QUIC.
  - QUIC implements Congestion control Algos without going to kernel.

- **5. Does not use TCP's SACK for lost packets**
  - QUIC uses Packet number for packet ordering. 
  - Each Packet Number is strictly incremented, so if Packet-4 is lost and Packet-5 arrives. Reciever knows Packet-4 is lost.
