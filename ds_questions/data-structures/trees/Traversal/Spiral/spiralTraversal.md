## Problem
- Traverse binary tree in zigzag fashion.

![ImgURL](spiralTraversalExample.jpeg)  

- **Example**
```c++
      1       << Level 0
     / \
    10  4     << Level 1
   /   / \
  3   7   9   << Level 2
 / \  /    \
12 8  6     2 << Level 3

Print: 1 4 10 3 7 9 12 8 6 2

Level:
  - Even: Traverse from Left to Right
  - Odd:  Traverse from Right to Left
```

