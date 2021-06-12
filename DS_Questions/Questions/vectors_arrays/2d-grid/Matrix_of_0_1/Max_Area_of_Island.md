## [Max Area of Island](https://leetcode.com/problems/max-area-of-island/)
- Grid of 0,1. Group of 1's (representing land), 0=water.
- Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

<img url=https://assets.leetcode.com/uploads/2021/05/01/maxarea1-grid.jpg width=500 />

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

int check(vec2d& grid, int r, int c){                           //1a
  if (r<0 || r>=grid.size() || c<0 ||c>=grid[0].size() || grid[r][c]==0)            
    return 0;

  grid[r][c] = 0;                                       //2

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
