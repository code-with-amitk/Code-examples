:toc:
:toclevels: 6

== link:https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/[1155. Number of Dice Rolls With Target Sum]
You have n dice, and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

Example 1:
```
Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.

Example 2:
Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

Example 3:
Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.
```

== Approach-1. Dynamic Programming.
=== Why DP
it involves breaking down the problem into smaller subproblems (number of ways to get a certain sum with a certain number of dice) and building up the solution using previously calculated subproblems.

=== Logic
* We use a 2D array dp where dp[i][j] represents the number of ways to get sum j using i dice.
* The base case is dp[0][0] = 1 because there is one way to get a sum of 0 with 0 dice.
* We iterate through the number of dice (i), the target sum (j), and the possible outcomes of the current die roll (k).
* The formula dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD represents the recursive relation. We accumulate the ways to get the current sum j by considering the outcomes of the previous dice rolls.
* The final result is stored in dp[d][target], which represents the number of ways to get the target sum using all d dice.

=== Complexity
=== Code
==== CPP
```cpp
class Solution {
public:
    //d=dice, f=faces
    int numRollsToTarget(int d, int f, int target) {
       const int MOD = 1000000007;

        // dp[i][j] represents the number of ways to get sum j using i dice
        std::vector<std::vector<int>> dp(d + 1, std::vector<int>(target + 1, 0));

        // Base case: there is one way to get sum 0 with 0 dice
        dp[0][0] = 1;

        for (int i = 1; i <= d; ++i) {
            for (int j = 1; j <= target; ++j) {
                // Roll the current die (from 1 to f)
                for (int k = 1; k <= f && k <= j; ++k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
                }
            }
        }
        return dp[d][target];
    }
};
```
