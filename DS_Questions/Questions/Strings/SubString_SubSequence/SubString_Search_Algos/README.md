### Comparison

|ALGO|Time Complexity|Space Complexity|How it works|
|---|---|---|---|
|1. NAIVE|O(mn)|1|Compare each character of needle with haystack|
|2. RABIN-KARP|<ul><li>Preprocessing: O(n)</li></ul><ul><li>Matching time: O(n*(m-n))</li></ul>|1|Calculates hash of needle & compare with haystack|
|3. KMP[BEST]|<ul><li>Preprocessing: O(n)</li></ul><ul><li>Matching:O(m)</li></ul><ul><li>Overall:O(m+n)</li></ul>|O(n)|Builds a lps(longest prefix which is also proper suffix) array using DP|
|4. Boyer Moore|<ul><li>Preprocessing: O(n+k)</li></ul><ul><li>Matching:O(k)</li></ul><ul><li>Overall: O(mn)</li></ul>|||
