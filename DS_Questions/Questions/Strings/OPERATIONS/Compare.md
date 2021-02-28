## Comparing
### A. int string::compare (const string& str) const
- Returns:        
  - 0: if both strings are equal.
  - value< 0 : if *this is shorter than str or,first character that doesn't match is smaller than str.
  - value > 0 : if *this is longer than str or,first character that doesn't match is greater
```
  string s = "ABC";
  string pat = "ABC";
  
  if(!s.compare(pat)){
    cout<<"Equal";
  }else{
    cout<<"Not equal";
  }
```
