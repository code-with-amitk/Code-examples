**Number of Ways to Reorder Array to Get Same BST**
- [Approach-1. Valid Combinations on lfet and right](#a1)
  - [Logic]
  - Code
    - [CPP](#cpp)


### [1569. Number of Ways to Reorder Array to Get Same BST](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/)
- Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.
- For example, given `nums = [2,1,3]`, we will have 2 as the root, 1 as a left child, and 3 as a right child. The array `[2,3,1]` also yields the same BST but `[3,2,1]` yields a different BST.
- Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.
- Since the answer may be very large, return it modulo 109 + 7.
- Examples:
```c
Example-1:
Input: nums = [2,1,3]
Output: 1
Explanation: We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.

Example-2:
Input: nums = [3,4,5,1,2]
    3
  /   \
 1     4     
  \      \
   2      5
Output: 5
Explanation: The following 5 arrays will yield the same BST: 
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]
```

<a name=a1></a>
### Approach-1.Valid Combinations on left and right
#### Logic
#### Code
<a name=cpp></a>
**CPP**
```cpp
using vvLL = vector<vector<long long>>;
using vLL = vector<long long>;
class Solution {
    long long mod = pow(10,9) + 7;
public:
    long long dfs(vector<int>& nums, vvLL& pascal_triangle) {
        int size = nums.size();
        if (size <= 2)
            return 1;
            
        vector<int> left, right;
        for (int i=1;i<size;++i) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
        
        long long left_comb = dfs(left, pascal_triangle)% mod;
        long long right_comb = dfs(right, pascal_triangle) % mod;
        

        //n-1
        //   C
        //    left_elements
        long long a = (pascal_triangle[size-1][left.size()] * left_comb) % mod;
        return (a * right_comb) %mod;
    }

    // 3,4,5,1,2
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        // Pascal Traingle representing Combinations
        vvLL pascal_triangle(n+1, vLL(n+1,0));
     
        for (int i=1;i<=n;++i) {
            pascal_triangle[i] = vLL(i+1, 1);
            for (int j=1;j<i;++j)
                pascal_triangle[i][j] = (pascal_triangle[i-1][j-1] + pascal_triangle[i-1][j]) % mod;
        }

        long long a = (dfs (nums, pascal_triangle) % mod);
        return  (a -1);

        // root is always index=0
        // Count all numbers which are less than nums[0]
        // int left_elements = 0;
        // for (auto&i:nums){
        //     if (i < nums[0])
        //         left_elements++;
        // }

        // // Left Combination: Number of ways to arrange left eleemnt(1,2)
        // // in 4 places. Because 1st position is always for root
        // // nums.size()-1        //Because 1st position is always for root
        // //    C
        // //      left_elements
        // int left_ways = (combination(nums.size()-1, left_elements))%mod;

        // // Right Combination: Number of ways to arrange right eleement(4,5)
        // // in 4 places. Because 1st position is always for root
        // // nums.size()-1    //Because 1st position is always for root
        // //    C
        // //      right_elements
        // int right_elements = nums.size()-1-left_elements;
        // int right_ways = (combination(nums.size()-1, right_elements))%mod;
        // return (left_ways+right_ways - 1);
    }
};
```
