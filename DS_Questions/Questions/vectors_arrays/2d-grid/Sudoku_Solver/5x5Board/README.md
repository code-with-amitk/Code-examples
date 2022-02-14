**5x5 Board**

### 5x5 Board
<img src=5x5Example1.PNG width=200></img>

#### [Logic](/DS_Questions/Questions/vectors_arrays/2d-grid/Sudoku_Solver#l)
```c
. 1 . . .
. . . 3 .
. . 4 . .
1 . . 5 .
3 . . . 4
```

**In Recursion we have something as:**
```c
  fun(row, col) {
    for (i=0 to n) {
      if (i can fit in box)
        fun (row, col+1)
    }
  }
```  

**Solving Suduko(using backtracking)**
```c
. 1 . . .
. . . 3 .
. . 4 . .
1 . . 5 .
3 . . . 4

-------------------Row=0----------------------
Postion=00. All possibilites(1?No 2?yes 3?no 4?yes 5?yes) 2,4,5. Place: 2
2 1 . . .
. . . 3 .
. . 4 . .
1 . . 5 .
3 . . . 4

Postion=02. All possibilites(1?No 2?no 3?yes 4?no 5?yes) 3,5. Place: 3
2 1 3 . .
. . . 3 .
. . 4 . .
1 . . 5 .
3 . . . 4

Postion=03. All possibilites(1?No 2?no 3?no 4?yes 5?no) Place: 4
2 1 3 4 .
. . . 3 .
. . 4 . .
1 . . 5 .
3 . . . 4

Postion=04. Place 5. Move to next row
2 1 3 4 5
. . . 3 .
. . 4 . .
1 . . 5 .
3 . . . 4

-------------------Row=1----------------------
Postion=10. All possibilites(1?No 2?no 3?no 4?yes 5?yes) 4,5 Place: 4
2 1 3 4 5
4 . . 3 .
. . 4 . .
1 . . 5 .
3 . . . 4

Position=11. All possibilites(1?No 2?y 3?n 4?n 5?y) 2,5 Place: 2
2 1 3 4 5
4 2 . 3 .
. . 4 . .
1 . . 5 .
3 . . . 4

Position=12. All possibilites(1?y 2?n 3?n 4?n 5?y) 1,5 Place: 1
2 1 3 4 5
4 5 1 3 .
. . 4 . .
1 . . 5 .
3 . . . 4

Position=14. All possibilites(1?n 2?y 3?n 4?n 5?n) Place: 2. Move to next row
2 1 3 4 5
4 5 1 3 2
. . 4 . .
1 . . 5 .
3 . . . 4

-------------------Row=2----------------------
Position=20. All possibilites(1?n 2?n 3?n 4?n 5?y) Place: 5
2 1 3 4 5
4 5 1 3 2
5 . 4 . .
1 . . 5 .
3 . . . 4

Position=21. All possibilites(1?n 2?y 3?y 4?n 5?n) 2,3 Place: 2
2 1 3 4 5
4 5 1 3 2
5 2 4 . .
1 . . 5 .
3 . . . 4

Position=23. All possibilites(1?y 2?n 3?n 4?n 5?n) Place: 1
2 1 3 4 5
4 5 1 3 2
5 2 4 1 .
1 . . 5 .
3 . . . 4

Position=24. All possibilites(1?n 2?n 3?y 4?n 5?n) Place: 3. Move to next Row
2 1 3 4 5
4 5 1 3 2
5 2 4 1 3
1 . . 5 .
3 . . . 4

-------------------Row=3----------------------
Position=31. All possibilites(1?n 2?n 3?y 4?y 5?n) 3,4. Place: 3
2 1 3 4 5
4 5 1 3 2
5 2 4 1 3
1 3 . 5 .
3 . . . 4

Position=32. All possibilites(1?n 2?y 3?n 4?n 5?n) Place 2
2 1 3 4 5
4 5 1 3 2
5 2 4 1 3
1 3 2 5 .
3 . . . 4

Position=34. All possibilites(1?n 2?n 3?n 4?n 5?n) Backtrack
Position=32. There was only solution=2 which we already used. Backtrack
Position=31. There was only solution=3 which we already used. Backtrack
2 1 3 4 5
4 5 1 3 2
5 2 4 1 3
1 . . 5 .
3 . . . 4

Position=24. There was only solution=3 which we already used. Backtrack
Position=23. There was only solution=1 which we already used. Backtrack
Position=21. There was only solution=2 which we already used. Backtrack
Position=20. There was only solution=5 which we already used. Backtrack
2 1 3 4 5
4 5 1 3 2
. . 4 . .
1 . . 5 .
3 . . . 4

Position=14. There was only solution=2 which we already used. Backtrack
Position=12. There were 2 solutions(1,5). we used 1 now we will use 5.
2 1 3 4 5
4 5 5 3 .
. . 4 . .
1 . . 5 .
3 . . . 4

Position=14. All possibilites(1?y 2?n 3?n 4?n 5?n) Place 1. Move to next row
2 1 3 4 5
4 5 5 3 1
. . 4 . .
1 . . 5 .
3 . . . 4

Position=20. All possibilites(1?y 2?n 3?n 4?n 5?y) Place 5
2 1 3 4 5
4 5 5 3 1
5 . 4 . .
1 . . 5 .
3 . . . 4

Position=21. All possibilites(1?n 2?y 3?y 4?n 5?y) 2,3 Place 2
2 1 3 4 5
4 5 5 3 1
5 2 4 . .
1 . . 5 .
3 . . . 4

Position=23. All possibilites(1?y 2?n 3?n 4?n 5?n) Place 1
2 1 3 4 5
4 5 5 3 1
5 2 4 1 .
1 . . 5 .
3 . . . 4

Position=24. All possibilites(1?n 2?n 3?y 4?n 5?n) Place 3
2 1 3 4 5
4 5 5 3 1
5 2 4 1 3
1 . . 5 .
3 . . . 4

Position=31. All possibilites(1?n 2?n 3?y 4?y 5?n) 3,4 Place 3
2 1 3 4 5
4 5 5 3 1
5 2 4 1 3
1 3 . 5 .
3 . . . 4

Position=32. All possibilites(1?n 2?y 3?n 4?n 5?n) Place 2
2 1 3 4 5
4 5 5 3 1
5 2 4 1 3
1 3 2 5 .
3 . . . 4

Position=34. All possibilites(1?n 2?y 3?n 4?n 5?n) Backtrack
2 1 3 4 5
4 5 5 3 1
5 2 4 1 3
1 3 2 5 .
3 . . . 4

```
