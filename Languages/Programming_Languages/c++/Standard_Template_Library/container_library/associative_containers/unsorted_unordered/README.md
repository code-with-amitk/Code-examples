**unordered_set`<key>`**
- Create
  - [Set of pairs](#screate)
- Find
  - [const_iterator find(key)](#find)
- Remove Delete
  - Delete a key in O(1)
- [Count](#count)

**unordered_map`<key, value>`**
- [Create](#uminsert)
- [Insert](#uminsert)
- [Print](#umprint)
- Find/Search
  - [key in um](#keyum)
  - [Pair having smallest `key`](#smllestk)
  - [Pair having smallest `value`](#smallestv)
  - [Count Number of occurences of value inside array](#count)
- [Remove/Delete](#erase)
  - [Delete a (k,v) in O(1) time]
- [Count](#count)



# unordered_set`<key>`
## Create
<a name=screate></a>
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
- `<key,value>` pair with unique keys. *Complexity* Amortized: O(1), Worst case: O(n)
<a name=createum></a>
### Create
```cpp
unordered_map<string, int> um;

unordered_map<int, std::string> m2 = {     //List ctr
  {1, "foo"},
  {3, "bar"},
  {2, "baz"}, 
}; 

unordered_map<int, std::string> um1 = um2;     //Copy Ctr

unordered_map<int, std::string> m4 = std::move(m2);    //Move ctr

unordered_map<std::bitset<8>, double> m5(v.begin(), v.end());     //Range ctr
```

<a name=uminsert></a>
### Insert
```cpp
um[key] = value;   

um.insert (make_pair("test",4));

unordered_map<string, int> test = { {"test5",5}, {"test6",6} };
um.insert(test.begin(),test.end());
```

<a name=umprint></a>
### Print
```cpp
for (auto i:um)                               //auto()
  cout<<i.first<<","<<i.second<<"\n";

for (auto i=um.begin(); i!=um.end(); ++i)    //begin(), end()
    cout<<i->first<<","<<i->second<<"\n";
    
for (unordered_map<int,string>::iterator i=um.begin(); i!=um.end(); ++i)          //iterator
    cout<<i->first<<" "<<i->second<<"\n";
```

## Find
- [count()](#count) can also be used in place of find().
<a name=keyum></a>
#### key in um
```c++
class cmd{ ... };
class cmd1 : public cmd { ... };

unordered_map<string, cmd *> um;

um["cmd1"] = new cmd1();                  //Created unorderd_map
um["cmd2"] = new cmd2();

auto it = um.find ("cmd1");                   //Finding Key
if (it != um.end()) {                         //Found Key
  cout << it->second->fun();                  //Call method of class
}
```
<a name=smllestk></a>
#### Pair having smallest `key`
```cpp
  unordered_map<int,int>::iterator it;
  it = min_element(um.begin(), um.end());
  cout<<it->first<<" " <<it->second;          //1 2
```
<a name=smallestv></a>
#### Pair having smallest `value`
```cpp
  static bool comp(pair<int,int> i, pair<int, int> j)
    return i.second < j.second;

  unordered_map<int,int>::iterator it;
  it = min_element(um.begin(), um.end(),compare_func);
  cout<<it->first<<" " <<it->second;          //4 1
```
<a name=count></a>
#### Count Number of occurences of value inside array
- Let's suppose an array `{4,3,1,1,3,3,2}` is present we need to create a map
```c++
key ->            4 3 1 2
NoOfOccurences -> 1 3 2 1

  vector<int>& arr = {4,3,1,1,3,3,2};
  unordered_map<int,int> um;           //<key=element, value=count>
  
Method-1:                     //USE THIS
  for(auto i:arr)
    um[i] = um[i] + 1;
  
Method-2:  
  unordered_map<int,int>::iterator it;
  for(auto i:arr){
    it = um.find(i);
    if(it != um.end())
      ++it->second;
    else
      um.insert(make_pair(i,1));
  }
```

<a name=erase></a>
## Erase/Delete
```cpp
  um.erase(const iterator);    //Using iterator

  um.erase(const iteratorStart, const iteratorEnd);   //Range Delete
  
  um.erase(const key);              //Using Key
```

<a name=count></a>
## size_type count ( const key_type& k ) const;
- Searches key and returns the number of elements found. Because unordered_map,unordered_set do not allow for duplicate keys, this means that the function returns 1 if an key  exists in the container, and zero otherwise.
- **find() vs count()**  equal performance, choice depends on the semantics in your code.
```cpp
  cout << um.count(1);
```
