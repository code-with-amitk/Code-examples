## [Problem leetcode](https://leetcode.com/problems/first-missing-positive/submissions/)
- From unsorted int array, find the smallest missing positive integer.
- **Examples**
 ```c
Input: nums = [1,2,0]
Output: 3

Input: nums = [3,4,-1,1]
Output: 2

Input: nums = [7,8,9,11,12]
Output: 1
```

## Logic
- Copy array into unordered_set
- Take variable i=1
  - Increment i by 1 and search in set. Searching is O(1)
  - if i is not found return i. //This is the least missing element from i=1.
  
## Code
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
