## [Minimum number of jumps to reach end / Selecting Ladder to reach end](https://leetcode.com/problems/jump-game/)
- Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
- Each element in the array represents **maximum jump/ladder length** from that position, we can choose smaller jump from that position also.
- Determine if you are able to reach the last index.
- **Examples**
```c
Input: nums = [2,3,1,1,4]
Output: true
Explanation: jump 1 -> 3(end)  
            index 0    1          
//Jump 1 step from index 0 to 1, then 3 steps to the last index.
  
Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
```

### Approach-1  //[Backtracking](/DS_Questions/Algorithms)


 
