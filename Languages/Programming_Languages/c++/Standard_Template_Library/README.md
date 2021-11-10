- **[STL / Standard template library](#stl)**
- **Types of STL**
  - [1. Containers: Sequence containers, Container Adopters, Sorted/Ordered, Unsorted/unordered](#con)
  - [2. Algorithms](#algo)
  - [3. Iterators](#itr)
  - [4. Functors](#func)

<a name=stl></a>
## STL
- **What?** Library providing common programming data structures such as lists, stacks, arrays, etc. Implemented using compile-time polymorphism. These are wrapper of data-structures present in C providing functions for fast/accurate access. 
- **Why?** code reuse, Increases Program Speed & Quality: STL is already tested & fast, Easy to learn & Adapt, Accurate & Less Buggy, Reduce control flow in code, Standardized
- **Internal implementation?** 
  - Every container is defined as template class. class provides templated contructors/functions. /usr/include/c++/8/profile/set.h
  - CLASS ALLOCATOR Dynamic memory allocation/deallocation tasks are done by allocators. STL uses allocators internally, while programmer can specifically call allocators also.

## Types of STL
<a name=con></a>
### 1. Containers
Data structures for storing data. 
```c
    Type    | Sequence Containers     | 2. Container Adoptors  | 3. Associative (Sorted/Ordered) | 4. Associative (unsorted/unordered)
------------|-------------------------|------------------------|---------------------------------|---------------
Example     | vector,deque,list,array | stack,queue            | set<key>, multiset<key>         | unordered_set<key>, unordered_multiset<key>
                                        priority_queue           map<k,v>, multimap<k,v>         | unordered_map<k,v>, unordered_multimap<k,v>
                                        
How elements| Contigiuosly            | These are not container| Self-Balanced BST (RBT)         | Hash Table
are stored                            | classes, but uses other| All elements are in ascending or|
                                      | STL classes.           | decending order. 
Access      | Sequential

Adv         | Better cache locality   |                        | Sorted elements                  | Insert, search, delete = O(1)

Complexity  | O(n)                    |                        |    O(nlogn)//All cases           |  Best:O(1), Worst:O(n)
```

<a name=algo></a>
### 2. Algorithms
This is logic to work on containers. algorithms works via iterators over containers

<a name=itr></a>
### 3. Iterators
This is interface to iterate through containers.

<a name=func></a>
### 4. Functors/Function Objects
