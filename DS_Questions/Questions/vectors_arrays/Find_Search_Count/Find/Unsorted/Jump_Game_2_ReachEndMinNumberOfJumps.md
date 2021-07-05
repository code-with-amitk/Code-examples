- [Problem](#prob)
- [Approach-1(BackTracking, Brute Force)](#apr1)
- [Approach-2(Greedy)](#apr2)


<a name=prob></a>
## [Jump Game 2 / Jump Game II / Reach end in Minimum No of Jumps](https://leetcode.com/problems/jump-game-ii/)
- Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
- Each element in the array represents your maximum jump length at that position. Your goal is to reach the last index in the minimum number of jumps.
- You can assume that you can always reach the last index.
- Examples
```c
Example-1
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2
```

<a name=apr1></a>
## Approach-1 / Backtracking / BF / O(2<sup>n</sup>)
- Exhaustively test all possible jumps from start to end.
- [Jump-Game-1](/DS_Questions/Questions/vectors_arrays/Find_Search_Count/Find/Unsorted/Jump_Game_1.md)

<a name=apr2></a>
## Approach-2 / Greedy / O(n)
- [What is Greedy Approach](/DS_Questions/Algorithms/Greedy)
- **Logic**
  - _1._ Always always picks the largest subarray, but also check how can we reach by choosing larger subarray.
  - _2._ Initialize three integer variables
    - jumps to count the number of jumps
    - currentJumpEnd to mark the end of the range that we can jump to
    - farthest to mark the farthest place that we can reach. Set each variable to zero.
  - _3._ Iterate over input. Note that we exclude the last element from our iteration because as soon as we reach the last element, we do not need to jump anymore.
    - Update farthest to `i + nums[i]` if the latter is larger.
    - If we reach currentJumpEnd, it means we finished the current jump, and can begin checking the next jump by setting currentJumpEnd = farthest.
- **Complexity**
  - Time: O(n). Traversed once
  - Space: O(1)
- **Code**
```c
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, currentJumpEnd = 0, farthest = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
        
            // we continuously find the how far we can reach in the current jump
            farthest = max(farthest, i + nums[i]);
            
            // if we have come to the end of the current jump,
            // we need to make another jump
            if (i == currentJumpEnd) {
                jumps++;
                currentJumpEnd = farthest;
            }
        }
        return jumps;
    }
}
```
