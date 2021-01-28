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
  - *a.* Guess Approximate input data? OS creates hash table of size=X, when X+1st element need to be placed, then size of hash table needed to be increased. All element in hash table have to be rehashed. This insertion operation takes O(n).
  - *b.* Elements are stored as unsorted? In certain circumstance, we want data to be stored with sorted order, like contacts in cell phone.
  - *c.* Hash Collision? It's possible that a hash function generates same hash value for different inputs. Now newly inserted key maps to an already occupied slot in hash table.  

### Rehashing
- Let's consider `unordered_map<int,string>`(ie storing unique keys). 
- At start of program a hash table of size=X(let's say 3) is created     `key -> |Hash Function| -> index/hash`
```c
        key > |Hash function = %3| > index.    0 > |%3| > 0.    1 > |%3| > 1.     2 > |%3| > 2
        
//Hash Table size=3
    key   Value
    0     amit
    1     never
    2     up
```
- Now, 4th element need to be stored (key=5, value=up). When X+1st element need to be placed, then size of hash table needed to be increased, else separate chaining will happen for unordered_multimap(allows duplicate keys) else prev value would be overwritten.
- Size is doubled. size=6. With (old Hash function = %3) we can only goto index number=2. But we want to reach 5. Hence Hash function is changed (old Hash function = %6). So hash is again calculated for existing values.
