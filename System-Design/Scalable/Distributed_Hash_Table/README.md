## Distributed Hash Table
- **How it works**
  - Each node maintains a pointer to its successor and predecessor node. Each node maintains Routing/Finger Table.
  - Message is forwarded to nearest node in routing table.
- **Search**
  - Any data object can be searched in O(log N) where N is the number of nodes in the system.

### DHT Implementations
- [Chord](Chord)
