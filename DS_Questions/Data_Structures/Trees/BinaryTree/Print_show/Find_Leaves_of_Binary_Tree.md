**Find Leaves of Binary Tree**
- [Approach-1. O(nlogn). DFS with Sorting = Get Height of every Node, insert into multimap](#a1)
- [Approach-2. O(n). DFS without sorting = Get Height of every node, insert directly to output](#a2)
  - [Logic](#l)
  - Code
    - [CPP](#cpp)
    - [Java](#j)

### [366. Find Leaves of Binary Tree](https://leetcode.com/problems/find-leaves-of-binary-tree/description/)
- Given the root of a binary tree, collect a tree's nodes as if you were doing this:
  - Collect all the leaf nodes.
  - Remove all the leaf nodes.
  - Repeat until the tree is empty.
```c
Example 1:
    1
   / \
  2   3 
 / \
4   5 
Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it does not matter the order on which elements are returned.
```

<a name=a1></a>
### Approach-1. O(nlogn). DFS with Sorting = Height of every Node, multimap
- Find height of everynode, store in multimap
```c
[Height]
        1[2]
       /   \
     2[1]   3[0]
   /    \
  4[0]   5[0]

multimap m<height, node>;
<0,5>, <0,4>, <0,3>, <1,2>, <2,1>
```
- Store nodes of same height in vector
```c
5,4,3
2
1
```
#### Complexity
- **Time** O(nlogn). Updating multimap on every node might need to balance on every node.
  - O(n): Traversing every node in tree
  - O(logn): Balancing of multimap
#### Code
**CPP**
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
    multimap<int, int> height;
public:
    int findHeight(TreeNode* root){
        int lh=0, rh=0;
        if (root->left)
            lh += findHeight(root->left);
        if (root->right)
            rh += findHeight(root->right);
        height.insert(pair<int, int>(max(lh,rh), root->val)); 
        return max(lh,rh)+1;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        //Find Height of nodes
        findHeight(root);

        vector<vector<int>> out;
        vector<int> temp;
        //Store all same heighted nodes in 1 row in vector
        int presentHeight = height.begin()->first;
        for (auto&i:height){
            if (i.first == presentHeight){
                temp.push_back(i.second);
            }else{
                out.push_back(temp);
                temp.clear();
                presentHeight = i.first;
                temp.push_back(i.second);
            }
        }
        //Insert last entries
        out.push_back(temp);
        
        return out;
    }
};
```

<a name=a2></a>
### Approach-2. O(n). DFS without sorting = Get Height of every node, insert directly to output
<a name=l></a>
#### Logic
- Find height of everynode, store directly in output vector
```c
[Height]
        1[2]
       /   \
     2[1]   3[0]
   /    \
  4[0]   5[0]

vecOutput
{4,5,3} {2} {1}
  0      1   2
```
#### Complexity
- **Time:** O(n). Traverse to every node of tree
- **Space:** O(n)
#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
    int findHeight(TreeNode* root, vector<vector<int>>& vecOutput){
        int lh=0, rh=0;
        if (root->left)
            lh += findHeight(root->left, vecOutput);
        if (root->right)
            rh += findHeight(root->right, vecOutput);

        int currHeight = max(lh,rh);

        // We start with 0 sized vecOutput
        // (4,5,3) height=0. Insert empty vector<int>
        // (2) height=1. Insert empty vector<int>
        // (1) height=2. Insert empty vector<int>
        if (vecOutput.size() == currHeight)
            vecOutput.push_back({});

        // Directly insert element in array at height index
        vecOutput[currHeight].push_back(root->val);

        return currHeight + 1;
    }
    /*
        1
       / \
      2   3 
      /\
      4 5
    */
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> vecOutput;

        //Find Height of nodes
        findHeight(root, vecOutput);

        return vecOutput;
    }
};
```
<a name=j></a>
**Java**
```java
class Solution {
    public int findHeight(TreeNode root, List<List<Integer>> listOutput) {
        int lh=0, rh=0;
        if (root.left != null)
            lh += findHeight(root.left, listOutput); 
        if (root.right != null)
            rh += findHeight(root.right, listOutput);
        int currHeight = Math.max(lh,rh);

        if (listOutput.size() == currHeight)
            listOutput.add(new ArrayList<>());
        listOutput.get(currHeight).add(root.val);

        return currHeight+1;
    }
    public List<List<Integer>> findLeaves(TreeNode root) {
        List<List<Integer>> listOutput = new ArrayList();
        findHeight (root, listOutput);

        return listOutput;
    }
}
```
