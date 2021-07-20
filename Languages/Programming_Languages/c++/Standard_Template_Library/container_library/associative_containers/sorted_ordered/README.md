- Map
  - [1. insert](#mins)
  - [2. erase](#merase)
- Set
  - [1. Create / Constructors](#scre)
  - [2. Insert](#sins)



## Map<key, value>
- All elements are always sorted means All elements are in order(ascending/descending). 
- Some operations does not make sense Eg: push_back(), push_front().

<a name=mins></a>
### 1. insert
- **insert()**
  - Used for inserting element into stl. Creates object somewhere else, copies objects into the vector
- **emplace()** //Preferred over insert()
  - same, used for inserting elements into stl. But constructs elements inside the vector only.
  - *Adv:* Does in place insertion, avoids unneccessary copy

#### insert()
```cpp
pair<iterator,bool> insert (const value_type& val);
template <class P> pair<iterator,bool> insert (P&& val);

map< char, int > m;
m.insert(make_pair('a', 1));
```
#### emplace
```cpp
template <class... Args>
  pair<iterator,bool> emplace (Args&&... args);
  
m.emplace('b', 2);

for (auto i:m)
  cout << i;                    //a 1   b 2
```

<a name=merase></a>
### `2. erase(const key_type& k)`
- Finding key and erase.
```cpp
template < typename K, typename V >
class mymap {
  std::map < K, V > m;
public:
  void assign ( K const& key, V const& value ) {
    m.insert ( std::pair <K, V> (key, value) );
  }
  
  void find ( K key ) {
    if ( (m.find (key)) != m.end() )   //key found
      m.erase (key);
  }
  
};

int main() {
  std::map <
}
```

## Set ///usr/include/c++/8/profile/set.h
<a name=scre></a>
### 1. Create/Constructors
#### a. Default ctr
  - Constructs empty container
```cpp
  set<string> a;
  a.insert("dog");  a.insert("horse");  a.insert("cat");
```

#### b. Range ctr
- Constructs the container from range `[first, last)`. 
- If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted.
```cpp
  set<string> b(a.find("dog"), a.end());
  for(auto i: b)
    cout << i << ' ';               //dog horse
```

#### c. Copy ctr: Since C++11
- Constructs the container with the copy of the contents of other.
```cpp
  set<string> c(a);
  c.insert("another horse");              //another horse cat dog horse
  for(auto i: c)
    cout << i << ' ';
  cout << endl;
```

#### d. Move ctr: Since C++11
- Constructs the container with the contents of other using move semantics.
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

#### e. Initializer list : Since C++11
- Constructs the container with the contents of the initializer list init. 
- if multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted
```cpp
  set<string> e {"one", "two", "three", "five", "eight"};
  for(auto i: e)
    cout << i << ' ';
  cout << '\n';
```

<a name=sins></a>
### 2. Insert
- **Inserting Pair**
```cpp
  set<pair<int,int>> s;                       //Create a set of pairs
  s.insert(make_pair(x,y));                   //Insert
  
  if(s.find({x,y}) != s.end())                //FINDING pairs {}
    return true;
```
