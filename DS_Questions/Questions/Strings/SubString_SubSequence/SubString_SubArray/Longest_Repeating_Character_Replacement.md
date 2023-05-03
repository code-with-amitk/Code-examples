**Always Take 1 example of your own. In question, delibrately they donot provide all cases**

**Longest Repeating Character Replacement**

### [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/description/)
- You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
- Return the length of the longest substring containing the same letter you can get after performing the above operations.
```c
Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

Example 3:
Input: s = "AABACBA", k = 1
Output: 4
Explanation: Replace the one 'B' in the middle with 'A' and form "AAAACBA".
The substring "AAAA" has the longest repeating letters, which is 4.
```

### Approach-1. Naive. Brute Force. O(n<sup>2</sup>)
1. Take all substrings. O(n<sup>2</sup>)
```c
"A A B A C B A"
 0 1 2 3 4 5 6
 
All substring
 Fixing A(index=0):  A, AA, AAB, AABA, AABAC, AABACB, AABACBA,
 Fixing A(index=1):  A, AB, ABA, ABAC, ABACB, ABACBA
 Fixing B(index=2):  B, BA, BAC, BACB, BACBA
 Fixing A(index=3):  A, AC, ACB, ACBA
 Fixing C(index=4):  C, CB, CBA
 ..
```
2. For every substring find _longest substring without repeating character._
```c
substring   longest_substr_without_repeating_char (k=1 replacement allowed)
    A         1
    AA        2
    AAB       3 (AAB=AAA)
    AABA      4 (AABA=AAAA)
    AABAC     Not allowed. Freq(A=3,B=1,C=1). With k=1, We can only replace B or C
    
    A         1
    AB        2
    ABA       3
    ABAC      Not allowed. Freq(A=2,B=1,C=1). With k=1, We can only replace B or C
```
