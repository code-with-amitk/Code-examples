/*      2-d-vector.cpp
  
- Same as 2-D Array but of arbitary size.
C1. Arbitary size 2-D vector
     vector<vector<int>> v = {{1,2,3},{4,5,6}};

C2. Fixed sized 2-D vector, initialized to value.
     vector<vector<int>> v(rows, vector<int>(cols,0));
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){

        //C1. ARBITARY SIZED
        vector<vector<int>> vec =
        {
                {1,2,3},
                {4,5,6}
        };
        for (int i = 0; i < vec.size(); i++) {
                for (int j = 0; j < vec[0].size(); j++){
                        cout<< vec[i][j]<< " "; //1 2 3 4 5 6
                }
        }
        cout << '\n';

        //C2. FIXED SIZED
        int row=2,col=3;
        vector<vector<int>> vec1(row, vector<int>(col,0));
        for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++){
                        cout<< vec1[i][j]<< " "; //0 0 0 0 0 0
                }
        }
        cout << '\n';
}
