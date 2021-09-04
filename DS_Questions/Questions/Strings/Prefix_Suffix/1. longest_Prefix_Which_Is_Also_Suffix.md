**[Longest Happy Prefix](https://leetcode.com/problems/longest-happy-prefix/)**
- [What is Prefix, Suffix?](#ps)
- [Logic](#l)


<a name=ps></a>
### What is Prefix, Suffix
- **Prefix?** Substrings taken from `index[0]`, excluding the complete string.
- **Suffix?** Substrings taken from last index, excluding the complete string.
Examples
```c
Ex-1:
s = "level". 
  - 4 prefixes ("l", "le", "lev", "leve")    //s contains 4 prefix excluding itself
  - 4 suffixes ("l", "el", "vel", "evel"). 
  - The longest prefix which is also suffix is given by "l".

Example-2:
s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.

Example-3:
s = "leetcodeleet"
Output: "leet"

Example-4:
Input: s = "a"
Output: ""
```

<a name=l></a>
### [Logic](https://www.youtube.com/watch?v=GTJr8OvyEVQ)
#### Step-1. Build LPSArray(Longest prefix which is also suffix)
- **1a. LPSArray?** Each entry means what's length of longest prefix which is also suffix in substring `[0, presentIndex]`
```c++
Example:
    String               LPS array
  a b a b c a b d =>  0 0 1 2 0 1 2 0

Explanation of LPS Array:
Index   Value   Meaning
0       0       0 Because in array [0,0] there is no prefix and suffix since suffix,prefix need to exclude compelte string
1       0       There is no prefix which is also suffix in subarray[0,1]
2       1       Length of longest prefix which is also suffix in subarray[0..2] is 1. aba (ie a)
3       2       Length of longest prefix which is also suffix in subarray[0..3] is 2. abab (ie ab)
4       0       There is no prefix which is also suffix in subarray[0..4]  ababc
5       1       Length of longest prefix which is also suffix in subarray[0..5] is 1. ababca (ie a)
6       2       Length of longest prefix which is also suffix in subarray[0..6] is 2. ababcab (ie ab)
7       0       Length of longest prefix which is also suffix in subarray[0..7] is 0. ababcabd
```

- *1b.* Build the LPSArray(very simple)
```c++
 - Take LPSArray of same size as string. Initialize to 0 assuming there are no Prefix which matches suffix.
 - LPSArray[0] = 0   //reason above
 - take 2 pointers, i=0,j=1. We will check all substrings using i,j
   - j represents substring from [0, j]
 - loop until j reaches end
   if(s[i] == s[j])                      //Found prefix which is also suffix
     LPSArray[j] = i+1;
     Point i,j to next position. ++i;++j
   else
     if (i == 0)
       Check next substring. j++
     else
       point i to lps[i-1]

 - You can see simply and understand it
 ```

#### Step-2: return substring

- **Complexity**
  - Time: O(n)      //n-Length of input string
  - Space: O(n)     //Same lengthed temporary InfoArray

### Code
```c++
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution{
public:
  void GetLPSArray(string& s, vector<int>& LPSArray){
    for(int i = 0, j = 1; j < s.size();){
      if(s[j] == s[i]){
        LPSArray[j] = i + 1;
        i++; j++;
      }else{
         if(i == 0)
           j++;
         else
           i = LPSArray[i - 1];
      }
    }//for
  }

  string longestPrefix(string s) {
    vector<int> LPSArray(s.size(),0);
    GetLPSArray(s, LPSArray);                   //Step-1

    return s.substr(0, LPSArray[s.size() - 1]);
  }
};

int main(){
  Solution obj;
  string s = "leetcodeleet";
  cout<<obj.longestPrefix(s);
}
#./a.out
leet
```
