**Balanced Binary Tree**
- [Approach-1. Bottom up, Recursion. O(n)](#a1)
  - [CPP](#cpp)
  - [Java](#j)
  - [Python](#p)
  - [Rust](#r)


### [110. Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/description/)
- Given a binary tree, determine if it is height-balanced
- Height balanced tree has balancing factor (0,1,-1)
```c
Example-1
Input: root = [3,9,20,null,null,15,7]
          3
         / \
        9   20
           /  \
          5    7 
Output: true
  
  
Example-2
Input: root = [1,2,2,3,3,null,null,4,4]
          1
         / \
        2   2
      /  \
     3    3
    / \
   4   4
Output: false
```

<a name=a1></a>
### Approach-1. Bottom up, Recursion
#### Logic
- _1._ Find left height, right height of every node.
- _2._ Balancing factor of that node = leftHeight - rightHeight
- _3._ Keep a bool variable(balanced), if balancing factor > 1, flip variable balanced=false
- _4._ Leaf node will return height as 0
#### Complexity
- **Time:** O(n)
- **Space:** O(n)
#### Code
<a name=cpp></a>
- **CPP**
```c
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
  
    // Keep track whether tree is balanced or not
    bool bTreeBalanced;
public:
    int balanced(TreeNode* root){
      
        // leaf node or we found a node which is not balanced just return
        if (!root || (!root->left && !root->right) || !bTreeBalanced)
            return 0;
      
        int lh=1, rh=1;
      
        // if left child exists, add 1
        // if does not exists leftHeight should not be considered, lh=0
        if (root->left)
            lh += balanced(root->left);
        else
            lh=0;
      
        // if right child exists, add 1
        // if does not exists rightHeight should not be considered, rh=0
        if (root->right)
            rh += balanced(root->right);
        else
            rh=0;
      
        // Check this node is balanced or not
        if (abs(lh-rh) > 1)
            treeBalanced = false;
      
        // Return max of left or right height
        return max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        // Assumed tree is balanced
        bTreeBalanced = true;
        if (!root)
            return true;
        balanced(root);
        return treeBalanced;
    }
};
```
<a name=p></a>
- **Python**
```py
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if (root == None):
            return True
        bTreeBalanced = True

        def balanced(root: Optional[TreeNode]) -> int:
            nonlocal bTreeBalanced
            if ((root.left == None and root.right == None) or bTreeBalanced == False):
                return 0
            
            lh = 1
            rh = 1
            if (root.left):
                lh += balanced(root.left)
            else:
                lh = 0

            if (root.right):
                rh += balanced(root.right)
            else:
                rh = 0

            if (abs(lh - rh) > 1):
                bTreeBalanced = False
            
            return max(lh, rh)
        
        balanced(root)
        return bTreeBalanced
```
<a name=j></a>
- **Java**
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private boolean bTreeBalanced;
    public int balanced(TreeNode root) {
        if (root.left == null && root.right==null || !bTreeBalanced)
            return 0;
        int lh = 1, rh = 1;
        if (root.left != null)
            lh += balanced(root.left);
        else
            lh = 0;
        if (root.right != null)
            rh += balanced(root.right);
        else
            rh = 0;
        if (Math.abs(lh - rh) > 1)
            bTreeBalanced = false;
        return Math.max(lh, rh);
    }
    public boolean isBalanced(TreeNode root) {
        bTreeBalanced = true;
        if (root == null)
            return true;
        balanced(root);
        return bTreeBalanced;
    }
}
```
<a name=r></a>
**Rust**
```rs

```
