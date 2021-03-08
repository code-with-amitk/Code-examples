## IPv4 Characteristics
- **1. Connectionless:** No state related to IP datagrams is maintained either on source or destination side. Advantages:
  - network layer is much simpler.
  - Transport layer already provides connection-oriented, should not repeat the work.
  - Routers could become overloaded managing too many connections.
- **2. Unreliable:** It not guaranteed that an IP data gram will get delivered to the destination or not. If IP packet gets any error in Transit, at source or destination, its discarded and ICMP message is sent back.
