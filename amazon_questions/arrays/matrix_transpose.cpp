/*      matrix_transpose.cpp

Transpose? is just reflection of elements along major diagonal. Diagonal remains fixed. https://en.wikipedia.org/wiki/Transpose
Examples:
 Matrix      Transpose
 1 2    =>      1 3     //Major diagonal passes from 1 and 4
 3 4            2 4

 1 2 3  =>      1 4
 4 5 6          2 5     //Major diagonal passes from 1 and 5
                3 6
 
 1 2 3          1 4 7
 4 5 6  =>      2 5 8   //Major diagonal passes from 1,5,9
 7 8 9          3 6 9
*/
#include<iostream>
using namespace std;

int main(){
        int a[][3]={{1,2,3},    //While initializing row can be skipped
                    {4,5,6},
                    {7,8,9}};
        int t[3][3];            //While declaring row,col both are required

        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        if(a[i][j])
                                t[j][i] = a[i][j];
                }
        }

        cout<<"\nOriginal: ";
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        cout<<a[i][j]<<" ";
                }
        }

        cout<<"\nTranspose ";
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        cout<<t[i][j]<<" ";
                }
        }
        cout<<"\n";
}
/*
# ./a.out 

Original: 1 2 3 4 5 6 7 8 9 
Transpose 1 4 7 2 5 8 3 6 9 
*/
