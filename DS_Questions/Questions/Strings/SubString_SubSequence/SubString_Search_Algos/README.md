### Comparison
```c
haystack = "testmanman" //len=n
needle = "man"          //len=m

  Algorithm   |     Time Complexity       | Space Complexity | How it works
--------------|---------------------------|------------------|---------------
1. Naive/BF   |     O(mn)                 |   O(1)           | Compare each character of needle with haystack
2. Rabin Karp | Preprocessing: O(n)       |   O(1)           | Calculates hash of needle & compare with haystack
                Matching time: O(n*(m-n))
3. KMP[Best]  | Preprocessing: O(n)       | O(n)             | Builds a lps(longest prefix which
                Matching:O(m)                                  is also proper suffix) array using DP
                Overall:O(m+n)
4. Boyer Moore | Preprocessing: O(n+k)
                 Matching:O(k)
                 Overall: O(mn)
```
