## unordered_map<key, value> (Since C++11)
  - **What** <key,value> pair with unique keys.
  - **Complexity** Amortized: O(1), Worst case: O(n)
  - **Internal Implementation**
    - |bucket-1|  |bucket-2|..... |bucket-n|
    - elements are stored in buckets based on hash value.

### **Files**
- constructor_insert.md
  a. Constructors: default, copy, fill, range, move
  b. insert()
     - make_pair()
  c. printing
    
- count_update_find.md    
  - find pair having smallest key
  - find pair having smallest value
    
