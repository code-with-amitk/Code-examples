## [Problem](https://leetcode.com/problems/battleships-in-a-board/)

## Problem Description
- Given a 2-D board filled with `X` and `.`
- Continous `X` represents a battle ship, `.` represents a seperation
- Battleships can only be placed horizontally or vertically ie they can only be made of 1XN size or Nx1 size.
- At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
## Example
- This has 2 battleships
```
  {'X','.','.','X'},
  {'.','.','.','X'},
  {'.','.','.','X'}
```

## Logic
- Take a visited array of same size as 2-D grid. Initialize it to 0.
- Traverse Complete 2-D array from top-left to bottom-right.
  - if node=='X' && unvisited
    - Increment the battleship count by 1
    - Check Right,Bottom connected nodes with (value = `X`) & mark them visited
      - Do not take stack(since it involves extra space,time)
      - Just traverse to adjacent nodes having value='X' recursively. if adjacent node = 'X' mark it visited.
- **Complexity**
  - *Time* O(mxn) Visiting all nodes, because once node is marked visited it not revisited
  - *Space* O(mxn) Taking a visited array.    
   
## Code   
```
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

  void markConnectedVisited(vector<vector<char>>& grid, vector<vector<int>>& vis, int f, int s, int row, int col){
    vis[f][s]=1;
    
    //We only check right & below elements, not bothered about up,left
    if ((s<=col-2) && (vis[f][s+1] == false) && (grid[f][s+1] == 'X')){ //Right Element
      markConnectedVisited (grid, vis, f, s+1, row, col);
    }
    if ((f<=row-2) && (vis[f+1][s] == false) && (grid[f+1][s] == 'X')){ //Below element
      markConnectedVisited (grid, vis, f+1, s, row, col);
    }
  }
  
  int countBattleships(vector<vector<char>>& v) {
    int rows = v.size();

    if(rows == 0)
      return 0;
    int cols = v[0].size();
    
    cout<<"cols="<<cols<<",rows="<<rows<<endl;

    vector<vector<int>> vis(rows, vector<int>(cols,0));

    int count = 0;

    for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){

        //For unvisited Node having value=X
        if(v[i][j] == 'X' && vis[i][j]==0){
          count++;
          markConnectedVisited (v, vis, i, j, rows, cols);
        }
        
      }
    }
    return count;
  }
};

int main(){
  vector<vector<char>> v= {
    {'X','.','.','X'},
    {'.','.','.','X'},
    {'.','.','.','X'}
  };
  Solution s;
  cout<<s.countBattleships(v);
}

```
