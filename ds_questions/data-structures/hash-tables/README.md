## Hash Table
DS search complexity = O(1){Average Case}. O(n){Worst case}

### Why Hash Tables?
For storing real world data structures. EG:
  1. Big Employees data:    Name, Ph Number, Residential address, Age, salary, designation etc
  2. Big Student Data:    Roll No, Name, class, subjects, age, address etc

### Hash Function
A hash function maps a big number or string to a small integer that can be used as index in hash table. 
```
  key -> |Hash Function| -> index of array/table
```

### Disadvantages of HT
  1. Guess Approximate input data? 
    - You have to know approximate size of input data before initializing hash table. Otherwise you need to resize hash table which is a very time-consuming operation. For example, your hash table size is 100 and then you want to               insert the 101st element. Not only the size of hash table is enlarged to 150, all element in hash table have to be rehashed. This insertion operation takes O(n).
  2. Elements are stored as unsorted order
    - In certain circumstance, we want data to be stored with sorted order, like contacts in cell phone.
  3. Hash Collision?   
    - It's possible that a hash function generates same hash value for different inputs. Now newly inserted key maps to an already occupied slot in hash table
