- **unordered_set`<key>`**
  - [1. Create](#screate)
    - set of pairs
  - [2. const_iterator find(key)](#find)

## unordered_set`<key>`
<a name=screate></a>
### 1. Create
#### Set of Pair
- We cannot create `unordered_set<pair<int,int>>` Why?
  - By default, it uses std::hash but there is no specialization of std::hash for std::pair<T1,T2> provided in the standard library.
- How to create `unordered_set<pair<int,int>>`? Provide own hash functor
```cpp
struct SimpleHash {
    size_t operator()(const std::pair<int, int>& p) const {
        return p.first ^ p.second;
    }
};

std::unordered_set<std::pair<int, int>, SimpleHash> S;
S.insert(std::make_pair(0, 1));
```

<a name=find></a>
### 2. const_iterator find(key)
- Searches the container for an element with k as value and returns an iterator to it if found, else returns iterator to unordered_set::end (element past end of container).
```cpp
  unordered_set<int> us = { 1,2,4 };
  unordered_set<int>::const_iterator it = myset.find (2);
  if ( it == myset.end() )
    cout << "not found";
  else
    cout << "Found";
```
