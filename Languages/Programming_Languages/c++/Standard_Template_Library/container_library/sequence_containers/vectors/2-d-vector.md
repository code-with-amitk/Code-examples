## 2D Vector
- This is 2-D Array but of arbitary size.
### 1. Initialization of 2d vector
- **1. Varaible size**
```c++
  vector<vector<int>> vec = {
    {1,2,3},
    {4,5,6}
  };
  for (int i = 0; i < vec.size(); ++i) {
    for (int j = 0; j < vec[0].size(); ++j){
      cout<< vec[i][j]<< " "; //1 2 3 4 5 6
    }
  }  
```
- **2. Fixed size**
```c++
  int row=2,col=3;
  vector<vector<int>> vec1(row, vector<int>(col,0));
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      cout<< vec1[i][j]<< " "; //0 0 0 0 0 0  
```

## 2. Inserting row into 2-D vector
```c++
  std::vector<std::vector<int> > vec2D;
  std::vector<int> vec1D;
  
  vec1D.push_back(1); vec1D.push_back(2);
  vec2D.push_back(vec1D); vec1D.clear();
  
  vec1D.push_back(3); vec1D.push_back(4);
  vec2D.push_back(vec1D);
  
  for(int i = 0; i < vec2D.size(); ++i) {
    for(int j = 0; j < vec2D[i].size(); ++j) {
      std::cout << vec2D[i][j];
    }
    std::cout<<"\n";
  }
/*
  1 2
  3 4
*/
```
