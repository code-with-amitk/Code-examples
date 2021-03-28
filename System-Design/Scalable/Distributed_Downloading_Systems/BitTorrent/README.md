## Bit Torrent
- **What?**
  - [P2P(Peer to Peer)](/Networking/OSI-Layers/Layer5/P2P_OverlayNetwork/) file-sharing protocol downloading large amounts of data, designed by Bram Cohen in 2001.
  - According to some estimates, roughly 35% of all Internet traffic uses bittorrent.
- **[Terms](Terms.md)**: Torrent file, Tracker server
- **[Bit-torrent vs HTTP](Bittorrent_vs_http.md)**
- **[Advantages, Disadvantages of Bittorrent](Advantages_Disadv_of_Bittorrent.md)**
- **[Example of downloading a file](Example_of_download.md)**

### 5.2 Phases of Downloading a file
- **1. Bootstrap phase** Node has just received its first fragment/block. Node has recieved block using optimistic unchoking
  - *optimistic unchoking* unselfishly provide block(s) to node(s) in Neighbour set.
- **2. Trading Phase** Enough nodes can be paired to exchange data.  This is longest and most efficient phase.
- **3. Last download phase:** Node's NS potentially dropped to 0. Node dependents on newly arriving peers to get the last missing fragments/blocks.

## 6. Bottlenecks
### A. Tracker-server
  - Tracker server can come down when huge number of clients connect
  - **Solution** User machines/Participating nodes becoming Tracker-servers for small number of files in DHT(Distributed Hash Table) approach.
### B. [Free-Riding](/Scalable/Distributed_Downloading_Systems/README.md)
  - **Solution** Node will only send packet to that whose is in his Neighbour set(NS).
    - Example: User-1 requests swarm from Tracker server. Swarm=User-2,User-10. User-1 decides to connect user-2 for file. Now User-2 will only send file to user-1 when user-1 is in swarm downloaded from Tracker server. It means User-1 is also sending fragments.
### C. Slow Peer
  - **Solution-1** TCP Sliding window
  - **Solution-2** Choose peer from NS who has max upload speed.
