### unordered_map<key, value> (Since C++11)
- **What** <key,value> pair with unique keys.
- **Complexity** Amortized: O(1), Worst case: O(n)
- **Internal Implementation**
```c++
  |bucket-1|  |bucket-2|..... |bucket-n|
  elements are stored in buckets based on hash value.
```
    
