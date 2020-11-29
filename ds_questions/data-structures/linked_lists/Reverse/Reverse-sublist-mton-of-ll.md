## Reverse a sublist of linked list
```c++
pos      1  2   3           6     
Input : 10->20->30->40->50->60->70->NULL
                /\          /\
 m = 3, n = 6
Output : 10->20->60->50->40->30->70->NULL
```

## Logic
- *Step-1.* Find following pointers:
  - start: Pointer to position m
  - start_prev: Pointer to position before start
  - end: Pointer to n
  - end_next: Pointer to next element of n
```c++
  10  ->  20  ->  30  ->  40  ->  50  ->  60  ->  70  ->  NULL
          /\      /\                      /\      /\
      start_prev start                    end   end_next
```
- *Step-2* Make next of end = NULL.
```c++
  10  ->  20  ->  30  ->  40  ->  50  ->  60      70  ->  NULL
          /\      /\                      /\      /\
      start_prev start                    end   end_next
```
- *Step-3* Reverse the LL between start and end and return new Head, store new Head in start_prev->next
```c++

      30  ->  40  ->  50  ->  60
      /\                      /\
     start                    end
     head
     
After Reverse
      become
      30  <-  40  <-  50  <-  60
      60  ->  50  ->  40  ->  30
      /\
      head
      
  10  ->  20  ->  60  ->  50  ->  40  ->  30      70  ->  NULL
          /\      /\                      /\      /\
      start_prev end                    start   end_next      
```
- *Step-4* Make start->next = end_next
```c++
  10  ->  20  ->  60  ->  50  ->  40  ->  30  ->  70  ->  NULL
          /\      /\                      /\      /\
      start_prev end                    start   end_next      
```

## Code
```c++
#include<iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
public:
  ListNode* createLL(){
    ListNode* a7 = new ListNode(70);
    ListNode* a6 = new ListNode(60);  a6->next = a7;
    ListNode* a5 = new ListNode(50);  a5->next = a6;
    ListNode* a4 = new ListNode(40);  a4->next = a5;
    ListNode* a3 = new ListNode(30); a3->next = a4;
    ListNode* a2 = new ListNode(20); a2->next = a3;
    ListNode* a1 = new ListNode(10); a1->next = a2;
    cout <<"created\n";
    return a1;
  }
  ListNode* reverseBetween(ListNode* A, int B, int C);
  void print(ListNode*);
  ListNode* reverse(ListNode* head);
};
ListNode* Solution::reverse(ListNode* head) {                             //Step-3
  ListNode *a,*b,*c, *newH;
  if(head != NULL){
    a=b=c=head;
  }
  if(a->next != NULL){
    b = c = a->next;
  }
  while(b!=NULL){
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
  return newH;
}
//m,n : start and end positions of to be reversed LL
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
  if (m == n)
    return head;

  ListNode* start = NULL, *start_prev = NULL, *end = NULL, *end_next = NULL;

  // Find values of above pointers.
  int i = 1;
  ListNode* c = head;

  //Step-1
  while (c && i <= n) {
    if (i < m)
      start_prev = c;

    if (i == m)
      start = c;

    if (i == n) {
      end = c;
      end_next = c->next;
    }

    c = c->next;
    i++;
  }

  end->next = NULL;                                 //Step-2

  ListNode* test = reverse(start);                //Step-3

  if (start_prev)              // If starting position was not head
    start_prev->next = test;
  else                        // If starting position was head
    head = end;

  start->next = end_next;
  return head;
}
void Solution::print(ListNode* p){
  while(p!=nullptr){
    cout<<p->val<<" ";
    p = p->next;
  }
  cout<<"\n";
}

int main(){
  Solution s;
  ListNode* A = s.createLL();
  s.print(A);
  int m=3, n=6;   //Start and end positions of reverse
  s.reverseBetween(A, m, n);
  s.print(A);
}
$ ./a.out
created
10 20 30 40 50 60 70
10 20 60 50 40 30 70
```
