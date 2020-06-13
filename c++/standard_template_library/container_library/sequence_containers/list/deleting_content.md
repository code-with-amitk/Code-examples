### 1. Emptying container
> void clear() noexcept;
- Removes all elements from the list container (which are destroyed), and leaving the container with a size of 0
```c++
        list<string> dll{"one","two","three","four","five"};

        cout<<dll.size()<<endl;                           //5
        dll.clear();              
        cout<<dll.size()<<endl;                           //0
```

### 2. Removing 1 or more elements
> iterator erase (const_iterator position);
- Remove 1 element
```
  list<int> a ={1,2,3,4,5};
  list<int>::iterator it1;

  it1 = a.begin();
  a.erase(it1);
  for (auto i:a)
    cout<< i <<" ";   //2 3 4 5
```
