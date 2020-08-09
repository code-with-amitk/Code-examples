## [Make The String Great](https://leetcode.com/contest/weekly-contest-201/problems/make-the-string-great/)

- Given a string s of lower and upper case English letters.
- A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
  - s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
- To make the string good, remove both lower and upper case. keep doing this until the string becomes good.

- Example 1:
```
Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
```
- Example 2:
```
Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""
```
-Example 3:
```
Input: s = "Hvh"
Output: "Hvh"
````
- Example-4:
```
Input= "RLlr"
Ouput=""
```
## Logic
- Take a string s1 to be build.
- Iterate through alphabets of incoming string.
- if two adjacent characters are same and either (upper and lower) or (lower and upper). remove them.
- Before inserting element into string `s1` check whether current character is same as prev, if yes then lower or upper if yes, remove the last element also.
## Code
```
  string makeGood(string s) {
    string s1;
    int size = s.size();
    
    if(!size)
      return "";

    for(int i=0;i<size; i++){

      if(i<size-1){
        if(
          ((islower(s[i]) && isupper(s[i+1])) && (s[i] == tolower(s[i+1]))) ||
          ((isupper(s[i]) && islower(s[i+1])) && (s[i+1] == tolower(s[i])))){
          i += 1;
          continue;
        }
      }

      //Check if prev element is not same as mine before pushing
      if(s1.empty() != 1){
        if(
          (isupper(s[i]) && (s1.back() == tolower(s[i]))) ||
          (islower(s[i]) && (s1.back() == toupper(s[i])))
          ){
          s1.pop_back();
          continue;
        }
      }
      s1.push_back(s[i]);
    }

    return s1;
  }
```
