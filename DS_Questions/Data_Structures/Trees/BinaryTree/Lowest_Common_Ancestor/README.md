**[Lowest Common Ancestor](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)**
- [LCA](#lca)
- **Approach-1**
  - [Logic](#l)

<a name=lca></a>
### What is LCA
LCA is defined between two tree nodes p, q as the lowest node in tree that has both p and q as descendants (where we allow a node to be a descendant of itself).
- Examples
```
        p,q
 LCA of 1,2 is 0
 LCA of 8,5 is 1. Bcoz 1 is 1st common node in ancestors of 8,5. Ancestors of 8: 8, 4, 1.    Ancestors of 5: 5,1
 LCA of 6,2 is 2. Bcoz we consider node is ancestor of itself.
 
        0
      /   \
     1     2
    /  \  /  \
   4   5 6    7
  / \
 8   9
```

### Approach-1, Compare during inorder traversal
<a name=l></a>
#### Logic
- _1._ if `node->val == p->val` it will return self address.
- _2._ On any node, if value returned from both left and right children are nonnull, that is LCA.
- _3._ On every node check if I am left or right. if I am left(ie p) then set left pointer, if I am right(ie q) right pointer. return null.
```c  
  if (my->val == p->val)
    left = myself              
  if (my->val == q->val)
    right = myself 
```      
  - *4.* On everynode check returned from left child and right child. if both left and right are nonnull I am LCA.
- **Complexity**
  - **Time:** O(n). Visting every node once
  - **Space:** [O(n)](/DS_Questions/README.md). Space occupied by every stack in recursion.
- **Code**
```c
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
      TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
  };
 
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if(!root)
    return nullptr;
                
  TreeNode* left = lowestCommonAncestor(root->left,p,q);
  TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
  if (root->val == p->val)
    left = root;
  if(root->val == q->val)
    right = root;
        
  if (left and right)
    return root;
  else if(left)
    return left;
  else if(right)
    return right;
        
  return nullptr;
}

int main(){
  TreeNode *p8 = new TreeNode(8);
  TreeNode *p9 = new TreeNode(9);
  TreeNode *p4 = new TreeNode(4,p8,p9);
  TreeNode *p5 = new TreeNode(5);
  TreeNode *p1 = new TreeNode(1,p4,p5);
  TreeNode *p6 = new TreeNode(6);
  TreeNode *p7 = new TreeNode(7);
  TreeNode *p2 = new TreeNode(2,p6,p7);
  TreeNode *p0 = new TreeNode(0,p1,p2);
  TreeNode* ptr = lowestCommonAncestor(p0,p1,p7);
  cout<<ptr->val; //0
}
```
