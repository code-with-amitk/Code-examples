## MTU vs MSS

||MTU (maximum Transmission Unit)|MSS (Maximum TCP Segment Size)|
|---|---|---|
|What|IPv4 Maximum IP packet size for a given link. Packets bigger than the MTU is fragmented|TCP, Maximum amount of data that Receiver or Sender wants to receive(specified in Octets/bytes) OR maximum amount of data computer can handle at once(in single frame, unfragmented). It excludes TCP, IP Headers.Each side can have different MSS.This value cannot be changed When connection is Established.|
|Default value|1500| 536|
|Related to|IPv4|	TCP|
|When decided|Routing|3-way handshake|
|Aftermaths 	If (packet size > MTU) {fraagmentation}|	if (TCP_packet_size > MSS) {Discard Packet}|

- If i dont want fragmentation? Increase MTU size, Use helper protocols [PMTUD]
- Different Networks may have different MTU's. As per IEEE:
        Network               MTU(in bytes)
            802.3                    1500
            4Mb token ring     4464
            16Mb token ring   17914
