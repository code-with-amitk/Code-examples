**9x9 Board**
- [Logic, understand 4x4 board](/DS_Questions/Questions/vectors_arrays/2d-grid/Sudoku_Solver/4x4Board)
- Code
  - [CPP (int board)](#cpp1)
  - [CPP (char board)](#cpp1)
  - [Rust](#rs)
- [Complexity](#co)

## [Suduko Solver](https://leetcode.com/problems/sudoku-solver/)
Write a program to solve a Sudoku puzzle by filling the empty cells. A sudoku solution must satisfy all of the following rules:
- Each of the digits 1-9 must occur exactly once in each row.
- Each of the digits 1-9 must occur exactly once in each column.
- Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
- The '.' character indicates empty cells.

<img src=https://upload.wikimedia.org/wikipedia/commons/f/ff/Sudoku-by-L2G-20050714.svg width=200></img>
<img src=https://upload.wikimedia.org/wikipedia/commons/3/31/Sudoku-by-L2G-20050714_solution.svg width=200></img>

### Code
<a name=cpp1></a>
#### CPP (int board)
We will follow [BT Template](/DS_Questions/Algorithms/Backtracking#tem)
```c
class Solution {
    int size;
    vecVecI sol;
public:
    bool is_valid_solution(vecVecI board, int n, int row, int col){
        for (int i=0; i<size; ++i){
            if (board[row][i] == n)
                return false;
            if (board[i][col] == n)
                return false;
        }
        //Box check
        int boxr = row - row%3;
        int boxc = col - col%3;
        for(int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j) {
                if (board[i+boxr][j+boxc] == n)
                    return false;
            }
        }
        return true;
    }
    void backtrack (vecVecI board, int row, int col) {

        if (row == size-1 && col == size-1) {       //Base case
            sol = board;
            return;
        }
        
        if (col == size)
            backtrack(board, row+1, 0);

        if (board[row][col] != 0){                  //Not valid candidate continue
            backtrack(board, row, col+1);
        } else {            
            for (int i=1; i<=size; ++i){    //All possible solutions
                if (is_valid_solution(board, i, row, col)){
                    board[row][col] = i;
                    backtrack(board, row, col+1);
                    board[row][col] = 0;
                }
            }
        }
    }

    void solve_suduko(vecVecI& b){
        size = b.size();
        backtrack(b, 0, 0);
        for (int i=0;i<size;++i){
            for (int j=0;j<size;++j){
                cout << sol[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    vecVecI b = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};
    Solution s;
    s.solve_suduko(b);
}
# ./a.out
5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
```

<a name=cpp2></a>
#### CPP (char board)
We will follow [BT Template](/DS_Questions/Algorithms/Backtracking#tem)
```c
using vecC = vector<char>;
using vecVecC = vector<vecC>;

class Solution {
    vecVecC sol;
    int size;
public:
    bool is_valid_solution(vecVecC& board, char val, int row, int col){
        for (int i=0; i< 9;i++){
            if (board[row][i] == val)             //Check entire row
                return false;
            if (board[i][col] == val)             //Check entire col
                return false;
        }

        //Check box
        int boxr = row - row%3;
        int boxc = col - col%3;
        for(int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j) {
                if (board[i+boxr][j+boxc] == val)
                    return false;
            }
        }
        return true;
    }

    void backtrack(vecVecC& board, int row, int col) {

        if (row == size-1 && col == size-1) {       //Base case
            sol = board;
            return;
        }
        
        if (col == size)
            backtrack(board, row+1, 0);

        if (board[row][col] != '.'){                  //Not valid candidate continue
            backtrack(board, row, col+1);
        } else {            
            for (char i='1'; i<='9'; ++i) {    //All possible solutions
                if (is_valid_solution(board, i, row, col)){
                    board[row][col] = i;
                    backtrack(board, row, col+1);
                    board[row][col] = '.';
                }
            }
        }
    }        

    void solveSudoku(vecVecC& b) {
        size = b.size();
        backtrack(b, 0, 0);

        cout << "Suduko solved";

        for (int i=0;i<9;++i){
            for (int j=0;j<9;++j){
                cout << sol[i][j] << " ";
            }
            cout <<"\n";
        }
        cout << "\n";
    }
};

int main() {
    vecVecC board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
        };
    Solution s;
    s.solveSudoku(board);
}
```

<a name=co></a>
### Complexity
#### Time complexity
- TC is constant since the board size is fixed. Number of operations needed : 9!<sup>9</sup>
- Let's consider one row having 9 cells. 
  - There are not more than 9 possibilities for the first number to put
  - not more than 9x8 for the second one
  - not more than 9x8x7 for the third one etc.
  - In total that results in not more than 9! possibilities for a just one row and not more than 9!<sup>9</sup> for total.
#### Space complexity
The board size is fixed, and the space is used to store board, rows, columns and boxes structures, each contains 81 elements.
