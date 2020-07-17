[Problem](https://leetcode.com/contest/weekly-contest-197/problems/number-of-substrings-with-only-1s/)

## Question
- Given a binary string s (a string consisting only of '0' and '1's).
- Return the number of CONTINIOUS substrings with all characters 1's.
- Since the answer may be too large, return it modulo 10^9 + 7.

### Example-1
```
Input: s = "0110111"
Output: 9
Explanation: There are 9 substring in total with only 1's characters.
index   substring
  1       1,11
  2       1
  4       1,11,111
  5       1,11
  6       1
        ------
          9
```

### Logic(Dynamic Programming)
- Take a dp array of same size as input string. Consider s = "0110111"

|  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4  | 5 | 6 |

- if(s[0] == 0) dp[0]=0   //else 1

| 0 |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4  | 5 | 6 |
