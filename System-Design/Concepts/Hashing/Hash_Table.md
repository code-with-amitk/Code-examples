## [Hash Table](/DS_Questions/Data_Structures/Hash_Tables)

## Rehashing
- Let's consider `unordered_map<int,string>`(ie storing unique keys). 
- At start of program a hash table of size=X(let's say 3) is created     `key -> |Hash Function| -> index/hash`
```c
        key > |Hash function = %3| > index.    0 > |%3| > 0.    1 > |%3| > 1.     2 > |%3| > 2
        
//Hash Table size=3
    key   Value
    0     amit
    1     never
    2     up
```
- Now, 4th element need to be stored (key=5, value=up). When X+1st element need to be placed, then size of hash table needed to be increased, else separate chaining will happen for unordered_multimap(allows duplicate keys) else prev value would be overwritten.
- Size is doubled. size=6. With (old Hash function = %3) we can only goto index number=2. But we want to reach 5. Hence Hash function is changed (old Hash function = %6). So hash is again calculated for existing values.
