## 1. Create BT using Array
- Input:  {1,2,3,4,5,6,7}
```
Output:
                1
               / \
              2   3
             / \ / \
            4  5 6  7 
									
#include<iostream>
using namespace std;

typedef struct node{
	int val;
  struct node *left, *right;
}Node;

Node *newnode(int t){
	Node *p = new Node;
	p->val = t;
  p->left = p->right = NULL;
  return p;
}

Node *create(int a[], int i, int size){
	Node *ptr;
  while(i<size){
  	ptr = newnode(a[i]);

    ptr->left = create(a, 2*i+1, size);
		ptr->right = create(a, 2*i+2, size);
    return ptr;
	}
  return NULL;
}

int main(){
  int a[] = {1,2,3,4,5,6,7};
  				 //0 1 2 3 4 5 6

	Node *root = create(a,0,7);
  cout<<"Created Tree using array\n";
}			
```

## 2. Create BT without Arrays
```
#include<stdio.h>
#include<stdlib.h>	//malloc()
typedef struct node {
	int ele;
	struct node *left, *right;
}Node;

Node* create(int ele) {
	Node* ptr = (Node *) malloc (sizeof(Node));
	ptr->ele = ele;
	ptr->left = ptr->right = NULL;
}

void main() {
	Node *root = create (1);
	root->left = create(2);
	root->right = create(3);
	root->left->left = create(4);
	printf("Just Created");
}
```
