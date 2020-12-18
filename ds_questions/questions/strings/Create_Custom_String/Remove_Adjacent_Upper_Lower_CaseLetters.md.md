### [Make The String Great](https://leetcode.com/contest/weekly-contest-201/problems/make-the-string-great/)

- Delete adjacent lower and upper case alphabets from string.
- Examples
```c
Example-1
Input: s = "leEeetcode"
Output: "leetcode"    //Delete adjacent E and e

Example-2:
Input: s = "abBAcC"
Output: ""            //Delete bB -> aAcc -> Delete aA -> cC -> Delete cC -> ""

Example-3:
Input: s = "Hvh"
Output: "Hvh"
```

### Logic
- Take out string. Iterate through alphabets of input string.
- if two adjacent characters are same and either (upper and lower) or (lower and upper). remove them.
- Before inserting element into string `out` check whether current character is same as prev, if yes then lower or upper if yes, remove the last element also.

### Code
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
