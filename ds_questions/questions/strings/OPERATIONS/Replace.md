## Replacing
### A. string.replace(position, length, string-to-replace-with)
-  Replace a character in string with some other character
```
//REPLACE: replace "." with "[.]"

  string s = "1.1.1.1";
  for(auto i=0;i<s.size();i++){
    if(s[i]=='.'){
      s.replace(i,1,"[.]");
        i=i+3;
    }
  }
  
  cout<<s<<endl;                                        //1[.]1[.]1[.]1
```
