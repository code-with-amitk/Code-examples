## 1. Function returning Vector<int> created after inorder traversal [Recursive]
- Pass Created tree to a function
- Create a vector during recursive traversal & return it
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
### Code
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
    vector<int> r, x;
    if (!root) {
      return r;
    }
    if (root->left != NULL) {
      x = inorderTraversal(root->left);
      r.insert(r.end(), x.begin(), x.end());
    }
    r.push_back(root->val);
    if (root->right != NULL) {
      x = inorderTraversal(root->right);
      r.insert(r.end(), x.begin(), x.end());
    }
    return r;
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
