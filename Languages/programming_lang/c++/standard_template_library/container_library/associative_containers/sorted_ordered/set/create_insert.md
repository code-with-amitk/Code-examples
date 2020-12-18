## A. Create
### A1. Constructors
##### 1. Default ctr
  - Constructs empty container
```c
  set<string> a;
  a.insert("dog");  a.insert("horse");  a.insert("cat");
```

#### 2. Range ctr
  - Constructs the container from range `[first, last)`. 
  - If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted.
```c
  set<string> b(a.find("dog"), a.end());
  for(auto i: b)
    cout << i << ' ';               //dog horse
```

#### 3. Copy ctr: Since C++11
  - Constructs the container with the copy of the contents of other.
```c
  set<string> c(a);
  c.insert("another horse");              //another horse cat dog horse
  for(auto i: c)
    cout << i << ' ';
  cout << endl;
```

#### 4. Move ctr: Since C++11
  - Constructs the container with the contents of other using move semantics.
```c
  set<string> d(move(a));
  for(auto i : d)
    cout << i << ' ';               //cat dog horse
  cout << endl;
  cout << "Original set:";
  for(auto i : a)
    cout << i << ' ';               //Nothing
  cout << endl;
```

#### 5. Initializer list : Since C++11
  - Constructs the container with the contents of the initializer list init. 
  - if multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted
```c
  set<string> e {"one", "two", "three", "five", "eight"};
  for(auto i: e)
    cout << i << ' ';
  cout << '\n';
```                                         

## B. Insert
  - Inserting elements to set.
### B1. Pair
```
  set<pair<int,int>> s;                       //Create a set of pairs
  
  s.insert(make_pair(x,y));                   //Insert
  
  if(s.find({x,y}) != s.end()){               //FINDING pairs {}
    return true;
  }else{
    s.insert(make_pair(x,y));
  }  
```
