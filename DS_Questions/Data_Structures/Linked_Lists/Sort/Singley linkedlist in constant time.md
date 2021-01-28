### [Sort list](https://leetcode.com/problems/sort-list/)
- Given the head of a linked list, return the list after sorting it in ascending order.
- Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
```c
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

<img src="https://assets.leetcode.com/uploads/2020/09/14/sort_list_1.jpg"  width="300" />

### 1. Approach    //Time:O(n), Space:O(n)
- Create vector from linked list.
- sort vector
- Create list from vector using recursion
- **Code**
```c
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

class Solution {
public:
  ListNode* fun (std::vector<int>& v, int i){
    ListNode* p = nullptr;
    if (i == v.size()-1)
      return new ListNode(v[i]);
    p = new ListNode(v[i], fun(v, i+1));
    return p;
  }
    
  ListNode* sortList(ListNode* head) {
    if(not head)
      return nullptr;
      
    std::vector<int> v;
    while (head != nullptr){
      v.push_back(head->val);
      head = head->next;
    }
    
    std::sort(v.begin(), v.end());

    //creating list from end;
    return fun(v, 0);        
  }
};
```

### 2. Approach-2 (Quick-Sort)
- But quick sort has O(n<sup>2</sup>) Time complexity in case of sorted array

### 3. Approach-3 (Merge Sort)   //Time:O(nlogn) 

![ImgURL](https://4.bp.blogspot.com/-f3BrOBTs-8Q/XUE8CQSzOuI/AAAAAAAAGic/OfQdRosWR28o8OZY-hT8iJZIS6uvLP2qQCK4BGAYYCw/s1600/merge-sort-linked-list-recursive-stack-trace.png)
- **Logic:**
  - *1.* Break the original/input list (Donot create temporary list for merging)
  - *2.* In merge() function
    - *2a.* Take a linked list with TempHead. TempHead->val=0. This is dummy head.
    - *2b.* Compare values of broken list nodes. Keep inserting sorted values after TempHead.
    - *2c.* When any broken LL get finished, insert remaninig linked list.
- **Complexity**
  - **Space:** O(1). No extra memory allocated apart from takening few pointer for breaking,merging.
    - O(1) is not Constant Space? Constant soace means amount of space that your algorithm uses is independent of the input parameters. Say you are given an array of size n. If the amount of space your algorithm uses increases/decreases with n, then it's not constant. If your algorithm always uses a fixed amount of space everytime independent of input size, then its constant space.
  - **Time:** 
    - O(logn): Breaking the entire LL
    - O(n): Merging sorted LL
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
class Solution {
public:
  void Print(ListNode* head){
    while (head != nullptr){
      std::cout << head->val <<" ";
      head = head->next;
    }
  } 
  
  //5->4->2->1->3   return 2
  //4->2->1->3      return 1
  ListNode* FindMiddle(ListNode* head) {
    ListNode* PrevOfMid = nullptr;
    while (head && head->next) {
      PrevOfMid = (PrevOfMid == nullptr) ? head : PrevOfMid->next;      
      head = head->next->next;
    }
    ListNode* Middle = PrevOfMid->next;
    PrevOfMid->next = nullptr;                //1. Breaking the LL
    return Middle;
  }
  
  ListNode* sortList(ListNode* head) {
    if ((not head) || (not head->next))
      return head;
    ListNode* mid = FindMiddle(head);
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);
    return merge(left, right);
  }

  ListNode* merge(ListNode* left, ListNode* right) {
    ListNode TempHead(0);               //2a This is dummy Head. We will return next of this head
    ListNode* ptr = &TempHead;
    while (left && right) {
      if (left->val < right->val) {
        ptr->next = left;
        left = left->next;
      } else {
        ptr->next = right;
        right = right->next;
      }
      ptr = ptr->next;
    }

    if(left)
      ptr->next = left;
    else
      ptr->next = right;

    return TempHead.next;                           //2c
  }
};
  
int main(){
  ListNode *p3 = new ListNode(3);
  ListNode *p1 = new ListNode(1, p3);
  ListNode *p2 = new ListNode(2, p1);
  ListNode *p4 = new ListNode(4, p2);
  ListNode* head = p4;

  Solution s;
  s.Print (head);
  std::cout<<"\n";
  ListNode* p = s.sortList (head);
  s.Print(p);
}
$ ./a.out
4 2 1 3
1 2 3 4
```
