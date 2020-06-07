/*      0
      /   \
     1     2
    /  \  /  \
   4   5 6    7
  / \
 8   9
What Lowest Common Ancestor(LCA) of Node-1, Node-2? The LCA of (Node-1,Node-2) is the 
1st common node in ancestors of node-1 & node-2.
Examples: 
a. LCA for 8,5 is 1. Bcoz 1 is 1st common node in ancestors of 8,5. Ancestors of 8: 8, 4, 1.    Ancestors of 5: 5,1
b. LCA for 6,2 is 2. Bcoz we consider node is ancestor of itself.

Logic:
        - Search node-1,node-2 in Tree.
        - if either node-1 or node-2 is found, return that node Address.
        - On whichever node ((left returned Address != NULL) && (right returned Address != NULL)) 
        This is the common Ansector. Print.
*/
#include<iostream>
struct Node{
        int data;
        Node *left;
        Node *right;
};
Node *create(int val){
        Node* ptr = new Node;
        ptr->data = val;
        ptr->left = ptr->right = NULL;
        return ptr;
}
Node *findLCA(Node *root, int val1, int val2){
        Node *left = NULL, *right = NULL;
        if(!root)return NULL;

        if(root->data == val1 || root->data == val2){
//              std::cout<<root->data<<std::endl;
                return root;
        }
        if(root->left)  left = findLCA(root->left, val1, val2);
        if(root->right) right = findLCA(root->right, val1, val2);
        if((left != NULL) && (right != NULL)){
                //This is the node
                std::cout<<root->data<<std::endl;
        }
        if(left!=NULL)return left;
        if(right!=NULL)return right;
        return NULL;
}

int main(){
        Node *root = create(0);
        root->left = create(1);
        root->right = create(2);
        root->left->left = create(4);
        root->left->right = create(5);
        root->right->left = create(6);
        root->right->right = create(7);
        root->left->left->left = create(8);
        root->left->left->right = create(9);
        std::cout<<"Tree Created"<<std::endl;

        //findLCA(root, 1, 0);  =>      0
        //findLCA(root, 1, 5);  =>      1
        //findLCA(root, 9, 5);  //=>    1
        //findLCA(root, 4, 5);  =>      1
        //findLCA(root, 6, 7);  =>      2
        findLCA(root, 8, 7);    //=>    0
}
