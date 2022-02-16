**4x4 Board using Backtracking**
- [Example-1](#ex1)
- [Example-2](#ex2)
- **Code**
  - [CPP](#c1)
  - [Rust](#c2)
- [Complexity](#co)

### 4x4 Board using Backtracking
**In Recursion we have something as:**
```c
  fun(row, col) {
    for (i=0 to n) {
      if (i can fit in box)
        fun (row, col+1)
    }
  }
```

<a name-ex1></a>
#### Example-1 (using backtracking)
[READ LOGIC](/DS_Questions/Questions/vectors_arrays/2d-grid/Sudoku_Solver/README.md#l)

<img src=suduko_backtrack.png width=900></img>

<a name-ex2></a>
#### Example-2 (using backtracking)
[READ LOGIC](/DS_Questions/Questions/vectors_arrays/2d-grid/Sudoku_Solver/README.md#l)

<img src=4x4Example1.PNG width=200></img>

```c
2 1 . .
. 3 2 .
. . . 4
1 . . .

-------------------Row=0----------------------
Postion=02. All possibilites(1?No, 2?No, 3?yes 4?yes) 3,4. Place: 3
2 1 3 .
. 3 2 .
. . . 4
1 . . .

Position=03. All possibilites(1?No, 2?No, 3?no 4?no) Backtrack
2 1 3 .
. 3 2 .
. . . 4
1 . . .

Postion=02. We have already placed 3 earlier. Place: 4
2 1 4 .
. 3 2 .
. . . 4
1 . . .

Position=03. All possibilites(1?No, 2?No, 3?yes 4?no) Place 3. Move to next row
2 1 4 3
. 3 2 .
. . . 4
1 . . .

---------------------Row-1---------------------
Position=10. All possibilites(1?No, 2?No, 3?no 4?yes) Place 4
2 1 4 3
4 3 2 .
. . . 4
1 . . .

2 1 4 3
4 3 2 1
. . . 4
1 . . .

---------------------Row-2---------------------
Position=20. All possibilites(1?No, 2?No, 3?yes 4?no) Place 3
2 1 4 3
4 3 2 1
3 . . 4
1 . . .

Postion=21. All possibilites(1?No, 2?yes, 3?no 4?no) Place 2
2 1 4 3
4 3 2 1
3 2 . 4
1 . . .

Postion=22. All possibilites(1?yes, 2?no, 3?no 4?no) Place 1. Move to next row
2 1 4 3
4 3 2 1
3 2 1 4
1 . . .

---------------------Row-3---------------------
Position=31. All possibilites(1?No, 2?no 3?no 4?yes) Place 4
2 1 4 3
4 3 2 1
3 2 1 4
1 4 . .

Position=32. All possibilites(1?No, 2?no 3?yes 4?no) Place 3
2 1 4 3
4 3 2 1
3 2 1 4
1 4 3 .
```

### Code
<a name=c1></a>
#### CPP
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
    vecVecI b = {{0,0,1,0},{3,0,0,0},{0,3,0,0},{0,0,0,2}};
    Solution s;
    s.solve_suduko(b);
}
```
#### Rust
```rs
```
<a name=co></a>
### Complexity
