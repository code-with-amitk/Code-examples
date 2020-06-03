
## BST (Binary Search Tree)
- **What** Binary tree having 2 child nodes. ***Every key is unique***. It follows this property
	- Left child < parent
 	- right child > parent
 
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
	return ptr;
}

int main() {
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

### 2. FindMin
```
int findMin(Node *node)
{
	Node *nPtr = node;

        if (!nPtr)
                return -1;

        while (nPtr->left)
                nPtr = nPtr->left;
		
        return nPtr->ele;
}
```
- Complexity
	- O(h) height of tree log(n)

### 3. Deletion of Node
#### Case-1: Node with 0 children
- Simple
#### Case-2: Node with 1 child
- Delete 6 and make 5 as child of 4
```
	4
	   \
	     6
	    /
	5
```
#### Case-3: Node with 2 children
- Delete 4 and make 5 parent of 3. ie Place immediate successor in sorted orded at place of deleted node.
- This successor must be the smallest value in the right subtree
```
	  7
	 /
	4
       / \
      3   5
```
##### **Complexity**
	- Every deletion need 2 search operations (2 O(logn))
	- Plus constant amount of time in pointer manipulations.
