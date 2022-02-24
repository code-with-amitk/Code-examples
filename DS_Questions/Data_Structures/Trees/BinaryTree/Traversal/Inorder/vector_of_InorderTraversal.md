**Inorder Traversal**
- Recursive
  - [CPP](#rc)
  - [Complexity. Time:O(n), Space:O(n)](#co1)
- Iterative Using stack
  - [CPP](#ic)
  - [Complexity, Time:O(n), Space:O(n)](#co2)
- Morris Traversal
  - [CPP](#ic)
  - [Complexity, Time:O(n), Space:O(1)](#co3)


### [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
Given the root of a binary tree, return the inorder traversal of its nodes' values.
```c
Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []
```

### 1. Recursive
<a name=rc></a>
#### CPP
```cpp
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
    void traverse(TreeNode* root, vector<int>& out){
        if (root->left)
            traverse (root->left, out);
        out.push_back(root->val);
        if (root->right)
            traverse (root->right, out);        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        if (root)
            traverse (root, out);
        return out;
    }
};
int main(){
  TreeNode n3(3);
  TreeNode n2(2, &n2, NULL);
  TreeNode n1(1, NULL, &n2);
  cout<<"Tree created";

  Solution s;
  vector<int> v = s.inorderTraversal(&n1);
  for(auto i:v)
    cout<<i<<" ";
}
```
<a name=co1></a>
#### Complexity
- **Time:** O(n). Traversing all nodes
- **Space:** 
  - Worst case: O(n)
  - Average Case: O(logn). At any time logn function stacks are allocated.

### 2. Iterative (Using stack)
- Keep pushing left children on stack.
- Once reach leaf node(ie node having left child). pop, push on vector.
-  Make pointer point to right child(if exist).
<a name=ic></a>
#### CPP
```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        if (!root)
            return r;

        stack<TreeNode*> st;
        
        TreeNode* p = root;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            out.push_back(p->val);
            p = p->right;
        }
        return out;
    }
};
```
<a name=co1></a>
#### Complexity
- **Time:** O(n). Traversing all nodes
- **Space:**
  - Worst case: O(n)
  - Average Case: O(logn). At any time logn function stacks are allocated.

### 3. Morris Traversal
**Logic**
- if left node exist on tree, make parent as right child of left node.
- if no left child exist
  - Add current value to vector
  - go to right
```c
Example-1:
    1               2
   / \    =>         \
  2   3               1
                       \
                         3

Example-2:
    1               2                     4
   / \             / \                     \
  2   3   =>      4   5           =>        2
 / \                   \                     \
4  5                    1                     5
                         \                     \
                          3                     1
                                                 \
                                                  3
Example-3:
      1
       \
        2     =>    vector=1,     2     =>    3
       / \                       / \           \
      3   4                     3   4           2
                                                 \
                                                  4
``` 
