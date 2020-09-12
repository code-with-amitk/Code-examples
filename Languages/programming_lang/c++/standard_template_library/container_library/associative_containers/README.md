## Associative Containers <key,value> pair
- **Properties**
  - Keys are always RO.
  - `set,map` have UNIQUE Keys.
  - `multiset,multimap` can have DUPLICATE Keys.
  
### Types of AC

|  | Sorted/Ordered | Unordered/Unsorted |
| --- | --- | --- |
| Meaning | Elements are always sorted(ascending/descending) | Elements are stored in any order(ascending or descending) |
| Implemented Internally using | Self-Balanced RB Trees | Hash tables |
| Operations does not make sense | push_back(),push_front() | 
| Complexity (insert,remove,Search) | O(logn) | O(1)Best O(n)Worst|
| Types | <ul><li>`set<key>`</li></ul> <ul><li>`map<key,value>`</li></ul> <ul><li>`multiset<key>`</li></ul> <ul><li>`multimap<key,value>`</li></ul> | <ul><li>`unordered_set<key>`</li></ul> <ul><li>`unordered_map<key,value>`</li></ul> <ul><li>`unordered_multiset<key>`</li></ul> <ul><li>`unordered_multimap<key,value>`</li></ul> |
