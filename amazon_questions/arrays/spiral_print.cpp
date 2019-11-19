/* Spiral Print of Array
        1   2   3   4
        5   6   7   8
        9  10  11  12
       13  14  15  16   

O/P->   1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

Logic:
   - (1st fun() call)Print top row, last col, last row(rev), 1st col(rev)
        Again call fun()
   - (2nd fun call) Print 2nd row, 2nd last col, 2nd last row(rev), 2nd 1st col(rev)
*/

#include<iostream>
#define row 4
#define col 4 
void print(int arr[row][col], int tmp1, int tmp2, int m, int n){
        int i;
        if (tmp1 >= m or tmp2 >= n)
                return;

        //Print top row.
        for (i=tmp1; i<n-2; i++)
                std::cout<<arr[tmp1][i]<<" ";

        //Prints last Coloum from Top to Bottom
        for (i = tmp1; i < m; i++)
                std::cout << arr[i][n - 1] << " ";

        //Print last row in reverse order from right to left
        if ((m - 1) != tmp1)
                for (i = n - 2; i >= tmp2; i--)
                        std::cout << arr[m - 1][i] << " ";

        //Print 1st Col in reverse order bottom to up
        if ((n - 1) != tmp2)
                for (i = m - 2; i > tmp1; i--)
                        std::cout << arr[i][tmp2] << " ";

        print(arr, tmp1 + 1, tmp2 + 1, m - 1, n - 1);
}

int main()
{
        int a[row][col] = { { 1, 2, 3, 4 },
                           { 5, 6, 7, 8 },
                           { 9, 10, 11, 12 },
                           { 13, 14, 15, 16 } };

        print(a, 0, 0, row, col);
        return 0;
}
