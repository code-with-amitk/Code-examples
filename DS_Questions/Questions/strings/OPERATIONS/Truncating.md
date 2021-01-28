## Truncate
### A. erase(starting_pos, length
- Erases portion of string, reducing its length
```
  string s="Hunger for Success";
  
  s.erase(0, 7);                                      //Erase from index=0 to index=7
  cout<<s<<", size="<<s.size()<<endl;                 //for success, size=11
  
  s.erase(3, s.size()-1);                             //Erase from index=3 to end
  cout<<s<<", size="<<s.size()<<endl;                 //for, size=3
```
