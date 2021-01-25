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
  - *2a.* Double/Float? No
    - You must be thinking double or float to store slope?
    - But that's not correct and accurate in all cases because float/double are intrinsically inaccurate, due to [how float/double are represented in the memory](https://en.wikipedia.org/wiki/Floating-point_arithmetic)
```c
double:8bytes, float:4bytes

Example:
  double b = 1.2 - 1.0;
  std::cout.precision(17);
  std::cout<<(double)b<<"\n";       //0.19999999999999996 (should be .2)
```
  - *2b.* Pair of coprimes <int,int>: YES
    - *coprimes/relative primes?* two integers are co-primes, if and only if their greatest common divisor is 1.
```c
Examples:

1,3 are coprimes                        pair=<1,3>
2,4 not coprimes. Reduce to coprimes.   pair=<1,2>
```
### Complexity
> n distinct points on 2-d plane.
  - **Space** O(3n)=O(n). Storing `unordered_map <key=<int,int>, value=count>` Considering all points are distinct we will have n entries in HT.
  - **Time** O(n<sup>2</sup>). Since we will find slope of every point with other.
  
### Code
```c++
class Solution {
public:
  int maxPoints(vector<vector<int>>& points) {
    //0 returns 0
    //1 point returns 1
    //2 points are always colinear, return 2
    if (points.size() < 3)
      return points.size();    
      
      
  }
};
```
