## Problem
- Traverse binary tree in zigzag fashion.
- **Example**

![ImgURL](spiralTraversalExample.jpg)  

```c++
       40       << Level 0
      / \
    20   60     << Level 1
   / \   / \
  10 30  50 70  << Level 2
 /        \
5          55   << Level 3

Print: 40 60 20 10 30 50 70 55 5

Level:
  - Even: Traverse from Left to Right
  - Odd:  Traverse from Right to Left
```

