## Create
### 1. Constructors
```c++
//1. Empty
std::unordered_map<string, int> um1;

//2. List ctr
std::unordered_map<int, std::string> m2 = { 
  {1, "foo"},
  {3, "bar"},
  {2, "baz"}, 
}; 

//3. Copy Ctr
std::unordered_map<int, std::string> m3 = m2;

//4. Move ctr
std::unordered_map<int, std::string> m4 = std::move(m2);

//5. Range ctr
std::unordered_map<std::bitset<8>, double> m5(v.begin(), v.end());
```

## Insert
```c++
//Method-1
unordered_map<string, int> um = { 
  {"test1", 1} 
};
um.insert(make_pair("test4",4));

//2. Range insertion
unordered_map<string, int> test = {
  {"test5",5},
  {"test6",6}
};
um.insert(test.begin(),test.end());

//Method-3 Initializer List
um.insert({
    {"test8",8},
    {"test7",7}
    });

//Method-4 Preferred 
um[key] = value;
```

## Z. PRINTING
```c++
  for (auto i:um)
    cout<<i.first<<","<<i.second<<"\n";
```
