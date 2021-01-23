## [Problem](https://leetcode.com/problems/longest-univalue-path/)
- Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
- The length of path between two nodes is represented by the number of edges between them.

## Note
- This question is about longest path on both side.

## Example
```
      4
     / \
    4   4
   / \   \
  4   9   5
 /
4

Answer = 4
```

## Logic
> There are 4 parts of this algorthm which needed to carried on every node:
1. Traversing to child nodes
2. Is there any child(of current node) whose value is equal to mine?
```
  if(yes)
    same_child_as_me = (recieved_value_of_same_child_nodes + 1);
  else
    same_child_as_me = 0;
```
3. Maintaining a single Reference/global variable b/w function calls which stores **maximum path length till present node(ON BOTH SIDES)**
   - This is the answer we are seeking and will return finally.
```
  return max(stored_value, leftPath+rightPath)
```
4. Return Maximum pathlen of only 1 side. This is because for node above present node, there is no signifiance of pathlen of both sides.
  
  
## Code
```c++
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

int len(TreeNode *node, int &a) {
  if (!node)
    return 0;

  int lmax = 0, rmax = 0;

  //Check subtrees
  int leftLen = len(node->left, a);                           //1
  int rightLen = len(node->right, a);

  //Curr node and it's left child has same value
  if (node->left && node->left->val == node->val)             //2
    lmax += leftLen + 1;

  //Curr node and it's right child has same value
  if (node->right && node->right->val == node->val)           //2
    rmax += rightLen + 1;

  a = max(a, lmax + rmax);                                    //3
  return max(lmax, rmax);                                     //4
}

int longestSameValuePath(TreeNode *root) {
  int pathLen = 0;
  len(root, pathLen);
  return pathLen;
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
  cout<<longestSameValuePath(&ne4);
}
```
