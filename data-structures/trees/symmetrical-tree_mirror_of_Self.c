/*What is Symmetrical BT?
 * Tree which is mirror image of each other on left & right hand
 * Example:
 * 	1
 *     / \
 *    2   2
 *   / \  /\
 *  4  3  3 4
 *
 *  Logic:
 *  Approach_1:	Traverse inorder. Save elements in Array. Traverse Array from Front & Back. Compare
 *  Approach_2:	Do comparison inside function only, No need to store in separate array 
 */
#include<stdio.h>
typedef struct Node{
	int val;
	struct Node *left;
	struct Node *right;
}NODE;
NODE *create () {
	NODE *ptr;
	ptr = (NODE*)malloc (sizeof(NODE));
	ptr->val = 1;
	ptr->left = (NODE*)malloc (sizeof(NODE));
	ptr->right = (NODE*)malloc (sizeof(NODE));
	ptr->left->val = 2; ptr->right->val = 2;
	ptr->left->left = (NODE*)malloc (sizeof(NODE));
	ptr->left->right = (NODE*)malloc (sizeof(NODE));
	ptr->left->left->val = 4; ptr->left->right->val = 3;
	ptr->left->left->left = ptr->left->left->right = ptr->left->right->left = ptr->left->right->right = NULL;
	ptr->right->left = (NODE*)malloc (sizeof(NODE));
	ptr->right->right = (NODE*)malloc (sizeof(NODE));
	ptr->right->left->val = 3; ptr->right->right->val = 4;
	ptr->right->left->left = ptr->right->left->right = ptr->right->right->left = ptr->right->right->right = NULL;
	return ptr;
}
int approach_2(NODE *a, NODE*b){
    return (a&&b)? (a->val == b->val) && approach_2(a->left, b->right) && approach_2(a->right, b->left) : (a==b);
}
void main() {
	NODE *root = create();
	printf("Tree created\n");
//	approach-1(root);
	if(approach_2(root->left,root->right))
		printf("Symmetrical Tree\n");
	else
		printf("Non-Symmetrical Tree\n");
}

