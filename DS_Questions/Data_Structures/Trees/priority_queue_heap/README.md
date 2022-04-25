**Heap/Binary Heap/Priority Queue**
- [Priority Queue](#pq)
- [Operations on heap](#o)
- [Types of Heap](#t)


## Heap
Heap is a data structure which is used for implementing PQ

<a name=pq></a>
### Priority Queue
- This is a implementation using Heap DS, where Each element is given a priority, higher priority element is processed/printed before any lower priority element.  
- Any two elements having same priority will be accessed according to the order in which they are added in the queue.
- **Implementation**
  - Using balanced complete Binary tree.
  - Root of tree is either greatest(max_heap) or smallest(min_heap). Min,Max search = O(1)
  - Reordering of elements in done prior to arrival.
  - Duplicates are allowed in heap. This is suited to be stored in array ie Heap can be implemented using arrays.
  - If you use arrays to implement Heaps then you don't need to store pointer as done in trees and its space advantage. 
    
<a name=o></a>
### Operation on Heap
- **Insert(Q,x):** Given an item x with key k, insert it into the priority queue Q. 
- **Find-Minimum(Q) or Find-Maximum(Q):** Return a pointer to the item whose key value is smaller (larger) than any other key in the priority queue Q. 
- **Delete-Minimum(Q) or Delete-Maximum(Q):** Remove the item from the priority queue Q whose key is minimum (maximum).

<a name=t></a>
### Types of Heap
#### MAX_HEAP (`priority_queue<int>`)
Root is always greatest. Condition: `parent >= child`
  
#### MIN_HEAP (`priority_queue <int, vector<int>, greater<int>>`)
- Root is always least. Condition: `parent =< child`. 
- Heapify only non-leaf nodes. Follow same algo as in max heap. `a[] = {17, 15, 8, 9, 10, 13, 6, 4, 5, 3, 1}`
