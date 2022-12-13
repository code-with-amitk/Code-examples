**104. Maximum Depth of Binary Tree**
- [Approach-1, Recursive. O(n)](#a1)
  - [CPP](#c)
  - [Java](#j)
  - [Python](#p)

### 104. Maximum Depth of Binary Tree
- Given the root of a binary tree, return its maximum depth.
- A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
```c
           3
         /   \
        9     20
             /  \
            15   7
            
Input: root = [3,9,20,null,null,15,7]
Output: 3
```

<a name=a1></a>
### Approach-1, Recursive
#### Complexity
- **Time:** O(n). Since we traverse every node
- **Space:** O(1)

#### Code
<a name=c></a>
- **CPP**
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
public:
    int depth(TreeNode* root) {
        if (!root)
            return 1;
        int leftHeight=1, rightHeight=1;
        if (root->left)
            leftHeight += depth(root->left);
        if (root->right)
            rightHeight += depth(root->right);
        return max(leftHeight, rightHeight);
    }
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return depth(root);
    }
};
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
    int depth (TreeNode root){
        if (root == null)
            return 1;
        int leftHeight = 1, rightHeight = 1;
        leftHeight += depth(root.left);
        rightHeight += depth(root.right);
        return Math.max(leftHeight, rightHeight);
    }
    public int maxDepth(TreeNode root) {
        if (root==null)
            return 0;
        return depth(root)-1;
    }
}
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
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if (not root):
            return 0
        depth = 1
        l = 1
        r = 1
        def dfs(root):
            if (not root):
                return 1
            return max (dfs(root.left)+1, dfs(root.right)+1)
                       
        return dfs(root)-1
```
