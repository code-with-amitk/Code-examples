**All Nodes Distance K in Binary Tree**
- [Approach-1. DFS. O(n)](#a1)
  - [Logic](#l)
  - Code
    - [CPP](#cpp)

### [863. All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/)
- Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
- You can return the answer in any order.
```c
Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
         3
        /  \
       5    1
      /\    / \
     6  2   0  8
        /\
       7  4
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
```

<a name=a1></a>
### Approach. DFS. O(n)
<a nam=l></a>
#### Logic
- _1._ Take `unordered_map<node=TreeNode,distance>`
- _2._ Find distance of root from target node. `root, 1`
- _3._ Perform DFS on all other nodes. increment ditance by 1 when jumping to child node
  - if (distance == k) store node in output vector
#### Code
<a name=cpp></a>
**CPP**
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> um;
    TreeNode* tar;
    int k;
public:
    /*
            3
          /   \
        5       1
       / \      / \
       6  2     0   8
          /\
         7  4
    */
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        tar = target;
        k = K;
        vector<int> out;
        get_distance_of_root_from_target(root);
        /*
        // Distance of root from target
        um   | key=5,value=0 | key=3,value=1 |
        */
        for(auto&i:um){
            cout << i.first << "," << i.first->val << "," << i.second << "\n";
        }
        //  3       1(distance from target)       
        dfs(root, um[root], out);
        return out;
    }
    
private:
    int get_distance_of_root_from_target(TreeNode* root) {
        if (root == tar) {
            um[root] = 0;
            return 0;
        }
        if (root->left){
            int left = get_distance_of_root_from_target(root->left);
            if (left >= 0) {
                um[root] = left+1;
                return left+1;
            }
        }
        if (root->right){
            int right = get_distance_of_root_from_target(root->right);
            if (right >= 0) {
                um[root] = right+1;
                return right+1;
            }
        }
        return -1;
    }
    
    void dfs(TreeNode* node, int distance_from_target, vector<int>& out) {
        if (um.find(node) != um.end())
            distance_from_target = um[node];

        // if distance from target==k, Fill in output vector
        if (distance_from_target == k)
            out.push_back(node->val);

        if (node->left)
            dfs(node->left, distance_from_target + 1, out);
        if (node->right)
            dfs(node->right, distance_from_target + 1, out);
    }
};
```


