## [Problem](https://leetcode.com/problems/first-missing-positive/submissions/)
- Given an unsorted integer array nums, find the smallest missing positive integer.
- Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space.?
- Examples
 ```c
Example 1:
Input: nums = [1,2,0]
Output: 3

Example 2:
Input: nums = [3,4,-1,1]
Output: 2

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
```

### Logic
- Copy array into unordered_set
- Take variable i=1
  - Increment i by 1 and search in set. Searching is O(1)
  - if i is not found return i. //This is the least missing element from i=1.
  
### Code
```c++
class Solution {
public:
  int firstMissingPositive(vector<int>& a) {
    int i=1;
    unordered_set<int> us(a.begin(), a.end());
    while(i <= us.size()){
      if (us.find(i) == us.end())
        break;
      ++i;
    }
    return i;
  }
};
```
