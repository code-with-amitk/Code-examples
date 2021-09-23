 **KEY VALUE DB**
  - [1. sled](#sl)

## Key Value DB
<a name=sl></a>
### Sled (written in rust)
- This is persistant DB. Values can be searched based on keys. Internally implemented as [BTree](https://www.geeksforgeeks.org/introduction-of-b-tree-2/).
- All operations are atomic and done with 1 key at a time single-key operations, including compare and swap operation.
- It uses lock-free data structures to improve scalability and organizes storage on disk in a log-structured way optimized for SSDs.
