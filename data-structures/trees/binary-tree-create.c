/* Create this:
 * 	1
 *     / \
 *    2   3
 *   /
 *  4    
 */
#include<stdio.h>
#include<stdlib.h>	//malloc()
typedef struct node {
	int ele;
	struct node *left;
	struct node *right;
}Node;

Node* create(int ele) {
	Node* ptr = (Node *) malloc (sizeof(Node));
	ptr->ele = ele;
	ptr->left = NULL;
	ptr->right = NULL;
}

void main() {
	Node *root = create (1);
	root->left = create(2);
	root->right = create(3);
	root->left->left = create(4);
	printf("Just Created");
}
/*
 * Output:
 * Just Created
 */
