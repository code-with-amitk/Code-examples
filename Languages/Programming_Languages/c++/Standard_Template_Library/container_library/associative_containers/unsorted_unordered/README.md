**unordered_set`<key>`**
  - Create
    - [Set of pairs](#sp)
  - Find
    - [const_iterator find(key)](#find)
    - [random key with same probability in O(1)](/DS_Questions/Questions/Random/Implement_Class/RandomisedSet_Insert_Delete_GetRandom_in_O1.md)
  - Remove Delete
  - [Count](#count1)

**unordered_map`<key, value>`**
  - **Create**
    - [Constructors](#umctr)
    - [Map of Structures](#umstruct)
    - [Map of Maps](#mapmap)
  - [Insert](#uminsert)
  - [Print](#umprint)
    - [random (k,v) with same probability in O(1)](/DS_Questions/Questions/Random/Implement_Class/RandomisedSet_Insert_Delete_GetRandom_in_O1.md)
  - **Find/Search**
    - [1. using index ](#f1)
    - [2. using count()](#f2)
    - [3. using find()](#f3)
    - [4. Smallest key](#f4)
    - [5. Smallest Value](#f5)
    - [6. Count Number of occurences of value](#f6)
  - [Remove/Delete](#erase)
  - [Count](#c1)



# unordered_set`<key>`
Keys are stored in HashMap, hence unordered not in ascending,descending order.
## Create
<a name=sp></a>
#### Set of Pair
We cannot create `unordered_set<pair<int,int>>` Why?
  - By default, it uses std::hash but there is no specialization of std::hash for std::pair<T1,T2> provided in the standard library.
  - Solution: Provide own hash [functor](/Languages/Programming_Languages/c++/Characteristics_of_OOPS/Polymorphism/Static_CompileTime/Operator_Overloading/Functor).
```cpp
struct SimpleHash {
    size_t operator()(const std::pair<int, int>& p) const {
        return p.first ^ p.second;
    }
};

std::unordered_set<std::pair<int, int>, SimpleHash> S;
S.insert(std::make_pair(0, 1));
```

## Find
<a name=find></a>
#### const_iterator find(key)
- Searches the container for an element with k as value and returns an iterator to it if found, else returns iterator to unordered_set::end (element past end of container).
```cpp
  unordered_set<int> us = { 1,2,4 };
  unordered_set<int>::const_iterator it = myset.find (2);
  if ( it == myset.end() )
    cout << "not found";
  else
    cout << "Found";
```


# unordered_map`<key, value>`
- `<key,value>` pair with unique keys. *Time Complexity* Normal: O(1), Worst case: O(n)

<a name=fun_hm></a>
### Functions in C++, Rust, Python
||C++|Rust|Python(Dictionary)|
|---|---|---|---|
|Create|unordered_map<string, int> um||self.hm = {}|||
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

<a name=mapmap></a>
#### Map of Maps
```cpp
    using map1 = unordered_map<uint32_t, uint32_t>;
    using map2 = unordered_map <string, map1>;
    map2 um;
    map1 temp = { { 1,2 } };
    um[A] = temp;    
```
