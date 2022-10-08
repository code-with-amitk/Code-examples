**Level Order Traversal**
- [Approach-1, Using BFS Template](#a1)
- [Approach-2, Inserting NULL as level seperator](#a2)

## [Self Video, BFS Template](https://youtu.be/ranS-TE-kMU)

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

<a name=a1></a>
### Approach-1 / BFS Template
- [BFS Template](/DS_Questions/Algorithms/Traversals/BFS#t)
#### Logic
- [BFS Template](/DS_Questions/Algorithms/Traversals/BFS#t)
#### Code
```cpp
using vecI = vector<int>;
using vecVecI = vector<vector<int>>;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vecVecI out;
        vecI level;
        
        if (!root)
            return out;
        
        q.push(root);
        out.push_back({root->val});
        
        //Traverse whole tree
        while (!q.empty()){
            int size = q.size();
            
            //Traverse each level
            for (int i=0;i<size;++i) {
                TreeNode* f = q.front(); q.pop();
                
                if (f->left) {
                    q.push(f->left);
                    level.push_back(f->left->val);
                }
                if (f->right) {
                    q.push(f->right);
                    level.push_back(f->right->val);
                }

            }//for
            if (level.size())
                out.push_back(level);
            level.clear();
        
        }//while
        return out;
    }
};
```
#### Complexity
- **Time:** O(n). n=Number of nodes
- **Space:** O(m). m=Number of nodes a particular level

<a name=a2></a>
### Approach-2 / Inserting NULL as level seperator
#### Logic
- _1._ Take `queue<Node*>`.
- _2._ Push root on queue. Push null on queue. NULL is level seperator. After every level we will insert null.
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

#### Complexity
- **Time:** O(n). n=number of nodes
- **Space:** O(m). m=Max number of nodes on any level

#### Code
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
