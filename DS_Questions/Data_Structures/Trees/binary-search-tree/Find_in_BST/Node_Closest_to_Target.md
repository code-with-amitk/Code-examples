## [Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/)
- Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
- Given target value is a floating point. You are guaranteed to have only one unique value in the BST that is closest to the target.
- Example
```html
Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4
```

### Approach-1  //Inorder traversal + Linear Search
- **Logic**
  - *1.* Traverse BST inorder and store in vector.
  - *2.* Find nearest value to target from stored vector using linear search
- **Complexity**
  - Time: O(n)+O(n) = O(n)
    - O(n): Storing value in vector after inorder traversal
    - O(n): Finding nearest value from target.
  - Space: O(n)
- **Code**
```c++
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
  void inorder(TreeNode* root, vector<double>& v) {
    if (root->left)
      inorder(root->left, v);
    v.push_back(root->val);
    if (root->right)
      inorder(root->right, v);
  }

  int closestValue(TreeNode* root, double target) {
    vector<double> v;
    inorder(root, v);

    long val= UINT32_MAX;
    long mini=0;

    for (const auto i : v) {
      if (abs(i - target) <= val) {
        mini = i;
        val = abs(i - target);
      }
    }
    return mini;
  }
  TreeNode* createTree(){
    TreeNode* p14 = new TreeNode(1400000000);
    TreeNode* p15 = new TreeNode(1500000000, p14, nullptr);
    return p15;
  }
};
int main(){
  Solution s;
  TreeNode* root = s.createTree();
  //cout<<s.closestValue(root,3.71);
  cout<<s.closestValue(root,-1500000000.0);
}  
```
