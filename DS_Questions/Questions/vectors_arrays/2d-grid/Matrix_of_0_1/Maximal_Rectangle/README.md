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
  
  (x1,y1)   (x2,y2)  Rectangle   Area
//Check all rectangles from [0][0]  
  [0][0]    [0][0]    1           1
  [0][0]    [0][1]    1 0         0
  [0][0]    [0][2]    1 0 1       0
  [0][0]    [0][3]    1 0 1 0     0
  [0][0]    [0][4]    1 0 1 0 0   0
  
  [0][0]    [1][0]    1           2
                      1
  [0][0]    [1][1]    1 0         0
                      1 0
  [0][0]    [1][2]    1 0 1       0
                      1 0 1
  [0][0]    [1][3]    1 0 1 0     0
                      1 0 1 1
  [0][0]    [1][4]    1 0 1 0 0   0
                      1 0 1 1 1
                      
  [0][0]    [2][0]    1           3
                      1
                      1
  [0][0]    [2][1]    1 0         0
                      1 0
                      1 1          
  [0][0]    [2][2]    1 0 1       0
                      1 0 1
                      1 1 1                  
                      
  [0][0]   [3][4]
  
//Now Check all rectangles from [0][1]  till [3][4] so on..
```
- **Complexity**
  - **Time** O(n<sup>3</sup>m<sup>3</sup>). n=rows, m-cols
    - 1st for loop for traversing each element
    - 2nd for loop for traversing rows
    - 3rd for loop for traversing cols
  - **Space** O(1)

### Approach-2    //Dynamic Programming, Visualizing Histogram
```c
   0 1 2 3 4    < Index
0  1 0 1 0 0
1  1 0 1 1 1     
2  1 1 1 1 1
3  1 0 0 1 0
```
- **Logic**
  - _1._ Calculate maximum width of a rectangle that ends at a given coordinate.
    - Take dp array of same size as input array
    - Initialize to 0.
```c
dp[4][5]
   0 1 2 3 4
0  0 0 0 0 0
1  0 0 0 0 0
2  0 0 0 0 0
3  0 0 0 0 0

if (input array == '1')
  dp[i][j] = dp[i][j-1] + 1

dp[4][5]
   0 1 2 3 4
0  1 0 1 0 0
1  1 0 1 2 3     
2  1 2 3 4 5    
3  1 0 0 1 0
```
