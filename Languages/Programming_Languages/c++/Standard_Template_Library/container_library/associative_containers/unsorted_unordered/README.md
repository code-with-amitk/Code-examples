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
- `<key,value>` pair with unique keys. *Complexity* Amortized: O(1), Worst case: O(n)

### Create
<a name=umctr></a>
#### Constructors
```cpp
unordered_map<string, int> um;
unordered_map<int, std::string> m2 = {     //List ctr
  {1, "foo"},
  {2, "baz"}, 
}; 
unordered_map<int, std::string> um1 = um2;     //Copy Ctr
unordered_map<int, std::string> m4 = std::move(m2);    //Move ctr
unordered_map<std::bitset<8>, double> m5(v.begin(), v.end());     //Range ctr
```

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

<a name=uminsert></a>
### Insert
```cpp
unordered_map<int,float> um;
um[1] = 4.0;    //um[key] = value;

unordered_map<string,float> um1;
um1.insert (make_pair("test",4));

unordered_map<string, int> test = { {"test5",5}, {"test6",6} };
test.insert(test.begin(),test.end());

unordered_map<int, unordered_set<int>> um2;
um2[key].insert({value});
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

<a name=f1></a>
#### 1. using index {Preferred}
```cpp
    unordered_map<int, pair<int,int>> = {{1,100}, {2,200}};
    auto it = um [1];
    cout << it.first << it.second;    //1,100
```
<a name=f2></a>
#### 2. using [count()](#c1)
<a name=f3></a>
#### 3. using find()
```
class cmd{ ... };
class cmd1 : public cmd { ... };
unordered_map<string, cmd *> um;
um["cmd1"] = new cmd1();                  //Created unorderd_map
um["cmd2"] = new cmd2();
auto it = um.find ("cmd1");                   //Finding Key
if (it != um.end())
  cout << it->second->fun();
```
<a name=f4></a>
#### 4. Smallest key
```cpp
  unordered_map<int,int>::iterator it;
  it = min_element(um.begin(), um.end());
  cout<<it->first<<" " <<it->second;          //1 2
```
<a name=f5></a>
#### 5. Smallest Value
```cpp
  static bool comp(pair<int,int> i, pair<int, int> j)
    return i.second < j.second;

  unordered_map<int,int>::iterator it;
  it = min_element(um.begin(), um.end(),compare_func);
  cout<<it->first<<" " <<it->second;          //4 1
```

<a name=f6></a>
#### 6. Count Number of occurences of value
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

<a name=c1></a>
## size_type count ( const key_type& k ) const;
- Searches key and returns the number of elements found. Because unordered_map,unordered_set do not allow for duplicate keys, this means that the function returns 1 if an key  exists in the container, and zero otherwise.
- **find() vs count()**  equal performance, choice depends on the semantics in your code.
```cpp
  cout << um.count(1);
```
