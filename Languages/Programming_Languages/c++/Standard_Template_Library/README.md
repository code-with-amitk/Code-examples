## STL(Standard template library)
- **What?** Library providing common programming data structures such as lists, stacks, arrays, etc. Implemented using compile-time polymorphism. These are wrapper of data-structures present in C providing functions for fast/accurate access. 
- **Why STL?** code reuse, Increases Program Speed & Quality: STL is already tested & fast, Easy to learn & Adapt, Accurate & Less Buggy, Reduce control flow in code, Standardized
- **STL internal implementation?** Every container is defined as template class. class provides templated contructors/functions. /usr/include/c++/8/profile/set.h
CLASS ALLOCATOR Dynamic memory allocation/deallocation tasks are done by allocators. STL uses allocators internally, while programmer can specifically call allocators also.

## Types of STL
### 1. Containers
- **What** Data structures for storing data. 
- **Types:**

|Type|Information|Example|Complexity|
|---|---|---|---|
|**1.Seqeunce Containers**|Elements stored contigiuosly, accessed sequentially. Provides better cache locality.|vectors, deque, list, forward_list, array|O(n)|
|**2.Container Adopters**|These are not full container classes, but classes that provide a specific interface relying on an object of one of the container classes|stack, queue, priority_queue|Depends on use case|
|**3a.Associative Sorted/Ordered**|<ul><li>Implemented using Self-Balanced RBT.</li></ul><ul><li>All elements are always sorted means All elements are in order(ascending/descending)</li></ul>|`set<key>, multiset<key>, map<key,value>, multimap<key,value>`|O(logn)|
|**3b.Associative UnSorted/Unordered**|<ul><li>Implemented using Hash tables</li></ul><ul><li>Means elements are not stored in any order(ascending or descending). Only fast insert/delete/search operations matter.</li></ul>|`unordered_set<key>, unordered_multiset<key>, unordered_map<key,value>, unordered_multimap<key,value>`|Best:O(1), Worst:O(n)|

### 2. Algorithms: 
- This is logic to work on containers. algorithms works via iterators over containers

### 3. Iterators
- This is interface to iterate through containers.

### 4. Functors/Function Objects
