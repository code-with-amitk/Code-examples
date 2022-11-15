**Combination Sum 2**
- [Approach-1. Backtracking](#a1)


### [40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/description/)
- Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
- Each number in candidates may only be used once in the combination.
- Note: The solution set must not contain duplicate combinations.
```c
Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: [ [1,1,6],  [1,2,5],  [1,7],  [2,6] ]
```

<a name=a1></a>
### Approach-1, Backtracking
- [What is Backtracking, BackTracking Template](/DS_Questions/Algorithms/Backtracking/)
#### Logic
- **[Use backtracking Template](/DS_Questions/Algorithms/Backtracking/)**
- 1.
<img src=combination_sum_2-bt-tree.jpg width=600 />

#### Code-1 (Combinations With Duplicates)
```cpp
using vecVecI = vector<vector<int>>;
using vecI = vector<int>;
class Solution {
    vecVecI out;
public:
    void rb(vecI& cand, vecI& nums, int target, int start, int sum) {
        /// Base case
        if (sum > target)
            return;
        if (sum == target) {
            out.push_back(cand);
            return;
        }

        /// Place all candidates
        for (int i=start; i<nums.size(); ++i){
            if (nums[i]>target)
                continue;
            cand.push_back(nums[i]);
            rb (cand, nums, target, i+1, sum+nums[i]);
            cand.pop_back();
        }
    }
    vecVecI combinationSum2(vecI& nums, int target) {
        vecI cand;
        sort(nums.begin(), nums.end());
        rb (cand, nums, target, 0, 0);
        return out;
    }
};
```

#### Code-2 (Without Duplicates)
```cpp
using vecVecI = vector<vector<int>>;
using vecI = vector<int>;
class Solution {
    vecVecI out;
public:
    void rb(vecI& cand, vecI& nums, int target, int start, int sum) {
        /// Base case
        if (sum > target)
            return;
        if (sum == target) {
            out.push_back(cand);
            return;
        }

        /// Place all candidates
        for (int i=start; i<nums.size(); ++i){
            if (nums[i]>target)
                continue;
                
            /// Avoid Duplicates
            if (i > start && nums[i] == nums[i - 1])
                continue;
                
            cand.push_back(nums[i]);
            rb (cand, nums, target, i+1, sum+nums[i]);
            cand.pop_back();
        }
    }
    vecVecI combinationSum2(vecI& nums, int target) {
        vecI cand;
        sort(nums.begin(), nums.end());
        rb (cand, nums, target, 0, 0);
        return out;
    }
};
```
