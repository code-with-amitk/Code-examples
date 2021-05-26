## Distributed Hash Table
- **How it works**
  - Each node maintains a pointer to its successor and predecessor node. Each node maintains Routing/Finger Table.
  - Message is forwarded to nearest node in routing table.
- **Search**
  - Any data object can be searched in O(log N) where N is the number of nodes in the system.

### DHT Implementations
- [Chord](Chord)

### Comparison

|DHT Implementations|CAN|Chord|Kademlia|Koorde|Pastry|Tapestry|Viceroy|
|---|---|---|---|---|---|---|---|
|Based on|Multi-dimensional space (dimensional torus)|Circular space(hypercube)|XOR Metric|De Bruijn graph|Plaxton-style mesh (hypercube)|Plaxton-style mesh (hypercube)|Butterfly network|
|Routing Function|Maps (key, value) pairs to coordinate space|Matching key and nodeID|Matching key and nodeID|Matching key and nodeID|Matching key and prefix in nodeID|Suffix matching|Routing using levels of tree,vicinity search|



