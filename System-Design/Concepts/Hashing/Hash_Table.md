## Hash Table
- **What**
  - Data Structure which provides search complexity = O(1){Average Case}. O(n){Worst case}. Hashing is an improvement over Direct Access Table. 
  - It uses hash function that converts key(eg:phone number) to a smaller number and uses the small number as index in a table called hash table.        
```c
key -> |Hash Function| -> index of array/table
```
- **Applications:** a. storing Huge data and searching key in O(1) time. Eg: Company employees data: Name, Ph Number, Residential address, Age, salary, designation etc
- **Hash Function?** Maps a big number/string to a small integer that can be used as index in hash table. Values returned by a hash function are called hashes. Irrespective of how good a hash function is, collisions are bound to occur. Therefore, to maintain the performance of a hash table, it is important to manage collisions through various collision resolution techniques.
-  **Disadvantages of HT?**
  - *a.* Guess Approximate input data? Its good to know approximate size of input data before initializing hash table. Else OS need to resize hash table which is a very time-consuming operation. For example, your hash table size is 100 and then you want to               insert the 101st element. Not only the size of hash table is enlarged to 150, all element in hash table have to be rehashed. This insertion operation takes O(n).
  - *b.* Elements are stored as unsorted? In certain circumstance, we want data to be stored with sorted order, like contacts in cell phone.
  - *c.* Hash Collision? It's possible that a hash function generates same hash value for different inputs. Now newly inserted key maps to an already occupied slot in hash table.  
