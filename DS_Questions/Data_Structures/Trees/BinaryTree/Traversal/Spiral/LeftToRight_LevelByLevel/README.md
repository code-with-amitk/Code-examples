**Level Order Traversal**
- Approach-1 / Queue
  - [Logic](#log1)
  - [Complexity](#c)
  - [Code](#cpp1)

### [Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
- Given the root of a binary tree, return the level order traversal of its nodes values. (i.e., from left to right, level by level).
```c
      3
     / \
    9   20
        / \
       15  7

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]       
```

## Approach-1 / Queue
<a name=log1></a>
### Logic
- _1._ if tree is empty return null
- _2._ if not empty push root on queue. Push null on queue. NULL is level seperator. After every level we will insert null.
```c
 |3|null|
```
- _3._ while until queue is empty
- _3a._ if non-null entry found. Insert left, right on queue (if left, right exist).
```c
 |9|20|
```
- _3b._ if null entry found. push null. Also create output vector.
```c
 |9|20|null|
```

<a name=c></a>
### Complexity
- **Time:** O(n). n=number of nodes
- **Space:** O(m). m=Max number of nodes on any level

<a name=cpp1></a>
### Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
  std::vector<std::vector<int>> vecNodes;
  std::vector<int> vecLevel;
  std::queue<TreeNode*> qTree;
  TreeNode* pNode;
  
public:
  vector<vector<int>> levelOrder(TreeNode* pRoot) {
    if (!pRoot)                   
      return vecNodes;

    qTree.push(pRoot);            
    qTree.push(NULL);             

    while (qTree.size() > 1){        
      pNode = qTree.front();
      qTree.pop();

      if (!pNode) {
        qTree.push(NULL);
        vecNodes.push_back(vecLevel);
        vecLevel.clear();
      } else {     
        vecLevel.push_back(pNode->val);
        if(pNode->left)
          qTree.push(pNode->left);
        if(pNode->right)
          qTree.push(pNode->right);
      }
    }//while
    
    if (vecLevel.size())
      vecNodes.push_back(vecLevel);        
    return vecNodes;        
  }
};
```
