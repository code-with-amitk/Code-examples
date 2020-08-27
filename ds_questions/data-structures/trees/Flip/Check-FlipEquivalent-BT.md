## [Problem](https://leetcode.com/problems/flip-equivalent-binary-trees/)
- Given 2 binary trees we need to check whether 1 can be obtained by flipping the other or not?
- A BT X is flip equivalent to a BT Y if and only if we can make X equal to Y after some number of flip operations.
- Given 2 BT's return True if both are flip equivalents false otherwise

### Example
- Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
- Output: true
- Explanation: root2 is obtained after flipping at nodes 1,3,5
```diff
       1                  1                   
     /   \              /  \
    2     3            3     2
   / \    /            \    / \
  4   5  6              6  4   5
     / \                      / \
    7   8                    8   7
    root1
```
