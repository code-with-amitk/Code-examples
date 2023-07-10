**Minimum Depth of Binary Tree**
- Approach-1. inorder.O(n)
  - [Logic](#l)
  - [Complexity](#com)
  - Code
      - [CPP](#cpp)
      - [Rust](#rs)

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
<a name=rs></a>
**Rust**
[What is `Option<Rc<RefCell<TreeNode>>>`](Code-examples/tree/master/DS_Questions/Data_Structures/Trees#r)
```rs
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {

    fn inorder(root: &Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let (mut lh, mut rh) = (0,0);

        if let Some(node) = root {
            let node_ref = node.borrow();
            if node_ref.left.is_none() && node_ref.right.is_none() {
                return 0;
            }
            
            if let Some(left) = &node_ref.left {
                lh = 1;
                lh += Solution::inorder(&(node_ref.left.clone()));
            }
            if let Some(left) = &node_ref.right {
                rh = 1;
                rh += Solution::inorder(&(node_ref.right.clone()));
            }
            
            if lh == 0 && rh != 0 {
                return rh;
            }
            else if rh == 0 && lh != 0 {
                return lh;
            }
            return std::cmp::min(lh, rh);
        }
        0        
    }
    pub fn min_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if let Some(node) = root {
            return Solution::inorder(&Some(node))+1;
        }
        0
    }
}
```
