||MTU (maximum Transmission Unit)|MSS (Maximum TCP Segment Size)|
|---|---|---|
|What|IPv4 Maximum IP packet size for a given link. Packets bigger than the MTU is fragmented. If (packet size > MTU) {fraagmentation}|TCP, Maximum amount of data that Receiver or Sender wants to receive(specified in Octets/bytes). It excludes TCP, IP Headers.Each side can have different MSS.This value cannot be changed When connection is Established. if (TCP_packet_size > MSS) {Discard Packet}|
|Default value|1500|536|
|Related to|IPv4|TCP|
|When decided|Routing|3-way handshake|
|If i dont want fragmentation?|Increase MTU size, Use helper protocols:PMTUD||
|Network & respective MTUs(bytes)|802.3(Ethernet):1500, 4Mb token ring:4464, 16Mb token ring:17914||

- MTU = 1500 bytes
```c
| IP(20 bytes) | TCP(20 bytes) | App (1460 bytes) |
```
