**Minimum Absolute Difference in BST**
- [Approach-1. Inorder Traversal & 2 loops. O(n<sup>2</sup>)](#a1)
- Approach-2. Inorder Traversal & Sorting. Compare adjacent elements. O(nlogn)
- Approach-3. Inorder Traversal & Insert in map. Compare adjacent elements. O(nlogn)


### [530. Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/)
- Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
```c
Example-1
Input: root = [4,2,6,1,3]
Output: 1   //2-1

Example-2
Input: root = [543,384,652,null,445,null,699]
          543
        /     \
      384      652
        \       \
         445    699
Output: 47 = (699-652). Note this is not difference between minimum 2 elements
```

<a name=a1></a>
### Approach-1. Inorder & 2 loops. O(n<sup>2</sup>)
#### Logic
- Store all nodes in vector and then traverse using 2 for loops finding diff of every 2 elements
#### Code
**CPP**
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int min1, min2;
    void note_mins (int val) {
        //cout << "min1=" << min1 << ", min2=" << min2;
        if (val < min1 && val < min2) {
            min2 = min1;
            min1 = val;
        }
        else if (val < min2) {
            min2 = val;
        }
        //cout << "val=" << val << ", min1=" << min1 << ", min2=" << min2 <<"\n";
    }
    void inorder(TreeNode* root) {
        if (root->left)
            inorder(root->left);
        note_mins (root->val);
        if (root->right)
            inorder(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        min1 = INT_MAX;
        min2 = INT_MAX-1;
        // Inorder traversal
        inorder(root);
        return min2 - min1;
    }
};
```
