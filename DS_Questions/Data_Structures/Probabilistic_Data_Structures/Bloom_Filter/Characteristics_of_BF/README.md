## Characteristics of Bloom Filter
- [False positive](..) is possible when the queried positions are already set to 1. But false negative is impossible.
- Query time is O(k).
- Union and intersection of bloom filters with same size and hash functions can be implemented with bitwise OR and AND operations.
- Cannot remove an element from the set.
