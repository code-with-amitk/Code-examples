## [Leet-code-3](https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/)
- Given a string s, find the length of the longest substring without repeating characters.
- Examples
```c
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

### Logic
- Insert unique characters in unordered_set starting at index=i
- Once a repeating character is found, Delete complete stack
  - Start insert from index=i+1

### Code
```c++
class Solution {
public:
  void insertUnique(char i){
    us.insert(i);
    if (us.size() > max)
      max = us.size();
  }

  int lengthOfLongestSubstring(string s) {
    uint32_t size = s.size(),i,j;
    i=j=0;

    while (i <size) {
      j = i;
      while (j<size) {
        if (us.find(s[j]) == us.end()) {
          insertUnique(s[j]);
        }else{
          us.clear();
          break;
        }
        ++j;
      }
      ++i;
    }

    return max;
  }
private:
  unordered_set<char> us;
  int max = 0;
};
```
