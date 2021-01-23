## [Problem](https://leetcode.com/problems/longest-univalue-path/)
- Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
- The length of path between two nodes is represented by the number of edges between them.

## Note
- This question is about longest path on 1 side.
- another variant is for both sides.

## Example
```
      4
     / \
    4   4
   / \   \
  4   9   5
 /
4
This Algo will give Answer = 3
On-Both-sides will give answer = 4
```

## Logic
1. Start from root
2. Traverse left, right subtrees
3. At each node:
  - Find length of left Subtree
  - Find length of right subtree
  - if(present_node's_value == left_child's_value)
      leftVal = left_subree_length + 1
  - if(present_node's_value == right_child's_value)
      rightVal = right_subree_length + 1
  - We need to consider the greater length
      max(leftVal, rightVal)

## Code
```
#include<iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}  
};

int length(TreeNode *node) {
  if (!node)
    return 0;

  //Check subtrees
  int leftPath = length(node->left);
  int rightPath = length(node->right);

  // If curr node and it's left child has same value
  if (node->left && node->left->val == node->val)
    leftPath += 1;

  return max(leftPath, rightPath);
}

int main(){
/*
      4
     / \
    4   4
   / \   \
  4   9   5
 /
4
*/
  TreeNode na4(4,NULL,NULL);
  TreeNode nb4(4,&na4,NULL);
  TreeNode n9(9,NULL,NULL);
  TreeNode nc4(4,&nb4,&n9);
  TreeNode n5(5,NULL,NULL);
  TreeNode nd4(4,NULL,&n5);
  TreeNode ne4(4,&nc4,&nd4);
  cout<<"Created Tree\n";
  cout<<length(&ne4);             //3
}    
```
