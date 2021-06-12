## [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)
- Grid of 0's and 1's
- find the largest rectangle containing only 1's and return its area.
- Example

<img src=https://assets.leetcode.com/uploads/2020/09/14/maximal.jpg width=100 />

```c
  1 0 1 0 0
  1 0 1 1 1     //3 rows, 2 cols
  1 1 1 1 1
  1 0 0 1 0
Max Area: 6
```

### Approach-1    //Brute Force
- **Logic**
  - Enumerate every possible rectangle. 
  - Consider (x1,y1) and (x2,y2) as opposite corners, Find area of this rectangle.
```c
   0 1 2 3 4    < Index
0  1 0 1 0 0
1  1 0 1 1 1     
2  1 1 1 1 1
3  1 0 0 1 0
  
  (x1,y1)  (x2,y2)  Rectangle   Area
   0,0      1,0     1           2
                    1
   0,0      1,1     1 0         2
                    1 0
   0,0      1,2     1 0 1       2
                    1 0 1
   1,2      2,4     1 1 1       6
                    1 1 1
```
- **Complexity**
  - **Time** 
  - **Space** O(1)
