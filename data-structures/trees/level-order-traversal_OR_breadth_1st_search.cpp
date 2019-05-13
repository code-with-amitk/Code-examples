#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
//using namespace std;
/*
        12
       /  \
      10  30
     /    / \
   14   25   40
             /
            50

Logic: 
- Traverse Level by level.
- Take a vector, insert elements in it as follows:
        a. Insert root
        b. Insert left and right elements of visted node.
        c. Visit left child, right child.
        d. Goto step b.
 */
struct node
{
    int data;
    struct node *left, *right;
};
std::vector <int> queue;

struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void lv(struct node *root){
        if (root==NULL)  return;
        if(root->left){ queue.push_back(root->left->data); }
        if(root->right){ queue.push_back(root->right->data); }
        if(root->left){ lv(root->left); }
        if(root->right){ lv(root->right); }
        return;
}

int main()
{
    struct node *root = newNode(12);
    root->left = newNode(10);
    root->left->left = newNode(14);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    root->right->right->left = newNode(50);

    queue.push_back(root->data);
    lv(root);

    for(int i=0;i<queue.size();i++)
        std::cout<<" "<<queue[i];
    std::cout<<"\n";
    return 0;
}
