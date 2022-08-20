**Number of Islands**
- [Approach-1, Find Connected Components Using visited array](#a1)
  - [Code](#c1)
- [Approach-2, Modifying incoming array, No extra Space](#a2)
  - [Code](#c2)

### [Number of Islands](https://leetcode.com/problems/number-of-islands/)
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
### Approach-1, Find [Connected Components](/DS_Questions/Data_Structures/Graphs#t) (Using visited array)
```cpp
1. Take visited[][] vector same sized as original 2D vector.
2. Mark all adjacent `1's` as visited using recursion.
        -> Do not use queue/stack because it will slow adding and removing elements
           to queue.
3. Traverse whole array and check unvisited `1's`:
        -> count++ whenever unvisited 1 is found.
```
<a name=c1></a>
#### Code-1
```cpp
#include<vector>
#include<iostream>
#include<queue>
#include<chrono>
using namespace std::chrono;
using namespace std;
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

<a name=a2></a>
### Approach-2, Find [Connected Components](/DS_Questions/Data_Structures/Graphs#t) (Modifying incoming array, No extra Space)
- Each visited node is marked as 2
- Start from index=0,0. Mark Island as 2.
```c++
   1  1  1  1  0
   1  1  0  1  0
   1  1  0  0  0
   0  0  0  0  0
--become-->   
   2  2  2  2  0
   2  2  0  2  0
   2  2  0  0  0
   0  0  0  0  0
```
<a name=c2></a>
#### Code-2
```cpp
using vecVecC = vector<vector<char>>;
using vecI = vector<int>;
using vecVecI = vector<vecI>;

void MarkIslandVisited(vecVecI& grid,
                        int i/*row*/, int j/*col*/, int& MaxRows, int& MaxCols){
  grid[i][j]=2;
  
  if (i<=MaxRows-2 and grid[i+1][j]==1)   //below
    MarkIslandVisited(grid,i+1,j,MaxRows,MaxCols);

  if (j<=MaxCols-2 and grid[i][j+1]==1)     //right
    MarkIslandVisited(grid,i,j+1,MaxRows,MaxCols);

  if (j>0 and grid[i][j-1]==1)    //back
    MarkIslandVisited(grid,i,j-1,MaxRows,MaxCols);

  if (i>0 and grid[i-1][j]==1)    //above
    MarkIslandVisited(grid,i-1,j,MaxRows,MaxCols);
}

int numIslands(vecVecI grid){
  int MaxRows = grid.size();
  int MaxCols = grid[0].size();
  int count = 0;

  for (int i=0; i<MaxRows; ++i)
    for (int j=0; j<MaxCols; ++j)
      if (grid[i][j] == 1){
        ++count;
        MarkIslandVisited(grid,i,j,MaxRows,MaxCols);
      }
  return count;
}
```
