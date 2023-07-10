**Minimum Depth of Binary Tree**

### [111. Minimum Depth of Binary Tree]
- Given a binary tree, find its minimum depth.
- The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
- Note: A leaf is a node with no children.
```c
Example-1:
Input: root = [3,9,20,null,null,15,7]
    3
   / \
  9   20
      / \
    15   7
Output: 2

Example-2:
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
    2
     \
      3
       \
         4
          \
           5
            \
             6
```

<a name=a1></a>
### Approach-1. Inorder
<a name=l></a>
#### Logic
- _1._ Depth of node
```c
  children     Depth
    0          0
    1          depth of non-empty child
```
<a name=com></a>
#### Complexity
- **Time:** O(n). Traversing every node once
- **Space:** O(1)
#### Code
<a name=cpp></a>
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
    int inorder(TreeNode* root) {
        int lh = 0, rh = 0;
        if (!root->left && !root->right)
            return 0;

        if (root->left) {
            lh = 1;
            lh += inorder(root->left);
        }
        if (root->right) {
            rh = 1;
            rh += inorder(root->right);
        }
        
        if (!lh && rh)      //lh==0 and rh!=0
            return rh;
        else if (lh && !rh) //rh==0 && lh!=0
            return lh;
        return std::min(lh, rh);
    }
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return inorder (root)+1;
    }
};
```
