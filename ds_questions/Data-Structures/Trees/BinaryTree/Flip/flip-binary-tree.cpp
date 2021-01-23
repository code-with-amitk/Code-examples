/*
Flip Binary Tree? Means rotating the tree towards right direction clockwise.
Tree:
                1
              /   \
             2     3
            / \   / \
           4  5   6  7
Answer:
                4
              /   \
             5     2
                  / \
                 3   1
                / \
               6   7

How flipped tree is achieved?         
a. Leftmost leaf node becomes root.
b. Recursively perform this for all nodes:
        - Parent of leafmost leaf node becomes right child.
        - Right sibling of leafmost leaf node becomes left child.
        - Repeat this process of all nodes.
*/

#include<iostream>
using namespace std;

typedef struct node{
        int val;
        struct node *left, *right;
}Node;

class tree{
        Node *r;
public:
        void create();
        Node *newNode(int a){
                Node *p = new Node;
                p->val = a;
                p->left = p->right = NULL;
                return p;
        }
        Node *flip(Node *);
        void inorder(Node *);
};

void tree::inorder(Node *r){
        if(!r)
                return;
        if(r->left)
                inorder(r->left);
        cout<<r->val<<" ";
        if(r->right)
                inorder(r->right);
        return;
}

void tree::create(){
        r = newNode(1);
        r->left = newNode(2);
        r->right = newNode(3);
        r->left->left = newNode(4);
        r->left->right = newNode(5);
        r->right->left = newNode(6);
        r->right->right = newNode(7);
        cout<<"Tree created\n";
        r = flip(r);
        cout<<"Tree flipped\n";
        cout<<"Inorder traversal:\n";
        inorder(r);
}

Node *tree::flip(Node *r){
        if (r == NULL)
                return r;

        if (r->left == NULL && r->right == NULL)
                return r;

        Node* k = flip(r->left);

        r->left->left = r->right;
        r->left->right = r;
        r->left = r->right = NULL;

        return k;
}

int main(){
        tree t;
        t.create();
}
/*
Output:
# ./a.out 
Tree created
Tree flipped
Inorder traversal:
5 4 6 3 7 2 1
*/
