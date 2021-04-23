## [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/)
- Find all colinear points on the line, ie all points which lies on the same line.
- **Example**
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

## Approach  //Slope
- **Slope/Gradient?** if line is represented using y = mx + c. Then its slope is:
```c
  (y2 - y2)/(x2 - x1)
```
### Logic
  - *1.* Calculate slope of every 2 points and store in unordered_map`<key=slope, value=count>`
```c++
{1,1},{2,2},{3,3}

um  key=slope value
      1        2
```
  - *2.* Find max value and keep in variable. 
  - *3.* Clear unordered_map since slope of line (1,1)<>(2,2) is already calculated, recalculation will give wrong ans.
### Complexity
  - **Time** O(n<sup>2</sup>). Since we will find slope of every point with other.
  - **Space** O(3n)=O(n). Storing `unordered_map <key=<int,int>, value=count>` Considering all points are distinct we will have n entries in HT.
  
### Code
```c++
class Solution {
public:
  int maxPoints(vector<vector<int>>& points) {
    int iSize = points.size();
    
    if(iSize<3)
      return iSize;        
      
            //key=slope, value=count
    unordered_map<double, int> um;

    int out = 0;
  
    for (int i=0;i<iSize;++i) {
      auto FirstPoint = points[i];

      for (int j=0;j<iSize;++j) {
        if (j==i)
          continue;
        
        double slope = (double)(points[j][1] - FirstPoint[1])/
                       (double)(points[j][0] - FirstPoint[0]);
        um[slope]++;                                              //1
      }//for(j)

      for (auto i:um)                                            //2
        a = max(a, i.second);

      um.clear();                                                //3
    }//for(i)
    
  return a+1;        
  }
};
```
