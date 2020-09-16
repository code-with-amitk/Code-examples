## Create
### 1. Constructors

|Ctr|Format|
|---|---|
|1. Empty| std::unordered_map<string, int> um1; |
|2. List ctr|std::unordered_map<int, std::string> m2 = { {1, "foo"}, {3, "bar"}, {2, "baz"}, }; |
|3. Copy Ctr|std::unordered_map<int, std::string> m3 = m2; |
|4. Move ctr|std::unordered_map<int, std::string> m4 = std::move(m2);|
|5. Range ctr| std::unordered_map<std::bitset<8>, double> m5(v.begin(), v.end()); |

## Insert

|Methods|How|
|---|---|
|1.|<ul><li>unordered_map<string, int> um = { {"test1", 1} };</li></ul>  <ul><li>um.insert(make_pair("test4",4));</li></ul>|
|2. Range insertion | <ul><li>unordered_map<string, int> test = {{"test5",5},{"test6",6}};</li></ul>  <ul><li>um.insert(test.begin(),test.end());</li></ul>|
|3. Initializer List|<ul><li>um.insert({{"test8",8},{"test7",7}});|
|**4. Preferred**| ```um[key] = value;```|

### Z. PRINTING
```
  for (auto i:um)
    cout<<i.first<<","<<i.second<<"\n";
```
