- **Gnutella?** 
  - Distributes both the search and download capabilities amongst peers.

## HLD
- **[Gnutella Nodes:](Node_Types.md)** Leaf, Ultra Nodes, Push Proxies
<img src=Gnutella.jpg width=700 />

- **How Gnutella works?**
  - **Part-1(Search):** Locate the peers that have desired data items.
    - QUERY message is sent(with TTL)
    - When peer recieves the query(fileId), it checks its own database for particular, if cannot find forwards to next node.
    - QUERYHit message is sent back when file is found.
  - **Part-2(Download):** Transfer actual file from the peer using HTTP over UDP. [Advantages of HTTP over UDP](/Networking/OSI-Layers/Layer-4/Protocols/Google_QUIC/FeaturesCharacteristics_Improvements_Over_TCP).
- **[Message Types](Message_Types.md)**
- **[Problems in Gnutella](Problems_with_Gnutella.md)**

