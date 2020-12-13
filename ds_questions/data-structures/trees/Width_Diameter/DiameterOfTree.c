/*
 * Diameter:	Number of nodes on longest path between 2 nodes of Tree
 *  	 1
 *      / 
 *     2
 *    / \
 *   4   5
 *  / 	  \
 * 8  	   10
 Here: Diameter is 5 between 8 & 10. Nodes are counted in diameter.
 8,4,2,5,10 -> 5 nodes. Diameter 5.
 
 Logic:	
 diameter = max ((leftHeight + rightHeight + 1) , max(leftDiameter, rightDiameter))
 
 So, 4 things to be calculated:
 	a. leftHeight
	b. rightHeight
	c. leftDiameter
	d. rightDiameter
 */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct node {
	int val;
	struct node *right;
	struct node *left;
}NODE;

NODE *create() {
	NODE *ptr = (NODE *) malloc (sizeof(NODE));
	ptr->val = 1;	ptr->right = NULL;	
	ptr->left = (NODE *) malloc (sizeof(NODE));
	ptr->left->val = 2;	
	ptr->left->left = (NODE *) malloc (sizeof(NODE));
	ptr->left->left->val=4;	ptr->left->left->right = NULL;
	ptr->left->left->left = (NODE *) malloc (sizeof(NODE));
	ptr->left->left->left->val = 8;
	ptr->left->left->left->left = ptr->left->left->left->right = NULL;
	ptr->left->right = (NODE *) malloc (sizeof(NODE));
	ptr->left->right->val = 5; 	ptr->left->right->left = NULL;
	ptr->left->right->right = (NODE *) malloc (sizeof(NODE));
	ptr->left->right->right->val=10; ptr->left->right->right->left=NULL;
	ptr->left->right->right->right=NULL;
	return ptr;
}

int height(NODE *node){
        if (node == NULL)return 0;
        return 1 + max(height(node->left), height(node->right));	
}

int diameter(NODE *ptr){
	if(ptr == NULL) return 0;
	int leftHeight = height(ptr->left);
	int rightHeight = height(ptr->right);
	int leftDiameter = diameter(ptr->left);
	int rightDiameter = diameter(ptr->right);
	
	return max((leftHeight + rightHeight + 1), max(leftDiameter, rightDiamter));
}

void main(){
	NODE *root = create();
	printf("Tree Created\n");
	printf("Diameter=%d\n",diameter(root));	//findDiameter
}
