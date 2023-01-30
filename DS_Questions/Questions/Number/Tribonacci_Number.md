**N-th Tribonacci Number**
- [Approach-1, dynamic Programming](#a1)
  - [Logic](#l)
  - Code
    - [CPP](#cpp)

### [1137. N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/description/)
- The Tribonacci sequence Tn is defined as follows: 
- T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
- Given n, return the value of Tn.
```c
Example 1:
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

Example 2:
Input: n = 25
Output: 1389537
```

<a name=a1></a>
## Approach-1, Dynamic Programming
**[Why this is DP Problem?](/DS_Questions/Algorithms/Dynamic_Programming/README.md#i):** It has overlapping subproblem, optimal substructure property.
<a name=l></a>
### Logic
- _1._ Take a dp array of size=38
- _2._ Check dp array before returning from recurring function, also fill values into dp array after calculation.
### Code
<a name=cpp></a>
#### CPP
```cpp
class Solution {
public:
    int recur (int n, vector<int>& dp) {
        if (dp[n] != -1)
            return dp[n];

        dp[n] = recur(n-3, dp) + recur(n-2, dp) + recur(n-1, dp);
        return dp[n];
    }
    int tribonacci(int n) {
        vector<int> dp(38, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        return recur(n, dp);
    }
};
```
#### Rust

### Complexity
