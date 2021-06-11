## Compressed Bloom Filter
- **What?** 
  - CBF is useful when passing messages between distributed nodes.
  - _Applications using CBF:_ web caches, P2P information sharing.
- **How Implemented?**
  - Pattern of storing bits in filter is compressed for transmission purposes.
  - After transmission, the filter is decompressed for use
  -  CBF uses some additional compression algorithm for transmitting data over the network, for example, arithmetic coding.
