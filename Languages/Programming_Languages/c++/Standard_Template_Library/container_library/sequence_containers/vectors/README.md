## Vector
- **What** 
  - Dynamic Allocated Array, Elements are stored in contiguous location. 
  - Vector keeps some space reserved in advance for storage of some variables. Now when this space is exhausted. It again re-allocates bigger contiguous space, copies the elements to new space, deletes present memory.  
- **ARRAYLIST Vs VECTORS?**
  - Vectors are synchronized by default but ArrayLists are not.
  - Means if multiple threads accesses vectors then no synchronization needed but required in AL.    

## Pages
- **2-d-vector.cpp** 2-Dimensional vector(Arbitary size, Fixed size)
- **Convert_vector_to_heap.md** to min_heap, to max_heap
- **insert_iterate_delete.cpp** *insert* push_back(), assign(), *Traversal* Using index, iterator, vector.at(), begin() end(), *Deletion* erase(): Removes a range, clear(): Empties the container
- **sizeof_vector.md** Calculating sizeof vector
- **vector_constructors.cpp**: default, fill, range, copy, fixed, move, initializer list
- **Searching.md** max element in vector, min element
