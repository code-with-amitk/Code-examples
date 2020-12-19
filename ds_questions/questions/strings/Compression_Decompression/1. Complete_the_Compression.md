## Problem
- In string each character is followed by its frequency of occurence.
- For example, the string a3c9b2c1 has two instances where ‘c’ is followed by a count: once with 9 occurrences, and again with 1. It should be compressed to a3b2c10.

## Logic
- Take count-array `a[26]` storing count of all alphabets
- Iterate over string and update count-array.
- Create string using count array

## Code
```c++
#include<iostream>
#include<sstream>
using namespace std;

string betterCompression(string s) {
  string out;
  int a[26] = {0};

  for (int i=0;i<s.size();i+=2){
    a[s[i]-'a'] += s[i+1]-'0';
  }

  stringstream ss;

  for(int i=0;i<26;++i){
    if(a[i]){
      ss << char('a' + i);
      ss << a[i];
      cout<<a[i]<<" ";
    }
  }
  cout<<ss.str()<<"\n";
  return ss.str();
}

int main(){
  string s = "a3c9b2c1";
  cout<<betterCompression(s);
}
# ./a.out
a3b2c10
```
