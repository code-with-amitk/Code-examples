- **Gnutella?** 
  - Distributes both the search and download capabilities amongst peers.

## HLD
- **Part-1(Search):** Locate the peers that have desired data items.
  - QUERY message is sent(with TTL)
  - When peer recieves the query(fileId), it checks its own database for particular, if cannot find forwards to next node.
  - QUERYHit message is sent back when file is found.
- **Part-2(Download):** Transfer actual file from the peer using HTTP.
