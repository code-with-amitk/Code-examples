**Combination Sum 2**
- [Approach-1. Backtracking. O(2<sup>n</sup>)](#a1)


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
- _1._ Create empty candidate list `vector<int> cand`
- _2._ insert element at index=0 into `cand`
- _3._ `if (element > target)` Do not insert element into candidate list.
- _4._ Pass following as parameters in recursive_backtrack function
  - sum
  - next index in array.
- _5._ BASE CASE: if (sum == target), insert this combination into final sol array.

<img src=combination_sum_2-bt-tree.jpg width=600 />

**How to avoid Duplicate combinations in output?**
- _1._ sort the input
```c
input = [10,1,2,7,6,1,5]
sorted = [1,1,2,5,6,7,10]

Duplicates can be:
1,2,5   (indexes=0 2 3)
1,2,5   (indexes=1 2 3)
```
- _2._ After sorting, if (prev element = current element), we must have noted all combinations from prev element, Hence do not consider current element.
  - `index=0, a[0]=1`. 
  - `index=1, a[1]=1`
    - Prev element than me was 1, We must have backtracked all combinations and noted the result
```c
start = 0.
- We take combination starting at index=0 (0 2 3)

i = 1
            if (i > start && nums[i] == nums[i - 1])
                continue;
```

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
            /// Invalid Candidate
            if (nums[i] > target)
                continue;
                
            /// Place candidate on sol list
            cand.push_back(nums[i]);
            rb (cand, nums, target, i+1, sum+nums[i]);
            
            /// Remove placed candidate from list
            cand.pop_back();
        }
    }
    vecVecI combinationSum2(vecI& nums, int target) {
        /// 1. Start with Empty candidate list
        vecI cand;
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

        /// Place candidate on sol list
        for (int i=start; i<nums.size(); ++i){
            if (nums[i]>target)
                continue;
                
            /// Avoid Duplicates
            if (i > start && nums[i] == nums[i - 1])
                continue;
                
            cand.push_back(nums[i]);
            rb (cand, nums, target, i+1, sum+nums[i]);
            
            /// Remove placed candidate from list
            cand.pop_back();
        }
    }
    vecVecI combinationSum2(vecI& nums, int target) {
    
        /// 1. Start with Empty candidate list
        vecI cand;
        
        /// sort to remove duplicates.
        sort(nums.begin(), nums.end());
        rb (cand, nums, target, 0, 0);
        return out;
    }
};
```
#### Complexity
- **Time:** O(2<sup>n</sup>) + O(nlogn)
  - Worst case algorithm will exhaust all possible combinations from the input array.
- **Space:** O(n)
