## Bottlenecks
- **1. [Tracker-server](Terms.md) can become bottleneck:** Tracker server can come down when huge number of clients connect
  - *Solution* Using DHT(Distributed Hash Table) approach.
- **2. [Free-Riding](/System-Design/Concepts/Terms/README.md)**
- **3. Slow Peer**
  - *Solution-1* TCP Sliding window
  - *Solution-2* Choose peer from NS who has max upload speed.
