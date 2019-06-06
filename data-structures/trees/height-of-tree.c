/*	5
 *     / \
 *    6   9
 *         \
 *         19
 *  	    
 *  Algorithm:
 *  On every node:
 *  	a. Find leftHeight (lh)
 *  	b. Find rightHeight (rh)
 *  	c. return whichever is bigger
 *  	return (lh > rh) ? lh : rh
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
        int val=0,tmp=0;
        std::cout<<"node="<<ptr->data<<std::endl;
        if((ptr->left != NULL) || (ptr->right != NULL)){
                val++;
                std::cout<<"node="<<ptr->data<<" val="<<val<<std::endl;
        }
        if(ptr->left){
                tmp = height(ptr->left);
        }
        if(ptr->right){
                tmp = height(ptr->right);
        }
        std::cout<<"node="<<ptr->data<<" Returning"<<val+tmp<<std::endl;
        return (val+tmp);
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
