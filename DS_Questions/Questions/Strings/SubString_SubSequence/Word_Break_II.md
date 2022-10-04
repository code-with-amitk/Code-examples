**Word Break II**
- [Approach-1, Naive. Greater than O(n<sup>n</sup>)](#a1)

### Word Break II
- Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. 
- Return **all such possible sentences** in any order.
- Note that the same word in the dictionary may be reused multiple times in the segmentation.
```c
Example 1:
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

Example 2:
Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "abcdefg", wordDict = ["a", "bc", "d", "ef", "de", "f", "fg", "ab", "abc", "g", "c" , "cd"]
Output = ["a bc d ef g", "ab c d ef g", ...]
```

<a name=a1></a>
### Approach-1, BF (Greater than O(n<sup>n</sup>))
#### Logic
- _1._ Take substring from 1st character and search in dict.
```c
Input: s = "abcdefg", wordDict = ["a", "bc", "d", "ef", "de", "f", "fg", "ab", "abc", "g", "c" , "cd"]
substr = a  //Found in dict
```
- _2._ Search next letter in dict ie b
```c
substr = b  //Found in dict
```
- _3._ As soon all letters are found, Create substring of 2 characters and continue step-2(ie searching)
```c
substring = ab
```
#### Complexity
- **Time:** O(n<sup>n</sup>) n=words.
