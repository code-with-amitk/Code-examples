**Binary Lifting for Finding kth Ansector**
- [Approach-1, Linear, O(n)](#a1)
- **Approach-2, Binary Lifting, O(logn)**
  - [Idea](#i)

## Finding kth Ansector of Node in Binary Tree
**Problem?** Find kth(k=6) ansector of node=10. Answer=0
```c
          0   <6th
         / 
        1     <5th
         \
          4   <4th
         /
        7     <3rd
         \
          8    <2nd
           \ 
            9  <1st
             \
              10
```
<a name=a1></a>
### Approach-1 / Linear / O(n)
To find nth ansector of node, Traverse from node n times up.

### Approach-2 / Binary Lifting / log(n)
<a name=i></a>
#### Idea
> (1,2,4,8,16,32,64,128.. These are Power of 2)
- _1._ Precompute/Precreate a dp-table which stores nodes present at power of 2 from last node in tree.
```c
dp-Table of 10
Place   Node
1       9         //At 1st place from 10, 9 is present
2       8         //At 2nd, 8
4       4         //At 4th, 4
```
- _2._ For k=6. Perform 2 Jumps, Since 6=4+2. Hence only in 2 steps we can find kth ansector
```c
Jump=1. Place=4. Node=4
Jump=2. From 4 to 2 places. Node=0
```
