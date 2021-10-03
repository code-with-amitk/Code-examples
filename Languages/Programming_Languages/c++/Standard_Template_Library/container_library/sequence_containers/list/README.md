list (Doubly LL)
- **[insert](#i)**
- **[delete, erase](#d)**


<a name=i></a>
### insert
```cpp
  iterator insert (const_iterator position, const value_type& val)

  list<string> dll;

  dll.insert(dll.begin(),"hi");              //insert at begin
  dll.insert(dll.end(),"there");             //insert at end
  
  list<string> temp{"Hello", "I", "Great"};  
  list<string>::iterator it = temp.begin();
  dll.insert (dll, it.begin(), it.end());
```

<a name=d></a>
### Delete
```cpp
  list<int> l{1,2,3,4};
  list<int>::iterator it = l.begin();
  l.erase (it);                           //Erase 1 element. 1st element erased here
  l.erase (it1, it2);                     //Delete elements from within the range
  dll.clear();                            //Removes all elements, leaving size=0
  
```
