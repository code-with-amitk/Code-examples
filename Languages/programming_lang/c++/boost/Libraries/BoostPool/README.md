## Boost.Pool
- **What**
  - classes to manage memory.
  - Boost.Pool works on concept called **simple segregated storage**.
    - Boost.pool partitions memory segments with the same size.
    - Every time you request memory from Boost.Pool, the library accesses the next free segment and assigns memory from that segment.
    - The entire segment is then marked as used, no matter how many bytes you actually need from that segment.
    - All classes of Boost.Pool are based on class boost::simple_segregated_storage.
- **Why**
  - With boost.pool we can accelerate memory management to provide memory to program faster.
