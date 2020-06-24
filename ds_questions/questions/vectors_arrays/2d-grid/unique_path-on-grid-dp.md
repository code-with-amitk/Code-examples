
[Problem](https://leetcode.com/problems/unique-paths/)
[Solution](https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/)

  - `mxn` grid. Robot will start from `0x0` to bottom-right corner of the grid
  -  robot can only move either down or right at any point in time.
  - **Problem** How many possible unique paths are there?
  
### Solution-1 (Dynamic-programming)
#### Logic
  - Count of paths will be same either we calculate for `2x3` or `3x2` matrix
  - Consider `3x2` matrix. We take `3x2` array. a[3][2]
#### Steps
  1. Number of paths to reach element in 1st row, 1st col is always 1, since only right and down movements allowed. So we can make 1st row, 1st col as 1.

| 1 | 1 |
| --- | --- |
| 1 | 0 |
| 1 | 0 |
   
  2. iterate for remaining entries in matix
     - count of reaching position = count-of-up-position + count-of-back-position

| 1 | 1 |
| --- | --- |
| 1 | 2 = (a[0][1]=1 + a[1][0]=1) |
| 1 | 3 = (a[1][1]=2 + a[2][0]=1) |

**Complexity**: O(row*col)
```
int numberOfPaths(int row, int col)
{
    int a[row][col];

    for (int i = 0; i < row; i++)       //No of paths to reach 1st row, col is always 1
        a[i][0] = 1;

    for (int j = 0; j < col; j++)
        a[0][j] = 1;

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++)
            //By uncommenting the last part the code calculatest he total
            //possible paths if the diagonal Movements are allowed
            a[i][j] = a[i - 1][j] + a[i][j - 1]; //+ a[i-1][j-1];
    }
    return a[row - 1][col - 1];
}
```

### Solution-2
  - Count can be calculated using this formula:
    - (m-1 + n-1)!/(m-1)!(n-1)!.
```
int numberOfPaths(int m, int n) 
{ 
    // We have to calculate m+n-2 C n-1 here 
    // which will be (m+n-2)! / (n-1)! (m-1)! 
    int path = 1; 
    for (int i = n; i < (m + n - 1); i++) { 
        path *= i; 
        path /= (i - n + 1); 
    } 
    return path; 
} 
```
