## [Problem](https://leetcode.com/problems/intersection-of-two-linked-lists/)
- There are 2 LL, find intersection point.
- Sizes:
  - LL-1: n //10
  - LL-2: m //8

## Solutions

| Solution | Space Complexity(worst) | Time Complexity(worst) | Disadv |
| --- | --- | --- | --- |
| 1. Using_hash | O(n) | O(n+m). They are intersecting at last node | In case 1 LL is Huge, Hash would be huge |
| 2. Mark Visited Nodes | O(1) | O(m+2n) | LL-1 need to be traversed twice |
| 3. Difference of Lengths | | | |

- **2. Mark visited Node**
  - On LL-1 change node->val = -1*(node->val)
  - Traverse from start of LL-2, whereever value = *, this is the intersection
  - We need to change value to original if question requires Linked lists to remain unchanged.
