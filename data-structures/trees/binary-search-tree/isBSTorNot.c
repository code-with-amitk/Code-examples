/* This code creates a simple BST and checks if Tree is BST or not
 * 	5
 *     / \
 *    3	  6
 *   / \    \
 *  2	4     1
 */
#include<stdio.h>
#include<stdlib.h>	//malloc
typedef struct Node {
        int data;
        struct Node *left;
        struct Node *right;
}NODE;

NODE *createBST (){
        NODE *ptr;
        ptr = (NODE *) malloc (sizeof(NODE));
        ptr->data = 5;
        ptr->left = (NODE *) malloc (sizeof(NODE));
        ptr->left->data = 3;
        ptr->left->left = (NODE *) malloc (sizeof(NODE));
        ptr->left->right = (NODE *) malloc (sizeof(NODE));
        ptr->left->left->left = ptr->left->left->right = NULL;
        ptr->left->left->data = 2;
        ptr->left->right->data = 4;
        ptr->left->right->left = ptr->left->right->right = NULL;

        ptr->right = (NODE *) malloc (sizeof(NODE));
        ptr->right->data = 6;
        ptr->right->left = NULL;
        ptr->right->right = (NODE *) malloc (sizeof(NODE));
        ptr->right->right->data = 1;
        ptr->right->right->right = NULL;
        ptr->right->right->left = NULL;

        return ptr;
}

NODE * findMaximum(NODE * root){
    if( !root ) return root;
    while( root->right ){
        root = root->right;
    }
    return root;
}

NODE * findMinimum(NODE * root){
    if( !root ) return root;
    while( root->left ){
        root = root->left;
    }
    return root;
}

//return=0 (if not BST)
//return=1 (if BST)
int isBST_logic_1 (NODE *root) {
    if(!root)
        return 1;

    if( ! ( root->left || root->right ) ) return 1;
    int isLeft  = isBST_logic_1(root->left);
    int isRight = isBST_logic_1(root->right);

    if(isLeft && isRight){
        /* Since we already know that left sub tree and
        *  right sub tree are Binary search tree, finding min and max in them would be easy */

        NODE *max  =  NULL;
        NODE *min  =  NULL;
        if( root->left )
            max = findMaximum(root->left);
        if( root->right )
            min = findMinimum(root->right);
         if(max && !min)
            return root->data > max->data;
        if(!max && min)
            return root->data < min->data;
        return (root->data > max->data && root->data < min->data);
   }
   return 0;
}

int isBST_logic_2 (NODE *root) {
        int ret;
        if((root->left) && (root->left->data > root->data))     //Not BST
                return 0;

        if((root->right) && (root->right->data < root->data))   //Not BST
                return 0;

        if (((root->left) && !(isBST_logic_2(root->left))) || (root->right && !(isBST_logic_2(root->right))))
                return 0;

        return 1;
}


void main() {
        NODE *root = createBST();
        printf("Tree created\n");

        if(isBST_logic_1(root)) {
                printf("BST\n");
        } else {
                printf("Not BST\n");
        }
	
        if(isBST_logic_2(root)) {
                printf("BST\n");
        } else {
                printf("Not BST\n");
        }
}

/* Output:
 * Tree created
 * Tree is BST
 */
