## Consistent Hashing / Consistent Hash Ring
- if key generated using hash function is greater than max allowed key then value is stored at start of hash table.
```c
  
    cat->|Hash-fun|->2000        
    dog->|Hash-fun|->8392        
    rat->|hash-fun|->3000    
    mat->|hash-fun|->10500    //Key is greater than max_allowed_key value, move to 1st location & Store

Hash Table  (Allowed max key = 10000)
  Key    Value
  2000    cat
  8392    dog
  3000    rat
  10500   mat       //key>allowed_max_key. Move to 1st location and store

Final Hash Table
  Key    Value
  2000    cat
  8392    dog
  3000    rat
  1000    mat

//Search key greater than generated value and store at that index.

          ----------------sort of ring----------------------------------
          |                                                             |
         \/     cat     rat                               dog           |
keys    1000    2000    3000    4000  5000  6000  7000  ..8392  10000   
```
