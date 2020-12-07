## [Longest Prefix which is also Suffix](https://leetcode.com/problems/longest-happy-prefix/)
- **Prefix?** Substrings taken from `index[0]`, exculding the complete string.
- **Suffix?** Substrings taken from last index, exculding the complete string.
- Examples
```c++
Example-1:
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

## [Logic](https://www.youtube.com/watch?v=GTJr8OvyEVQ)
- *1.* Build LPS(Longest prefix which is also suffix) array containing information of prefix and suffix. This array is build from pattern which is to be searched inside main string.
```c++
Example:
  Pattern         LPS array
  a b a b a b =>  0 0 1 2 3 4

Explanation of LPS Array:
Index   Value   Meaning
0       0       0 Because in array [0,0] there is no prefix and suffix since suffix,prefix need to exclude compelte string
1       0       There is no prefix which is also suffix in subarray[0,1]
2       1       Length of longest prefix which is also suffix in subarray[0..2] is 1. aba (ie a)
3       2       Length of longest prefix which is also suffix in subarray[0..3] is 2. abab (ie ab)
4       3       Length of longest prefix which is also suffix in subarray[0..4] is 3. ababa (ie aba)
5       4       Length of longest prefix which is also suffix in subarray[0..5] is 4. ababab (ie abab)
```

- *1a.* Build the LPSArray(very simple)
```c++        
 - LPSArray[0] = 0 //reason above
 - take 2 pointers, i=0,j=1. 
 - loop until j reaches end
   if(s[i] == s[j])
     LPSArray[j] = i+1;
     Make i an j to point to next position
   if(s[i] != s[j])
     if( i != 0)
       Point i to Value of (i-1) from LPSArray
     else
       Make current LPSArray[j] = 0;

 - You can see simply and understand it
 ```

- *2.* Complexity:
  - Time: O(n)      //n-Length of input string
  - Space: O(n)     //Same lengthed temporary InfoArray

## Code
```c++
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution{
public:
  string longestPrefix(string s) {
    vector<int> LPSArray(s.size(),0);
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
