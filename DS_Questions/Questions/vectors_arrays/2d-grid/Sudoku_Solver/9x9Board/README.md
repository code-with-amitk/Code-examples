**9x9 Board**
- [Logic, understand 4x4 board](/DS_Questions/Questions/vectors_arrays/2d-grid/Sudoku_Solver/4x4Board)
- Code
  - With int board
    - [CPP](#cpp)
    - [Rust](#rs)
  - With char board
- [Complexity](#co)

### Code
#### With int board
<a name=cpp></a>
##### CPP
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
