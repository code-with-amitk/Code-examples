[Problem](https://leetcode.com/problems/minimum-path-sum/)

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the 
sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

### Example
```
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
```

### Logic:
  1. Take a cost[][] array of equal size as input. Initlize to infinity.
  2. Calculate cost of traversal from a[i] to right & a[i] to below
    - if(travel_cost_to_right < present_cost_in_cost_array)
      - update cost array
    - same cost calculation for below element      
  3. Complexity: O(mn)
  
```c++
class Solution {

public:
    template<typename T>
    T minPathSum(vector<vector<T>>& grid) {
      //Finding 2-D vector row and col
      int row = grid.size();
      int col = grid[0].size();

      //Taking an array of grid size
      T cost[row][col];
      for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
          cost[i][j]=INT_MAX;

      cost[0][0] = grid[0][0];

      //Traverse vector
      for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
          //cout<<grid[i][j]<<" ";

          //Checking right
          if(j<col-1 && (cost[i][j+1] > cost[i][j]+grid[i][j+1])){
              cost[i][j+1] = cost[i][j]+grid[i][j+1];
          }

          //Checking Below
          if(i<row-1 && (cost[i+1][j] > cost[i][j]+grid[i+1][j])){
              cost[i+1][j] = cost[i][j]+grid[i+1][j];
          }

        }
      }
      for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
          cout<<cost[i][j]<<" ";
        }
        cout<<"\n";
      }
      cout<<"\n";
      return cost[row-1][col-1];
    }
};
int main(){
  vector<vector<int>> a ={
    {1,3,1},
    {1,5,1},
    {4,2,1}
  };
  Solution s;
  cout<<s.minPathSum(a);
}
```
