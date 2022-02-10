**4x4 Board**

### 4x4 Board using Backtracking
#### Example. Backtracking on same row(ie prev element)

<img src=4x4Example1.PNG width=200></img>

```c
2 1 . .
. 3 2 .
. . . 4
1 . . .

start by placing number=1 on 1st empty cell.

-------------------Row=0----------------------
Postion=02
1? No
2? No
3? yes
2 1 3 .
. 3 2 .
. . . 4
1 . . .

Position=03. number=4
4? No... Backtrack
2 1 3 .
. 3 2 .
. . . 4
1 . . .

Backtrack.
	- Remove last placed element ie 3
2 1 . .
. 3 2 .
. . . 4
1 . . .
	- Place last placed element+1.
	- 4? Yes
2 1 4 .
. 3 2 .
. . . 4
1 . . .

Position=03. number=1
1? No
2? No
3? Yes. We are at last col. Move to next row
2 1 4 3
. 3 2 .
. . . 4
1 . . .

---------------------Row-1---------------------
Position=10
1? No
2? No
3? No
4? Yes
2 1 4 3
4 3 2 .
. . . 4
1 . . .

2 1 4 3
4 3 2 1
. . . 4
1 . . .

---------------------Row-2---------------------
Position=20. number=1
1? No
2? no
3? yes
2 1 4 3
4 3 2 1
3 . . 4
1 . . .

Postion=21. number=4
4? No
1? no
2? yes
2 1 4 3
4 3 2 1
3 2 . 4
1 . . .

Postion=22. number=3
3? no
4? no
1? yes
2 1 4 3
4 3 2 1
3 2 1 4
1 . . .

---------------------Row-3---------------------
Position=31. number=1
1? no
2? no
3?no
4?yes
2 1 4 3
4 3 2 1
3 2 1 4
1 4 . .

2 1 4 3
4 3 2 1
3 2 1 4
1 4 3 2
```
