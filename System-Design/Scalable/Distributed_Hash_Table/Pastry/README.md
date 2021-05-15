## Pastry
- This is self-organizing, structured peer-to-peer overlay network.
- NodeIds are 128 bit long.
- Pastry is build on Consistent Hashing & Plaxton's Algorithm.

### How it works
- Pastry routes a message to the node with the nodeId that is numerically closest to the given key. This node is called the key’s root.

### Joining a new node
- Joining node informs other nodes that it has joined.
- Nodes near to joined node send their routing tables to joined node.
- A Pastry node fails when its immediate neighbors cannot communicate with it.
