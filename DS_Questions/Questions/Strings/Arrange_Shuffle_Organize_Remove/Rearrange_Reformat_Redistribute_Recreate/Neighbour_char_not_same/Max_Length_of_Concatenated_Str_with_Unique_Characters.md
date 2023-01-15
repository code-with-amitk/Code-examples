Maximum Length of a Concatenated String with Unique Characters

### [1239. Maximum Length of a Concatenated String with Unique Characters](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/)
- You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
- Return the maximum possible length of s.
- A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
- **Condition1:** skip all strings having repetative characters
```c
Example 1:
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

Example 2:
Input: arr=["aa", "bc"]
Output: 2
Explanation: skip "aa" string since it has repetative characters
```
