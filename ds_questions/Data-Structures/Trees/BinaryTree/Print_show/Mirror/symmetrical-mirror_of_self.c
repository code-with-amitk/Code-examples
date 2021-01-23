/*
Symmetrical BT? Tree which is mirror image of each other on left & right hand.
  Example:
        1
      / \
     2   2
    / \  /\
   4  3  3 4
 
Logic-1: Traverse inorder. Save elements in Array. Traverse Array from Front & Back. Compare
 
*****************Logic-2********************
a. Pass left and right children into comparsion fun
b. Check (left->val == right->val)
c. Recursively perform this check for 
        a->left == b->right
        and
        a->right == b->left
********************************************
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

int mirror(Node *a, Node*b){
        if(a!=NULL && b!=NULL){
                if(a->val == b->val){
                        int i = mirror(a->left,b->right);
                        int j = mirror(a->right,b->left);
                        return i&&j;
                }else{
                        return 0;
                }
        }else if(a==NULL && b==NULL){
                return 1;
        }else{
                return 0;
        }
}

int main() {
        Node *r = create(1);
        r->left = create(2);
        r->left->left = create(4);
        r->left->right = create(3);
        r->right = create(2);
        r->right->left = create(3);
        r->right->right = create(4);

        if(mirror(r->left,r->right))
                cout<<"Mirror\n";
        else
                cout<<"Not mirror\n";
}
/*Output:
Mirror
*/
