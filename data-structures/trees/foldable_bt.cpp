/*              foldable_bt.cpp

Foldable Tree? A tree can be folded if left and right subtrees of the tree are structure wise mirror image of each other.
 Empty tree is foldable
Examples:
                1
              /   \
             2     3    //Foldable Tree
              \   /
               4 5

               1
             /   \
            2     3     //Non-foldable Tree
           /     /
          4      5

Logic:
- same as mirror of tree. Just values are not checked.
*/

#include<iostream>
using namespace std;

typedef struct node{
        int val;
        struct node *left;
        struct node *right;
}Node;

Node *create(int v){
        Node *p = new Node;
        p->left = p->right = NULL;
        p->val = v;
        return p;
}

int mirror(Node*, Node*);
int foldable(Node *p){
        if(!p)                  //Empty tree is foldable
                return 1;
        if(!p->left && !p->right)       //Single root is foldable
                return 1;

        return mirror(p->left,p->right);
}

int mirror(Node *a, Node*b){
        if(a!=NULL && b!=NULL){
                int i = mirror(a->left,b->right);
                int j = mirror(a->right,b->left);
                return i&&j;
        }else if(a==NULL && b==NULL){
                return 1;
        }
        return 0;
}

int main() {
        Node *r = create(1);
        r->left = create(2);
        r->left->right = create(3);
        r->right = create(4);
        r->right->right = create(5);

        if(foldable(r))
                cout<<"Fodable\n";
        else
                cout<<"Not Foldable\n";
}
