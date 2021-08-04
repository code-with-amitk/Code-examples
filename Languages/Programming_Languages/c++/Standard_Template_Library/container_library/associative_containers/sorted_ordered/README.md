**Map**
- Inserting element
  - [insert()](#mins)
  - [emplace()](#emp)
- [erase](#merase)

**Set**
- [Create / Constructors](#scre)
- [Insert](#sins)
- [Implementing set](set)



## Map<key, value>
- All elements are always sorted means All elements are in order(ascending/descending). Some operations does not make sense Eg: push_back(), push_front().

### Insert
<a name=mins></a>
#### `<iterator, bool>` insert(const val_type& val)
For inserting element into stl. Creates object somewhere else, copies objects into the vector
```cpp
map< char, int > m;
m.insert(make_pair('a', 1));
```
<a name=emp></a>
#### `<iterator,bool>` emplace(Args&.. args)   //Preferred over insert()
Same, used for inserting elements into stl. But constructs elements inside the stl only. Does in place insertion, avoids unneccessary copy.
```cpp  
m.emplace('b', 2);
for (auto i:m)
  cout << i;                    //a 1   b 2
```

<a name=merase></a>
### erase(const key_type& k)
Find key and erase.
```cpp
  void find ( K key ) {
    if ( (m.find (key)) != m.end() )   //key found
      m.erase (key);
  }
```

## Set ///usr/include/c++/8/profile/set.h
<a name=scre></a>
### Create/Constructors
#### Default ctr
Constructs empty container
```cpp
  set<string> a;
  a.insert("dog");  a.insert("horse");  a.insert("cat");
```

#### Range ctr
Constructs the container from range `[first, last)`. If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted.
```cpp
  set<string> b(a.find("dog"), a.end());
  for(auto i: b)
    cout << i << ' ';               //dog horse
```

#### Copy ctr //Since C++11
Constructs the container with the copy of the contents of other.
```cpp
  set<string> c(a);
  c.insert("another horse");              //another horse cat dog horse
  for(auto i: c)
    cout << i << ' ';
  cout << endl;
```

#### Move ctr     //Since C++11
Constructs the container with the contents of other using move semantics.
```cpp
  set<string> d(move(a));
  for(auto i : d)
    cout << i << ' ';               //cat dog horse
  cout << endl;
  cout << "Original set:";
  for(auto i : a)
    cout << i << ' ';               //Nothing
  cout << endl;
```

#### Initializer list : Since C++11
Constructs container with contents of the initializer list.
```cpp
  set<string> e {"one", "two", "three", "five", "eight"};
  for(auto i: e)
    cout << i << ' ';
  cout << '\n';
```

<a name=sins></a>
### Insert
```cpp
/////Inserting Pair////////
  set<pair<int,int>> s;                       //Create a set of pairs
  s.insert(make_pair(x,y));                   //Insert
  
  if(s.find({x,y}) != s.end())                //FINDING pairs {}
    return true;
```
