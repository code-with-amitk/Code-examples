### 1. Delete list
- **a. Empty the list**  `void clear() noexcept`
  - Removes all elements from the list container leaving the container with a size of 0
```c++
  list<string> dll {"one","two","three","four","five"};

  cout<<dll.size()<<endl;                           //5
  dll.clear();              
  cout<<dll.size()<<endl;                           //0
```

### 2. Remove elements
- **a. Remove 1 element** `iterator erase (const_iterator position);`
```c++
  list<int> a = {1,2,3,4,5};
  list<int>::iterator it;

  it = a.begin();
  a.erase(it);
  
  for (auto i:a)
    cout<< i <<" ";   //2 3 4 5
```

- **b. Remove Range:**    `iterator erase (const_iterator first, const_iterator last);`
  - Remove range of elements (first,last)
```c++
  list<int> a = {1,2,3,4,5};
  list<int>::iterator it1,it2;

  it1 = a.begin();  it1++;
  it2 = a.end();
  
  a.erase(it1,it2);
  for (auto i:a)
    cout<< i <<" ";             //1
```
