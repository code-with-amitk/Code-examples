## Advantages
  - Search in O(1) time.
## Disadvantages of HT
  - *a. Guess Approximate input data* 
    - You have to know approximate size of input data before initializing hash table. Otherwise you need to resize hash table which is a very time-consuming operation. For example, your hash table size is 100 and then you want to  insert the 101st element. Not only the size of hash table is enlarged to 150, all element in hash table have to be rehashed. This insertion operation takes O(n).
  - *b. Elements are stored as unsorted order* 
    - In certain circumstance, we want data to be stored with sorted order, like contacts in cell phone.
  - *c. Hash Collision* 
    - It's possible that a hash function generates same hash value for different inputs. Now newly inserted key maps to an already occupied slot in hash table
