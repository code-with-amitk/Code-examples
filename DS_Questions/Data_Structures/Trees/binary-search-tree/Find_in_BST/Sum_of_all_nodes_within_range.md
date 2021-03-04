## [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/) / Sum of all nodes within Range in BST
- Given the root node of a binary search tree, return the sum of values of all nodes with a value in the range `[low, high]`.
- Examples
```c
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32    //7+10+15
            10
          /    \
        5        15
       / \        \
      3   7       18
```

### Approach-1 //[DFS](https://sites.google.com/site/amitinterviewpreparation/data-structures) using Binary Search + Recursion.
- **Logic**
  - At every node check, if node->val is within [low,high] include in sum.
  - if node->val < low, Move to right
  - if node->val > high, move to left
- **Complexity:**
  - **Time:** O(logn)
  - **Space:** [O(logn)](/DS_Questions)  //Recursion Stack
```c++
class Solution {
public:
    int BinarySearch(TreeNode* root, int low, int high) {
        if (root == nullptr)
            return 0;
        
        int count=0;
        if(root->val >= low && root->val <= high)
            count += root->val;
        count += BinarySearch(root->left, low, high);
        count += BinarySearch(root->right, low, high);
        return count;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        return BinarySearch(root,low,high);
    }
};
```

### Approach-2 //DFS using Iteration
- **Logic** DFS uses stack. Touch every node in path to reach deepest node and come back, instead of reaching all neighbours.
  - *1.* Take stack`<TreeNode*>`. push root on it
  - *2.* Pop top and perform this this till stack is not empty.
```c
  if popped->val lies between low and high
    count += popped->val
  else if popped->val < low
    move right
  else if popped->val > high
    move left
  else
    move left and right both
 ```
- **Complexity**
  - **Time:** O(logn)
  - **Space:** [O(logn)](/DS_Questions)
- **Code**
```c++
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int count=0;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* t = st.top(); st.pop();
            if (t){
                if (t->val >= low && t->val <= high)
                    count += t->val;
                if (t->val < low)
                    st.push(t->right);
                else if (t->val > high)
                    st.push(t->left);
                else{
                    st.push(t->left);
                    st.push(t->right);
                }
            }
        }
        return count;
    }
};
```
