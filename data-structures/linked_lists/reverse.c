#include<stdio.h>
typedef struct Node{
	int data;
	struct Node *next;
}NODE;

NODE *create(){
	//1->2->3->4->N
       //ptr
	NODE *ptr = malloc (sizeof(NODE));
	ptr->data = 1;
	ptr->next = malloc (sizeof(NODE));
	ptr->next->data = 2;
	ptr->next->next = malloc (sizeof(NODE));
	ptr->next->next->data = 3;
	ptr->next->next->next = malloc (sizeof(NODE));
	ptr->next->next->next->data = 4;
	ptr->next->next->next->next = NULL;
	return ptr;	
}

NODE* reverse(NODE *head){
	NODE *a,*b,*c, *newH;
	if(head != NULL){
		a=b=c=head;
	}
	if(a->next != NULL){
		b = c = a->next;
	}
	while(b!=NULL){
		c=b->next;
		b->next=a;
		if(a==head){
			a->next = NULL;
		}
		a=b;
		if(c==NULL)
			newH = b;
		b=c;
	}
	printf("Done rev\n");
	return newH;
}

void main(){
	printf("Created LL:%u",create());
	NODE *p = reverse(create());
	NODE *t = p;
	while(t!=NULL){
		printf("%d ", t->data);
		t = t->next;
	}
}
