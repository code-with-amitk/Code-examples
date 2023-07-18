**LRU Cache**
- [Approach1](#a1)
  - [Logic](#l)
  - Code
    - [CPP](#cpp)

### [Self Good Video](https://www.youtube.com/watch?v=mhcTL2lqwI0)

### [146. LRU Cache](https://leetcode.com/problems/lru-cache/)
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

<a name=a1></a>
### Approach-1     //Doubly LL+ Hash
<a name=l></a>
#### Logic
- Most Recently used(MRU) is stored at front, LRU at back of doubly LL.
```c
Cache capacity = 3
cache =  | 5 | 3 | 2 | 1 | 4 |
          MRU             LRU
```
- _2._ INSERT. Adding new entry
```c
if space is there in cache {
  if (entry exist in cache)
    - entry comes to front becomes MRU. Update hm
  else
    - insert entry at front. Add entry in hm
}
else    // No space in cache
{
  - Delete last entry(LRU) from cache
  - insert new entry in front
  - update hm
}
```
- _3._ Search entry in cache
```c
  if entry exist
    - move entry to front. return
  else
    - return -1
```
#### Code
<a name=cpp></a>
**CPP**
```cpp
using lp = list <pair<int,int>>;

class LRUCache {
  int c;
  lp dll;
  unordered_map<int, lp::iterator> um;

public:
    LRUCache(int capacity):c(capacity){
        um.reserve(capacity);
    }
    
    int get(int key) {
        auto it = um.find(key);
        // if key not found return -1
        if (it == um.end()) {
            return -1;
        }

        // if key found, Move entry to front ie MRU(Most recently used)
        // void splice (const_iterator position, list& x, const_iterator i)
        dll.splice(dll.begin(), dll, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        
        auto it = um.find(key);
        // if Key found in um
        //  - Replace value of key
        //  - key comes to front, ie becomes MRU(Most recently used)
        if (it != um.end()){
            it->second->second = value;     //Replace the value in dll
            dll.splice(dll.begin(), dll, it->second); //Move element to end of dll
            return;
        }

        // if key not found
        if (dll.size() < c) {
            // Cache has space
            //  Insert at front of dll ie becomes MRU(Most recently used)
            um[key] = dll.insert(dll.begin(), {key, value});
        } else {
            // Size of cache is full.
            //  - Remove last entry from cache ie remove LRU (Least recently used)
            //  - Remove key from hashmap
            if (!dll.empty()) {
                int temp_key = dll.back().first;
                um.erase(temp_key);
                dll.pop_back();
            }

            // Insert (key,value) at start
            // Note address in hashmap
            dll.push_front({key, value});
            um[key] = dll.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
