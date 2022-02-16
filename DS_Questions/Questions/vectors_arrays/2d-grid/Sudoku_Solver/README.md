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
### Logic
[How to solve Suduko. PepCode](https://www.youtube.com/watch?v=uyetDh-DyDg)
- _1._ Find all possible numbers/solutions which can be placed on cell.
  - Place 1st number/solution from all possible numbers.
- _2._ if on particular cell no number can be placed, Backtrack to previous cell.
  - Place next number/solution from possible solutions which were found in step-1.

#### [Example-1: 4x4 Board](4x4Board)
