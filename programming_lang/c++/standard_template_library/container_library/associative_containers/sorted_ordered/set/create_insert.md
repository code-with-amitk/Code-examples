## A. CREATE
### A1. CONSTRUCTORS
##### 1. DEFAULT CTR
  - Constructs empty container
  - ***Syntax***
    - explicit set( const Allocator& alloc );
```  
  set<string> a;
  for(auto i:a)
    cout<<i;                //Nothing printed
  cout<<endl;
  a.insert("cat");
  a.insert("dog");
  a.insert("horse");
  for(auto i:a)
    cout<<i<<" ";           //cat dog horse
```

#### 2. RANGE CTR
  - Constructs the container from range [first, last). 
  - If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted.
  - Internally                                         
```
  template< typename T >
  set( T first, T last, const Allocator& alloc) : 
  set(first, last, Compare(), alloc) {}    
```
  - Example
```
  set<string> b(a.find("dog"), a.end());
  for(auto i: b)
    cout << i << ' ';               //dog horse
```

#### 3. COPY CTR: Since C++11
  - Constructs the container with the copy of the contents of other.
  - Internally: set( const set& other, const Allocator& alloc );
```
  explicit set(const _Allocator& __a) : _Base(__a) { }
```
  - EXAMPLE
```
  set<string> c(a);
  c.insert("another horse");              //another horse cat dog horse
  for(auto i: c)
    cout << i << ' ';
  cout << endl;
```

#### 4. MOVE CTR: Since C++11
  - Constructs the container with the contents of other using move semantics.
  - Internally
```
  set( set&& other );                            //Since C++11
  set( set&& other, const Allocator& alloc );    //Since C++11
  
  set(set&& __x, const _Allocator& __a)
  noexcept( noexcept(_Base(std::move(__x), __a)) )
  : _Base(std::move(__x), __a) { }
```
  - Example
```
  set<string> d(move(a));
  for(auto i : d)
    cout << i << ' ';               //cat dog horse
  cout << endl;
  cout << "Original set:";
  for(auto i : a)
    cout << i << ' ';               //Nothing
  cout << endl;
```

#### 5. INITIALIZER LIST CTR: Since C++11
  - Constructs the container with the contents of the initializer list init. 
  - if multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted
  - Internally 
```
        set( initializer_list<value_type> init, const Compare& comp = Compare(),
        const Allocator& alloc = Allocator() );
        /////////INITIALIZER LIST CTR////////
        set(initializer_list<value_type> __l, const _Allocator& __a)
        : _Base(__l, __a) { }
```
  - Example
```  
  set<string> e {"one", "two", "three", "five", "eight"};
  for(auto i: e)
    cout << i << ' ';
  cout << '\n';
```                                         
