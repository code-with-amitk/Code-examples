**House Robber**
- [Approach-1, Recursion](#a1)
- [Approach-2, Dynamic Programming](#a2)
  - [Logic](#l)
  - Code
    - [CPP Top Down Approach](#cpptd)

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
- _4. Memorize/Cache/Memoization:_ Remember the Money looted from prev houses to find max money that can be looted from present house.

### Code
<a name=cpp></a>
#### CPP Top Down Approach
[What is Top Down](/DS_Questions/Algorithms/Dynamic_Programming/README.md#td)
```cpp
class Solution {
    vector<int> vecMoney;
public:
    
    //state: Max money which I can loot when i am at house=i
    int dp(int i, vector<int>& nums, vector<int>& vecMoney) {
        int ret = -1;
        if (i==0)
            ret = vecMoney[0];
        if (i==1)
            ret = vecMoney[1];
        
        if (vecMoney[i] == -1)
            vecMoney[i] = max ((nums[i] + dp(i-2, nums, vecMoney)), dp(i-1, nums, vecMoney));
        else
            ret = vecMoney[i];

        return ret;
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        //Aim: to fill vecMoney
        //Ans: Last element of vecMoney
        vector<int> vecMoney(nums.size(), -1);
        vecMoney[0] = nums[0];
        vecMoney[1] = max(nums[0],nums[1]);
        
        int _ret;
        for (int i = 2; i<nums.size(); ++i)
            _ret = dp (i, nums, vecMoney);
        
        return vecMoney.back();
    }
};
```

### Complexity
#### Time
O(n)
#### Space
O(n) = Taking vecMoney equal to input size, which stores the max looted money till present house.
