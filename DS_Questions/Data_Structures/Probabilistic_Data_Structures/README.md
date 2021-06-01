## Probabilistic Data Structures / PDS
- **Why?** 
  - In data structures we want to search a particular or min element. 
  - When data set is small then using _Deterministic data structures(Eg: Hashtable, minHeap)_ solves the purpose somehow.
  - But when _data set becomes Huge and unmanagable(BIG DATA)_, Deterministic DS cannot be used because DATA WILL NOT FIT IN MEMORY.
    - Eg: Streaming applications which need data to be processed in one pass and perform incremental updates.
- **How it works?** 
  - PDS also use hash table to generate hash & store in hash table. 
  - But hash Collisions are ignored, errors are controlled under certain threshold. 
  - wrt _Deterministic data structures(Error free)_ PDS use much less memory and have constant query time. 
  - PDS support union and intersection operations and therefore can be easily parallelized.

### Commonly Used PDS
  - _[1. Bloom Filter](Bloom_Filter)_
