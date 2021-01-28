## [Problem](https://leetcode.com/problems/diameter-of-binary-tree/)
- **Diameter?**	Number of nodes on longest path between 2 nodes of Tree
```c++
 	1
       / 
      2
     / \
    4   5
   / 	  \
  8  	   10
 Here: Diameter is 4 between 8 & 10 only edges are calculated 8,4,2,5,10 -> 4
```	 
 
 ## Logic
 - diameter = max ((leftHeight + rightHeight + 1) , max(leftDiameter, rightDiameter))
 - So, 4 things to be calculated:
  a. leftHeight
  b. rightHeight
  c. leftDiameter
  d. rightDiameter
 
 ## Code
 ```c++
#include<iostream>
#include<algorithm>

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}};

TreeNode* Create() {
  TreeNode* p4 = new TreeNode(4);
  TreeNode* p5 = new TreeNode(5);
  TreeNode* p3 = new TreeNode(3);
  TreeNode* p2 = new TreeNode(2, p4, p5);
  TreeNode* p1 = new TreeNode(1, p2, p3);
  return p1;
}

int Height(TreeNode* node){
  if (node == NULL)return 0;
    return 1 + std::max(Height(node->left), Height(node->right));
}

int Diameter(TreeNode* pRoot){
  if(pRoot == NULL)
    return 0;
  int leftHeight = Height(pRoot->left);
  int rightHeight = Height(pRoot->right);
  int leftDiameter = Diameter(pRoot->left);
  int rightDiameter = Diameter(pRoot->right);

  return std::max((leftHeight + rightHeight ), std::max(leftDiameter, rightDiameter));
}

int main(){
  TreeNode* pRoot = Create();
  printf("Tree Created\n");
  printf("Diameter=%d\n",Diameter(pRoot));  //findDiameter
}
```
