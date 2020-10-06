## Problem
- Traverse binary tree in zigzag fashion.
- **Example**
  - Print: 40 60 20 10 30 50 70 55 5
  - Traversal on Levels:
    - Even: Traverse from Left to Right
    - Odd:  Traverse from Right to Left
    
![ImgURL](spiralTraversalExample.jpg)

### Logic
- Take 2 stacks. `mainStack<TreeNode*>, tempStack<TreeNode*>`.
  - *1.* mainStack for traversing a particular level
  - *2.* tempStack for storing children at time of traversal
- When mainStack is empty (ie all nodes on particular level) are traversed.
  - Swap mainStack and tempStack
- For Example
```c

```

### Code
```c++
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  void ZigZagTraversal (TreeNode* root) ;
  void PrintZigZag();
  bool isEvenOddTree(TreeNode* root);
private:
  stack<TreeNode*> mainStack;
  stack<TreeNode*> tempStack;
  int level = 0;
};

void Solution::PrintZigZag() {
    while (mainStack.empty() != 1) {
      while (mainStack.empty() != 1) {

        TreeNode* top = mainStack.top();
        mainStack.pop();

        if (!top)
          continue;

        cout<<top->val<<" ";

        if (level%2 == 0) {     //Even level
          tempStack.push(top->left);
          tempStack.push(top->right);
        }
        else                    //Odd level
        {
          tempStack.push(top->right);
          tempStack.push(top->left);
        }
      }

      if (tempStack.empty() != 1)
        tempStack.swap(mainStack);

      ++level;
    }
}

void Solution::ZigZagTraversal (TreeNode *root) {
  if (!root)
    return;

  mainStack.push(root);
  PrintZigZag();
  cout<<"\n";
}

int main(){
  TreeNode a12(12);
  TreeNode a8(8);
  TreeNode a6(6);
  TreeNode a2(2);
  TreeNode a3(3,&a12,&a8);
  TreeNode a7(7,&a6,nullptr);
  TreeNode a9(9,nullptr,&a2);
  TreeNode a10(10,&a3,nullptr);
  TreeNode a4(4,&a7,&a9);
  TreeNode r(1,&a10,&a4);
  TreeNode* root = &r;

  Solution s;
  s.ZigZagTraversal(root);
}
```
