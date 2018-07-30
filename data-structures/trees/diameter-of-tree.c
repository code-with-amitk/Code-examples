/*
 * Diameter:	Number of nodes on longest path between 2 nodes of Tree
 *  	 1
 *      / 
 *     2
 *    / \
 *   4   5
 *  / 	  \
 * 8  	   10
 * Here: Diameter is 4 between 8 & 10, This does not passed through ROOT
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int val;
	struct node *right;
	struct node *left;
}NODE;
int lv,rv;
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

}
int fD(NODE *ptr){
#if 0	//Wrong logic. TBD
	if(ptr->left) {
		lv++;
		lv = fD(ptr->left);
	}
	if(ptr->right) {
		rv++;
		rv = fD(ptr->right);
	}
	return ((lv>rv)?lv:rv);
#endif
}
void main(){
	NODE *root = create();
	printf("Tree Created\n");
	printf("Diameter=%d\n",fD(root));	//findDiameter
}
