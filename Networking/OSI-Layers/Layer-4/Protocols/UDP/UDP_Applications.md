## UDP Applications / Use Cases
- *1. Time sensitive Applications:* Dropping is acceptable but not delay.
- *2. Good choice for Sending Audio/Video over internet*
  - Less Delay(No ACKs)
  - No retransmissions (for lost packets)
  - No Connection Setup (Handshakes)
  - Exceptions with tftp: tftp sends binary applications, in which 1 byte missed is total loss. Then how it runs over UDP. It implements Reliable DGRAM (For each sent Pkt, receiver has to send ACK back, if sender does not recieve ACK, He sends pkt again in time t). Unreliable DGRAM (For Audio, Video conferencing) you ignore dropped packets.
