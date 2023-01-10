**Max area of island**
- [Approach-1. DFS](#a1)
  - [Logic]
  - [Complexity]
  - Code
    - [CPP](#cpp)

### [Max Area of Island](https://leetcode.com/problems/max-area-of-island/)
- Grid of 0,1. Group of 1's (representing land), 0=water.
- Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
- Example 1:

<img src="https://assets.leetcode.com/uploads/2021/05/01/maxarea1-grid.jpg" width=500 />

```c
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
 
Ouput: 6 
``` 

<a name=a1></a>
### Approach-1. DFS
<a name=l></a>
#### Logic
- *1.* Iterate through every element of grid. if element==1
  - *1a.* Check all 4 directions of element.
    - if row,col crosses bounds, return 0.
    - else check all directions N,E,W,S and all 1 if element==1
- *2.* Mark element as visited by making element=0
<a name=c></a>
#### Complexity
- m rows, n cols
- **Time:** O(m x n)
- **Space:** O(1), No extra space taken
#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
    int iRow, iCol;
        /*          N(-1,0)
            W(0,-1)          E(0,1)
                    S(1,0)
        */
    int dirR[4] = {-1,0,1,0};
    int dirC[4] = {0,1,0,-1};
public:
    // if in any direction I have 1
    // return true
    bool checkNeighbours(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row >= iRow || col >= iCol)
            return false;
        if (grid[row][col] == 1)
            return true;
        return false;
    }
    int dfs(vector<vector<int>>& grid, int row, int col) {
        grid[row][col] = 0;    //Mark as visited

        // We are here because we have a cell with value 1
        // Cell with value 1 has area = 1;
        int presentArea = 1;            
        
        // Check all 4 directions
        for (int i=0;i<4;++i){
            int r = row + dirR[i];
            int c = col + dirC[i];
            if (checkNeighbours(grid, r,c)) {
                presentArea += dfs (grid, r, c);
            }
        }
        return presentArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int iMaxArea = 0;
        iRow = grid.size();
        iCol = grid[0].size();
        for (int i=0;i<iRow;++i) {
            for (int j=0;j<iCol;++j) {
                if (grid[i][j] == 1)
                    iMaxArea = max(iMaxArea, dfs(grid, i, j));
            }
        }
        return iMaxArea;
    }
};
```
