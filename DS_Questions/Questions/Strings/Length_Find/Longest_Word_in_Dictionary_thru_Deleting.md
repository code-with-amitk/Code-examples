**[Longest Word in Dictionary through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/)**
- [Question](#q)

<a name=q></a>
### Question
- Given a string s and string of words called dictionary. Delete some letters from input string match formed word in dictionary & return longest word in the dictionary.
- If more than one possible result, return the longest word with the smallest [lexicographical](/DS_Questions/Questions/Strings/Lexicographical) order. If there is no possible result, return the empty string.
```c
Example 1:
Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"
  
Example 2:
Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"
```

### Approach-1
#### Logic
- Find all words which can be formed by deleting the letter/letters(using recursion), store in unordered_set. Match dictionary words with unordered_set.
```c
string = abpc, dictionary=["ap"]

apc, abc, abp   //Fix a, Delete 1 letter.
bpc, abc, abp   //Fix b, Delete 1 letter.
bpc, apc, abc   //Fix p, Delete 1 letter.
bpc, apc, abc   //Fix c, Delete 1 letter.

ab, ap, ac   //Fix a, Delete 2 letter.
bc, ab, bp   //Fix b, Delete 2 letter.
..
  
a   //Fix a, Delete 3 letter.
...
```
