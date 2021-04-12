 ## Hash Collision 
  - When hash function provides same index or value for 2 different keys.

## Solutions to Hash Collision
### A. SEPERATE CHAINING 
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
### B. OPEN ADDRESSING
  - All elements are stored in HT itself. Once same hash is derived, insert element in hash table itself no seperate chains. Types of Open addressing
![ImgUrl](https://i.ibb.co/b7Qnkh2/oa.png)
#### B1. Linear/Sequential probing
  - **INSERTION**: Once same hash is derived, inserts the new item in the next open spot in the table ie next to already existent element with same hash.
  - If the table is not too full, the contiguous runs of items should be fairly small, hence this location should be only a few slots from its intended position
  - **DELETION** 
    - Ugly here removing one element might break a chain of insertions, making some elements inaccessible. 
    - We need to reinsert all the items into new holes.
  
#### B2. Quadratic Probing
