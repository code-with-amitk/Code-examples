## [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/) / Sum of all nodes within Range in BST
- Given the root node of a binary search tree, return the sum of values of all nodes with a value in the range `[low, high]`.
- Examples
```c
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32    //7+10+15
            10
          /    \
        5        15
       / \        \
      3   7       18
```

### Approach-1 //Binary Search + Recursion.
- **Logic**
  - At every node check, if node->val is within [low,high] include in sum.
  - if node->val < low, Move to right
  - if node->val > high, move to left
- **Complexity:**
  - **Time:** O(logn)
  - **Space:** O(logn)  //Recursion Stack
```c++
class Solution {
public:
    int BinarySearch(TreeNode* root, int low, int high) {
        if (root == nullptr)
            return 0;
        
        int count=0;
        if(root->val >= low && root->val <= high)
            count += root->val;
        count += BinarySearch(root->left, low, high);
        count += BinarySearch(root->right, low, high);
        return count;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        return BinarySearch(root,low,high);
    }
};
```
