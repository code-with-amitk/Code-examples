## Bootstraping
- **What?** Method by which new node enters into Distributed Downloading system(Eg: [Gnutella, Freenet, Bittorrent](/System-Design/Scalable/Distributed_Downloading_Systems)).
- **Types of Bootstraping Protocols**
  - *1. Opennet:* Connection between arbitary nodes is allowed
  - *2. Darknet:* Connection between arbitary nodes is not allowed. This is more secure wrt opennet but need laborios Manual Configuration.

### Darknet Protocol
- *1.* New node in the Freenet network gets its public-private key pair and location identifier for itself.
  - Data is secured using [Public-Pvt Assymetric Cryptography](https://sites.google.com/site/amitinterviewpreparation/networking/layer3/security), Integrity check is done using [Hashing](https://sites.google.com/site/amitinterviewpreparation/networking/layer3/security).
- *2.* [Announcement message](/System-Design/Scalable/Distributed_Downloading_Systems/Freenet/Message_Types) is sent in freenet network with TTL.
- *3.* The message is propagated by randomly selecting a destination in the current node’s routing table.
- *4.* TTL becomes 0. All nodes to which message have reached collectively assign a new location ID for the new node.
