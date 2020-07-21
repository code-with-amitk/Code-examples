- **Anagrams?** This is a word or phrase formed by rearranging the letters of a different word or phrase.

## Problem
- Given a string, remove each string ie anagram of earlier string. Return remanining array in sorted order.

## Example:
```
str = [`code`, `doce`, `ecod`, `framer`, `frame`]
```
- `code` & `doce` are anagrams. Remove `doce`, keep 1st
- `code` & `ecod` are anagrams. Remove `ecod`, keep 1st
- `code` & `framer` are not anagrams. Keep both
- `framer` & `frame` are not anagrams. keep both.
- Output:
  - [`code`, `frame`, `framer`]
  
  Solution:
  https://www.geeksforgeeks.org/removing-string-that-is-an-anagram-of-an-earlier-string/
