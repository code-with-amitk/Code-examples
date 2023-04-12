**Longest Common Prefix**
- [Approach-1. HashMap. O(n)](#a1)
  - [Logic](#l)
  - Code
    - [CPP](#cpp)


### [14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/description/)
- Write a function to find the longest common prefix string amongst an array of strings.
- If there is no common prefix, return an empty string "".
```c
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```

<a name=a1></a>
### Approach-1. Hashmap. O(n)
#### Logic
- _1._ if any of input strings is empty, return ""
- _2._ Create a HashMap to note characters at index in all arrays
```c
Input: strs = ["flower","flow","flight"]
        key     value
        0       f,f,f
        1       l,l,l
        2       o,o,i
        3       w,w,g
        4       e,h
        5       r,t
```
- _3._ Output will contain character which happens in all arrays. That means, all characters in values should be same.
```c
  Take a unordered_set<char> and Insert all characters from HashMap's value into same.
  if set.size() == 1. Append to Output. if 2 unmatching characters found Break
  unordered_set
  f           //add to output
  l
  o,i         //break. Because we want char to happen in all arrays
  w,g
```
#### Complexity
- **Time:** O(n)
#### Code
**CPP**
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string out="";
        unordered_map<int, vector<char>> charMap;

        // Check if any of the input strings are empty
        for (const auto& str : strs) {
            if (str.empty())
                return "";
        }
        /* 
        Create a HashMap to note characters at index in all arrays
        key     value
        0       f,f,f
        1       l,l,l
        2       o,o,i
        3       w,w,g
        4       e,h
        5       r,t
        */
        for (const auto& str : strs) {
            for (int i = 0; i < str.size(); ++i) {
                charMap[i].push_back(str[i]);
            }
        }

        /*
        - Output will contain character which happens in all arrays
            - That means, all characters in values should be same.
        
        Take a unordered_set<char> and Insert all characters from value into same
        if set.size() == 1. Append to Output. if 2 unmatching characters found Break
        unordered_set
        f           //add to output
        l
        o,i         //break. Because we want char to happen in all arrays
        w,g
        */
        for (int i=0;i<charMap.size();++i){
            auto it = charMap.find(i);
            if (it->second.size() != strs.size())
                break;
            if (unordered_set<char>(it->second.begin(), it->second.end()).size() == 1) {
                out += it->second[0];
            } else {
                // If there is a mismatch in characters, ie char is not present in
                // all arrays
                break;
            }
        }
        return out;
    }
};
```
