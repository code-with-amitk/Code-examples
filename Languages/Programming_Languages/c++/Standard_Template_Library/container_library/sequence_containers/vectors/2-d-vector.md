- [Initialization](#in)
- [2. Inserting row into 2-D vector](#i)

## 2D Vector
- This is 2-D Array but of arbitary size.

<a name=in></a>
### 1. Initialization of 2d vector
#### 1. Initialization list
```cpp
  vector<vector<int>> vec = {
    {1,2,3},
    {4,5,6}
  };
```
#### 2. m row, n col
```c++
  int row=2,col=3;
  vector<vector<int>> vec(row, vector<int>(col,0));    //vec[2][3] initialized to 0
```
#### 3. m rows, variable cols
```c++
  int row=2;
  vector<vector<int>> vec(row);
  vec[0][0] = 1;
  vec[0][1] = 1;
  vec[0][2] = 1;
  vec[1][0] = 2;
```

<a name=i></a>
### 2. Inserting row into 2-D vector
```c++
  std::vector<std::vector<int> > vec2D;
  std::vector<int> vec1D;
  
  vec1D.push_back(1); 
  vec1D.push_back(2);
  vec2D.push_back(vec1D);
    
  for(int i = 0; i < vec2D.size(); ++i) {
    for(int j = 0; j < vec2D[i].size(); ++j) {
      std::cout << vec2D[i][j];
    }
    std::cout<<"\n";
  }
```
