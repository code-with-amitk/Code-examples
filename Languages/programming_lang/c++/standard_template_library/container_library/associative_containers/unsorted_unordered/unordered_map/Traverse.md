### Traverse/Iterating unordered_map
- **1. for (auto)**
```c++
{
  unordered_map<int, string> um;
  um[1] = "gpu1";
  um[2] = "gpu2";
  
  for (auto i : um) 
    cout << i.first << "   " << i.second << endl;
}    
 
O/p:            //May come in any order
2 gpu2
1 gpu1
```

- **2. begin(),end()**
```c++
  for (auto i=um.begin(); i!=um.end(); ++i) {
    cout<<i->first<<" "<<i->second<<"\n";
  }
  
O/p:
2 gpu2
1 gpu1  
```

- **3. ::iterator**
```c++
  unordered_map<int,string>::iterator i;

  for ( i=um.begin(); i!=um.end(); ++i) {
    cout<<i->first<<" "<<i->second<<"\n";
  }
  
O/p:
2 gpu2
1 gpu1  
```  
