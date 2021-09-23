 **KEY VALUE DB**
  - [1. sled](#sl)

## Key Value DB
<a name=sl></a>
### Sled (written in rust)
- values can be searched based on keys.
- All operations are atomic and done with 1 key at a time single-key operations, including compare and swap operation.
- It uses lock-free data structures to improve scalability and organizes storage on disk in a log-structured way optimized for SSDs.
