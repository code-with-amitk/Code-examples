## [LRU](https://leetcode.com/problems/lru-cache/)
- Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
- get and put in O(1) time complexity
- Implement the LRUCache class:
  - LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
  - `int get(int key)` Return the value of the key if the key exists, otherwise return -1.
  - `void put(int key, int value)` Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
- **Example:**
```c
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]

Output
[null, null, null, 1, null, -1, null, -1, 3, 4]
```

### Approach-1     //Doubly LL+ Hash
- **Logic**
  - Same as [lru_cache_key_and_value.md](lru_cache_key_and_value.md). Here Most recently used entry is inserted at back of dll and LRU entry is kept at start of DLL.
```c
Cache capacity = 3
             DLL                          Hash
put(1,1)    |1,1|                        |1,10|
      
put(2,2)  |1,1| <> |2,2|                 |1,10|2,20|
          /\          /\
          LRU         MRU

put(3,3)  |1,1| <> |2,2| <> |3,3|        |1,10|2,20|3,30|
          /\                /\
          LRU               MRU
          
put(4,4)  |4,4| <> |2,2| <> |3,3|        |4,40|2,20|3,30|
                              /\
                             MRU  
                             
splice    |2,2| <> |3,3| <> |4,4|        |4,40|2,20|3,30|
                              /\
                             MRU                               
```
- **Code**
```c++
class LRUCache {
  int c;
  list <pair<int,int>> dll;
  unordered_map<int, list<pair<int,int>>::iterator> um;
public:
    //Capacity of cache is kept in c
    //Unorderd_map is reserved in advance
    LRUCache(int capacity):c(capacity){
        um.reserve(capacity);
    }
    
    int get(int key) {
        auto it = um.find(key);
        if (it == um.end())
            return -1;

        dll.splice(dll.end(), dll, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        
        //Key found and replace the value
        if (auto it = um.find(key); it != um.end()) {
            it->second->second = value;
            dll.splice(dll.end(), dll, it->second);
            return;
        }

        if (dll.size() < c) {
            //dll is not full
            um[key] = dll.insert(dll.end(), {key, value});
        } else {
            //dll is full, Delete LRU entry. LRU is kept at start of dll
            um.erase(dll.begin()->first);
            
            //Insert new {key,value} at beggining of dll
            *dll.begin() = {key, value};
            
            //Update entry of unordered_map
            um[key] = dll.begin();
            
            //splice(destination, container, source)
            //Move source to destination in container.
            //newly created entry is moved to back, ie MRU entry is kept at back
            dll.splice(dll.end(), dll, dll.begin());
        }
    }
};
```
