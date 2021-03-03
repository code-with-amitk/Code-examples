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

### Approach-1  //Inorder traversal + Linear Search. Time:O(n), Space:O(n)
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

### Approach-2: Binary Search. Time:O(logn), Space:O(1)
- **Logic**
  - *1.* Start from root, if `target<root->val`. Move to left else to right. Keep noting closest value.
```c
        5       target=1.8
       / \
      3   6
     / \
    2   4
   /
  1 
  
Step-1:     5       //Move left, because 1.8 < 5
           / \
    here> 3   6
         / \
        2   4
       /
      1 
      
Step-2:     5       //Move left, because 1.8 < 3
           / \
          3   6
         / \
  here> 2   4
       /
      1

Step-3:     5       //Move left, because 1.8 < 2
           / \
          3   6
         / \
        2   4
       /
here> 1         //Ok value is between 2 and 1
```
- **Complexity**
  - **Time:** O(logn)
  - **Space:** O(1)
- **Code**
```c++
int closestValue(TreeNode* root, double target) {
  int val=0;
  int closest = root->val;
  while (root != nullptr) {
    val = root->val;
      
    //Keep noting closet value to target.
    if (abs(val - target) < abs(closest - target))
      closest = val;
      
      
    //Move on left or right
    if(target < root->val)            //root =  target < root->val ? root->left : root->right;
      root = root->left;
    else
      root = root->right;
  }
  return closest;
}
```
