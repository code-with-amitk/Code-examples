**Permutations**
- [Approach-1, next_permutation() cpp function](#a1)

## Permutations
- Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
```c
Example-1:
Input: [1,2,3]
Output: {1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,1,2}, {3,2,1}
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
#### Code
```cpp
using vecI = vector<int>;
using vecVecI = vector<vector<int>>;

class Solution {
	vecVecI out;
public:
	void rb (vecI& nums, vecI& cand, int start) {
		if (start == nums.size()) {
			out.push_back(cand);
      return;
    }
			
		for (int i = start; i<nums.size(); ++i) {
      cand.push_back(nums[i]);
      //Swap ith number with 1st
			swap(nums[i], nums[start]);
			rb (nums, cand, start+1);
      cand.pop_back();
			swap(nums[i], nums[start]);
		}
  }

  vecVecI permute(vecI nums) {
    vecI cand;
    rb(nums, cand, 0);	//start from index=0
    return out;
  }
};
```
