/* subtree: Tree1:
 * 	3
 *     / \
 *    6   7
 * Main Tree:
 * 	1
 *     /  \
 *    2    3
 *   / \  / \
 *  4  5  6  7
 *
 *  Logic:
 * 1. create_subtree(): Create subtree 3,6,7
 * 2. create_maintree(): Create maintree 1 2 4 5 3 6 7
 * 3. Traverse Both Tree in pre-order fashion and store in Linked List
 * 	a. preorderTraversal_sub(subtree_values)
 * 	b. preorderTraversal_sub(roottree_values)
 * 4. Find Whether subtree is part of main Tree or not?
 * 	findPart(). 
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int val;
	struct node *left;
	struct node *right;
}NODE;

typedef struct ll {
	int val;
	struct ll *next;
}LL;
LL *subtree_values;
LL *roottree_values;

LL *create_ll_node(LL *ptr, int val){
	//This function checks LL is NULL.
	//if LL is NULL insert element
	//if Not NULL, traverse to tail of LL, insert Node at end. Return head.
//	printf("create_ll_node, val=%d\n",val);
	LL *p, *head;
	if(!ptr){
//		printf("if(!ptr), val=%d\n",val);
		p = (LL *) malloc (sizeof(LL *));
		p->val = val;
		p->next = NULL;
		head = p;
	}else {
//		printf("else, val=%d\n",val);
		head = ptr;
		while(ptr->next != NULL)
			ptr++;
		
		p = (LL *) malloc (sizeof(LL *));
		p->val = val;
		p->next = NULL;	
		ptr->next = p;
	}
//	printf("returning head=%ld\n",head);
	return head;
}

void printValues_in_LL(LL *ptr) {
	if(!ptr){
		printf("Nothing present in LL\n");
		return;
	}
//	printf("\nValues of Sub Tree:\n");
	while(ptr->next !=NULL) {
		printf("%d\t",ptr->val);
		ptr++;
	}
	printf("%d",ptr->val);
}

NODE *create_node(int value) {
	NODE *p = (NODE *) malloc (sizeof(NODE *));
	p->val = value;
	return p;
}

NODE *create_subtree() {
	NODE *ptr = create_node(3);
	ptr->left = create_node(6);
	ptr->right = create_node(7);
	ptr->left->left = ptr->left->right = NULL;
	ptr->right->left = ptr->right->right = NULL;
	return ptr;
}
NODE *create_maintree() {
	NODE *ptr = create_node(1);
	ptr->left = create_node(2);	ptr->right = create_node(3);
	ptr->left->left = create_node(4);	ptr->left->right = create_node(5);
	ptr->right->left = create_node(6);	ptr->right->right = create_node(7);
	ptr->left->left->left = NULL;	ptr->left->left->right = NULL;
	ptr->left->right->left = NULL;	ptr->left->right->right = NULL;
	ptr->right->left->left = NULL;	ptr->right->left->right = NULL;
	ptr->right->right->left = NULL;	ptr->right->right->right = NULL;
	return ptr;
}

LL *preorderTraversal_sub (NODE *ptr) {
	subtree_values = create_ll_node(subtree_values, ptr->val);
	if(ptr->left)
		preorderTraversal_sub(ptr->left);
	if(ptr->right)
		preorderTraversal_sub(ptr->right);
	return subtree_values;
}

LL *preorderTraversal_main (NODE *ptr) {
	roottree_values = create_ll_node(roottree_values, ptr->val);
	if(ptr->left)
		preorderTraversal_main(ptr->left);
	if(ptr->right)
		preorderTraversal_main(ptr->right);
	return roottree_values;
}

void findPart(LL* sub, LL *root) {
	int equal = 0;
	while(root != NULL) {
//		printf("root values %d \n",root->val);
		if(root->val == sub->val) {
//			equal = 1;
//			printf("Sub values %d \n",sub->val);
			if(sub->next != NULL) {
				sub++;
			}else {
				//Subtree Reached End	
				printf("Sub Tree is Part of Main Tree\n");
				break;
			}
		}
		root++;
	}
}

void main() {
	NODE *root_subtree = create_subtree();
//	printf("Sub Tree Created Sucessfully address=%ld\n",root_subtree);
	NODE *root_maintree = create_maintree();
//	printf("Main Tree Created Sucessfully address=%ld\n",root_maintree);

	subtree_values = preorderTraversal_sub(root_subtree);
//	printf("Tree converted to LL Sucessfully address=%ld\n",subtree_values);
	printf("SubTree values:\n");
	printValues_in_LL(subtree_values);	
	printf("\n");

	roottree_values = preorderTraversal_main(root_maintree);
	printf("mainTree values:\n");
	printValues_in_LL(roottree_values);	
	printf("\n");

	printf("Finding Is Subtree part of Main Tree\n");
	findPart(subtree_values, roottree_values);
}
