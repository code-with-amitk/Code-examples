 ## IPv6 Header
 - Header Length: 39 bytes
 
 |version=6 (4 bit) | packet priority/Traffic class (1 byte) | QOS Management/Flow Label (20 bit) | Payload length (1 byte) | Next header (1 byte) | TTL/Hop Limit (1 byte) | SrcIP(16 byte) | DstIP(16 byte) |
 |---|---|---|---|---|---|---|---|
 

- *VERSION=6:*
  - But this field has a limited use because IPv4 and IPv6 packets are not distinguished based on the value in the version field but by the protocol type present in the layer 2 envelope
- *PACKET PRIORITY:* Assigning priorities to different packets
- *FLOW LABEL:*     Flow = srcIP + Flow Label
  - Used by source to mark packets belonging to same flow. Traffic that is not associated with any flow has flow label=0. Packets belonging to same flow should be treated same by IPv6 Routers
- *PAYLOAD LENGTH:* Length of data field. data=TCP+Appdata. So Max data can be 2<sup>16</sup> =  65535 bytes = 64Kilobytes.
  - When Application want to send packet > 64kilo. **Jumbo packet(Jumbogram)** is created. Now payload Length=0.  And new jumbo Payload extension header is provided
- *NEXT HEADER:* Transport Layer Header. TCP(6), UDP(17)
- *TTL/Hop Limit:*  This is decremented by 1 as each node sends the packet. If it reaches 0, packet is discarded. 28 =  256. So max nodes that can fall between 2 IPv6 nodes are 255
