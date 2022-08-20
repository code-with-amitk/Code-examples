**Region cut by slashes**
- **Approach-1, upsize the grid**
  - [Logic](#l)
  - [Complexity](#co)
  - [Code](#c)

### [Region cut by slashes](https://leetcode.com/problems/regions-cut-by-slashes/)
- An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.
- Given the grid grid represented as a string array, return the number of regions.
- Note that backslash characters are escaped, so a '\' is represented as '\\'.
- Example-1
<img src=region_cut_by_slashes.png width=500 />

```
Input: grid = [" /","/ "]
Output: 2
```

### Approach-1, Upsize grid
<a name=l></a>
#### Logic
- _1._ Upsize grid to `[n*3-1][n*3-1]`. Then problem will be of number of islands
<img src=upsize_grid.png width=500 />

<a name=co></a>
#### Complexity
- **Time:**
  - O(n<sup>2</sup>): upsize grid
  - O(n<sup>2</sup>): dfs grid
- **Space:**
  - O(nx3<sup>2</sup>): storing upsized grid

<a name=c></a>
#### Code
```cpp
using vecI = std::vector<int>;
using vecS = std::vector<std::string>;
using vecVecS = std::vector<vecS>;
using vecVecI = std::vector<vecI>;
using vecB = std::vector<bool>;
using String = std::string;
using USet = std::unordered_set<int>;

class Solution {
    int size;
public:
    vecVecI upsizeGrid(vecS& g){

        //Create a [n*3][n*3] grid
        size = g.size();
        vecVecI grid(size*3, vecI(size*3, 0));

        for (int i=0; i<size; ++i){
            for (int j=0; j<size; ++j){
                if (g[i][j] == '/') {
                    grid[i*3][j*3 + 2] =
                    grid[i*3 + 1][j*3 + 1] =
                    grid[i*3 + 2][j*3] = -1;
                }
                else if (g[i][j] == '\\'){
                    grid[i*3][j*3] =
                    grid[i*3 + 1][j*3 + 1] =
                    grid[i*3 + 2][j*3 + 2] = -1;
                }
            }
        }
        return grid;
    }
    void dfs(vecVecI& grid, int r, int c) {
        grid[r][c] = -1;
        //Check all 4 directions

        if (r>0 && !grid[r-1][c])   //North
            dfs(grid, r-1, c);
        if (c>0 && !grid[r][c-1])   //East
            dfs(grid, r, c-1);
        if (c<size*3-1 && !grid[r][c+1])   //West
            dfs(grid, r, c+1);
        if (r<size*3-1 && !grid[r+1][c])   //South
            dfs(grid, r+1, c);
    }
    int regionsBySlashes(vecS& g) {
        int count = 0;
        //Create n*3xn*3 grid
        vecVecI grid = upsizeGrid(g);

        //Perform DFS On grid
        for (int i=0;i<size*3;++i) {
            for (int j=0;j<size*3;++j) {
                if (!grid[i][j]) {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
       return count;
    }
};
```
