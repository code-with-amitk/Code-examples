## Kademlia
- This is based on [XOR geometry](XOR_Geometry).
- Distance between two nodes d(a,b) = (20Byte_Identifier_of_a ⊕ 20Byte_Identifier_of_b)    //⊕ is XOR

### Joining the Network
- Nodes joins using [Bootstrap process](/System-Design/Concepts/Terms).
- Initiating node maintains a **shortlist of k closest nodes**.
  - Closer nodes replace more distant nodes in the shortlist.

### Routing
- Routing table contains logn neighbours.
- In case of failure to reach node in routing table, with only bit shifting, XOR geometry can quickly find next node to reach.
- In Kademlia, a node’s neighbors are called contacts. Contacts are stored in buckets. Each bucket can hold max k contacts.
- Routing table is a binary tree in which each node in the tree is a k-bucket. Every k bucket corresponds to a specific distance from the node.
