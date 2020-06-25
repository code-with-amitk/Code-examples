## Hash Table
  - **What** This is very efficient in searching. Search complexity = O(1){Average Case}. O(n){Worst case}
  - **Advantages**
    - Efficient search in O(1) time.
  - **Disadvantages of HT**
    - ***a. Guess Approximate input data*** You have to know approximate size of input data before initializing hash table. Otherwise you need to resize hash table which is a very time-consuming operation. For example, your hash table size is 100 and then you want to  insert the 101st element. Not only the size of hash table is enlarged to 150, all element in hash table have to be rehashed. This insertion operation takes O(n).
    - ***b. Elements are stored as unsorted order*** In certain circumstance, we want data to be stored with sorted order, like contacts in cell phone.
    - ***c. Hash Collision*** It's possible that a hash function generates same hash value for different inputs. Now newly inserted key maps to an already occupied slot in hash table
  - **Why Hash Tables?**  For storing real world data structures. EG:
    1. Big Employees data:    Name, Ph Number, Residential address, Age, salary, designation etc
    2. Big Student Data:    Roll No, Name, class, subjects, age, address etc
    
### A. Hash Function 
  - Hash function maps a big number or string to a small integer that can be used as index in hash table. 
```
  key -> |Hash Function| -> index of array/table
```

#### A1. Hash Collision
  - When hash function provides same index or value for 2 different keys. Solutions to Hash Collision:

##### (i) SEPERATE CHAINING 
  - Each cell of HT point to a linked list of records that have same hash function value. This requires additional memory outside the table.
  - ***Advantages:*** Simple implementation, Space will never exhaust, Less sensitive to hash function
  - ***Disadvantages:***
    - Once LL/chain grows long, performance will degrade search time=O(n)
    - Space wastage, some parts of hash table may never be used
    - Devotes huge amount of memory to pointers. This is space that could be used to make the table larger
![ImgUrl](https://i.ibb.co/XWZfxwX/chain.png)        
```
  Example:  Hash Function = xmod7, a[]={50, 700, 76, 85, 46, 92, 73, 10}        
  50mod7=1, 700mod7=0,  76mod7=6,  85mod7=1,    46mod7=1
                     46
                     |
                    85
                     |
        |  700  |   50     |        |        |        |        |    76    |        Hash Table
             0         1          2      3       4        5       6
```
##### (ii) OPEN ADDRESSING
  - All elements are stored in HT itself. Once same hash is derived, insert element in hash table itself no seperate chains. Types of Open addressing
###### a. Linear/Sequential probing
  - `INSERTION`: Once same hash is derived, inserts the new item in the next open spot in the table ie next to already existent element with same hash.
  - If the table is not too full, the contiguous runs of items should be fairly small, hence this location should be only a few slots from its intended position
  - `DELETION`: Ugly here removing one element might break a chain of insertions, making some elements inaccessible. We need to reinsert all the items in the run following the new hole.
  
###### b. Quadratic Probing
![ImgUrl](https://i.ibb.co/b7Qnkh2/oa.png)

