## [Problem](https://leetcode.com/problems/rotate-list/)
- Given a linked list, rotate the list to the right by k places, where k is non-negative.

- Example 1
```
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
```

- Example 2
```
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
```

## Logic
> Input 1->2->3->4->5 [k=97]. k=97%5=2    Output: 5->4->1->2->3
- return head itself
  - if `k==0` means no rotation.
  - if `head == NULL` means nothing to rotate
- Find length of LL, to reduce k if its a large number.
  - Here, k = 97%5 = 2. These many rotations are required.
  - if after mod, k is multiple of len, return 0
- Move to (k)th index, which is 3
  - make 3->next = NULL
  - point last node's next to 1st.  5->next = 1
  - make next node of kth index as head.  head = 4
- **Complexity** Greater than O(n). Would be working on O(n) solution.  
```
    ListNode* rotateRight(ListNode* head, int k) {
      //k=0 means no rotation
      if(k==0 || head==NULL)
        return head;

      int len=0;
      ListNode* t = head;

      //Finding length
      while (t!=NULL){
        len++;
        t=t->next;
      }

      k %= len;

      //if k is a multiple of len, same list should be returned
      if(k==0)
        return head;

      //t was moved only to find the length
      t = head;

      for(int i=0; i<len-k-1 ; i++){
        t = t->next;
      }

      ListNode* temp = head;

      head = t->next;
      t->next = NULL;
      t = head;

      while(t->next!=NULL)
        t=t->next;

      t->next = temp;
      return head;
    }
```
