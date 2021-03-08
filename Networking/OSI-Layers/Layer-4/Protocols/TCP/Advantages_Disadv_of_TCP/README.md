## Disadvantages
- *1.* Transport semantics are not application specific and finally application has to bear burden of solving them. Examples:
  - Application-1 want to send message with unlimited boundaries.
  - Application-2 want to send message with preserved boundaries.
  - Application-3 want better control over network path. May be error recovery per 10 hopes etc.
- *2.* Congestion Control is based on packet losses as a signal of congestion. More packets getting lost we need congestion control.
  - This maybe a not good Congestion signal and can be replaced by anything else. Eg:
    - Packet Transmission error rate
  - Since networks are getting faster and faster, Developers are revisting Congestion control.
- *3.* Slow Start
  - During [TCP-3-way handshake](../State_Transition_Diagram) window size exchanged is relatively small, cannot be Max.
  - In [Flow control(Sliding Window)](../Characteristics/Flow_and_Congestion_Control/TCP_Flow_Control/Sliding_Window) window size shrinks to smallest.
  - This can be especially disadvantageous when downloading larger streams of data. 
    - GOOGLE PROPOSED SOLUTION: [QUIC](../../Google_QUIC)
- **4. Image, Stream Blockings / Head of Line Blocking Issue**
  - Consider webpage has 2 images, image-1 is lost while image-2 is recieved. TCP will try getting image-1 and block. 
  - Similar problem will be seen when streaming video using TCP. Once the Segment is lost, the TCP will try retrieving even if other Segments of the video are watchable.
- *5.* 3 Way Handshake can take large time on large latency devices, low BW Network. Eg:
  - Web server connecting to slow mobile device.
    - Solution: [QUIC](../../Google_QUIC)
- *6.* TCP may not work faster in LAN, its designed for WAN.
- *7.* Cannot distinguish between Packet lost and retransmission in wireless network.
  - In wireless network packet losses are there(more wrt to wired).

## [Advantages](../Characteristics)
- Same as characeristics
