### [Sort list](https://leetcode.com/problems/sort-list/)
- Given the head of a linked list, return the list after sorting it in ascending order.
- Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
```c
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

<img src="https://assets.leetcode.com/uploads/2020/09/14/sort_list_1.jpg"  width="500" />

### Approach-1    //Time:O(n), Space:O(n)
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

### Approach-2 (Quick-Sort)
- But quick sort has O(n<sup>2</sup>) Time complexity in case of sorted array

### Approach-3 (Merge Sort)   //Time:O(nlogn) 

![ImgURL](https://4.bp.blogspot.com/-f3BrOBTs-8Q/XUE8CQSzOuI/AAAAAAAAGic/OfQdRosWR28o8OZY-hT8iJZIS6uvLP2qQCK4BGAYYCw/s1600/merge-sort-linked-list-recursive-stack-trace.png)
