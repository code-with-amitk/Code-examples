**list (Doubly LL)**
- **[insert](#i)**
- **[delete, erase](#d)**


<a name=i></a>
### insert
```cpp
#include<list>
#include<iterator>

///////// list<int> ////////////
  list<int> dll;
  lst.push_front(1);
  um[key] = dll.begin();
  //um[key] = dll.end();                    //Crash
  
/////// list of pair ////////////  
  list<int, string> lst;
  lst.push_front(make_pair(1, "amit"));   //or {1, "amit"}
  um[key] = lst.begin();
  //um[key] = lst.end();                    //Crash
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
