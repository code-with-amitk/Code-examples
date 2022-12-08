**Jump Game 2**
- [Approach-1. BackTracking. TLE. O(2<sup>n</sup>)](#a1)
- [Approach-2. Greedy](#a2)


<a name=prob></a>
### [Jump Game 2 / Jump Game II / Reach end in Minimum No of Jumps](https://leetcode.com/problems/jump-game-ii/)
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

<a name=a1></a>
### Approach-1. Backtracking. TLE. O(2<sup>n</sup>)
- [Backtracking Template](/DS_Questions/Algorithms)
- _Why Backtracking?_ We need to find all ways/combinations to reach end.
- Exhaustively test all possible jumps from start to end.
```c
Backtrack Tree
a = 2  3  1  1  4
    0  1  2  3  4  
                    
                  []
                  | 
                  2 rb(0)
               /     \
             1 rb(2)  3 rb(1)
            /          \
           1 rb(3)      4 rb(4)
          / 
         4 rb(4)
```
#### Logic
- _1._ Start from index=0. Jump to all possible indexes from 0.
```c
nums = [2,3,1,1,4]
        0 1 2 3 4
From index=0, we can jump to index=2 and index=1
```
- _2._ Jump to index=2, check whether I can reach end from here, if not jump to all possible indexes

#### Complexity
- **Time:** O(2<sup>n</sup>)
  - Look at backtrack tree. For n=5 elements, consider only n-1=4 elements.
  - For n elements there can be n levels and every node can have n children. So its traversing n array tree.
- **Space:** O(n). Recursion requires additional memory for the stack frames.

#### Code
```cpp
class Solution {
    int size;
    int minSteps;
public:
    void rb (int startIndex, vector<int>& nums, int steps){
        // Base case
        if (startIndex >= size-1) {
            minSteps = min(steps, minSteps);
            return;
        }
        
        // Place all candidates on candidate list
        for (int i=nums[startIndex]; i>0; --i)
            rb (startIndex+i, nums, steps+1);
            // Remove candidate means steps gets back to original value
    }
    int jump(vector<int>& nums) {
        int startIndex = 0;
        minSteps = INT_MAX;
        size = nums.size();
        rb (startIndex, nums, 0);
        return minSteps;
    }
};
````

<a name=a2></a>
### Approach-2 / Greedy / O(n)
- [What is Greedy Approach](/DS_Questions/Algorithms/Greedy)
#### Logic
  - _1._ Always always picks the largest subarray, but also check how can we reach by choosing larger subarray.
  - _2._ Initialize three integer variables
    - jumps to count the number of jumps
    - currentJumpEnd to mark the end of the range that we can jump to
    - farthest to mark the farthest place that we can reach. Set each variable to zero.
  - _3._ Iterate over input. Note that we exclude the last element from our iteration because as soon as we reach the last element, we do not need to jump anymore.
    - Update farthest to `i + nums[i]` if the latter is larger.
    - If we reach currentJumpEnd, it means we finished the current jump, and can begin checking the next jump by setting currentJumpEnd = farthest.
#### Complexity
  - Time: O(n). Traversed once
  - Space: O(1)
#### Code
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
