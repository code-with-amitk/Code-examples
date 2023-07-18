**Add Two Numbers II**
- [Approach-1. 2 Stacks](#a1)
  - [Logic](#l)
  - Code
    - [CPP](#cpp)
    - [Rust](#rs)

### [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/description/)
- You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
- You may assume the two numbers do not contain any leading zero, except the number 0 itself.

<img src=https://assets.leetcode.com/uploads/2021/04/09/sumii-linked-list.jpg width=200 />

```c
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
```

<a name=a1></a>
### Approach-1. 2 Stacks
#### Logic
- _1._ store both linked lists on stack
- _2._ pop top from both linked lists, perform addition.
  - if carry is left, add to next stack add operation
- _3._ if one stack is over, copy all elements of other stack to output stack, taking care of carry.
- _4._ convert out stack to linked list and return.
#### Code
<a name=cpp></a>
**CPP**
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
    ListNode* createOutLL (stack<int>& s) {
        ListNode *head = nullptr, *tail = nullptr;
        while (!s.empty()) {
            ListNode* newNode = new ListNode(s.top());
            s.pop();
            if (head == nullptr) {
            head = newNode;
            tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        return head;
    }
    void createStack(stack<int>&s, ListNode* ll) {
        while (ll != nullptr) {
            s.push(ll->val);
            ll = ll->next;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stack1, stack2, out;

        // Push values from linkedlist to stacks
        createStack(stack1, l1);
        createStack(stack2, l2);

        int carry = 0;

        while (!stack1.empty() || !stack2.empty() || carry != 0) {
            int sum = carry;
            if (!stack1.empty()) {
                sum += stack1.top();
                stack1.pop();
            }
            if (!stack2.empty()) {
                sum += stack2.top();
                stack2.pop();
            }
            carry = sum / 10;
            int digit = sum % 10;
            out.push(digit);
        }

        // Create output linkedlist
        return createOutLL(out);
    }
};
```

<a name=rs></a>
**Rust**
```rs
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn add_two_numbers(mut l1: Option<Box<ListNode>>, mut l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut st1 = vec![];
        while let Some(t) = l1 {
            st1.push(t.val);
            l1 = t.next;
        }

        let mut st2 = vec![];
        while let Some(t) = l2 {
            st2.push(t.val);
            l2 = t.next;
        }

        let mut node = None;
        let mut carry = 0;
        loop {
            carry += st1.pop().unwrap_or(0) + st2.pop().unwrap_or(0);
            if carry == 0 && st1.is_empty() && st2.is_empty() {
                break;
            }

            node = Some(Box::new(ListNode {
                val: carry % 10,
                next: node,
            }));
            carry /= 10;
        }
        if node.is_none() {
            node = Some(Box::new(ListNode::new(0)));
        }
        node
    }
}
```
