## [Problem](https://leetcode.com/contest/weekly-contest-209/problems/even-odd-tree/)
- A binary tree is named Even-Odd if it meets the following conditions:
- The root of the binary tree is at level index 0, its children are at level index 1,2 and so on.
- For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
- For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
- Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.
- **Examples** See examples with pictures on Leetcode only.

### Logic

### Code
```c++
#include<iostream>
#include<stack>
#include<vector>
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

  bool Comparator(const int &a, const int &b) {
    //cout<<"\nComparator a="<<a<<", b="<<b<<endl;
    return a > b ? false : true;
  }
  
class Solution {
public:
  bool CheckZigZag();
  bool isEvenOddTree(TreeNode* root);
private:
  stack<TreeNode*> mainStack;
  stack<TreeNode*> tempStack;
  vector<int> vecSorted;
  int level = 0;
};

bool Solution::isEvenOddTree(TreeNode* root){
  if (!root)
    return false;

  mainStack.push(root);
  return CheckZigZag();
}

bool Solution::CheckZigZag() {

    while (mainStack.empty() != 1) {
      while (mainStack.empty() != 1) {

        TreeNode* top = mainStack.top();
        mainStack.pop();

        if (!top)
          continue;

        vecSorted.push_back(top->val);

        cout<<top->val<<" ";

        if (level%2 == 0) {     //Even level

          if (!(top->val % 2))
            return false;

          tempStack.push(top->left);
          tempStack.push(top->right);
        }
        else                    //Odd level
        {
          if ((top->val % 2))
            return false;

          tempStack.push(top->right);
          tempStack.push(top->left);
        }
      }
      if(!is_sorted(vecSorted.begin(), vecSorted.end(), Comparator))
        return false;

      vecSorted.clear();

      if (tempStack.empty() != 1)
        tempStack.swap(mainStack);

      ++level;
    }
    return true;
}

int main(){
  TreeNode a3l(3);        //0
  TreeNode a3r(3);
  TreeNode a7(7);
  TreeNode a4(4,&a3l,&a3r);
  TreeNode a2(2,&a7,nullptr);
  TreeNode r(5,&a4,&a2);

  TreeNode* root = &r;

  Solution s;
  cout<<s.isEvenOddTree(root);
}
```
