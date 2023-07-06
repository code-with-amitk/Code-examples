**Minimum Size Subarray Sum**
- [Approach-1. O(n<sup>2</sup>)](#a1)
- [Approach-2. Sliding Window O(mn)](#a2)
  - [Logic](#l)
  - Code
    - [CPP](#cpp)

## [Self Video](https://youtu.be/ZJxLAncsAso)

### [209. Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/description/)
- Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray  whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
```c
Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
```

### Approach-1. O(n<sup>2</sup>). Check every subarray
<a name=l></a>
#### Logic
- Take sliding window
- expand window when `(window sum) < target`
- contract window when `(window sum) <= target`
- Note number of elements in window
<a name=a2></a>
### Approach-2. Sliding Window O(mn). 
#### Code
<a name=cpp></a>
**CPP**
```cpp
using vI = std::vector<int>;
class Solution {
public:
    int minSubArrayLen(int target, vI& nums) {
        if (!nums.size())
            return 0;

        int wstart = 0, wend = 0, wsum = 0; //Window start,end,sum

        /*              std::numeric_limits<int>::max()     INT_MAX
        Available in    C++ standard library            C Standard library(<climits>)
        type safety     more                            less
        */
        int minlen = std::numeric_limits<int>::max();

        // []: Capture list. Pass all outside variables inside lambda
        std::for_each(nums.begin(), nums.end(), [&](int element){

                /*              nums.at(i)           nums[i]
                Bound Check     throw exception     None
                                std::out_of_range
                                if i>size
                Speed           slow                fast(no bound check overhead)
                */
                wsum += nums.at(wend++);

                while (wsum >= target) {
                    minlen = std::min(minlen, wend-wstart);
                    wsum -= nums.at(wstart++);
                }
        });

        return minlen == INT_MAX ? 0 : minlen;
    }
};
```

