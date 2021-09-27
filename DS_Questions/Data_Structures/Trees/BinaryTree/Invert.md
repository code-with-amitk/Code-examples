**Invert BT**
- [Approach-1, Recursive](#a1)
  - **Code**
    - [C++](#cpp1)
    - [Python3](#py1)
    - [Java](#j1)
- [Approach-2, Iterative](#a2)
  - [Code](#c2)

### [Invert BT](https://leetcode.com/problems/invert-binary-tree/)
- Given the root of a binary tree, invert the tree, and return its root.
```
    1                       1
   / \                     / \
  2   3     =Invert=>     3   2
 / \ / \                 / \ / \
4  5 6  7               7  6 5  4
```

<a name=a1></a>
### Approach-1, Recursive
#### Logic
- breaking condition is root=null
- goto deepest node, invert that(ie swap left, right). Keep traversing to root using same pattern.
<a name=co1></a>
#### Complexity
- **Time:** O(n). n is number of node. Since each node is visited once. We cannot do better than that, since at the very least we have to visit each node to invert it.
- **Space:** O(h). h is height of tree, h = log(n). O(h) stack would be created.

#### Code
<a name=cpp1></a>
**C++**
```cpp
 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        TreeNode* right = invertTree(root->right);
        TreeNode* left = invertTree(root->left);
        root->left = right;
        root->right = left;
        return root;        
    }
};
```
<a name=py1></a>
**Python3**
```py
class TreeNode:
  def __init__ (self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right
class Solution:
  def invertTree (self, root) -> Optional[TreeNode]:
    if root is None:
      return None
    root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
    return root
```
<a name=j1></a>
**Java**
```java
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null)
            return null;
        TreeNode right = invertTree(root.right);
        TreeNode left = invertTree(root.left);
        root.left = right;                      //No pointers in java
        root.right = left;
        return root;
    }
}
```
<a name=rs1></a>
**Rust**
```rs
use std::rc::Rc;
use std::cell::RefCell;
type Node = Rc<RefCell<TreeNode>>;
impl Solution {
    pub fn invert_tree(root: Option<Node>) -> Option<Node> {
        match root {
            None => None,
            Some(node) => {
                let (left, right) =
                    (Self::invert_tree(node.borrow().right.clone()),
                     Self::invert_tree(node.borrow().left.clone()));
                let node = node.clone();
                node.borrow_mut().left = left;
                node.borrow_mut().right = right;
                Some(node)
            }
        }
    }
}
```

<a name=a2></a>
### Approach-2, Iterative
<a name=l2></a>
#### Logic (BFS)
- Take a queue. Push root into queue.
- Pop front, Swap left right.
- if popped node's, left and right exist. Insert left, right into queue.

<a name=co2></a>
#### Complexity
- **Time:** O(n). We need to visit all nodes atleast once.
- **Space:** O(n). n=number of node. n sized queue is formed.
<a name=c2></a>
#### Code
```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front(); q.pop();
            
            //Swap
            TreeNode* temp = current->left;
            current->left = current->right;
            current->right = temp;
            
            if (current->left != nullptr)
              q.push(current->left);
              
            if (current->right != nullptr)
              q.push(current->right);
        }
        return root;      
    }
};
```
