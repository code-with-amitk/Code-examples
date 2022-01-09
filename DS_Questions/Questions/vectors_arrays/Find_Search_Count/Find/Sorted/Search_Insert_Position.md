**Search Insert Position**
- Code
  - [C++](#cpp)

### [Search Insert Position](https://leetcode.com/problems/search-insert-position/)
- Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
- You must write an algorithm with O(log n) runtime complexity.
```c
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
```

### Code
<a name=cpp></a>
#### CPP
```c
class Solution {
public:    
  int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;

    // Invariant: the desired index is between [low, high+1]
    while (low <= high) {
      int mid = low + (high-low)/2;
      if (nums[mid] < target)
        low = mid+1;
      else
        high = mid-1;
    }
        // (1) At this point, low > high. That is, low >= high+1
        // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
        // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
        //     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
    return high+1;
  }
};
```
