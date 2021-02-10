## [Word Break](https://leetcode.com/problems/word-break/)
- Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
- The same word in the dictionary may be reused multiple times in the segmentation. Dictionary does not contain duplicate words.
- **Examples**
```c
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true    //Explanation: Return true because "leetcode" can be segmented as "leet code".

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true    //Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

Input: s = "aaaaaaa", wordDict = ["aaaa", "aaa"]
Output: true

Input: s = "testyourgutson", wordDict = ["t", "te", "test", "your", "guts", "son", "gut"]
Output: true
```

## Understanding the problem
> s = "testyourgutson", wordDict = ["t", "te", "test", "your", "guts", "son", "gut"]
- *1.* We need to start matching every single character in dictionary
```c
t: match. Move to e
e: no match

te: match
s: no match

tes: no match

test:match
y:no match


```
