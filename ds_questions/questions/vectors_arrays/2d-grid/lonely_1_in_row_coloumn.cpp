/*      lonely_1_in_row_coloumn.cpp
 
 In a given 2-D array of 0,1s.
 1 is called lonely if there is no 1 in that row & coloumn apart from it.

Example:
Input
        0 0 0 1
        0 1 1 0
        0 1 0 0

Output (0,3). There is only (0,3) element which is lonely.
 
*****Logic(Dynamic Programming)*******
- Take 2 arrays
   r[number-of-rows]
   c[number-of-coloumns]
- Count number of 1's row-wise and coloumn-wise
- Lonely 1 is found when particular row and col has only 1
   if a[i][j]==1 and r[i]==1 && c[j]==1

COMPLEXITY:
Time: 2O(mn)
Space: O(m+n)
**************************************
*/
#include<iostream>
using namespace std;

void fun(int a[3][4], int row, int col){
        int r[3];
        int c[4];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                if (a[i][j]) {
                    r[i]++;
                    c[j]++;
                }
            }
        }

        //r[] = {1,2,2}   //row1 has 1 1s, row2 has 2 1s, row3 has 1 1s
        //c[] = {0,2,1,1} //col1 has 0 1s, col2 has 2 1s, col3 has 1 1s and col4 has 1

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                if (a[i][j] == 1 && r[i] == 1 && c[j] == 1) {
                    cout<<"lonely 1's at:"<<i<<","<<j<<endl;
                }
            }
        }
}

int main(){
        int a[3][4]={
                {0, 0, 0, 1},
                {0, 1, 1, 0},
                {0, 1, 0, 0}
        };

        fun(a,3,4);
}
/*
lonely 1's at: 0,3
*/
