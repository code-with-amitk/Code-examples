**House Robber**
- [Approach-1, Recursion](#a1)
- [Approach-2, Dynamic Programming](#a2)

### [House Robber](https://leetcode.com/problems/house-robber/)
- You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed.
- The only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
- Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
```c
Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).

Example 2:
Input: nums = [2,3,4,1,9,10]
Output: 16
Explanation: 
  2,4,9 = 15
  3,1,10 = 14
  2,4,10 = 16
```

<a name=a1></a>
### Approach-1, Recursion


<a name=a2></a>
### Approach-2, Dynamic Programming
- [Why this is DP Problem](/DS_Questions/Algorithms/Dynamic_Programming#i): Maximum money

#### [DP Logic = DP Template](/DS_Questions/Algorithms/Dynamic_Programming#tem)
- _1. Define state:_ Max Money which i can loot when I am at house number=i
- _2. Function for calculating state:_ Finding recurrance relationship
  - I am at house=i
    - _Scenario-1:_ I donot rob present house. `Money I have = dp(i-1)`
    - _Scenario-2:_ I rob present house. Then I must not have robbed prev house. `Money I have = dp(i-2) + num[i]`
```c
  int dp (int i) {    //Returns money when i am at house=i
    return max (scenario_1, scenario_2)
  }
```
- _3. Base case:_ Find base case using clues in problem description or using logical thinking.
```c
  dp(0) = num[0]                  //if there is only 1 house I can rob that only
  dp(1) = max(num[0], num[1])     //if there are 2 houses, I can start with max of 2
```
- _4. Memorize/Cache/Memoization:_
