**Add 2 numbers**

### [Add 2 numbers](https://leetcode.com/problems/add-two-numbers/description/)
- Given two non-empty linked lists representing two non-negative integers.
- The digits are stored in reverse order and each of their nodes contain a single digit.
- Add the two numbers and return it as a linked list.
```c
Ex-1:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) = 342+465 = 807
Output: 2+5 -> 4+6 -> 3+4 = 7 -> 0 -> 8

Ex-2:
Input: (2 -> 4 -> 3) + (5->0)   = 342+05 = 347
Output: 2+5 -> 4+0 -> 3 = 7 -> 4 -> 3

Ex-3:
Input: (2 -> 4 -> 3) + (0)   = 342+0 = 342
Output: 2+0 -> 4 -> 3
```

### Approach-1
#### Logic
a. Take head pointers of 2 Linked lists
b. if l1 && l2 both are NULL
        return NULL
c. if any one (l1 or l2) are not null:
        Create a new node using its value
d. if addition of ((l1->val + l2->val) > 10), 
        - create present node = added_value/10
        - Take carry = added_value%10. This value will be added to next nodes
        Example: 9+9=18 
                18/10 = 1 (present value)
                18%10 = 8 (carry to be added to next addition)

#### Complexity
> length(list1)=n, length(list2)=m
- **TIME: O(m+n)**
     - We have to iterate through the lists to add them 

- **SPACE**: O(n+1)   //Considering n>m
#### Code
**CPP**
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}             //ListNode(this_ptr)
      ListNode(int x) : val(x), next(nullptr) {}        //ListNode(this_ptr,int x)
      ListNode(int x, ListNode *next) : val(x), next(next) {}   //ListNode(this_ptr, int x, ListNode *next)
};

class Solution {
public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

                ListNode* head = nullptr;
                ListNode* current = nullptr;
                int carry = 0, presentVal;

                while (l1 != nullptr || l2 != nullptr || carry>0) {

                        if (l1 == nullptr && l2 == nullptr){
                                presentVal = carry;
                        }else if (l1 == nullptr){
                                presentVal = l2->val + carry;
                        }else if (l2 == nullptr){
                                presentVal = l1->val + carry;
                        }else{
                                presentVal = l1->val + l2->val + carry;
                        }

                        carry = presentVal/10;
                        presentVal %= 10;

                        if (current == nullptr){
                                head = new ListNode(presentVal);
                                current = head;
                        }else{
                                current->next = new ListNode(presentVal);
                                current = current->next;
                        }

                        if (l1 != nullptr)
                                l1 = l1->next;

                        if (l2 != nullptr)
                                l2 = l2->next;
                }
                return head;
        }
};

int main(){
        ListNode *l1 = new ListNode(3);
        l1->next = new ListNode(4);
        l1->next->next = new ListNode(2);

        ListNode *l2 = new ListNode(4);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(5);

        Solution s;

        //l1=nullptr;l2=nullptr;
        ListNode *p = s.addTwoNumbers(l1, l2);
        while(p != nullptr){
                cout<<p->val<<" ";
                p = p->next;
        }
}
```
