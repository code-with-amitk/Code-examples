
## BST (Binary Search Tree)
- **What** Binary tree having 2 child nodes. Every key is unique. It follows this property
 > Left child < parent
 
 > right child > parent
 
- **Usage** Mainly for searching operations.

### 1. CREATION	
- Perform binary search on Sorted array.
- mid of binary search is created as element of tree
```C++
Input: An sorted array {1,2,3,4,5,6,7,8,9}	
#include<stdio.h>
#include<stdlib.h>	//malloc
typedef struct node {
	int ele;
	struct node *left;
	struct node *right;
}Node;

Node *create (int a[], int start, int end) {
	if (start > end)
		return NULL;
	int mid = (start + end)/2;
	Node *ptr = (Node *) malloc (sizeof(Node));
	ptr->ele = a[mid];
	ptr->left = create (a, start, mid - 1);
	ptr->right = create (a, mid + 1, end);
}

void main() {
	Node *root;
	int a[] = {1,2,3,4,5,6,7,8,9};
		 //0 1 2 3 4 5 6 7 8
		//(array, start end);
	root = create (a, 0, 8);
	printf ("Just Created");
}
/* Output:
 * Just Created
 */
```
