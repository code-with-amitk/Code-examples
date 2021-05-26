## Distributed Hash Table
- **How it works**
  - Each node maintains a pointer to its successor and predecessor node. Each node maintains Routing/Finger Table.
  - Message is forwarded to nearest node in routing table.
- **Search**
  - Any data object can be searched in O(log N) where N is the number of nodes in the system.

### DHT Implementations

|DHT Implementations|CAN|[Chord](Chord)|[Kademlia](Kademlia)|Koorde|[Pastry](Pastry)|Tapestry|Viceroy|
|---|---|---|---|---|---|---|---|
|Based on|Multi-dimensional space (dimensional torus)|Circular space(hypercube)|[XOR Metric](/Kademlia)|[De Bruijn graph](/DS_Questions/Data_Structures/Graphs/Terms/Directed_Undirected/Directed/De_Bruijn_Graph)|Plaxton-style mesh ([hypercube](/DS_Questions/Data_Structures/Graphs/Terms/Directed_Undirected/Hypercube))|Plaxton-style mesh (hypercube)|[Butterfly network](/DS_Questions/Data_Structures/Trees/BinaryTree/Types_Variants/Butterfly_Network)|
|Routing Function|Maps (key, value) pairs to coordinate space|Matching key and nodeID|Matching key and nodeID|Matching key and nodeID|Matching key and prefix in nodeID|Suffix matching|Routing using levels of tree,vicinity search|
|Routing Performance|O(dN)|O(logn)|O(logN)+small constant|Between O(log logN) & O(logn)|O(logn)|O(logn)|O(logn)|



