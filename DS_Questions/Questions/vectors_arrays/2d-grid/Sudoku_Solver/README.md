**Suduko Solver**
- [Logic = Backtracking](#l)
  - Example 4x4 board

## [Suduko Solver](https://leetcode.com/problems/sudoku-solver/)
Write a program to solve a Sudoku puzzle by filling the empty cells. A sudoku solution must satisfy all of the following rules:
- Each of the digits 1-9 must occur exactly once in each row.
- Each of the digits 1-9 must occur exactly once in each column.
- Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
- The '.' character indicates empty cells.

<img src=https://upload.wikimedia.org/wikipedia/commons/f/ff/Sudoku-by-L2G-20050714.svg width=200></img>
<img src=https://upload.wikimedia.org/wikipedia/commons/3/31/Sudoku-by-L2G-20050714_solution.svg width=200></img>

<a name=l></a>
### READ Logic 1st = [Backtracking](/DS_Questions/Algorithms/Backtracking)
- Place digit "1" in the first cell and checking if it is allowed to be there. If there are no violations (checking row, column, and box constraints) then the algorithm advances to the next cell and places a "2" in that cell.
- When checking for violations, if it is discovered that the "2" is not allowed, the value is advanced to "3".
- If a cell is discovered where none of the 9 digits is allowed, then the algorithm leaves that cell blank and moves back to the previous cell. The value in that cell is then incremented by one. This is repeated until the allowed value in the last box is discovered.

#### [Example-1: 4x4 Board](4x4Board.md)
