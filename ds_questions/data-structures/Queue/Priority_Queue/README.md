## Priority Queue/HEAP/Binary heap
- **What**
  - Each element is given a priority. 
  - Higher priority element is processed before any lower priority element. 
  - Any two elements having same priority will be accessed according to the order in which they are added in the queue.
- **Internal Implementation**
  - This is balanced complete Binary tree. Duplicates are allowed. 
  - This is suited to be stored in array ie Heap can be implemented using arrays. If you use arrays to implement Heaps then you don't need to store pointer as done in trees and its space advantage
  
### Types of Heap
#### 1. Max Heap (priority_queue<int>)
- Root is always greatest. Condition: parent >= child

#### 2. Min Heap (priority_queue <int, vector<int>, greater<int>>)
- Root is always least. Condition: parent =< child. Heapify only non-leaf nodes.
  


