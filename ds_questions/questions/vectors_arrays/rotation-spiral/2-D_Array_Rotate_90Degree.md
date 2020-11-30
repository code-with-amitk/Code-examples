## Problem
- You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
- You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
- Example
```c
  input = {{1,2,3},
           {4,5,6},
           {7,8,9}};
  output = {{7,4,1},   
            {8,5,2},
            {9,6,3}};  
```

## Logic
- *1.* Find Transpose of matrix
```c
  Tranpose = {{1,4,7},   
              {2,5,8},
              {3,6,9}};
```
- *2.* Reverse coloumns of matrix
```c
  Col-1 is exchanged with col-3
  Tranpose = {{7,4,1},
              {8,5,2},
              {9,6,3}};
```

## Code
```c++
class Solution {
public:
    void rotate(vector<vector<int>>& a) {
    int rows = a.size();
    if (rows == 1)
      return;

    //Transpose
    for(int i = 0; i < rows; ++i){
      for(int j =i ; j < rows;++j){
        if(i not_eq j)
          swap(a[i][j], a[j][i]);
      }
    }
    
    //Reverse Coloumn
    int k;
    for (int i = 0; i < rows; i++) {
      k = rows-1;
      for (int j = 0; j < k; j++) {
        swap(a[i][j], a[i][k]);
        k--;
      }
    }        
        
    }
};
```
