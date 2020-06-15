## HEAP/BINARY HEAP/PRIORITY_QUEUE
  - **What**
    - Each element is given a priority.
    - higher priority element is processed before any lower priority element.  
    - Any two elements having same priority will be accessed according to the order in which they are added in the queue.
  - **Implemented using**    
    - This is balanced complete Binary tree.
    - Root of tree is either greatest(max_heap) or smallest(min_heap). Min,Max search = O(1)
    - Reordering of elements in done prior to arrival.
    - Duplicates are allowed in heap. This is suited to be stored in array ie Heap can be implemented using arrays.
    - If you use arrays to implement Heaps then you don't need to store pointer as done in trees and its space advantage. 
    
### A. OPERATIONS ON HEAP
#### A1. Insert(Q,x)  
  -  Given an item x with key k, insert it into the priority queue Q. 
#### A2. Find-Minimum(Q) or Find-Maximum(Q)
  -  Return a pointer to the item whose key value is smaller (larger) than any other key in the priority queue Q. 
#### A3. Delete-Minimum(Q) or Delete-Maximum(Q)
  -  Remove the item from the priority queue Q whose key is minimum (maximum).

### A. TYPES OF HEAP
#### A1. MAX_HEAP (priority_queue<int>)
  - Root is always greatest.
  - Condition: parent >= child
  
#### A2. MIN_HEAP (priority_queue <int, vector<int>, greater<int>>)
  - Root is always least.
  - Condition: parent =< child. 
  - Heapify only non-leaf nodes. Follow same algo as in max heap. 
  - a[] = {17, 15, 8, 9, 10, 13, 6, 4, 5, 3, 1}
