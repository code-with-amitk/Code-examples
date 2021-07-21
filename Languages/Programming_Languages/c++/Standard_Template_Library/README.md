STL / Standard template library 
- [What](#what)
- [Why](#why)
- [Internal Implementation](#impl)
- Types of STL
  - [1. Containers](#con)
    - [1.1 Seqeunce Containers](#seq)
    - [1.2 Container Adopters](#adop)
    - [1.3 Sorted/Ordered](#or)
    - [1.4 UnSorted/Unordered](#unor)
  - [2. Algorithms](#algo)
  - [3. Iterators](#itr)
  - [4. Functors](#func)

## STL
<a name=what></a>
**What?**
- Library providing common programming data structures such as lists, stacks, arrays, etc. Implemented using compile-time polymorphism. These are wrapper of data-structures present in C providing functions for fast/accurate access. 

<a name=why></a>
**Why?**
- code reuse, Increases Program Speed & Quality: STL is already tested & fast, Easy to learn & Adapt, Accurate & Less Buggy, Reduce control flow in code, Standardized

<a name=impl></a>
**Internal implementation?** 
- Every container is defined as template class. class provides templated contructors/functions. /usr/include/c++/8/profile/set.h
- CLASS ALLOCATOR Dynamic memory allocation/deallocation tasks are done by allocators. STL uses allocators internally, while programmer can specifically call allocators also.

## Types of STL
<a name=con></a>
### 1. Containers
Data structures for storing data. 

<a name=seq></a>
#### 1.1 Seqeunce Containers, Complexity:O(n)
- Elements stored contigiuosly, accessed sequentially. Provides better cache locality. Ex:
  - vectors, deque, list, forward_list, array

<a name=adop></a>
#### 1.2 Container Adopters, Complexity: Depends on use case
- These are not full container classes, but classes that provide a specific interface relying on an object of one of the container classes. Ex:	
  - stack, queue, priority_queue

<a name=or></a>
#### 1.3 Associative Sorted/Ordered, Complexity:O(nlogn)
- Implemented using Self-Balanced RBT. All elements are always sorted means All elements are in order(ascending/descending). Ex:
  - `set<key>, multiset<key>, map<key,value>, multimap<key,value>`

<a name=unor></a>
#### 1.4 Associative unsorted/unordered, Complexity:Best O(1), Worst O(n)
- Implemented using Hash tables. Means elements are not stored in any order(ascending or descending). Only fast insert/delete/search operations matter. Ex:
  - `unordered_set<key>, unordered_multiset<key>, unordered_map<key,value>, unordered_multimap<key,value>`

<a name=algo></a>
### 2. Algorithms
- This is logic to work on containers. algorithms works via iterators over containers

<a name=itr></a>
### 3. Iterators
- This is interface to iterate through containers.

<a name=func></a>
### 4. Functors/Function Objects
