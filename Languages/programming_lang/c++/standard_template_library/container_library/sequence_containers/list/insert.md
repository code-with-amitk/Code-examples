## insert()
### 1. iterator insert (const_iterator position, const value_type& val)    //Insert single element
```c++
  list<string> dll{"one","two","three"};
  list<string>::iterator it;
  
  it = dll.begin(); it++;
  dll.insert(it,"test");

  //Insert at end. dll.end() returns end iterator
  dll.insert(dll.end(),"four");
  for(auto i:dll)
    cout<<i<<" ";*              //one test two three four
```

### 2. iterator insert (const_iterator position, size_type n, const value_type& val)   //insert multiple elements
```c++
  list<int> dll{1,5,6,7};
  list<int>::iterator it = dll.begin();
  it++;

  list<int> temp{2,3,4};
  dll.insert(it,temp.begin(),temp.end());
  for(auto i:dll)
    cout<<i<<" ";         //1 2 3 4 5 6 7
```
