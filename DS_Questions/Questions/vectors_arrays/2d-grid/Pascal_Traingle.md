**Pascal Traingle = Combination Tree**
- [

### [Pascal Traingle](https://leetcode.com/problems/pascals-triangle/)
- Given an integer numRows, return the first numRows of Pascal's triangle.
- In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

<img src=https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif width=200/>

<img src=https://www.mathsisfun.com/numbers/images/pascals-triangle-add.svg width=200/>
- Examples:
```c
Input: numRows = 1
Output: [[1]]

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
          
0       1     //row=0, element=1
1      1 1    //row=1, element=2
2     1 2 1   //    2          3
3    1 3 3 1  //    3          4
4   1 4 6 4 1 //    4          5
```

### Pascal Triangle represents combination tree
```c
    0 1 2 3 4
0   1
1   1 1    
2   1 2 1  
3   1 3 3 1
4   1 4 6 4 1

4
 C   = table[4][3] = 6
  3
```

<a name=a1></a>
## Approach-1  //Dynamic Programming. Time:O(n<sup>2</sup>)
#### Logic
- Understand how each row are created from prev row.
  - 1st and last elements of any row are always 1.  `v[row][0]=1; v[row][size]=1` Other elements = `v[row][col] = v[row-1][col-1] + v[row-1][col]`
  - row: 0. `v[0][0]=1`
  - row: 1. `v[1][0]=1, v[1][1]=1`
  - row: 2. `v[2][0]=1, v[2][2]=1, v[2][1] = v[1][0]+v[1][1] = 2`
  - row: 3. `v[3][0]=1, v[3][3]=1, v[3][1] = v[2][0]+v[2][1] = 3, v[3][2] = v[2][2]+v[2][3] = 3`  
```c
    0  1  2  3  4
0   1
1   1  1
2   1  2  1
3   1  3  3  1
4   1  4  6  4  1
```
#### Complexity
  - **Time:** O(n<sup>2</sup>)    //n=number of rows
```c
  row
  1     1x1
  2     2x2
  3     3x3
        nxn
```
  - **Space:** O(n<sup>2</sup>). Taking vector to store nxn elements.
#### Code
```c++
class Solution {
  using VecVec = vector<vector<int>>;
public:
  vector<vector<int>> generate(int n) {
    VecVec v;
    int size = 1;

    for (int i=0; i<n; ++i){
      vector<int> temp(size);
      temp[0] = 1;

      for (int j=1; j < i; ++j)
        temp[j] = v[i-1][j-1] +v[i-1][j];

      temp[size-1] = 1;

      v.push_back(temp);
      temp.clear();
      size++;
    }
    return v;        
        
  }
};
int main(){
  Solution s;
  int n=5;
  VecVec v = s.generate(n);
  for (int i=0;i<n;++i){
    for (int j=0;j<n;++j){
      cout << v[i][j] << " ";
    }
    cout << "\n";
  }
}
```
