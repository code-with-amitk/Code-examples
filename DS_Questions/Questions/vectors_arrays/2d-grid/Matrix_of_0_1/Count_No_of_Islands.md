**Number of Islands**
- [Approach-1, DFS Graph. Connected Components](#a1)

### [200. Number of Islands](https://leetcode.com/problems/number-of-islands/)
- Given matrix '1's (land) and '0's (water). We need to count islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
```cpp
Example-1
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1               //Only 1 island

Example-2
Input: grid = [       
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3               //3 islands
```

<a name=a1></a>
### Approach-1, Find [Connected Components](/DS_Questions/Data_Structures/Graphs#t). DFS
- **Logic-1**
- _1._ Take visited[][] vector same sized as original 2D vector.
- _2._ Mark all adjacent `1's` as visited using recursion.
  - Do not use queue/stack because it will slow adding and removing elements to queue.
- _3._ Traverse whole array and check unvisited `1's`: count++ whenever unvisited 1 is found.
```cpp
using vecVecC = vector<vector<char>>;
using vecI = vector<int>;
using vecVecI = vector<vecI>;

class Solution {
public:
  void markConnectedVisited(vecVecC& grid, vecVecI& vis, int f, int s, int row, int col){
    vis[f][s]=1;
    if (f>0 && (vis[f-1][s] == false) && (grid[f-1][s] == '1')){        //Above Element
      markConnectedVisited (grid, vis, f-1, s, row, col);
     }
    if (s>0 && (vis[f][s-1] == false) &&  (grid[f][s-1] == '1')){       //Left Element
      markConnectedVisited (grid, vis, f, s-1, row, col);
    }
    if ((s<=col-2) && (vis[f][s+1] == false) && (grid[f][s+1] == '1')){ //Right Element
      markConnectedVisited (grid, vis, f, s+1, row, col);
    }
    if ((f<=row-2) && (vis[f+1][s] == false) && (grid[f+1][s] == '1')){ //Below element
      markConnectedVisited (grid, vis, f+1, s, row, col);
    }
  }

  int numIslands(vecVecC& grid){
    int rows = grid.size(), cols=grid[0].size(), count = 0;
    if(rows == 0)
        return 0;

    vecVecI vis(rows, vecI(cols,0)); //Visited Array of same size as grid, init to 0

    for(int i=0; i<rows; i++)                              //O(mn)
      for(int j=0; j<cols; j++)
                        
        if(vis[i][j]==0 && grid[i][j]=='1'){
          count++;
          markConnectedVisited (grid, vis, i, j, rows, cols);
        }
     return count;
   }
};
```


- **Logic-2 (Modify input array):**
  - _1._ Each visited node is marked as 2
  - _2._ Start from index=0,0. Mark Island as 2.
```cpp
   1  1  1  1  0      2 2 2 2 0
   1  1  0  1  0      2 2 0 2 0
   1  1  0  0  0      2 2 0 0 0 
   0  0  0  0  0      0 0 0 0 0
```
#### Complexity
- **Time:** O(mxn). m=rows, n=cols
- **Space:** O(1)
#### CPP
```cpp
class Solution {
    int rows, cols;
    vector<int> rowDirections = {-1,0,0,1};
    vector<int> colDirections = {0,-1,1,0};
public:
    // Return true if any 1 is found in 4 directions
    bool checkAllDirections(int row, int col, vector<vector<char>>& grid){
        if (row < 0 || col < 0 || row >= rows || col >= cols)
            return false;
        if (grid[row][col] == '1')
            return true;
        return false;
    }
    void searchNeighbours (int row, int col, vector<vector<char>>& grid) {
        grid[row][col] = '2';
        // Check all 4 directions
        for (int i=0;i<4;++i){
            int r = row+rowDirections[i];
            int c = col+colDirections[i];
            if (checkAllDirections(r, c, grid)) {
                searchNeighbours (r, c, grid);
            }            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        rows = grid.size();
        cols = grid[0].size();
        for (int i=0;i<rows;++i){
            for (int j=0;j<cols;++j){
                if (grid[i][j] == '1') {
                    count += 1;
                    searchNeighbours (i, j, grid);
                }
            }
        }
        return count;
    }
};
```
