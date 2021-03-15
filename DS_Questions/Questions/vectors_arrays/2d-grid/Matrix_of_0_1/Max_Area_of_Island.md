## [Max Area of Island](https://leetcode.com/problems/max-area-of-island/)
- Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
- Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
- Example 1:
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

### Approach-1         //DFS
- **Logic**
  - *1.* Iterate through every element of grid. if element==1
    - *1a.* Check all 4 directions of element.
      - if row,col crosses bounds, return 0.
      - else check all directions N,E,W,S and all 1 if element==1
  - *2.* Make elemnent=0
- **Complexity:** m rows, n cols
  - **Time:** O(m x n)
  - **Space:** O(1), No extra space taken
- **Code**
```c
    //      N
    //  W       E
    //      S

int check(vec2d& grid, int r, int c){
  if (r<0 || r>=grid.size() || c<0 ||c>=grid[0].size() || grid[r][c]==0)
    return 0;

  grid[r][c] = 0;

  int ret = 1;
  ret += check(grid,r+1,c);
  ret += check(grid,r-1,c);
  ret += check(grid,r,c+1);
  ret += check(grid,r,c-1);
  return ret;
}

int maxAreaOfIsland(vec2d& grid) {
  int maxArea = -1;
  int area = 0;
  for(auto i=0;i<grid.size();++i){    //row             //1
    for(auto j=0;j<grid[0].size();++j){ //col     
      if(grid[i][j] == 1)
        area = max(area,check(grid, i, j));
    }
  }
  return area;
}
```
