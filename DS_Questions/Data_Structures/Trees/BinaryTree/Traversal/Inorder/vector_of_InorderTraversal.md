**Inorder Traversal**
- Recursive
  - [CPP](#rc)
- Iterative
  - [CPP](#ic)

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

### Recursive
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


## 2. Iterative Approach
```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> r;
        if (root == NULL) {
            return r;
        }
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            r.push_back(p->val);
            p = p->right;
        }
        return r;
    }
};
```
