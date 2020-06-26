[Problem](https://leetcode.com/problems/unique-paths-ii/)
[Solution](https://www.geeksforgeeks.org/unique-paths-in-a-grid-with-obstacles/)

## Task
  - A robot is located at the top-left corner of a m x n grid need to reach bottom right.
  - The robot can only move either down or right at any point in time.
  - There are some obstacles added to grid. How many unique paths are there?
  - An obstacle and empty space is marked as 1 and 0 respectively
  
## Example-1
```
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
```

## LOGIC
  1. Take a seperate 2-D array(paths). Initlialize paths[0][0]=1 if grid[0][0]=0.
  2. Initialize 1st row, 1st col of paths array
     if(grid[0][i] == 0)
      path[0][i] = path[0][i-1]
    -> This means if there is no obstacle in Orginal grid
    -> And there is a path from prev node(ie prev == 1) then make current = 1
  3. Calculate paths of all nodes in 2-D array
    -> if (grid[i][j] == 0)   //Means no obstacle
        current_path = above_path + back_path
        
## Solution
```c++
#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& grid)
  {
    /*Corner Cases Start*/
    if(!grid.size())  //empty grid
      return 0;

    if(grid[0][0] & 1)  //1 element grid
      return 0;
    /*Corner cases End*/

    int rows = grid.size();
    int cols = grid[0].size();

    //Taking 2-D and initialize to 0.
    vector<vector<int>> paths(rows, vector<int>(cols, 0));

    if(!grid[0][0])
      paths[0][0] = 1;

    //Initlize 1st row
    for (int i = 1; i < cols; i++){
      if(!grid[0][i])
        paths[0][i] = paths[0][i-1];
    }

    //Initlize 1st col
    for (int i = 1; i < rows; i++){
      if(!grid[i][0])
        paths[i][0] = paths[i-1][0];
    }

    for (int i = 1; i < rows; i++) {
      for (int j = 1; j < cols; j++){
          if(!grid[i][j])
            paths[i][j] = paths[i][j - 1] + paths[i-1][j];
       }
    }
      return paths[rows - 1][cols - 1];
    }
};

int main(){
  Solution s;
  vector<vector<int>> v= {  //O/P=2 ok
    {0,0,0},
    {0,1,0},
    {0,0,0}
  };
  //vector<vector<int>> v= {};  //O/P=0 ok
  /*vector<vector<int>> v= {  //O/P=0 ok
    {0,1,0}
  };*/
  /*vector<vector<int>> v = {   //O/P=0 ok
    {0},
    {1},
    {0}
  };*/
  /*vector<vector<int>> v = {   //O/P=0 ok
    {0,0},
    {1,1},
    {0,0}
  };*/
  auto startTime = high_resolution_clock::now();
  cout<<s.uniquePathsWithObstacles(v)<<"\n";
  auto stopTime = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stopTime - startTime);
  cout<<duration.count();
}    
```
  
