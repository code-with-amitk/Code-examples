### Question
```c
typedef struct node {
  int val;
  node* next;
  node* prev;
}Node;

Implement 3 functions:
1. void InitializeToNull(Node** ptr);                        //Initialize a head pointing to null
2. void AddAfter (Node** head, int position, Node node);    //Add a node inside DLL after position p.
3. void RemoveNode (Node** head, int val)                   //Remove element from Doubly Linked List
```

### Code
```c
// DoublyLinkedList.cpp : Defines the entry point for the application.
//

#include "DoublyLinkedList.h"

using namespace std;
typedef struct node {
	int val;
	node* next;
	node* prev;
	node(int val): next(nullptr), prev(nullptr), val(val) {}
};

class DoublyLL {
public:
	void InitializeToNull(node** ptr) {
		node* head = nullptr;
		ptr = &head;
	}
	//void AddAtEnd(node&, node**);
	int AddAfter(node** head, int position, node node);
	void print(node** headref) {
		node* head = *headref;
		while (head) {
			cout << head->val << " ";
			head = head->next;
		}
		cout << "\n";
	}
	int RemoveNode(node**, int position);
};

/*
* LL			1 <-> 2	<->	4
* position		1	  2		4
* 
* Insert node at position.
* if position > sizeof(LL), insert at end
*/
int DoublyLL::AddAfter(node** headref, int position, node node_n) {
	if (!headref) {
		return -1;
	}
	node* head = *headref;
	int count = 0;
	bool insert_at_end = false;
	while (count < position-1)
	{
		if (head->next)
			head = head->next;
		else {
			insert_at_end = true;
			break;
		}
		count++;
	}
	if (!insert_at_end)
		node_n.next = head->next;
	head->next = &node_n;
	node_n.prev = head;
	return 0;
}

/* Remove node at position
* if position > sizeof(LL). Remove last
*/
int DoublyLL::RemoveNode(node** headref, int position) {
	if (!headref)
		return -1;
	int count = 0;
	node* head = *headref;
	while (count < position - 1) {
		if (head->next)
			head = head->next;
		count++;
	}
	head->prev->next = head->next;
	head->next->prev = head->prev;
	//delete(head);
	return 0;
}

int main()
{
	int ret = -2;
	node** headref = nullptr;
	DoublyLL obj;
	obj.InitializeToNull(headref);

	//////Create LL Start//////////
	node* node1 = new node(1);
	headref = &node1;

	node* node2 = new node(2);
	(*headref)->next = node2;
	node2->prev = node1;

	node* node4 = new node(4);
	node2->next = node4;
	node4->prev = node2;
	///////Create LL End//////////

	obj.print(headref);

	node* node3 = new node(3);
	ret = obj.AddAfter(headref, 2, *node3);
	if (ret == -1) {
		cout << "Empty Linked List";
	}
	else {
		cout << "AddAfter() Success\n";
	}

	obj.print(headref);

	node* node10 = new node(10);
	ret = obj.AddAfter(headref, 10, *node10);
	if (ret == -1) {
		cout << "Empty Linked List";
	}
	else {
		cout << "AddAfter() Success\n";
	}
	obj.print(headref);

	ret = obj.RemoveNode(headref, 3);
	if (ret == -1) {
		cout << "Empty Linked List";
	}
	else {
		cout << "RemoveNode() Success\n";
	}
	obj.print(headref);
	return 0;
}
```
