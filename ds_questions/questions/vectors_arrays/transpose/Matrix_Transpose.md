## Transpose? 
- Reflection of elements along major diagonal. Diagonal remains fixed.
- Examples:
```c
 Matrix      Transpose
 1 2    =>      1 3     //Major diagonal passes from 1 and 4
 3 4            2 4

 1 2 3  =>      1 4
 4 5 6          2 5     //Major diagonal passes from 1 and 5
                3 6
 
 1 2 3          1 4 7
 4 5 6  =>      2 5 8   //Major diagonal passes from 1,5,9
 7 8 9          3 6 9
```

## Logic
- *1.* Return if only 1 element
- *2.* if rows != cols (eg 2x3 matrix), exchange rows and cols.
- *3.* Create a vector to store transpose of matrix.
- *4.* Exchange elements across major diagonal.
 
## Code
```c
#include<iostream>
using namespace std;

class Solution{
public:
  vector<vector<int>> Transpose(vector<vector<int>>& a){
    int rows = a.size();
    int cols = a[0].size();
    int r,c;
    if (rows == 1 and cols == 1)                   //1
      return a;

    if (rows == cols)                              //2
      r = rows, c = cols;
    else
      r = cols,c = rows;

    vector<vector<int>> t(r, vector<int>(c,0));    //3

    for(int i = 0; i < c; ++i){                    //4
      for(int j =0 ; j <r;++j){
        if(a[i][j])
          t[j][i] = a[i][j];
      }
    }
    return t;
  }
  void print(vector<vector<int>>& a){
    int rows = a.size();
    int cols = a[0].size();
    for(int i = 0; i < rows; ++i){
      for(int j =0 ; j <cols;++j){
        cout<<a[i][j]<<" ";
      }
      cout<<"\n";
    }
    cout<<"\n";
  }
};

int main(){
  //int a[][3]={{1,2},{3,4}};    //While initializing row can be skipped
  //int t[3][3];            //While declaring row,col both are required

  vector<vector<int>> a =
              {{1,2,3},
               {4,5,6},
               {7,8,9}};
//  vector<vector<int>> a =
//              {{1,2,3},
//               {4,5,6}};

  Solution s;
  s.print(a);
  vector<vector<int>> b = s.Transpose(a);
  cout<<"Transpose\n";
  s.print(b);
}
/*
# ./a.out 
1 2 3
4 5 6
7 8 9

Transpose
1 4 7
2 5 8
3 6 9
*/
```
