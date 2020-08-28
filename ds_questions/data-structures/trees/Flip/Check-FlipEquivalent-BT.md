## [Problem](https://leetcode.com/problems/flip-equivalent-binary-trees/)
- Given 2 binary trees we need to check whether 1 can be obtained by flipping the other or not?
- A BT X is flip equivalent to a BT Y if and only if we can make X equal to Y after some number of flip operations.
- Given 2 BT's return True if both are flip equivalents false otherwise

### Example-1
```c
- Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
- Output: true
- Explanation: root2 is obtained after flipping at nodes 1,3,5
       1                  1                   
     /   \              /  \
    2     3            3     2
   / \    /            \    / \
  4   5  6              6  4   5
     / \                      / \
    7   8                    8   7
    root1                 root2
```

### Logic
- How pre-order works. Print node go left,right(recursively). Now if we modfiy pre-order that print node and go to smaller node 1st, then in both cases print would be 1,2,3. And this is the flip.
```c++
    1        1
   / \      / \
  2   3    3   2
```  
- Logic: Modified Pre-order. Goto smaller node
```c++
  Print node
  Find which child is smaller
    if(left<right)  goto left 1st
    else    goto right 1st
```

### Code
```c++
```
