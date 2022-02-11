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

Start by placing 1 in 1st empty cell

-------------------Row=0----------------------
Postion=00
1? No
2? yes
2 1 . . .
. . . 3 .
. . 4 . .
1 . . 5 .
3 . . . 4

Postion=02, number=3
3? yes
2 1 3 . .
. . . 3 .
. . 4 . .
1 . . 5 .
3 . . . 4

Postion=03, number=4
4? yes
2 1 3 4 .
. . . 3 .
. . 4 . .
1 . . 5 .
3 . . . 4

Postion=04, number=5
5? yes
2 1 3 4 5
. . . 3 .
. . 4 . .
1 . . 5 .
3 . . . 4

-------------------Row=1----------------------
Postion=10. New row start with 1
1? no
2? no
3? no
4? yes
2 1 3 4 5
4 . . 3 .
. . 4 . .
1 . . 5 .
3 . . . 4

Position=11
5? yes
2 1 3 4 5
4 5 . 3 .
. . 4 . .
1 . . 5 .
3 . . . 4

Position=12
1? yes
2 1 3 4 5
4 5 1 3 .
. . 4 . .
1 . . 5 .
3 . . . 4

Position=14
2? yes
2 1 3 4 5
4 5 1 3 2
. . 4 . .
1 . . 5 .
3 . . . 4

-------------------Row=2----------------------
Position=20. New row start from 1
1? no
2? no
3? no
4? no
5? yes
2 1 3 4 5
4 5 1 3 2
5 . 4 . .
1 . . 5 .
3 . . . 4

Position=21.
1? no
2? yes
2 1 3 4 5
4 5 1 3 2
5 2 4 . .
1 . . 5 .
3 . . . 4

Position=23
3? no
4? no
5? no     <<<<<<<<<<<<< Backtrack.
2 1 3 4 5
4 5 1 3 2
5 2 4 . .
1 . . 5 .
3 . . . 4

Position=21. Earlier 21 was 2. Start with 3
3? yes
2 1 3 4 5
4 5 1 3 2
5 3 4 . .
1 . . 5 .
3 . . . 4

Position=23
1? no
2? yes
2 1 3 4 5
4 5 1 3 2
5 3 4 2 .
1 . . 5 .
3 . . . 4

Position=24
3? no
4? no
5? no
1? yes
2 1 3 4 5
4 5 1 3 2
5 3 4 2 1
1 . . 5 .
3 . . . 4

-------------------Row=3----------------------
Position=31
1? no
2? yes
2 1 3 4 5
4 5 1 3 2
5 3 4 2 1
1 2 . 5 .
3 . . . 4

Position=32
3? no
4? no
5? no <<<<<<< Backtrack
2 1 3 4 5
4 5 1 3 2
5 3 4 2 1
1 2 . 5 .
3 . . . 4

Position=31. Earlier was 2. start with 3 till 2
3? no
4? yes
2 1 3 4 5
4 5 1 3 2
5 3 4 2 1
1 4 . 5 .
3 . . . 4

Position=32. start from 5 till 4 (ie 5,1,2,3)
5? no
1? no
2? yes
2 1 3 4 5
4 5 1 3 2
5 3 4 2 1
1 4 2 5 .
3 . . . 4

Position=34. start from 3
3? yes
2 1 3 4 5
4 5 1 3 2
5 3 4 2 1
1 4 2 5 3
3 . . . 4

----------------------Row=4---------------------
Position=41. start from 1
1? no
2? yes
2 1 3 4 5
4 5 1 3 2
5 3 4 2 1
1 4 2 5 3
3 2 . . 4

Position=42. we filled 2 earlier, check from 3.
3? no
4? no
5? yes
2 1 3 4 5
4 5 1 3 2
5 3 4 2 1
1 4 2 5 3
3 2 5 . 4

Position=43. Filled 5 earlier. start from 1
1?yes
2 1 3 4 5
4 5 1 3 2
5 3 4 2 1
1 4 2 5 3
3 2 5 1 4
```
