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
- _1._ Calculate maximum length at this point that ends at a given coordinate.
  - Take dp array of same size as input array. Initialize to 0.
  - if (value==`1`)
    - dp`[present]` = 1 + dp`[prev_row]`
```c
dp[4][5]
   0 1 2 3 4
0  0 0 0 0 0
1  0 0 0 0 0
2  0 0 0 0 0
3  0 0 0 0 0

if (input array == '1')
  dp[i][j] = dp[i][j-1] + 1

   0 1 2 3 4             //Maximum length at any point rectangle can have
0  1 0 1 0 0
1  1 0 1 2 3     
2  1 2 3 4 5    
3  1 0 0 1 0
```
_2._ Now Traverse up(onto coloumn) from given point in dpArray which is > 1 and find max height.
  - For particular row, we already know its max length, as we traverse up maxlen=min(maxlen,lenHere)
```c
   0 1 2 3 4
0  1 0 1 0 0
1  1 0 1 2 3     
2  1 2 3 4 5    
3  1 0 0 1 0

 row col  maxlen=min(maxlen,lenHere)  Height currArea
  0         
  1   0       min(1,1) = 1               1       1
      2       min(1,1) = 1               2       2
  2   0       min(1,1) = 1               3       3
      1       min(2,0) = 0               0       0
      2       min(1,3) = 1               2       2
      
maxLen = min(maxLen,widthHere)
curArea = maxLen * (currentRow - originalRow + 1)
maxArea = max(maxArea, curArea)
```
- **Complexity**
  - **Time:** O(n<sup>2</sup>m)
    - O(n*m): Creating dp array
    - O(n): Traversing coloums upwards.
  - **Space:**
- **Code**
```c++
class Solution {
  using vecC = std::vector<char>;
  using vecVecC = std::vector<vecC>;
  using vecI = std::vector<int>;
  using vecVecI = std::vector<vecI>;    
public:
  int maximalRectangle(vector<vector<char>>& a) {
    if (!a.size())        
        return 0;
    int cols = a[0].size();
    int rows = a.size();
    int maxArea = 0;
    vecVecI dp(rows, vecI(cols,0));     //vec(row, vector<int>(col,0))

    for (int i=0; i<rows; ++i){
      for (int j=0; j<cols; ++j){

        if (a[i][j] == '1') {
          dp[i][j] = j==0 ? 1 : dp[i][j-1]+1;              //Step-1. Creating dpArray

          int maxLen = dp[i][j];

          for (int k=i; k>=0; --k) {                      //Step-2: Traversing upward from col
            len = min(maxLen, dp[k][j]);
            maxArea = max(maxArea, maxLen * (i-k+1));
          }
        }
      }
    }

    return maxArea;        
  }
};
```
