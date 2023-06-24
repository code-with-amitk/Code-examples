**Tallest Billboard**
- [Approach-1. 3<sup>n</sup>. DFS. TLE](#a1)
- [Approach-2. DP](#a2)

### [956. Tallest Billboard](https://leetcode.com/problems/tallest-billboard/description/)
- You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.
- You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.
- Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.
```c
Example 1:
Input: rods = [1,2,3,6]
Output: 6
Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.

Example 2:
Input: rods = [1,2,3,4,5,6]
Output: 10
Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.
```

<a name=a1></a>
### Approach-1. DFS. 3<sup>n</sup>. TLE
<a name=l1></a>
#### Logic
- Find all permutations where a rod can be placed. Every rod can be added to left rod or right rod or not added to any.
```c
  _____      _______
  left        right
```
- Find all permutations by placing every rod on left, right, no selection.
<a name=com></a>
#### Complexity
- **Time:** 3<sup>n</sup>. At every rod we have 3 choices(place at left, place at right, donot place anywhere) and we need to do this for n rods.
#### Code
<a name=cpp1></a>
**CPP**
```cpp
using vI = vector<int>;
class Solution {
            //rods,left_rod_height,right_rod_height,index
    int dfs (vI& rods, int left, int right, int index) {
        // Base case. We reached last index
        if (index == rods.size()){
            // if (height of left rod == height of right rod)
            if (left == right)
                return left;
            return 0;
        }

        int take_left = dfs(rods, left+rods[index], right, index+1);
        int take_right = dfs(rods, left, rods[index]+right, index+1);
        int not_take = dfs(rods, left, right, index+1);
        return max(max(take_left, take_right), not_take);
    }
public:
    int tallestBillboard(vector<int>& rods) {
        return dfs (rods, 0, 0, 0);
    }
};
```

<a name=a2></a>
### Approach-2. DP. I did not understand
#### Code
**CPP**
```cpp
using vI = vector<int>;
int dp[10005][21];
class Solution {
            //rods,left_rod_height,right_rod_height,index
    int dfs (vI& rods, int diff, int index) {

        // Base case. We reached last index
        if (index >= rods.size()){
            // if (height of left rod == height of right rod)
            return (diff==0) ? 0 : INT_MIN;
        }

        if (dp[diff+5001][index] != -1)
            return dp[diff+5001][index];

        int take_left = dfs(rods, diff+rods[index], index+1) + rods[index];
        int take_right = dfs(rods, diff-rods[index], index+1);
        int not_take = dfs(rods, diff, index+1);

        dp[diff+5001][index] = max(max(take_left, take_right), not_take);
        return dp[diff+5001][index];
    }
public:
    int tallestBillboard(vector<int>& rods) {
        memset(dp, -1, sizeof(dp));
                    //rods, diff, index
        return dfs (rods, 0, 0);
    }
};
```
