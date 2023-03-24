**Subsets**
- [Approach-2, Backtracking](#bt)

### [78. Subsets](https://leetcode.com/problems/subsets/description/)
- Given an integer array nums of unique elements, return all possible subsets (the power set).
- The solution set must not contain duplicate subsets. Return the solution in any order.
```c
Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

<a name=bt></a>
### Approach-2, Backtracking
#### [Logic = Backtrack Template](/DS_Questions/Algorithms/Backtracking#tem)
#### Code
```cpp
#include<iostream>
#include<vector>
using namespace std;
using vecI = vector<int>;
using vecVecI = vector<vector<int>>;

class Solution {
    vecVecI all_sets;       //All Solutions combined
public:
    void bt(int start, int end, vecI& temp, vecI& nums) {
        //Base case
        if (start > end)
            return;

        all_sets.push_back (set1);

        //Candidate = temp
        for (int i=start; i<end; ++i) {

            //Place Candidate on 1 solution out of many
            set1.push_back (nums[i]);
            bt (i+1, end, set1, nums);

            //Remove Candidate from solution
            set1.pop_back();
        }
    }

    vecVecI subsets(vecI& nums) {
        //Create 1st Candidate
        vecI set1;

        //bt(start, end, candidate)
        bt(0, nums.size(), set1, nums);
        
        return all_sets;
    }
};
int main() {
    vector<int> nums = {1,2,3};
    Solution s;
    vecVecI out = s.subsets(nums);
    cout << out.size();
    for (int i=0;i<out.size();++i) {
        for (int j=0;j<out[i].size();++j) {
            cout << out[i][j] << " ,";
        }
        cout<<"\n";
    }
}
```
