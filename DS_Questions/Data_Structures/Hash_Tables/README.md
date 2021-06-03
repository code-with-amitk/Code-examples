## Hash Table
- **What?** Data structure that associates keys with values. `<key, value>`, Supports constant time lookups ie Search complexity:
```c
  Average Case: O(1)
  Worst case: O(n)
```
- _[Advantages Disadv of HashTables](Advantages_Disadv_of_HashTables.md)_
- *Hash Function?* Hash function maps a big number or string to a small integer that can be used as index in hash table.
- *[How Hash Table is implemented Internally](How_HashTable_Implemented_Internally)*
```c
  key -> |Hash Function| -> index of array/table
```
- _[Hash Collision and Solutions](Hash_Collision_And_Solutions.md)_
- *[Rehashing](ReHashing.md)*
- **[Implementations of Hash Tables?](Implementations)** 
  - [2-way/2-choice/2-left Hash Table](2-left_2-Choice_HashTable)
