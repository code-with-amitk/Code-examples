**Subsets**
- [Approach-2, Backtracking](#bt)

### [Subsets](https://leetcode.com/problems/subsets/description/)
- Given an integer array nums of unique elements, return all possible subsets (the power set).
- The solution set must not contain duplicate subsets. Return the solution in any order.
```c
Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

### Approach-2, Backtracking
#### [Logic = Backtrack Template](DS_Questions/Algorithms/Backtracking#tem)
#### Code
```cpp
#include<iostream>
#include<vector>
using namespace std;
using vecI = vector<int>;
using vecVecI = vector<vector<int>>;

class Solution {
    vecVecI out;
public:
    void bt(int start, int end, vecI& temp, vecI& nums) {
        //Base case
        if (start > end)
            return;

        out.push_back (temp);

        //Candidate = temp
        for (int i=start; i<end; ++i) {

            //Place Candidate
            temp.push_back (nums[i]);
            bt (i+1, end, temp, nums);

            //Remove Candidate
            temp.pop_back();
        }
    }

    vecVecI subsets(vecI& nums) {
        //Create 1st Candidate
        vecI temp;

        //bt(.., candidate)
        bt(0, nums.size(), temp, nums);
        return out;
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
