**Binary Tree**
- [Types of BT](#ty)
  - [1. Full BT](#f)
  - [2. Complete BT](#c)
  - [3. Perfact BT](#p)
  - [4. Balanced BT](#b)
  - [5. Degenerated or Pathological BT](#d)
  - [6. Rope / Cord](#r)


## Binary Tree
Each node cannot have more than 2 children. Height = log2n for n number of nodes. Eg: Butterfly Network
```c
        1
       /  \
      2    3
```

## Types of BT
<a name=f></a>
#### 1. Full / Proper BT / 2-Tree
Every node have 0 or 2 children. No node have 1 child
```c
        a
       /  \
     b      c
    /  \
  d     e
```
<a name=c></a>
#### 2. Complete BT
All levels are completely filled except last.
```c
            a                        a [Not CT]
           /   \                    /
         b      c                  b
      /    \    /                 /
     d     e    f                c
```
<a name=p></a>
#### 3. Perfect Tree
A full & complete BT. All leaves at same level.
```c
        a(Perfect)         a(not perfect)
      /    \              /\
    b       c            b  c
  /  \     /  \         /\  /
```
<a name=b></a>
#### 4. Balanced BT
- A binary tree is said to be ‘balanced’ if the tree height is O(logN), where ‘N’ is the number of nodes.
- In a balanced binary tree, the height of the left and the right subtrees of each node should vary by at most one. An AVL Tree and a Red-Black Tree
<a name=d></a>
#### 5. Degenerate / Pathological BT
Every internal node has only a single child. Such trees are similar to a linked list performance-wise.
```c
                a
               /
              b
             /
            c
             \
               d
```
<a name=r></a>
#### 6. Rope / Cord
```c
BT where:
non-leaf node holds   : sum of lengths of all leaves in left subtree
leaf node holds       : string+length(also called weight)

Storing: "Hello_my_name_is_Amit"
H e l l o _ m y _ n a m e _ i s _ A m i t
0 1 2 3 4 5 6 7 8 9 1011121314151617181920

                        21
                      /    
                    9
               /         \
              6             6
            /   \        /      \
     Hello_,6  my_,3    2          1
                      /   \      /    \
                  na,2  me_i,4  s,1   _Amit,5 
```
- **Advatanges**
  - _1._ Used for efficient storage and manipulation a very long string.
  - _2._ Unlike arrays, ropes do not require large contiguous memory allocations. 
  - _3. Time Complexity (for insertion/deletion/searching)_ is O(logn) unlike strings which is O(n). Hence its VERY IMPORTANT TO LEARN.
- **Disadvatanges**
  - _1._ Complex code
  - _2._ Extra memory required to store parent nodes.
  - _3._ Time to access ith character increases. In plain strings its O(1).
