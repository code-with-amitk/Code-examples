## [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/)
- Find all colinear points on the line, ie all points which lies on the same line.
- Example:
```c
Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
```

## 1. Approach  //Slope
- **Slope/Gradient?** if line is represented using y = mx + c. Then its slope is:
```c
  (y2 - y2)/(x2 - x1)
```
### Logic
- *1.* Calculate slope of every 2 points on plane. Store slope in hash-table, return max count.
- *2.* How to store slope?
  - Double/Float?
    - You must be thinking double or float to store slope?
    - But that's not correct and accurate in all cases because float/double are intrinsically inaccurate, due to [how float/double are represented in the memory](https://en.wikipedia.org/wiki/Floating-point_arithmetic)
```c
double:8bytes, float:4bytes

Example:
  double b = 1.2 - 1.0;
  std::cout.precision(17);
  std::cout<<(double)b<<"\n";       //0.19999999999999996 (should be .2)
```
  - 
