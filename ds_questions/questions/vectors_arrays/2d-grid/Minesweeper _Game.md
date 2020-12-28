### Problem
- Create minesweeper grid(4x5) with (5) mines.

### Logic
- *1.* Create a nxm grid.
- *2.* Generate mine positions using `rand()`, place mines on grid
- *3.* Traverse the grid and Fill numbers wrt mines.

### Complexity
> n:Number of rows, m:Number of cols, k:Mines
- **Time:** O(r)xk + O(mn)
  - k*O(r), where O(r): Time taken by random number generator function. 
  - O(mn)
- **Space:** O(nm)

### Code
```c++
//In 4x5 grid, Place 5 mines
#define ROWS 4
#define COLS 5
#define MINES 5
#include<iostream>
#include<vector>
#include<unistd.h>
using vec2d = std::vector<std::vector<int>>;

int GetRandom(int limit){
  srand(time(0));
  return rand()%limit;
}

//Check Mine in 8 directions
//      N
//    W   E
//      S
void Fill(vec2d& grid, int row, int col){
  if(col>0 and row>0 and grid[row-1][col-1] == -1)    //NW
    grid[row][col] += 1;
  if(col>0 and grid[row][col-1] == -1)    //W
    grid[row][col] += 1;
  if(col>0 and row<ROWS-1 and grid[row+1][col-1] == -1)   //WS
    grid[row][col] += 1;
  if(row<ROWS-1 and grid[row+1][col] == -1)   //S
    grid[row][col] += 1;
  if(col<COLS-1 and row<ROWS-1 and grid[row+1][col+1] == -1)    //SE
    grid[row][col] += 1;
  if(col<COLS-1 and grid[row][col+1] == -1)   //E
    grid[row][col] += 1;
  if(row>0 and col<COLS-1 and grid[row-1][col+1] == -1)   //NE
    grid[row][col] += 1;
  if(row>0 and grid[row-1][col] == -1)    //NE
    grid[row][col] += 1;
}

void PlaceMines(vec2d& grid) {
  int iPlaceMineOnRow=0, iPlaceMineOnCol=0;
  int iMines = MINES;
  for (int i = 0; i < iMines; ++i){
    iPlaceMineOnRow = GetRandom(ROWS);
    iPlaceMineOnCol = GetRandom(COLS);

    //Already placed Mine at [row][col], Get new [row][col]
    if (grid[iPlaceMineOnRow][iPlaceMineOnCol] == -1)
      --iMines;
    else
      grid[iPlaceMineOnRow][iPlaceMineOnCol] = -1;
    sleep(1);
  }
}

int main(){
  vec2d grid(ROWS, std::vector<int>(COLS,0));

  PlaceMines(grid);
  for (int i=0;i<4;++i){
    for (int j=0;j<5;++j){
      std::cout<<grid[i][j]<<" ";
    }
    std::cout<<"\n";
  }
  std::cout<<"\n\n";

  FillWithNumbers(grid);

  for (int i=0;i<4;++i){
    for (int j=0;j<5;++j){
      std::cout<<grid[i][j]<<" ";
    }
    std::cout<<"\n";
  }
}

# ./a.out
0 0 -1 0 -1
0 -1 0 -1 0
-1 0 0 0 0
0 0 0 0 0

1 2 -1 3 -1
2 -1 3 -1 2
-1 2 2 1 1
1 1 0 0 0
```
