/*      number_of_islands.cpp
https://leetcode.com/problems/number-of-islands/

*****************Logic******************
1. Take visited[][] vector same sized as original 2D vector.
2. Mark all adjacent 1's as visited using recursion.
        -> Do not use queue/stack because it will slow adding and removing elements
           to queue.
3. Traverse whole array and check unvisited 1's:
        -> count++ whenever unvisited 1 is found.
****************************************
*/
#include<vector>
#include<iostream>
#include<queue>
#include<chrono>
using namespace std::chrono;
using namespace std;

class Solution {
public:
        //O(m). m are number of directly connected 1's ie same island.
        void markConnectedVisited(vector<vector<char>>& grid, vector<vector<int>>& vis, int f, int s, int row, int col){
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

        int numIslands(vector<vector<char>>& grid){
                int rows = grid.size();

                if(rows == 0)
                    return 0;

                int cols = grid[0].size();

                //Visited Array of same size as grid, init to 0
                vector<vector<int>> vis(rows, vector<int>(cols,0));

                int count = 0;

                for(int i=0; i<rows; i++){                              //O(n2)
                        for(int j=0; j<cols; j++){

                                //For unvisited Node having value=1
                                if(vis[i][j]==0 && grid[i][j]=='1'){
                                        count++;
                                        markConnectedVisited (grid, vis, i, j, rows, cols);
                                }

                        }
                }
                return count;
        }
};

int main(){
        Solution s;
/*      vector<vector<char>> v =                //Expected 1 got 1
        {
                {'1','1','1','1','0'},
                {'1','1','0','1','0'},
                {'1','1','0','0','0'},
                {'0','0','0','0','0'}
        };*/
/*      vector<vector<char>> v =                //Expected 3, Got 3
        {
                {'1','1','0','0','0'},
                {'1','1','0','0','0'},
                {'0','0','1','0','0'},
                {'0','0','0','1','1'}
        };*/
//      vector<vector<char>> v = {};            //Expected=0, Got=0
/*      vector<vector<char>> v =                //Expected 1, Got=1
        {
                {'1','1','1'},
                {'0','1','0'},
                {'1','1','1'}
        };*/
        vector<vector<char>> v =                //Expected=5,Got=5
        {
                {'1','0','1'},
                {'0','1','0'},
                {'1','0','1'}
        };
        auto startTime = high_resolution_clock::now();
        cout<<s.numIslands(v)<<endl;
        auto stopTime = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stopTime - startTime);
        cout<<duration.count()/1000<<endl;
}
