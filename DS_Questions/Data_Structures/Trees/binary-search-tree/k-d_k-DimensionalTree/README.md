- [What is k-d Tree](#what)
- Variants
  - [2-d Tree](2d)
    - [1. Creating 2-d Tree](#create)

<a name=what></a>
## K-d Tree / k-Dimensional Tree
- This is binary search tree where data in each node is a K-Dimensional point in space. This is a space partitioning data structure for organizing points in a K-Dimensional space.
- A non-leaf node in K-D tree divides the space into two parts, called as half-spaces.

## Variants
<a name=2d></a>
### 2-d Tree
- For sake of simplicity let's understand 2-d tree. Every node contains 2 values.

<a name=create></a>
#### 1. Create
- Consider following points in a 2-D plane to be inserted into k-d tree:
> (3, 6), (17, 15), (13, 15), (6, 12), (9, 1), (2, 7), (10, 19)
- On level 0,2,4 x corrdinate is compared. On levels 1,3,5 y corrdinate is compared.
- _1._ Since tree is empty insert (3,6) at root
- _2._ (17,15). 17>3 goto right and insert.
- _3._ (13,15). 13>3,go right. 15=15, go right.
- _4._ (6,12). 6>3,go right. 15>12,go left.
- _5._ (9,1). 9>3,go right. 15>1,go left. 9>6,go right
- _6._ (2,7). 3>2,go left
- _7._ (10,19). 10>3,go right. 19>15,go right. 13>10,go left.
```c
      [3,6]                     ........X       //1
      /   \
   [2,7]  [17,15]               ........Y       //2,6
            /   \
        [6,12]  [13,15]         ........X       //3,4
         \         /
         [9,1]  [10,19]         ........Y       //5,7
```
