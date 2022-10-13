**Priority Queue/HEAP/Binary heap**
- Types
  - [Max Heap](#mh)
  - [Min Heap](#mih)

## Priority Queue/HEAP/Binary heap (Balanced Complete BT)
- Each element is given a priority. Higher priority element is processed before any lower priority element. 
- Duplicates are allowed. This is suited to be stored in array ie Heap can be implemented using arrays. If you use arrays to implement Heaps then you don't need to store pointer as done in trees and its space advantage
- **Complexities**
  - Insert: O(logn)
  - Search: O(1)
  - Delete: O(logn)
  
### Types of Heap
<a name=mh></a>
#### A. Max Heap `(priority_queue<int>)`
- Root is always greatest. `parent >= child`
- 2nd, 3rd largest element are direct children of root(either left or right).
- **Creation**
  - Traverse array and create Level-Order tree. 
  - Heapify only non-leaf nodes. Indexes of non-leaf nodes = (N/2 - 1)
    - Heapfiy a node means, exchange node with either left or right child who is greatest.
```c
  a[] = {1, 3, 5, 4, 6, 13}.

     1          1             5             5             13
    / \        / \           /  \          /  \          / \
   3   5      6   5         6    1   =>   6    13  =>   6    5
  / \   /    /\  /         / \   /       / \   /       /\   /
  4  6 13   3 4  13       3   4  13      3  4  1      3  4  1
            Heapify=3     Heapify=1     

- Max Heap of `pairs<key, value>`: Elements are sorted as per values.
 <2,gggg> <2,bb> <2,c> <2,aaaa>
    
          <2,gggg>
          /       \
       <2,bb>     <2,c>
       /
    <2,a>   
```
- **Insertion = O(logn)** 
  - Always insert element at bottom rightmost spot so as to maintain the complete tree property.
```c
Insert 10
    13                  13
   /  \                /  \
  6    5      =>      6   10
 / \   / \           / \   /\
3  4  1  10         3  4  1  5
  Swap 5,10       Until 10 finds correct spot
```
- **Delete = O(logn)** Rebalance is needed

<a name=mih></a>
#### B. Min Heap `priority_queue <int, vector<int>, greater<int>>`
- Root is always least. Condition: parent =< child. Heapify only non-leaf nodes.
 
