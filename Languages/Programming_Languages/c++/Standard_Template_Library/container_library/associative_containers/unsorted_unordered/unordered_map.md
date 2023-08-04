**unordered_map`<key, value>`**
- [Functions in C++, Rust, Python](#funhm)
- [Map of Structures](#umstruct)
- [Map of Maps](#mapmap)

### [HTML Page unordered_map](https://amitkumar50.github.io/Languages/Programming/C++/STL/Containers/Associative_Containers/Unsorted_Unordered/unordered_map.html)

### unordered_map`<key, value>`
- `<key,value>` pair with unique keys. *Time Complexity* Normal: O(1), Worst case: O(n)

<a name=funhm></a>
#### Functions in C++, Rust, Python
||C++|Rust (use std::collections::HashMap) |Python({} Dictionary)|
|---|---|---|---|
|Create|unordered_map<string, int> um | <ul><li>**Empty:** let hm:HashMap = HashMap::new() </li> <br> <li>**init:** `let hm:HashMap = HashMap::From([(1:"a"),(2:"b")]);` </li></ul>|<ul><li>**Empty:** self.hm = {} </li> <br> <li>**key,val:** self.hm={1:1, 2:2} </li></ul>|
|Delete/Erase|<ul><li>`um.erase(key)`</li> <br> <li>**Range:** um.erase(start,end)<li> <br> </ul>|||
|Find|<ul><li>`value = um[key]`</li> <br> <li>value=count(key)</li> <br> <li>**Smallest Key:** min_element(um.begin(), um.end())<li> <br> </ul>||`value = um[key]`|
|Insert|<ul><li>`um[key] = value`</li> <br> <li>`um.insert(make_pair(key,val))`</li> <br> </ul>||<ul><li>`self.hm={1:1, 2:2}`</li> <br> </ul>|

<a name=umstruct></a>
#### Map of Structures
- Value is pointer to structure containing vector. [Code: Underground Station]
```cpp
            | | | | | | vector
            /\
            |
          |pVec| val |
          struct data
          /\
          |
|key="a"|value=pointer_to_struct|  

    using stData = struct data {
        unique_ptr<vector<int>> pVec;
        int val;
    };
    
    unordered_map <string, unique_ptr<stData> > um;    
```
