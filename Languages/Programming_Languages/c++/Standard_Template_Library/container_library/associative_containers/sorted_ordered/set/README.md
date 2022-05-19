**Set**
- [Create](#scre)
- [Insert](#sins)
- [Implementing set](implementing_set.cpp)

## Set ///usr/include/c++/8/profile/set.h
<a name=scre></a>
### Create
```cpp
// Default ctr: Constructs empty container
  set<string> a;
  a.insert("dog");  a.insert("horse");  a.insert("cat");


// Range ctr: Constructs the container from range `[first, last)`. If multiple elements in the range 
  have keys that compare equivalent, it is unspecified which element is inserted.
  set<string> b(a.find("dog"), a.end());
  for(auto i: b)
    cout << i << ' ';               //dog horse


// Copy ctr(C++11): Constructs the container with the copy of the contents of other.
  set<string> c(a);
  c.insert("another horse");              //another horse cat dog horse
  for(auto i: c)
    cout << i << ' ';
  cout << endl;

// Move ctr(C++11): Constructs the container with the contents of other using move semantics.
  set<string> d(move(a));
  for(auto i : d)
    cout << i << ' ';               //cat dog horse
  cout << endl;
  cout << "Original set:";
  for(auto i : a)
    cout << i << ' ';               //Nothing
  cout << endl;

// Initializer list(C++11): Constructs container with contents of the initializer list.
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
