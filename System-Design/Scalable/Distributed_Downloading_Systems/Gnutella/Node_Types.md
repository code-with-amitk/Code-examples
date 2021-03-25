## Gnutella nodes
- Every node is either Leaf or Ultra node.
- Each node maintains QRT(Query routing table). Ultra nodes exchanges these QRTs with other ultra nodes.
  - **QRT?**
    - Hash of filename or keyword is maintained by each node(leaf of ultra) in QRT.
    - These hashes are submitted by leaf nodes to ultra node and ultra node creates a consolidated QRT after receiving from all leaf nodes.
    - Ultra nodes exchanges QRT amongst themseleves.
```c
  FileName or Keyword    Hash
  file1                   aaa
  file2                   bbb
```

### 1. Ultra node
  - Can be connected to max 3 leaf nodes and max 32 ultra nodes.
  - If node joins newly to network(and has good processing power) its joined as Ultra node.

### 2. Leaf Nodes
  - Child nodes of ultra nodes, always communicate over network using Ultar nodes.

### 3. Push Proxies
  - Historically Gnutella used same route for queries and push messages but this is not efficient as paths may change.
  - Push Proxies are announced in [QueryHit messages](Message_Types.md), this is ultra node of leaf node having data.
  - Now push proxies sends [Push Messages](Node_Types.md) on behalf of leaf nodes, since ultra nodes are considered more reliable wrt leaf nodes.
