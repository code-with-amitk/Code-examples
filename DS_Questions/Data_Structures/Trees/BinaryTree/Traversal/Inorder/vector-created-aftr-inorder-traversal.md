# Function returning Vector<int> created after inorder traversal
- Pass Created tree to a function
- Create a vector during inorder traversal & return it
- **Input**
```
  1
   \
    2
   /
  3 
```
- **Ouput**: Vector created after inorder traversal
```
vector<int> = {1,3,2}
```
## 1. Recursive Approach
- **Logic**
  - Take 2 vectors `v`, `temp`.
  - Create vector `temp` after recursive traversal of tree
  - Append `temp` at end of `v` when branch's traversal is over.
```
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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> v, temp;
    if (!root) {
      return v;
    }
    if (root->left != NULL) {
      temp = inorderTraversal(root->left);
      v.insert(r.end(), temp.begin(), temp.end());
    }
    v.push_back(root->val);
    if (root->right != NULL) {
      temp = inorderTraversal(root->right);
      v.insert(v.end(), temp.begin(), temp.end());
    }
    return v;
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
