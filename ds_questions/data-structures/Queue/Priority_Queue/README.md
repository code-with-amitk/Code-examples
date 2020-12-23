# Priority Queue/HEAP/Binary heap
- **What**
  - Each element is given a priority. Higher priority element is processed before any lower priority element. 
- **Internal Implementation**
  - Using balanced complete Binary tree. Duplicates are allowed. 
  - This is suited to be stored in array ie Heap can be implemented using arrays. If you use arrays to implement Heaps then you don't need to store pointer as done in trees and its space advantage
  
## Types of Heap
### A. Max Heap `(priority_queue<int>)`
- **What** Root is always greatest. Condition: parent >= child
- **1. Max Heap(key only)**
  - Traverse array and create Level-Order tree. 
  - Heapify only non-leaf nodes. Indexes of non-leaf nodes = (N/2 - 1)
    - Heapfiy a node means, exchange node with either left or right child who is greatest.
  - Example
```c++
  a[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}.    //Indexes of non-leaf nodes = (N/2 - 1) = 4,6,5,3,1
```
![ImgURL](https://i.ibb.co/vxFKzqD/max-heap.png)

- **2. Max Heap of pairs<key, value>**
  - **Unequal Keys** Elements are sorted as per key values.
```c++
      <5,a>
      /   \
    <4,b> <3,c>      
```
  - **Equal Keys** Elements are sorted as per values.
  ```c++
create:    <2,gggg> <2,bb> <2,c> <2,aaaa>
    
          <2,gggg>
          /       \
       <2,bb>     <2,c>
       /
    <2,a>   

Insert:   <2,z>

          <2,gggg>                          <2,gggg>                                   <2,z>
          /       \                         /       \                                 /     \
       <2,bb>     <2,c>   --Heapify z--   <2,z>     <2,c>     --Heapify gggg-->   <2,gggg>  <2,c>
       /    \                             /   \                                   /     \
    <2,a>   <2,z>                       <2,a> <2,bb>                            <2,a>   <2,bb>
```

### B. Min Heap `(priority_queue <int, vector<int>, greater<int>>)`
- Root is always least. Condition: parent =< child. Heapify only non-leaf nodes.
  
## Operations & Complexities

| |Heap|Array|Balanced BT|
|---|---|---|---|
|Search highest,least|O(1)|O(n)|O(logn)|
|Insert|O(logn)|O(1)|O(logn)|
 
