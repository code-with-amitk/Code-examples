**[Same Tree](https://leetcode.com/problems/same-tree/)**


### Question
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
- **Logic-1: Extra space**
  - Traverse tree1 and tree2 and save in vector1 and vector2.
```c
  if(vector1 == vector1)
                return 1;
          else 
                return 0;
```

- **Logic-2(Without Extra Space)**
  - Visit same node of each tree. ie tree1 & tree2
  - if values are same do nothing
  - if different return 0.     

### Code
**C++**
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

std::vector<int> v1;

void inorder(Node *root){
        if(!root) return;
        if(root->left) inorder(root->left);
        v1.push_back(root->data);
        //std::cout<<"Pushing back:"<<root->data<<"\n";
        if(root->right) inorder(root->right);
}

int compare(Node *t1, Node *t2){
        std::vector<int> vt1, vt2;

        inorder(t1);
        vt1 = v1;               //vt1 has tree1 nodes in inorder
        v1.clear();

        inorder(t2);
        vt2 = v1;

        if(vt1 == vt2){
                std::cout<<"Returning 1"<<std::endl;
                return 1;
        }else{
                std::cout<<"Returning 0"<<std::endl;
                return 0;
        }
}

int identicalTrees(Node* a, Node* b)          //Without extra space
{
    /*1. both empty */
    if (a == NULL && b == NULL)
        return 1;

    /* 2. both non-empty -> compare them */
    if (a != NULL && b != NULL)
    {
        return ((a->data == b->data) && (identicalTrees(a->left, b->left)) && (identicalTrees(a->right, b->right)));
    }

    /* 3. one empty, one not -> false */
    return 0;
}

int main(){
        Node *tree1, *tree2;
        tree1 = createTree1();
        tree2 = createTree2();
        std::cout<<"Trees created tree1="<<tree1<<" tree2="<<tree2<<"\n";
        /*if(compare(tree1, tree2))
                std::cout<<"Equal Trees";
        else
                std::cout<<"Non Equal Trees";*/
 
        //Logic without Extra Space
        if(identicalTrees(tree1, tree2))
                std::cout<<"Equal Trees";
        else
                std::cout<<"Non Equal Trees";

}
