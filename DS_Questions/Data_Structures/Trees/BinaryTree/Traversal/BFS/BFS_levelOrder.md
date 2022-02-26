- **Level Order Traversal**
- [Logic](#l)
- [Complexity](#c)
- Code
  - [CPP](#c1)

## [Level Order](https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/)
- Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
- Output is returned in 2-D vector.
```c++
        12
       /  \
      10  30
     /    / \
   14   25   40
             /
            50
O/P ->  12 
        10 30 
        14 25 40 
        50
```
<a name=l></a>
## Logic (QUEUE)
1. Take a queue. Allocate a temp node (value=2000 which is greater than max allowed value)
2. Push root, temp in queue. temp is pushed to track levels.
3. while(queue.empty() != 1)
```c
  pop top;
  if (top == null)
    push null.
    push 1D vector to 2D vector
  else
    push top in 1D
    if(node has left)
        push on queue
    if(node has right)
        push on queue        
```
<a name=c></a>
### Complexity
- Time: O(n) reaching all nodes.
- Space: O(n) queue to hold elements.
 
### Code
<a name=c1></a>
#### CPP
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
 
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
    using vecI = vector<int>;
    using vecVecI = vector<vector<int>>;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vecVecI out;
        vecI level;
        queue<TreeNode*> q;
        
        if (!root)
            return out;
        
        TreeNode* temp = new TreeNode(2000);

        q.push(root);
        q.push(temp);
        
        while (q.empty() != 1){
            TreeNode* front = q.front(); q.pop();
            
            if (front && front->left)
                q.push(front->left);
            if (front && front->right)
                q.push(front->right);
            
            if (front->val == 2000) {
                out.push_back(level);
                level.clear();
                if (q.size())
                    q.push(temp);
                else
                    break;
            }else
                level.push_back(front->val);

        }
        return out;
    }
};

int main(){
    TreeNode* r7 = new TreeNode(7);
    TreeNode* r15 = new TreeNode(15);
    TreeNode* r20 = new TreeNode(20, r15, r7);
    TreeNode* r9 = new TreeNode(9);
    TreeNode* r3 = new TreeNode(3, r9, r20);
    Solution s;
    vecVecI out = s.levelOrder(r3);
    for (int i=0;i<out.size();++i){
        for (int j=0;j<out[i].size();++j)
            cout << out[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
```
