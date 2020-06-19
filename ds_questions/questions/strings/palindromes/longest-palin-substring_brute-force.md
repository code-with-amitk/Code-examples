### Logic
  1. Loop over every substring present in main string.
    bab =loop over=>  b, ba, bab, a, ab, b
  2. Check if each substring is a palindrome.
  3. Store the starting, end index of longest palindrome.  
  
### Complexity
#### Time Complexity:  O(n<sup>3</sup>)
  1. O(n)
  2. Goes from 1 to (n-1) O(n)
  3. (Reverse O(n))
  4. Comparing  O(n)
    - Steps 3 and 4 are added hence O(n) + O(n)
####Space:  O(n)
  1. Storing reversed string
  
```
#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;

class Solution{
  unsigned len=1;
  int start=0, end=0;

  int isPalindrome(string s){
    string dup = string(s);
    reverse(dup.begin(),dup.end());   //O(n)  3
    if(s == dup)                      //O(n)  4
       return s.size();
    return 0;
  }

public:

  string lps(string s){
    int size = s.size();

    //Edge cases: Empty, size=1 string
    if (!size || size==1)
      return s;

    int now;
    for(int i=0;i<=size;i++){     //O(n)    1
      for(int j=1;j<=size-i;j++){ //O(n)    2

        if((now = isPalindrome(s.substr(i,j))) >= len){
          len = now;
          start = i;
          end = j;
        }  
        }
      }
    }
    return s.substr(start,end);
  }
};

int main(){
  //string a = "babad";       //aba
  string a = "kaaakbabdadkaak"; //kaaak
  //string a="";              //""
  //string a="a";             //a
  //string a="aa";            //aa
  //string a="ab";            //b
  Solution s;
  cout<<s.lps(a)<<"\n";
}        
```
