**Number of Longest Increasing Subsequence**
- [Approach-1. DP. Time: O(n<sup>2</sup>), Space: O(n)](#a1)
  - [Logic](#l)
  - [Complexity](#com)
  - Code
    - [CPP](#cpp)

### [Self Video, Must see](https://youtu.be/SjBdc_MR8N4)

### [673. Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/)
- Given an integer array nums, return the number of longest increasing subsequences.
- Notice that the sequence has to be strictly increasing.
```c
Example 1:
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
```

<a name=a1></a>
### Approach-1. DP. Time: O(n<sup>2</sup>), Space: O(n)
<a name=l></a>
#### Logic
1. Create a Array dp containing longest subsequnce till particular element. Initialize array by 1.
```c
        nums:       1   3   5   4   7

        dp:         1    1   1   1   1
        Final dp:   1    2   3   3   4
```
2. Take 2 pointers i and j. i will point to element whose lis need to be calculated and j will start from index=0
```c
            nums:       1   3   5   4   7
                        j   i
```
3. if `element[i]>element[j] and dp[i]<=dp[j]`. Increment `dp[i]` by 1 more than `dp[j]`. This means till element 2 there was LIS of length 1, But since 5 > 2. LIS at 5 can be 1 more than LIS at 2.
<a name=com></a>
#### Complexity
- **Time:** O(n<sup>2</sup>)
- **Space:** O(n)
#### Code
<a name=cpp></a>
**CPP**
```cpp
#include <iterator>
using vI = std::vector<int>;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int iMax = 1;
        
        vI dp(nums.size(), 1);
        vI count(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i){
            for (int j = 0; j < i; ++j){

                if (nums[i] > nums[j] && dp[i] <= dp[j]) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[i] == dp[j] + 1) {
                    count[i] += count[j];
                }
            }
            iMax = std::max(iMax, dp[i]);
        }
        
        int out = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (dp[i] == iMax) {
                out += count[i];
            }
        }
        
        return out;
    }
};  
```
