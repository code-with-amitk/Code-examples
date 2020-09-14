## Tokenize

```c++
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
  string s = "never give up";
  //OR
  //getline(cin, s);                  //Read from stdin. getline() is part of header<string> and reads space seperated input string.

  string temp_str;
  stringstream ss(s);                     //Fed string to ss constructor
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
