## Priority Queue/HEAP/Binary heap
- **What**
  - Each element is given a priority. 
  - Higher priority element is processed before any lower priority element. 
  - Any two elements having same priority will be accessed according to the order in which they are added in the queue.
- **Internal Implementation**
  - This is balanced complete Binary tree. Duplicates are allowed. 
  - This is suited to be stored in array ie Heap can be implemented using arrays. If you use arrays to implement Heaps then you don't need to store pointer as done in trees and its space advantage
  
### Types of Heap
#### 1. Max Heap `(priority_queue<int>)`
- **What** Root is always greatest. Condition: parent >= child
- **Building Max Heap from Array**
  - Traverse array and create Level-Order tree. 
  - Heapify only non-leaf nodes. Indexes of non-leaf nodes = (N/2 - 1)
    - Heapfiy a node means, exchange node with either left or right child who is greatest.
  - Example
```c++
  a[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}.    //Indexes of non-leaf nodes = (N/2 - 1) = 4,6,5,3,1
```
![ImgURL](https://i.ibb.co/vxFKzqD/max-heap.png)

#### 2. Min Heap `(priority_queue <int, vector<int>, greater<int>>)`
- Root is always least. Condition: parent =< child. Heapify only non-leaf nodes.
  
### Operations & Complexities

| |Heap|Array|Balanced BT|
|---|---|---|---|
|Search highest,least|O(1)|O(n)|O(logn)|
|Insert|O(logn)|O(1)|O(logn)|
 
