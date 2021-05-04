## Hash Table
  - **What** 
    - Data structure that associates keys with values. `<key, value>` 
    - Supports constant time lookups ie Search complexity:
      - Average Case: O(1)
      - Worst case: O(n)
  - [Advantages Disadv of HashTables](Advantages_Disadv_of_HashTables.md)
  - *Hash Function?* Hash function maps a big number or string to a small integer that can be used as index in hash table.
  - *[How Hash Table is implemented Internally](How_HashTable_Implemented_Internally)*
```c
  key -> |Hash Function| -> index of array/table
```
  - [Hash Collision and Solutions](Hash_Collision_And_Solutions.md)
  - **[Rehashing](ReHashing.md)**
