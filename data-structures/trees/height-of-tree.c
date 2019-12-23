/*	5
 *     / \
 *    6   9
 *         \
 *         19
 *  	    
 Logic:
 On every node(Node *ptr):
	- if(ptr == NULL) return 0
	- if(ptr->left)	Increment leftHght variable by 1.
	- if(ptr->right) Increment rightHght variable by 1.
	return the bigger of leftHght or rightHght
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int val;
	struct node *left;
	struct node *right;
}NODE;
int lh, rh;
NODE *create (){
	NODE *ptr = (NODE *) malloc (sizeof(NODE));
	ptr->val = 5;
	ptr->left = (NODE *) malloc (sizeof(NODE));
	ptr->left->val = 6;
	ptr->left->left = NULL;
	ptr->left->right = NULL;

	ptr->right = (NODE *) malloc (sizeof(NODE));
	ptr->right->val = 9;
	ptr->right->left = NULL;
	ptr->right->right = (NODE *) malloc (sizeof(NODE));
	ptr->right->right->val = 19;
	ptr->right->right->left = NULL;
	ptr->right->right->right = NULL;
	return ptr;
}
int heightOfTree(NODE *ptr){
	if (ptr->left){
		lh++;
		heightOfTree(ptr->left);
	}
	if (ptr->right){
		rh++;
		heightOfTree(ptr->right);
	}
	return ((lh>rh)?lh:rh);
}

/* This function does not takes global variables
*/
int height(Node *ptr){
        int lefthgt = 0, righthgt = 0, var1 = 0, var2 = 0;

        if(ptr == NULL) return 0;

        if(ptr->left){
                lefthgt++;
                var1 = lefthgt + hgt(ptr->left);
        }

        if(ptr->right){
                righthgt++;
                var2 = righthgt + hgt(ptr->right);
        }
        return((var1 > var2) ? (var1) : (var2));
	
/*	OR Simply
	return (1 + max(height(ptr->left), height(ptr-right)));
*/
}

void main() {
	NODE *root = create();
	printf("Tree Created\n");

	printf("Height of Tree=%d\n",heightOfTree(root));
}
/*Output:
 *	Tree Created
 *	Height of Tree = 2
 */
