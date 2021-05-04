## Seperate Chaining
  - Each cell of HT point to a linked list of records that have same hash function value. This requires additional memory outside the table.
  - **Advantages:** Simple implementation, Space will never exhaust, Less sensitive to hash function
  - **Disadvantages:**
    - Once LL/chain grows long, performance will degrade search time=O(n)
    - Space wastage, some parts of hash table may never be used
    - Devotes huge amount of memory to pointers. This is space that could be used to make the table larger
![ImgUrl](https://i.ibb.co/XWZfxwX/chain.png)        
```c
  Example:  Hash Function = xmod7, a[]={50, 700, 76, 85, 46, 92, 73, 10}        
  50mod7=1, 700mod7=0,  76mod7=6,  85mod7=1,    46mod7=1
                     46
                     |
                    85
                     |
        |  700  |   50     |        |        |        |        |    76    |        Hash Table
             0         1          2      3       4        5       6
```
