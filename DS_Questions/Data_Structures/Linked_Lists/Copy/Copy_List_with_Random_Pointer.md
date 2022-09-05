**Copy Custom Linked list**
- [Approach-1, Hashmap & Recursion](#a1)

## [Self Video](https://youtu.be/pM_GZ2tbLUA)

### [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)
Deep Copy the given linked list and return the copied linked list.
```c
struct list {
  int val,
  struct list* next;
  struct list* random;
};
```
- Examples
```c
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
```

<a name=a1></a>
### Approach, Hashmap & Recursion
#### Logic
- _1._ Allocate a node copy value present node. Save original and new node addresses on hashmap
  - Take a hashmap `unordered_map<key=original_Node*, value=newly_allocated_Node*>`
- _2._ `new_node->next = Find(key = old_node->next on HashMap) & return value`
- _3._ `new_node->random = Find(key = old_node->random on HashMap) & return value`

#### Code
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    std::unordered_map<Node*, Node*> um;
public:
    Node* copyRandomList(Node* head) {
        Node* head1 = head;
        Node* head2 = head;
        if(!head)
            return head;

        auto it = um.find(head1);
        if (it != um.end()){
            return it->second;
        }

        Node* temp = new Node(head->val);
        um[head1] = temp;
        temp->next = copyRandomList (head->next);
        temp->random = copyRandomList (head->random);
        return temp;
    }
};
```
#### Complexity
- **Time:** 2O(n) = O(n). n nodes in linked list. Since recursion is done for next, random for every node.
- **Space:** O(n). Hashmap
