### 1. void clear() noexcept;
  - Removes all elements from the list container (which are destroyed), and leaving the container with a size of 0
```c++
        list<string> dll{"one","two","three","four","five"};

        cout<<dll.size()<<endl;                           //5
        dll.clear();              
        cout<<dll.size()<<endl;                           //0
```

### 2. 
