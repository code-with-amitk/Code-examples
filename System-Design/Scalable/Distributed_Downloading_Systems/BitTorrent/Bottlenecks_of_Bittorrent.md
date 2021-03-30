## Bottlenecks
- **1. [Tracker-server](Terms.md) can become bottleneck:** Tracker server can come down when huge number of clients connect
  - *Solution* Using DHT(Distributed Hash Table) approach.
- **2. [Free-Riding](/Scalable/Distributed_Downloading_Systems/README.md)
  - **Solution** Node will only send packet to that whose is in his Neighbour set(NS).
    - Example: User-1 requests swarm from Tracker server. Swarm=User-2,User-10. User-1 decides to connect user-2 for file. Now User-2 will only send file to user-1 when user-1 is in swarm downloaded from Tracker server. It means User-1 is also sending fragments.
### C. Slow Peer
  - **Solution-1** TCP Sliding window
  - **Solution-2** Choose peer from NS who has max upload speed.
