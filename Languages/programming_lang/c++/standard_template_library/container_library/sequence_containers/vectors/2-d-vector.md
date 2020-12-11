## 2D Vector
- **What** This is 2-D Array but of arbitary size.
  
### Examples
- **1. Initialization**
```c++
/////////////A. Variable Sized//////////////
  vector<vector<int>> vec = {
    {1,2,3},
    {4,5,6}
  };
  for (int i = 0; i < vec.size(); ++i) {
    for (int j = 0; j < vec[0].size(); ++j){
      cout<< vec[i][j]<< " "; //1 2 3 4 5 6
    }
  }

///////////B. Fixed Sized///////////
  int row=2,col=3;
  vector<vector<int>> vec1(row, vector<int>(col,0));
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j){
      cout<< vec1[i][j]<< " "; //0 0 0 0 0 0
    }
  }
```
