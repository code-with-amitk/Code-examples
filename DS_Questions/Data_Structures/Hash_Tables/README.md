**Hash Table**
- [Advantages, Disadvantages](#adv)
- [HT vs Self Balanced BT](#vs)
- [How Hash Table is implemented internally](#int)
- **Hash Collision**
  - [Solution-1. Seperate Chaining](#sc)
  - [Solution-2. Open Addressing](#oa)
- [Rehashing](#re)
- [Implementations of Hash Tables](Implementations)

## Hash Table
- Data structure that associates keys with values. `<key, value>`, Supports constant time lookups. Average Case: O(1), Worst case: O(n)
- *Hash Function?* Hash function maps a big number or string to a small integer that can be used as index in hash table.
```c
key -> |Hash Function| -> index of array/table
```
**Hashing is improvement over Direct Access Table**
- Take huge array and use phone numbers as index in the array. if phone number is not present entry is empty, else the array entry stores pointer to records corresponding to phone number. Searching in DA: O(1) but HUGE Extra Space required.

<a name=adv></a>
### Advantages, Disadvantages
#### Advantage
Search in O(1) time.

#### Disadvantages
- **a. Guess Approximate input data:** We have to know approximate size of input data before initializing hash table. Once all HT entries are filled it needs resized/rehashing which is a time-consuming operation. Eg:
  - Let HT size = 100, we want to  insert 101st element. Not only the size of hash table is enlarged to 150, all element in hash table have to be rehashed. This insertion operation takes O(n).
- **b. Elements are stored as unsorted order:** Some circumstance data should stored in sorted order. Eg: contacts in cell phone.
- **c. Hash Collision:** When hash function provides same index/value for 2 different keys.
```c
  key -> |Hash Function| -> index of array/table
```

<a name=vs></a>
## HT vs Self Balanced BT
```c
                                                         Hash-Tables            |        Self-Balancing BT
---------------------------------|----------------------------------------------|----------------------------------
Complexity(Insert/Delete/Search) | O(1)[Average Time], O(n) during table resize | O(log n)[guaranteed all times].
Collision                        | Yes                                          | never
Implementation                   | Tough, We depend on libraries                | Easy, we can implement our own customized BST
ADVANTAGES of Tree over HT       |                                              | 1. Data can be retrieved in sorted order. inorder-traversal: O(n)
                                                                                | 2. lowest, biggest element finding: easy
                                                                                | 3. No need to guess size of input data.
```

<a name=int></a>
### How Hash Table is implemented internally
> LH* Network

Files are organized into buckets(Size is power of 2) stored either on RAM/disk/distributed servers. Hash function generates the bucket number which stores the key.
- **Example:**
  - Lets consider student data to be stored in hash table.
  - Each student data is stored in seperate file and File pointers are stored in Buckets (Similar to [Inode](/Operating_Systems/Linux/FileSystem/I_Node_IndexNode.md))
  - Hash Function generates bucket number as output with enrollment number(key) as input.
  - **Split Coordinator**
    - Once buckets on server gets full, splitting is done using SC. Making buckets/keys to half.
    - SC also supports the merging of buckets.
    - SC can be seen as [Super-Peer](/System-Design/Concepts/Terms) in P2P terminology.
  - *Dsiadvantage?* 
    - Clients maintain views to the global system state, ie overall bucket information.
```html
  | Name | Roll-No | Class | Sub-1 | Sub-2 | Sub-3 | .. | Enrollment No(Unique Key) |
  | Amit |   5     | 10    | Math  | Sci   | Eng   |    | 12345                     | <- File-1
  | Ram  |   35    | 10    | Math  | Sci   | Eng   |    | 23241                     | <- File-2
  
  file1		file2		file3		file4
  0x40		0xac		0x45		0x34		//Files stored at different addresses
  
  |file1 file2 file3 file4|		|...|
  |0x40  0xac  0x45  0x34 |		|...|
  Bucket-1. Size=4			Bucket-2. Size=8

  server1		server2			server3
 bucket-1,2		Bucket-3,4,5		Bucket-6,7,10


Enrollment-Number(Key)  -> hash_function ->  Bucket-3
```

## Hash Collision
When hash function provides same index or value for 2 different keys.
<a name=sc1></a>
### Solution-1: Seperate Chaining
Each cell of HT point to a **DOUBLY LINKED LIST** of records that have same hash function value. This requires additional memory outside the table.
- _Complexities:_ 
  - Insert(x): O(1). Insert at head of LL
  - Search(x): O(n). Need to search complete list
  - Delete(x): O(1). Assumed we are at element in chain, we delete x. copy prev to next pointer. In singly LL we need O(n) time to search prev node.
- _Advantages:_ Simple implementation, Space will never exhaust, Less sensitive to hash function
- _Disadvantages:_
  - Once LL/chain grows long, performance will degrade search time=O(n)
  - Space wastage, some parts of hash table may never be used
  - Devotes huge amount of memory to pointers. This is space that could be used to make the table larger
- **Load Factor α = n/m** where m=slots, n=elements
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
<a name=oa></a>
### Solution-2: Open Addressing  
All elements are stored in HT itself. Once same hash is derived, insert element in hash table itself no seperate chains.

![ImgUrl](https://i.ibb.co/b7Qnkh2/oa.png)

#### Types of Open addressing
**1. Linear/Sequential probing**
- *INSERTION*: Once same hash is derived, inserts the new item in the next open spot in the table ie next to already existent element with same hash. If the table is not too full, the contiguous runs of items should be fairly small, hence this location should be only a few slots from its intended position
- *DELETION:* Ugly here removing one element might break a chain of insertions, making some elements inaccessible. We need to reinsert all the items into new holes.
  
**2. Quadratic Probing**
look for i<sup>2</sup>th slot in i'th iteration. New hash function = (xmod7 + i2)%hash_table_size
```c
  h0 = (xmod7 + 0*0)%hash_table_size
  h1 = (xmod7 + 1*1)%hash_table_size
  h1 = (xmod7 + 2*2)%hash_table_size
  Example: Hash Function = xmod11  a[]=7,36,18,62.   7mod11=7,  36mod11=3,  18mod11=7,  62mod11=7
    Insert: Collision at insertion of 18. Since collision had occurred, we calculate h1 = (18mod11 + 1*1 = 8)
    Collision at insertion of 62. Since collision had occurred, we calculate h1 = (18mod11 + 1*1 = 8) which is occupied.  We calculate h2= (62mod11+ 2*2 = 11). This goes to index 0. And we insert.
    |   62   |        |        |   36  |        |        |        |    7     |   18     |        |        |
        0        1       2       3        4          5       6         7          8        9        10
```

**3. DOUBLE HASHING:** We use double hash function to re-calculate the hash if collision occurs.  In case of collision: hash1(x) = (hash1(x) + i*hash2(x))%hash_table_size

**Comparison**
```
                          Advantages                                     Disadvantages
Linear Probing      Easy to implement, best cache performance        Suffers from clustering
Quadratic Probing   Avg cache performance                            Small clustering occurs
Double hashing      worst cache performance                          No clustering occurs, More computation time is required.
```

<a name=re></a>
## Rehashing
Let's consider `unordered_map<int,string>` storing unique keys. At start of program sizeof hash table=3
```c
  Key | Value
  ----------
  01  | amit
  02  | never
  03  | give
```
- Now, (4, up) need to be stored, but hash table has no space so size of hash table is increased to 6. 
- (old Hash function = %3) we can only goto index number=2. But we want to reach 5. Hence Hash function is changed (old Hash function = %6). So hash is again calculated for existing values.
