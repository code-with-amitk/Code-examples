   
### A. CONSTRUCTORS
#### A1. DEFAULT
```      
\\explicit unordered_map( const Allocator& alloc );

#include<unordered_map>
std::unordered_map<string, int> um1;
```
#### A2. LIST
```
    std::unordered_map<int, std::string> m2 =
    {
        {1, "foo"},
        {3, "bar"},
        {2, "baz"},
    };
```
#### A3. COPY
```
std::unordered_map<int, std::string> m3 = m2;
```
#### A4. MOVE
```
std::unordered_map<int, std::string> m4 = std::move(m2);
```
#### A5. RANGE
```
    std::vector<std::pair<std::bitset<8>, int>> v = { {0x12, 1}, {0x01,-1} };
    std::unordered_map<std::bitset<8>, double> m5(v.begin(), v.end());
```

### B. INSERT()
  - inserting value or range into unordered_map
#### B1. Copy insertion
```
    unordered_map<string, int> um =
    {
        {"test1", 1},
        {"test2", 2},
        {"test3", 3},
    };
  um.insert(make_pair("test4",4));
```
#### B2. Range insertion
```
  unordered_map<string, int> test = {{"test5",5},{"test6",6}};
  um.insert(test.begin(),test.end());
```
#### B3. Initializer list insertion
```
  um.insert({{"test8",8},{"test7",7}});
```

### Z. PRINTING
```
  for (auto i:um)
    cout<<i.first<<","<<i.second<<"\n";
```
