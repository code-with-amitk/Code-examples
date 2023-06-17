**Number of Ways to Reorder Array to Get Same BST**
- [Approach-1. Valid Combinations on left and right](#a1)
  - [Logic](#l)
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
**Understanding problem:**
- _1._ We need to find all combinations of input which will yeild same bst.
```c
Input: nums = [3,4,5,1,2]
    3
  /   \
 1     4     
  \      \
   2      5
```
- _2._  Consider this combination=`[3,1,2,4,5]`. This will create same bst as input.
```c
  3
/    
1          //Place 3, Then Place 1, Then place 2
 \
  2
    
// Now place 4 and after 4, place 5.
    3
  /   \
  1    4   
  \     \
    2    5        //This is same BST as input.
```
- Similarly other combinations will also generate same bst.
```c
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]
```
- **Things we can derive from generated Combinations**
  - _1._ Root node of tree is always at index=0
  - _2._ All elements less than root node(1,2) will come in left subtree. All elements greter than root node will come in right subtree.  //BST property
  - _3._ To generate same BST(as input), relative ordering of left subtree elements and right subtree elements should be same.
    - ie 2 should always come after 1 in all generated combinations.
    - 5 should always come after 4 in all generated combinations.
```c
3  __  _4_  __  _5_    //1,2
3  __  _4_  _5_  __    //1,2
3  _4_  __  __  _5_    //1,2
3  _4_  __  _5_  __   //1,2
```
- So, we need to place 2 numbers(left subtree) at 4 places. 1st place is always occupied by root node.
```c
  n-1
    C
     2  //Left subtree elements
```
- For right subtree we need to place 2 numbers(4,5) at 4 places. 1st place is always occupied by root node.
```c
  n-1
    C
     2  //right subtree elements
```
- **Why we need recursion (DFS) here?**
  - We wil calculate <sup>n</sup>C<sub>r</sub> or left and right subtrees, but left, right subtrees might also be arranged differntly hence we need all possible ways.
```c
      10
      / \
     5    15
    / \   / \
   2   7  17 20
      /    \
     6      18
```
- **[Pascal Traingle](DS_Questions/Questions/vectors_arrays/2d-grid/Pascal_Traingle.md):** Stores all combinations, hence we need not to calculate combination product reptedly.
  - Pascal traingle represents combination tree.

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

        // if less than 3 elements, there is only possible way to arrange elements.
        if (size <= 2)
            return 1;

        // Count elements less than root, they will come in left subtree
        // elements greater than root, they will come in right subtree
        vector<int> left, right;
        for (int i=1;i<size;++i) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
        
        long long left_comb = dfs(left, pascal_triangle)% mod;
        long long right_comb = dfs(right, pascal_triangle) % mod;

        // Calculate Combination:
        //n-1
        //   C
        //    left_elements
        long long a = (pascal_triangle[size-1][left.size()] * left_comb) % mod;
        return (a * right_comb) %mod;
    }

    // 3,4,5,1,2
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        //1. Create Pascal Traingle representing Combinations
        vvLL pascal_triangle(n+1, vLL(n+1,0));
        for (int i=1;i<=n;++i) {
            pascal_triangle[i] = vLL(i+1, 1);
            for (int j=1;j<i;++j)
                pascal_triangle[i][j] = (pascal_triangle[i-1][j-1] + pascal_triangle[i-1][j]) % mod;
        }

        // 2. Find all combinationss of every subtree using recursion
        long long a = (dfs (nums, pascal_triangle) % mod);

        // Ans = (All combinations) - 1. Since input is also 1 combination which need not to be included.
        return  (a -1);
    }
};
```
