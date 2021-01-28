### Find Middle Node of LL
- Example
```c
Input:  4->3->2->1
Ouput:  3

Input:  3->2->1
Ouput:  2

Input:  []
Ouput:  []

Input:  1
Ouput:  1

Input:  2->1
Ouput:  2
```
### Approach  //fast,slow pointer
- **Complexity:** Space:O(1), Time: O(n)
- **Code**
```c++
#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* FindMiddle(ListNode* head){

  //0,1,2 nodes return 1st node
  if((not head) or (not head->next) or (not head->next->next))
    return head;

  ListNode *slow, *fast;
  slow = fast = head;

  while (fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;

    //even number of nodes. In case of even nodes break early
    if((not fast->next) or (not fast->next->next))
      break;
  }
  return slow;
}

int main(){
  //5->4->2->1->3
  ListNode *p3 = new ListNode(3);
  ListNode *p1 = new ListNode(1, p3);
  ListNode *p2 = new ListNode(2, p1);
  ListNode *p4 = new ListNode(4, p2);
  ListNode *p5 = new ListNode(5, p4);
  ListNode* head = p4;
  std::cout<<"\n";
  std::cout << FindMiddle(head)->val;
}  
```
