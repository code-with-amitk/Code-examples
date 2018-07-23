/* This code creates a simple BST and checks if Tree is BST or not
 * 	5
 *     / \
 *    3	  6
 *   / \
 *  2	4 
 */
#include<stdio.h>
#include<stdlib.h>	//malloc
typedef struct node {
	int val;
	struct node *left;
	struct node *right;
}NODE;

NODE *createBST (){
	NODE *ptr;
	ptr = (NODE *) malloc (sizeof(NODE));
	ptr->val = 5;
	ptr->left = (NODE *) malloc (sizeof(NODE));
	ptr->left->val = 3;
	ptr->left->left = (NODE *) malloc (sizeof(NODE));
	ptr->left->right = (NODE *) malloc (sizeof(NODE));
	ptr->left->left->left = ptr->left->left->right = NULL;
	ptr->left->left->val = 2;
	ptr->left->right->val = 4;
	ptr->left->right->left = ptr->left->right->right = NULL;

	ptr->right = (NODE *) malloc (sizeof(NODE));
	ptr->right->val = 6;
	ptr->right->left = NULL;
	ptr->right->right = NULL;

	return ptr;
}

int isBST (NODE *ptr, int parentVal, int isLeft, int isRight) {
	int temp;
	if(isLeft && (ptr->val > parentVal))
		return 1;
	if(isRight && (ptr->val < parentVal))
		return 1;

	if (ptr->left) 
		temp = isBST(ptr->left,ptr->val,1,0);
	if (ptr->right) 
		temp = isBST(ptr->right,ptr->val,0,1);
	return temp;
}

void main() {
	NODE *root = createBST();
	printf("Tree created\n");

	if(isBST(root, 5, 0, 0)) {
		printf("Not BST\n");
	} else {
		printf("Tree is BST\n");
	}
}

/* Output:
 * Tree created
 * Tree is BST
 */
