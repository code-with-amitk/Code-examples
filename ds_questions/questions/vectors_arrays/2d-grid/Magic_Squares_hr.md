## [Problem](https://www.hackerrank.com/challenges/magic-square-forming/problem)

### Description
- Find in how many replacements a 3x3 matrix can be converted to magic square?

### [WHAT IS MAGIC SAUARE](http://jwilson.coe.uga.edu/EMAT6680Su07/McKee/6690/magicsquares/ms1.html)
- A square grid in which distinct numbers are written into each cell of the grid in such a way that each row, each column and each diagonal add up to the same number.
#### 1x1 Magic square
- This is always a magic square
```
[1] or [2]
```

#### 2x2 Magic square
- Does not exist
- Recall that the numbers in each box of the grid must be distinct and that the sum of the columns, rows, and diagonals must all be the same.
-Either way, the numbers are not distinct, so the 2x2 grid does not exist.
```
  x1  x2
  x3  x4
```

#### 3x3 Magic square
- 3x3 magic square, the grid will have 9 boxes which are filled with the consecutive numbers 1 thru 9.
- Value of the entire square.
  - Since each number is used only once, this value is: 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45.
- Sum of 3 rows
  - R1 + R2 + R3 = 45.
  - Sum of each row is 45/3 = 15.
  - This means that the sum of the columns and the diagonals is also 15.
  - R1 = R2 = R3 = C1 = C2 = C3 = D1= D2 = 15
- Finding value of middle element. Let x.
  - x is included in R2, C2, and both diagonals(D1, D2).
  - R2 + C2 + D1 + D2 = 15 + 15 + 15 + 15 = 60
  - Recall sum of all numbers=45. Since the x-value has been used 4 times in the sum, it has been added 3 extra times.
  - 45 + 3x = 60. x = 5.  Middle element=5
- Finding other values.
  - Simply ensure that all rows, columns and diagonals sum to 15. and all elements are unique.
  
  ![ImgURL](https://i.ibb.co/pn8HBHY/magic-square.png)
  
- **Note** Variations on the 3x3 magic square can be found by rotating the entries around the center number 5.
  
 
