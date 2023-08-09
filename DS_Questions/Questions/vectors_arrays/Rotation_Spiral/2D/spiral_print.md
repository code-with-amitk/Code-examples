
```cpp
#include<vector>
#include<iostream>
using vecI = std::vector<int>;
using vecVecI = std::vector<vecI>;

class Solution {
public:
    void spiral(vecVecI& v, int tmp1, int tmp2, int m, int n){
        int i;
        if (tmp1 >= m || tmp2 >= n)
            return;

        //Print top row.
        for (int i=tmp1; i<n; i++)
            std::cout << v[tmp1][i] << " ";

        //Print last Coloum from Top to Bottom
        for (int i = tmp1+1; i < m; i++)
            std::cout << v[i][n-1] << " ";

        //Print last row in reverse order from right to left
        if ((m - 1) != tmp1)
                for (int i = n - 2; i >= tmp2; i--)
                    std::cout << v[m-1][i] << " ";

        //Print 1st Col in reverse order bottom to up
        if ((n - 1) != tmp2)
                for (i = m - 2; i > tmp1; i--)
                    std::cout << v[i][tmp2] << " ";

        spiral(v, tmp1 + 1, tmp2 + 1, m - 1, n - 1);
    }
public:
    void spiralPrint(vecVecI& v) {
        int row = v.size();
        int col = v[0].size();
        spiral(v,0,0,row,col);
    }
};
int main(){
    vecVecI v = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    Solution s;
    s.spiralPrint(v);
}
/*
$ ./a.out 
1 2 3 4 8 12 11 10 9 5 6 7
*/
```
