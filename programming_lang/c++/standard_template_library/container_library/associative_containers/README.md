## ASSOCIATIVE CONTAINERS
  - **What** Store <key,value> pair. 
  - **Properties**
    - Keys are always RO.
    - `unordered_set,map` have UNIQUE Keys.
    -  `multiset,multimap` can have DUPLICATE Keys.
  
### TYPES OF ASSOCIATIVE CONTAINERS

|  | Sorted/Ordered | Unordered/Unsorted |
| --- | --- | --- |
| Meaning | All elements are always sorted(ascending/descending) | Elements are not stored in any order(ascending or descending) |
| Implemented Internally as | Self-Balanced RBT | Hash tables |
| Complexity (Search) | O(nlogn) | O(1)Best O(n)Worst|
| Types | <ul><li>`set<key>`</li></ul> <ul><li>`map<key,value>`</li></ul> <ul><li>`multiset<key>`</li></ul> <ul><li>`multimap<key,value>`</li></ul> | <ul><li>`unordered_set<key>`</li></ul> <ul><li>`unordered_map<key,value>`</li></ul> <ul><li>`unordered_multiset<key>`</li></ul> <ul><li>`unordered_multimap<key,value>`</li></ul> |

  

