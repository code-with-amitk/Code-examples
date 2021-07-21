- `unordered_set<key>`
  - [1. Create](#screate)
    - set of pairs

## unordered_set<key>
<a name=screate></a>
### 1. Create
#### Set of Pair
- We cannot create `unordered_set<pair<int,int>>` Why?
  - By default, it uses std::hash but there is no specialization of std::hash for std::pair<T1,T2> provided in the standard library.
- How to create `unordered_set<pair<int,int>>`? Provide own hash functor
```c
struct SimpleHash {
    size_t operator()(const std::pair<int, int>& p) const {
        return p.first ^ p.second;
    }
};

std::unordered_set<std::pair<int, int>, SimpleHash> S;
S.insert(std::make_pair(0, 1));
```
