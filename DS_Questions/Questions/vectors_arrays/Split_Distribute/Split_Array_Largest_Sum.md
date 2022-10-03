**Split Array Largest Sum**


### [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/)
- Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
- Write an algorithm to get **minimum of largest sum** or minimize the largest sum among these m subarrays.
```c
Example 1:
Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
                                          [7,2,5,10,8]
                                               |
                    ---------------------------------------------------------
                    |                |               |                     |
                |7|2,5,10,8|    |7,2|5,10,8|      |7,2,5|10,8|      |7,2,5,10|8|  << Splitting into 2 subarrays
                    7,25             14,23            14,18           24,8
  Largest sum       25                23                18              24
  Min of lar sum                                        18    <<Ans
  
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
```
