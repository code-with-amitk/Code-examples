### [Problem](https://www.glassdoor.co.in/Interview/All-questions-are-mentions-in-the-review-and-practice-following-coding-questions-for-sure-on-leetcode-QTN_3960971.htm)
- Reverse a part of a vector, anonymize email addresses
- Example
```c++
 Input vector<string> v = {"test", "your", "ken", "everyday", "amit@gmail.com", 
 "Build your character", "Because", "vivek@yahoo.com", "Character", "is", "only", "thing", "for", "anil@times.com", "success"};
 
 output: Reverse 1st 5 words. Anonamize email addresses.
 Build your character amit@zrec.com everyday ken your test Because vivek@foxu.com Character is only thing for anil@wclk.com success
```

## Approach
### Logic
- Reverse 1st 5 words of vector //O(n)
- Traverse remaining vector, anomamize inplace using random number generator.
### Complexity  //O(2n+m)
- O(n) Total characters in vector to be reversed=n.
- m: Total characters in complete vector.
### Code
```c++
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using StringVector = std::vector<std::string>;
using StringVectorItr = std::vector<std::string>::iterator;
using String = std::string;

#define REVERSE 5 //Reverse 1st 5 words

void GenerateRandom(String& strRandom, int len) {
  int i=0;
  char ch='a';
  while (i < len){
    strRandom += ch+std::rand()%26;
    ++i;
  }
}

int main(){
  std::srand(time(0));
  StringVector v = {"test", "your", "ken", "everyday", "amit@gmail.com", "Build your character", "Because", "vivek@yahoo.com", 
  "Character", "is", "only", "thing", "for", "anil@times.com", "success"};
  StringVectorItr itr = v.begin();
  std::reverse(itr, (itr+REVERSE+1));

  String strRandom;
  int j, len, index=0;

  for (auto& i:v){
    j = len = index = 0;
    strRandom.clear();
    while (j<i.size()) {
      if (i[j] == '@'){
        if(len==0)
          index = j;
      }
      if (i[j] == '.'){
        GenerateRandom(strRandom, len-2);
        i.replace(index+1, len-1, strRandom);
        break;
      }
      if(index)
        ++len;
      ++j;
    }
  }
  for (auto i:v)
    std::cout<<i<<" ";
}
```
