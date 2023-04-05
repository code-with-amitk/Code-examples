**Permutations**
- [Approach-1, next_permutation() cpp function](#a1)
- [Approach-2, Backtracking with swap](#a2)

## Permutations
- Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
```c
Example-1:
Input: [1,2,3]
Output: {1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}
```

<a name=a1></a>
### Approach-1, next_permutation() cpp function
#### Code
```c
vector<vector<int>> permute(vector<int>& a) {
  vector<vector<int>> v;
  sort(a.begin(),a.end());
  do{
    v.push_back(a);
  }while(next_permutation(a.begin(),a.end()));
  return v;
}
```

<a name=a2></a>
### Approach-2, Backtracking with swap
#### Logic = Backtracking
- _1._ We will use [backtracking template](/DS_Questions/Algorithms/Backtracking/)
- _2._ Place 1st element on candidate.
- _3._ Iterate thru all elements using for() loop.
  - **Swap 1st and Present element:** Since this is permutation & we need all arrangments we need to swap.
  - Move to next element is pass (start+1) to recursive backtrack function.
#### Code
```cpp
using vecI = vector<int>;
using vecVecI = vector<vector<int>>;

class Solution {
	vecVecI out;
public:
	void rb (vecI& nums, vecI& cand, int start) {
		/// Base case
		if (start == nums.size()) {
			out.push_back(cand);
			return;
		}
			
		/// Insert all elements in candidate list
		for (int i = start; i<nums.size(); ++i) {
		
			// Insert present element to candidate list
      			cand.push_back(nums[i]);
		
			// Since Permutation is arrangement, we will swap
			// Present and 1st element and note the arrangement.
			swap(nums[i], nums[start]);
			rb (nums, cand, start+1);
			swap(nums[i], nums[start]);
			
			// Remove Inserted element from Candidate list
	      		cand.pop_back();
		}
	}

	vecVecI permute(vecI nums) {
		/// Take empty candidate
    		vecI cand;
		
    		rb(nums, cand, 0);	//start from index=0. call recursive backtrack
		
    		return out;
  }
};
```
