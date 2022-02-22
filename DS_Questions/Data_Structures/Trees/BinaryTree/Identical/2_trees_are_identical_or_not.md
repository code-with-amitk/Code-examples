**Same Tree**
   - [Logic](#log)
   - [Complexity](#comp)
   - [Code](#cpp)

### [Same Tree](https://leetcode.com/problems/same-tree/)
Compare 2 binary trees, return 1 if equal else 0.
```c
Input: p = [1,2,3], q = [1,2,3]
Output: true
   1          1
  / \        /  \
 2  3       2    3
    
Input: p = [1,2], q = [1,null,2]
Output: false
     1       1
    /         \
   2           2
```

<a name=log></a>
### Logic
#### Logic-1: Extra space
Traverse tree1 and tree2 and save in vector1 and vector2. if vectors are same return 1 else 0

#### Logic-2(Without Extra Space)
  - Visit same node of each tree. ie tree1 & tree2
  - if values are same do nothing
  - if different return 0.     

### Code
<a name=cpp></a>
#### CPP
 ```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int isSameTree(TreeNode* a, TreeNode* b) {
    if (a == NULL && b == NULL)                       //Both Empty
        return 1;

    if (a != NULL && b != NULL)                       //Both Non-empty
        return ((a->val == b->val) && 
                (isSameTree(a->left, b->left)) &&
                (isSameTree(a->right, b->right)));

    return 0;                             //if 1 is empty other not, return 0
}

int main(){
    TreeNode* p2a = new TreeNode(2);
    TreeNode* p3a = new TreeNode(3);
    TreeNode* p1a = new TreeNode(1, p2a, p3a);

    TreeNode* p2b = new TreeNode(2);
    TreeNode* p3b = new TreeNode(3);
    TreeNode* p1b = new TreeNode(1, p2b, p3b);
    
     //Logic without Extra Space
   cout << identicalTrees(p1a, p1b));
}
```
