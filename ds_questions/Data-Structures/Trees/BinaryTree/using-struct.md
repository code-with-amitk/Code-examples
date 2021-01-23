## 1. Create BT using struct
```
  1
   \
    2
   /
  3

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main(){
  TreeNode n3(3);
  TreeNode n2(2, &n2, NULL);
  TreeNode n1(1, NULL, &n2);
  cout<<"Tree created";
}  
```
