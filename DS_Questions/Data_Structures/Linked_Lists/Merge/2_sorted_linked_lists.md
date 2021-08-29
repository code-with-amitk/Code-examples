**Merge two Sorted linked lists**
- **Approach-1 / Recursion**
  - [Code](#cpp1)
- **Approach-2 / Iterative**
  - [Code](#cpp2)

```c 
Input:  
 1->3->5->7
 6->8->9

Output: 1->3->5->6->7->8->9
```

### Approach-1 / Recursion
<a name=cpp1></a>
**Code**
```cpp
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}             //ListNode(this_ptr)
      ListNode(int x) : val(x), next(nullptr) {}        //ListNode(this_ptr,int x)
      ListNode(int x, ListNode *next) : val(x), next(next) {}   //ListNode(this_ptr, int x, ListNode *next)
};

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
int main(){
        ListNode *l1 = new ListNode(1);
        l1->next = new ListNode(3);
        l1->next->next = new ListNode(5);

        ListNode *l2 = new ListNode(2);
        l2->next = new ListNode(4);
        l2->next->next = new ListNode(6);

        l1 = merge(l1,l2);

        while(l1){
                cout<<l1->val<<" ";
                l1 = l1->next;
        }
}
/*
Output:
# ./a.out 
1 2 3 4 5 6 
*/
```

### Approach-1 / Iterative
<a name=cpp2></a>
**Code**
```c
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}             //ListNode(this_ptr)
      ListNode(int x) : val(x), next(nullptr) {}        //ListNode(this_ptr,int x)
      ListNode(int x, ListNode *next) : val(x), next(next) {}   //ListNode(this_ptr, int x, ListNode *next)
};

//Always pass smaller head to l1
ListNode *fun(ListNode *l1, ListNode *l2){

        //if only 1 node in l1
        if(l1->next == nullptr){
                l1->next = l2;
                return l1;
        }

        ListNode *current1 = l1, *next1 = l1->next;
        ListNode *current2 = l2, *next2 = l2->next;

        while(current2 && next1){

                //linked-list2's lies between current1 and next1
                //Inserting current2 in between current1->current2->next1
                if ((current2->val) >= (current1->val) &&
                    (current2->val) <= (next1->val)){
                        next2 = current2->next;
                        current1->next = current2;
                        current2->next = next1;

                        current1 = current2;
                        current2 = next2;
                }else{//current2 does not lies inbetween current1 & next1

                        if(next1->next){
                                //if elements exist in LL1
                                current1 = current1->next;
                                next1 = next1->next;
                        }else{
                                next1->next = current2;
                                return l1;
                        }
                }
        }
        return l1;
}

ListNode *merge(ListNode *l1, ListNode *l2){
        if (!l1)
                return l2;
        if (!l2)
                return l1;

        if (l1->val < l2->val)
                return fun(l1, l2);
        else
                return fun(l2, l1);
}

int main(){
        ListNode *l1 = new ListNode(1);
        l1->next = new ListNode(3);
        l1->next->next = new ListNode(5);

        ListNode *l2 = new ListNode(2);
        l2->next = new ListNode(4);
        l2->next->next = new ListNode(6);

        l1 = merge(l1,l2);

        while(l1){
                cout<<l1->val<<" ";
                l1 = l1->next;
        }
}
/*
Output:
# ./a.out 
1 2 3 4 5 6 
*/
```
