## Chord
- Each real node comprises of v virtual nodes(ie virtual machines). Analysis will be for 1 of Virtual machine.
- Each node maintains the finger/routing table to reach nodes further away in the ring in clockwise direction.
- Nodes are arranged in circular ring. Node stores keys between its predecessor and itself.

<img src=chord-dht.JPG width=500/>

### Node joining Chord
- k keys, N nodes. Each node should hold k/N keys.
- When node n joins the network, some keys assigned to n’s successor will be moved to n. 
- 
### Leaving the Chord
- When node leaves the network, all keys assigned to node are reassigned to its successor.
- Leaving node informs its successor & predecessor that it is leaving, allowing the system to reconfigure.

### Finding node in chord
- In N-node network, number of nodes that must be contacted to find a successor: O(log N)
