**Merge k Sorted Lists**
- [Approach-1, Read, sort, create. O(mn)](#a1)

### Merge k Sorted Lists
- You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
- Merge all the linked-lists into one sorted linked-list and return it.
```c
Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []
```

<a name=a1></a>
### Approach-1, Read, sort, create. O(mn)
#### Logic
- _1._ Read all linked lists in `vector<int>`
- _2._ Sort the vector
- _3._ Create a linked list from vector.
#### Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        
        //Iterate thru all linked lists
        for (auto&head:lists) {
            while (head) {
                v.push_back(head->val);
                head = head->next;
            }
        }

        //Sort the read items
        sort(v.begin(), v.end());
        
        ListNode* head = nullptr;
        ListNode* temp = nullptr;
        
        //Create LL from items
        if (v.size()) {
            head = temp = new ListNode(v[0]);
            for (int i=1;i<v.size();++i) {
                temp->next =  new ListNode(v[i]);
                temp = temp->next;
            }
        }
        return head;
    }
};
```
#### Complexity
- **Time:** m:Number of Linked lists, n:max size of linked list
  - O(mn): Reading and creating vector of size=mn
  - O(logmn): sorting the vector
  - O(mn): Iterate thru vector and create linked list
- **Space:** O(mn)

### Approach-2
#### Logic
- _1._ From m linked lists, merge 2 linked lists at a time.
#### Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode *merge(ListNode *l1, ListNode *l2){
        if (!l1) 
                return l2; 
        if (!l2) 
                return l1; 
  
        if (l1->val < l2->val) { 
                l1->next = merge(l1->next, l2); 
                return l1; 
        }else{ 
                l2->next = merge(l1, l2->next); 
                return l2; 
        } 
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        if (!lists.size())
            return head;
        
        while(lists.size()>1) {
            head = merge(head, lists[0]);
            lists.erase(lists.begin());
        }
        
        if (lists.size()==1)
            head = merge(head, lists[0]);

        return head;
    }
};
```
#### Complexity
- **Time:** O(mn). m=size of 1 linked list, n=number of ll
- **Space:** O(2m). At a time merging of 2 linked lists takes this space.
