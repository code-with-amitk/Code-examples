## stringstream
- **1. Read input from keyboard. Tokenize for " ", create string**
```c++
#include<sstream>

int main(){
  string s = "never give up";
  //OR
  //getline(cin, s);                  //Read from stdin. getline() is part of header<string> and reads space seperated input string.

  string temp_str;
  stringstream ss(s);                             //Fed string to ss constructor
  while(getline(ss, temp_str, ' ')){              //Space tokenization
    cout<<temp_str<<" ";
    temp_str=temp_str+" ";
    cout<<endl;
  }
  
  /*O/P:
  never
  give
  up */
```

## boost::tokenizer
```
Code-examples/Languages/programming_lang/c++/boost/Libraries/Tokenizer/Examples/1.string-from-stdin.md
```
