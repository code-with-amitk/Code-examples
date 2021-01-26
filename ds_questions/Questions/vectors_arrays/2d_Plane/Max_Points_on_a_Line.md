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
- *1.* Calculate slope of every 2 points on plane. How slope is stored?
  - *Option-1.* Double or Float? No. You must be thinking double or float to store slope? But that's not correct and accurate in all cases because float/double are intrinsically inaccurate, due to [how float/double are represented in the memory](https://en.wikipedia.org/wiki/Floating-point_arithmetic)
```c
double:8bytes, float:4bytes

Example:
  double b = 1.2 - 1.0;
  std::cout.precision(17);
  std::cout<<(double)b<<"\n";       //0.19999999999999996 (should be .2)
```
  - *Option-2.* Store the slope as Pair of coprimes <int,int>. 
    - *Coprimes/relative primes?* two integers are co-primes, if and only if their greatest common divisor is 1.
```c
Examples:

1,3 are coprimes                              pair=<1,3>
2,4. 8,16 not coprimes. Reduce to coprimes.   pair=<1,2>

Hash-Table    key=slope, value=count    //unordered_map<<int,int>, int>
- Return the max value from hash table
```

### Complexity
> n distinct points on 2-d plane.
  - **Space** O(3n)=O(n). Storing `unordered_map <key=<int,int>, value=count>` Considering all points are distinct we will have n entries in HT.
  - **Time** O(n<sup>2</sup>). Since we will find slope of every point with other.
  
### Code
```c++
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

int iSize=0;
int HorizontalLines=0;
std::vector<std::vector<int>> points;
using Pair = std::pair<int,int>;
                  //slope, count
std::unordered_map<Pair, int, pair_hash> um;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};

Pair FindSlope(int x1, int y1, int x2, int y2){
  Pair p;
  int x = x2-x1;
  int y = y2-y1;

  if (x==0)     //Vertical Line
    return {0,0};
  else if (y==0)  //Horizontal Line
    return {INT32_MAX, INT32_MAX};
  else if (x<0){
    x = -x;
    y = -y;
  }
  int iGCD = std::__gcd(x,y);

  return {x/iGCD, y/iGCD};
}

Pair AddLine(int i, int j, int count, int duplicates) {
  //if i=0 means, 1st row, ie 1st point
  //if j=1 means, 2nd row, ie 2nd point
  int x1 = points[i][0];
  int y1 = points[i][1];
  int x2 = points[j][0];
  int y2 = points[j][1];
  Pair p;

  if (x1==x2 and y1==y2)
    ++duplicates;
  else if (y1 == y1){     //y = 10
    ++HorizontalLines;
    count = std::max(HorizontalLines, count);
  }else{
    //We will store slope as Pair as we defined, float/double are not accurate
    Pair slope = FindSlope(x1,y1,x2,y2);

    //Update count if slope already exist else create new <key,value>
    auto it = um.find(slope);
    if (it == um.end())
      um[slope] = 1;
    else
      it->second++;

    count = std::max(it->second, count);
  }
  return {count, duplicates};
}

int MaxPointsOnLineContainingPointi(int i){

  //Atleast 1 point will always be there
  int count = 1;

  //Duplicate point
  int duplicates = 0;

  //Are 2 points i and j colinear, ie fall on same line?
  for (int j = i+1; j<iSize; ++j) {
    Pair p = AddLine(i, j, count, duplicates);
    count = p.first;
    duplicates = p.second;
  }
  return count+duplicates;
}  

int maxPoints(std::vector<std::vector<int>>& points){

  iSize = points.size();
  points = points;
  //0 returns 0
  //1 point returns 1
  //2 points are always colinear, return 2
  if (iSize < 3)
    return iSize;

  int MaxPoints = 1;

  for (int i=0; i<iSize-1; ++i) {
    MaxPoints = std::max(MaxPoints, MaxPointsOnLineContainingPointi(i));
  }
  return MaxPoints;
}

int main(){
  std::vector<std::vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
  std::cout<<maxPoints(points);
}
```
