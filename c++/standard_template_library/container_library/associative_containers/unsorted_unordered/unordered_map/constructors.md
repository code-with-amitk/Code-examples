### unordered_map(Since C++11)
  - **What**
    - <key,value> pair with unique keys.
  - **Complexity**
    - Amortized: O(1), Worst case: O(n)
  - **Internal Implementation**
    - |bucket-1|  |bucket-2|..... |bucket-n|
    - elements are stored in buckets based on hash value.

#### 1. Default constructor
```      
\\explicit unordered_map( const Allocator& alloc );

#include<unordered_map>
std::unordered_map<string, int> um1;
```

#### 2. List constructor
```
    std::unordered_map<int, std::string> m2 =
    {
        {1, "foo"},
        {3, "bar"},
        {2, "baz"},
    };
```

#### 3. Copy constructor
```
std::unordered_map<int, std::string> m3 = m2;
```

#### 4. Move Constructor
```
std::unordered_map<int, std::string> m4 = std::move(m2);
```

#### 5. Range constructor
```
    std::vector<std::pair<std::bitset<8>, int>> v = { {0x12, 1}, {0x01,-1} };
    std::unordered_map<std::bitset<8>, double> m5(v.begin(), v.end());
```
