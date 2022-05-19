**Map**
- **Inserting element**
  - [insert()](#mins)
  - [emplace()](#emp)
- [erase](#merase)
- [Multidimentional Maps](#mdm)





## Map<key, value>
- All elements are always sorted means All elements are in order(ascending/descending). Some operations does not make sense Eg: push_back(), push_front().

### Insert
<a name=mins></a>
#### insert()
For inserting element into stl. Creates object somewhere else, copies objects into the vector
```cpp
<iterator, bool> insert(const val_type& val)
map<char, int> m;
m.insert(make_pair('a', 1));
```
<a name=emp></a>
#### emplace()
Same, used for inserting elements into stl. But constructs elements inside the stl only. Does in place insertion, avoids unneccessary copy.
```cpp  
<iterator,bool> emplace(Args&.. args)   //Preferred over insert()
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

<a name=mdm></a>
## Multidimentional Maps
Map inside map
```cpp   
map<int, map<string, string>>
```
