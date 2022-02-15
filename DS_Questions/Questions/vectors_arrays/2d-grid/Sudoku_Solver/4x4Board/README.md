**4x4 Board**

### 4x4 Board using Backtracking
#### Example. Backtracking on same row(ie prev element)

<img src=4x4Example1.PNG width=200></img>

**In Recursion we have something as:**
```c
  fun(row, col) {
    for (i=0 to n) {
      if (i can fit in box)
        fun (row, col+1)
    }
  }
```

#### Example-1 (using backtracking)
<img src=suduko_backtrack1.png width=900></img>

#### Example-2 (using backtracking)
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
