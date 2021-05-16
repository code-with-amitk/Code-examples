## Kademlia
- This is based on [XOR geometry](XOR_Geometry).

### Joining the Network
- Nodes joins using [Bootstrap process](/System-Design/Concepts/Terms).
- Initiating node maintains a **shortlist of k closest nodes**.
  - Closer nodes replace more distant nodes in the shortlist.

### Routing
- In Kademlia, a node’s neighbors are called contacts.
- Contacts are stored in buckets. Each bucket can hold max k contacts.
- Routing table is a binary tree in which each node in the tree is a k-bucket. Every k bucket corresponds to a specific distance from the node.
