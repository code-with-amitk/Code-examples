## 1. SELECTIVE ACK(SACK)
- Used By client to inform server that particular packet(segment) is lost.
- **Flow**
  - Client sends Request to server 
  - Server sends Segment1. Client sends ACK1
  - Server sends   Segments 2, 3, 4. Where Segment2 gets missed in n/w.
  - Client sends ACK1, TCP SACK Option(3-4) saying. I have received Segments from 3-4.           
  - Server receives Duplicate ACK1. Realizes Segment2 is missed. Server watches SACK TCP Option saying it has received 3-4.
  - Server sends Segment-2 again. Client acknowledges.

<img src=TCP_SACK.png width=400 />

