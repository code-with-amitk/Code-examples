**Heap/Binary Heap/Priority Queue**
- Types of Heap
  - [Max Heap](#maxh)
  - [Min Heap](#minh)
- [Priority Queue](#pq)

## Heap
- Heap is a data structure that can be viewed as **Nearly complete Binary tree**,  Each node of the tree corresponds to an element of the array.
- Root of tree is either greatest(max_heap) or smallest(min_heap). Min,Max search = O(1)
- Duplicates are allowed in heap.
- If you use arrays to implement Heaps then you don't need to store pointer as done in trees and its space advantage. 

<img src=images/binary_heap.JPG width=500/>

```c
PARENT(i) return [i/2]
LEFT(i)   return [2i]
RIGHT(i)  return [2i + 1]
```

### Types of Heap
<a name=maxh></a>
#### 1. max_heap (`priority_queue<int>`)
- Root is always greatest. Condition: `parent >= child`
- **Properties**
  - _a._ Max element is at root
  - _b._ 2nd, 3rd largest element are direct children of root(either left or right).
  
<a name=minh></a>
#### 2. min_heap (`priority_queue <int, vector<int>, greater<int>>`)
- Root is always least. Condition: `parent =< child`. 
- Heapify only non-leaf nodes. Follow same algo as in max heap. `a[] = {17, 15, 8, 9, 10, 13, 6, 4, 5, 3, 1}`

<a name=pq></a>
### Priority Queue 
- This is a implementation using Heap DS, where Each element is given a priority, higher priority element is processed/printed before any lower priority element.  
- Any two elements having same priority will be accessed according to the order in which they are added in the queue.
- **Operation on Heap**
  - **Insert(Q,x):** Given an item x with key k, insert it into the priority queue Q. 
  - **Find-Minimum(Q) or Find-Maximum(Q):** Return a pointer to the item whose key value is smaller (larger) than any other key in the priority queue Q. 
  - **Delete-Minimum(Q) or Delete-Maximum(Q):** Remove the item from the priority queue Q whose key is minimum (maximum).


