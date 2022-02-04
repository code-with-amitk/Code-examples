**N-Queens**
- [Approach = backtracking](#ap)
- [Complexity](#co)
- [Logic](#l)
- Code
  - [CPP](#cpp)
  - [Rust](#rs)


### N-Queens
- The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
- Given an integer n, return total number of distinct solutions.
- Examples
```c
Example-1. Input: n = 4. 4x4 chess board
Output: 2
Explanation: There exist two distinct solutions to the 4-queens puzzle
For 4x4 chess board there are 2 solutions.
Solution-1              Solution-2
 . Q . .                . . Q .
 . . . Q                Q . . .
 Q . . .                . . . Q
 . . Q .                . Q . .

Example-2:
Input: n = 1
Output: 1
```

<a name=ap></a>
### Approach = Backtracking
- We can solve all backtracking questions using a [backtracking template](/DS_Questions/Algorithms/Backtracking/README.md#tem)
- This problem also uses backtracking template, see that 1st.

<a name=l></a>
### Logic
_1._ Create a empty board & Start from index=`board[0][0]`
```c
board 
   0 1 2 3
0  0 0 0 0
1  0 0 0 0
2  0 0 0 0
3  0 0 0 0
```
_2._ if current position is not under attack. (Not Under attack means there is no queen in this row,col,both diagonals)
  - Place 1 Queen(means=1) and move to next row, ie row=1
```c
board 
   0 1 2 3
0  1 0 0 0
1  0 0 0 0
2  0 0 0 0
3  0 0 0 0
```
_3._ (Row=1) Start from col=0 and check which position is not under attack, place Queen=1 there.
```c
board 
   0 1 2 3
0  1 0 0 0
1  0 0 0 0
2  0 0 0 0
3  0 0 0 0

is (board[1][0] under attack)
  yes. Move to next element in same row

is (board[1][1] under attack)
  yes. Move to next element in same row  

is (board[1][2] under attack)
  No. Place Queen=1. And move to next row
```
_4._ (Row=2). if all positions are under attack and this row is not last. BACKTRACK(since we have not found all solutions).
```
board 
   0 1 2 3
0  1 0 0 0
1  0 0 1 0
2  0 0 0 0
3  0 0 0 0

is (board[2][0] under attack)
  yes. Move to next element in same row

is (board[2][1] under attack)
  yes. Move to next element in same row  

is (board[2][2] under attack)
  yes. Move to next element in same row  

is (board[2][3] under attack) {
  yes.
  We have not reached last row, it means we have not found all solutions.
}
```
_5._ BackTrack. We come back to (Row=1). remove earlier placed queen ie do `board[1][2]=0` and try next place. Repeat step-3,4.
```c
board 
   0 1 2 3
0  1 0 0 0
1  0 0 0 1
2  0 0 0 0
3  0 0 0 0
//Try placing Queen on row=2
```

<a name=co></a>
### Complexity
#### Space
O(n<sup>2</sup>) + O(n)   //nxn board, n sized vector to store coloumns
#### Time = O(N!)
- Unlike the brute force approach, we will only place queens on squares that aren't under attack. 
- For the first queen, we have O(N) options.
- For the next queen, we won't attempt to place it in the same column as the first queen, Thus, the maximum number of squares we can consider for the second queen is N−2. 
- For the third queen, we won't attempt to place it in 2 columns already occupied by the first 2 queens, and there must be at least two squares attacked diagonally from the first 2 queens. Thus, the maximum number of squares we can consider for the third queen is N−4. This pattern continues, resulting in an approximate time complexity of N!.

### Code
<a name=cpp></a>
#### CPP
```cpp
#include<iostream>
#include<vector>
#include<set>
using namespace std;

using vecI = vector<int>;
using vecVecI = vector<vecI>;

class Solution {
    vecVecS vecs_final_board;
    int board_size;
public:
  /*  This function checks whether particular [row][col] is under attack or not
      ie only check row, col, both diagonals have any 1 entry or not
  */
    bool is_not_under_attack(int row, int col, vecVecI& board){
        for (int i=0; i < board_size; ++i){
            if (board[row][i] || board[i][col])
                return false;
        }
        
        //Checking Diagonals
        int r = row, c = col;
        while (r >0 && c < board_size-1){    //Right up
            if (board[--r][++c])
                return false;
        }
        
        r = row, c= col;
        while (r < board_size-1 && c > 0){    //Left down
            if (board[++r][--c])
                return false;
        }

        r = row, c= col;
        while (r > 0 && c > 0){    //Left up
            if (board[--r][--c])
                return false;
        }

        r = row, c= col;
        while (c < board_size-1 && r < board_size-1){    //Left up
            if (board[++r][++c])
                return false;
        }
        return true;
    }
    void backtrack(int row, vecVecI& board, vecI& vecCols){
        if (row == board_size){                           //3. Base case, We reached last row.
            vecI temp;
            string strTemp(board_size, '.'), strTest;
            strTest = strTemp;
            vecS vecTemp;
            for (auto i:vecCols){                         //Create output Solution vector for 1 board
                temp.push_back(i);
                strTest[i] = 'Q';
                vecTemp.emplace_back(strTest);
                strTest = strTemp;
            }
            vecs_final_board.emplace_back(vecS);
            return;
        }
        for (int col=0; col<board_size; col++){
            if (!is_not_under_attack(row, col, board)) {    //4. If board[row][col] is not under attack, continue
                continue;
            }else{                                          //board[row][col] is not under attack
                vecCols.emplace_back(col);                  //Note solution
                
                board[row][col] = 1;    //Place the queen   
                backtrack(row+1, board, vecCols);

                vecCols.pop_back();
                board[row][col]=0;       //Remove queen
            } 
        }
    }
    vecVecS totalNQueens(int n) {
        if (n==1)
            return {{"Q"}};

        vecVecI board(n, vecI(n,0));    //Step-1. Create a empty board
        board_size = n;                 //Store board size

/*
        Solution-1             Solution-2
        . Q . .                . . Q .
        . . . Q                Q . . .
        Q . . .                . . . Q
        . . Q .                . Q . .
vecCols 1 3 0 2                 2 0 3 1
*/
        vecI vecCols;                 //We will store Queen Coloums in vecCols.
        backtrack(0, board, vecCols);

        return vecs_final_board;
    }
};

int main() {
    int n=5;

    Solution s;
    vecVecS out = s.totalNQueens(n);
    for (int i=0;i<out.size();++i){
        for (int j=0;j<out[0].size();++j){
            cout << out[i][j] <<" ";
        }
        cout <<"\n";
    }
}
```
