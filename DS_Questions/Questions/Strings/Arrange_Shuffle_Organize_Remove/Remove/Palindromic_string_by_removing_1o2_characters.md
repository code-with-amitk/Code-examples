**Create Palindromic String by removing 1 or 2 characters**

### Create Palindromic String by removing 1 or 2 characters
- Provided str parameter, determine if it is possible to create a palindromic string of minimum length 3 characters by removing 1 or 2 characters.
- Your program should return the two characters that were removed with no delimiter and in the order they appear in the string. Examples
```c
Example-1
input: "abjchba"
ouput: "jc"
Explanation: if we remove jc, string is reduced to "abhba" which is a palindrome.

Example-2:
Input: "mmop"
Output: "not possible"
Explanation: If 1 or 2 characters cannot be removed to produce a palindrome, then return the string not possible.

Example-3:
Input: "kjjjhjjj"
Output: k
Explanation: After removing 1 character "k", "jjjhjjj" becomes longest palindromic substring.
```

### Approach-1. [LCS(Longest Common Subsequence)](/DS_Questions/Questions/Strings/SubString_SubSequence/SubSeq/Longest_Common_SubSequence_in_2_strings.md)
#### Logic
- _1._ Find LCS of string and reverse of string
```c
str: "abjchba"    //len=7
revstr: "abhcjba"
LCS: "abhba"    //len=5
```
- _2._ Find difference in lenght of input string and LCS.
```c
len = input string length - length of LCS
  if (len > 2) 
    return "not possible"
  else
    return "different characters present in input array from LCS"
```
