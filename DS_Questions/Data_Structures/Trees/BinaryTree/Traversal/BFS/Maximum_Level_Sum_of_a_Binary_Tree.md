**Maximum Level Sum of a Binary Tree**
- [Approach-1](#a1)


### Maximum Level Sum of a Binary Tree
- Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
- Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
```c
Example 1:
Input: root = [1,7,0,7,-8,null,null]
          1
        /    \
      7       0
    /  \
  7    -8
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
```

<a name=a1></a>
### Approach-1
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
public:
    int maxLevelSum(TreeNode* root) {
                            //key=sum,value=level
        priority_queue<pair<int, int>> pq;

        // if level is already inserted do not insert again.
        unordered_set<int> usSum;
        int max_val = 100001;
        TreeNode maxn = TreeNode(max_val);  //Level seperator
        TreeNode* maxi = &maxn;
        queue<TreeNode*> q;
        q.push(root);
        q.push(maxi);
        int sum = 0, level = 1;

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node && node->left)
                q.push(node->left);
            if (node && node->right)
                q.push(node->right);

            if (node->val == max_val) {
                // This is next level
                if (usSum.find(sum) == usSum.end()) {
                    usSum.insert(sum);
                    pq.push ({sum, level});
                }
                sum=0;
                level++;
                if (q.size())
                    q.push(maxi);
            } else {
                // Same Level. Keep on adding values
                sum += node->val;
            }
        }
        return pq.top().second;
    }
};
```
