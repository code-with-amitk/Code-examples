/*
	height-of-tree.c	

Height: Number of edges from Root to deepest leaf node.
                1
               / \
              2   3
             / 
            4  
           /
          6
         /
        7 
       / \
      9   8
      
Ouput: 6
*/
#include<iostream>
using namespace std;

typedef struct node{
        int v;
        struct node *left, *right;
}Node;

Node *newnode(int a){
        Node *p = new Node;
        p->v = a;
        p->left=p->right=NULL;
        return p;
}

int hgt(Node *r){
  if(!r)
    return 0;
   return (max(hgt(r->left), hgt(r->right))+1);
}
/*
int hgt(Node *r){
   if (!root)
     return 0;
   int lchild = hgt(root->left);
   int rchild = hgt(root->right);
   if (lchild > rchild)
     return lchild+1;
   else
     return rchild+1;
   return 0;
}
*/

int main(){
        Node *r = newnode(1);
        r->left = newnode(2);      r->right = newnode(3);
        r->left->left = newnode(4);
        r->left->left->left = newnode(6);
        r->left->left->left->left = newnode(7);
        r->left->left->left->left->left = newnode(9);
        r->left->left->left->left->right = newnode(8);

        cout<<hgt(r)<<"\n";
}
