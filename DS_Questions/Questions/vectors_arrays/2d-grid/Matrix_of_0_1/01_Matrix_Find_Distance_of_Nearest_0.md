**01 Matrix**
- [Approach-1, Brute Force, TLE](#a1)

### [01 Matrix](https://leetcode.com/problems/01-matrix/)
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
```c
Example-1
Input
          0 0 0
          0 1 0
          0 0 0
Output:
          0 0 0
          0 1 0
          0 0 0

Example-2
Input
          0 0 0
          0 1 0
          1 1 1
Output
          0 0 0
          0 1 0
          1 2 1
```

<a name=a1></a>
### Approach-1, Brute Force, TLE
#### Logic
- _1._ Take a output matrix of same size as input matrix. Initialize 0 and inf for 1.
```c
Input
          0 0 0
          0 1 0
          1 1 1
temp
           0   0   0
           0  inf  0
          inf inf inf

```
- _2._ Traverse temp array and Calculate distance of every cell starting from 00..22 and note the min distance
```c
src[i][j]   dst[k][l]   distance = abs(k-i)+abs(l-i)
  00          11            2
  01          11            1     //We will note this
```
#### Code
```cpp
using vecVecI = vector<vector<int>>;

class Solution {
    vector<int> rowDir = {-1, 0, 1, 0};
    vector<int> colDir = {0, 1, 0, -1};
    
public:
    vecVecI updateMatrix(vecVecI& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vecVecI out(rows, vector<int>(cols, INT_MAX));
        
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j){
                
                if (!mat[i][j]) {
                    out[i][j]=0;
                } else {
                    for (int k = 0; k < rows; ++k){
                        for (int l = 0; l < cols; ++l){
                            if (k==i && l==j)
                                continue;
                                                
                            if (mat[k][l]==0) {     //if cell==0
                                int distance = abs(k-i) + abs(l-j);  //Calculate distance
                                out[i][j] = min(out[i][j], distance);
                            }
                        }
                    }
                }
            }
        }

        return out;
    }
};
```
#### Complexity
- **Time:** O(n<sup>2</sup>m<sup>2</sup>)
- **Space:** O(mn)
