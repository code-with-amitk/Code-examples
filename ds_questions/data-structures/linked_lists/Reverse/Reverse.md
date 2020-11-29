## Reverse LL
- Example
```c
  Input = 1->2->3->4->N
  Output = 4->3->2->1->N
```

# [Self Video Explanation](https://youtu.be/UheqFiqUbgQ)

## Logic (3 pointers)
- *1.* Take 3 pointers pointing 3 consecutive nodes in LL.
```c
  1  ->  2  ->  3  ->  4  ->  N
 /\     /\      /\
 a       b      c
```
- *2.* Make b->next = a. if a is head node, Make its next = NULL
```c
N<-1  <-  2      3  ->  4  ->  N
  /\     /\      /\
  a       b      c
```
- *3.* Move every pointer 1 step a head and so on.
```c
N<-1  <-  2      3  ->  4  ->  N
         /\      /\     /\
          a      b      c
```

## Code
```c
#include<iostream>
using namespace std;

struct Node {
  int val;
  Node *next;
  Node(int x) : val(x), next(NULL) {}
};

Node *create(){
  //1->2->3->4->N
  Node *n4 = new Node(4);
  Node *n3 = new Node(3); n3->next = n4;
  Node *n2 = new Node(2); n2->next = n3;
  Node *n1 = new Node(1); n1->next = n2;
  return n1;
}

Node* reverse(Node *head){
  Node *a,*b,*c, *newH;
  if(head)
    a = b = c = head;

  if(a->next != NULL)
    b = c = a->next;

  while(b != NULL){
    c = b->next;
    b->next = a;
    if(a == head){
      a->next = NULL;
    }
    a = b;
    if(c == NULL)
      newH = b;
    b = c;
  }
  printf("Done rev\n");
  return newH;
}

/* Reverse using Recursion
reverse(Node *ptr){
    if(ptr->next != NULL){
        Node *x = reverse (ptr->next);
    }
    x = ptr;
    return ptr->next;
} 
*/

void print(Node* t){
  while(t!=NULL){
    cout << t->val << " ";
    t = t->next;
  }
  cout<<"\n";
}

int main(){
  Node* a = create();
  print(a);
  Node *p = reverse(a);
  print(p);
}
$ ./a.out
1 2 3 4
Done rev
4 3 2 1
```
