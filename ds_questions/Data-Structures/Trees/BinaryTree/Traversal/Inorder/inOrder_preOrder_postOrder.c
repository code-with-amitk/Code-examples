#include<stdio.h>
#include<stdlib.h>
/*
        1
       /  \
      2    3
     /    / \
    4    5   6
             /
            7
 */
typedef struct node
{
    int data;
    struct node *left, *right;
}NODE;

NODE *newNode(int item)
{
    NODE *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inOrder(NODE *ptr){              //4 2 1 5 3 7 6
    if(ptr!=NULL){
        inOrder(ptr->left);
        printf("%d ", ptr->data);
        inOrder(ptr->right);
    }
}
void preOrder(NODE *ptr){             //1 2 4 3 5 6 7
    if(ptr!=NULL){
        printf("%d ", ptr->data);
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}
void postOrder(NODE *ptr){          //4 2 5 7 6 3 1
    if(ptr!=NULL){
        postOrder(ptr->left);
        postOrder(ptr->right);
        printf("%d ", ptr->data);
    }
}
int main()
{
    NODE *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->right->left = newNode(7);
    printf("\nTree Created");
    printf("\nInorder traversal:");
    inOrder(root);
    printf("\nPostorder traversal:");
    postOrder(root);
    printf("\nPreorder traversal:");
    preOrder(root);
}
