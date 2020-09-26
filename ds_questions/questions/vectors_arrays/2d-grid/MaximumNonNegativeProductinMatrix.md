### [Problem](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/)
- You are given a rows x cols matrix. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.
- Find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.
- Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative return -1.
- **Examples**
```c++
Example-1:
Input: grid = [[-1,-2,-3],
               [-2,-3,-3],
               [-3,-3,-2]]
Output: -1
Explanation: It's not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.

Example-2:
Input: grid = [[1,-2,1],
               [1,-2,1],
               [3,-4,1]]
Output: 8
Explanation: Maximum non-negative product is in bold (1 * 1 * -2 * -4 * 1 = 8).
```

## [Self Video Explanation](https://www.youtube.com/watch?v=rvK21xDqFxM)

### Logic (Dynamic Programming)
- Take 2 matrices of same size as input array: Matrix-1(maxProduct), Matrix-2(minProduct)
```c++
input arr=	    
      0   1  2
  0  {1, -2, 1},
  1  {1, -2, 1},
  2  {3, -4, 1}
	
maxProduct = 
     0   1  2
  0 {1, -2, -2}
  1 {1, 4,
  2 {3,

minProduct = 
     0   1  2
  0 {1, -2, -2}
  1 {1, -2,
  2 {3,	 
```  
- For filling `maxProduct[1][1],minProduct[1][1]`. We calculate 4 elements.
```c++
a = arr[1][1]*maxProduct[0][1] = -2*-2 = 4                //present-input-arr-element * Above-Product
b = arr[1][1]*maxProduct[1][0] = -2*1 = -2                //present-input-arr-element * Back-Product
c = arr[1][1]*minProduct[0][1] = -2*-2 = 4                //present-input-arr-element * Above-Product
d = arr[1][1]*minProduct[1][0] = 1*-2 = -2
maxProduct[1][1] = 4
minProduct[1][1] = -2
```
-Finally we get:
```c++
maxProduct:     //Every element represents max product till that element traversed from 0,0
    1 -2 -2
    1  4  4
    3  8  8

minProduct:     //Every element represents min product till that element traversed from 0,0
    1  -2 -2
    1  -2 -2
    3 -16 -16
```

### Code
```c++
template<typename T1>
class Solution {
  int rows, cols;
public:
  T1 mp ( vector<vector<T1>>& g ) {
try{
    if(not g.size()){
      string a = "size is 0";
      throw a;
    }

    rows = g.size();
    cols = g[0].size();

    T1 maxProduct[rows][cols];
    T1 minProduct[rows][cols];

    maxProduct[0][0] = minProduct[0][0] = g[0][0];

    //1st row
    for( int i = 1; i < cols; ++i ) {
      maxProduct[0][i] = g[0][i] * maxProduct[0][i-1];
      minProduct[0][i] = maxProduct[0][i];
    }

    //1st col
    for( int i = 1; i < rows; ++i ) {
      maxProduct[i][0] = g[i][0] * maxProduct[i-1][0];
      minProduct[i][0] = maxProduct[i][0];
    }
    T1 a=0, b=0, c=0, d=0;
    for (int i = 1; i < rows; ++i) {
      for (int j = 1; j < cols; ++j) {
        a = g[i][j] * maxProduct[i-1][j];
        b = g[i][j] * maxProduct[i][j-1];
        c = g[i][j] * minProduct[i-1][j];
        d = g[i][j] * minProduct[i][j-1];

        maxProduct[i][j] = max (max(a, b),
                                max(c, d));
        minProduct[i][j] = min (min(a, b),
                                min(c, d));
      }
    }
    return (maxProduct[rows-1][cols-1] < 0) ? -1 : (maxProduct[rows-1][cols-1] % 1000000007);
  }catch(string e){
    cout<<"Exception!! "<<e;
  }catch(...){
    cout<<"Caught=";
  }
  }
};
int main() {
  vector<vector<int64_t>> g = {   //8
    {1,-2,1},
    {1,-2,1},
    {3,-4,1}
  };
  Solution <int64_t>s;
  cout << s.mp(g);
}
```
