## [Problem](https://www.hackerrank.com/challenges/magic-square-forming/problem)

### 1. Description
- Find in how many replacements a 3x3 matrix can be converted to magic square?
```
5 3 4
1 5 8
6 4 2
```
- We can convert it to the following magic square:
```
8 3 4
1 5 9
6 7 2
```
- This took three replacements at a cost of |5-8|+|8-9|+|4-7| = 7

### 2. [WHAT IS MAGIC SAUARE](http://jwilson.coe.uga.edu/EMAT6680Su07/McKee/6690/magicsquares/ms1.html)
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
- There can be 8 Magic Squares for 3x3 matrix.  
  
  ![ImgURL](https://i.ibb.co/pn8HBHY/magic-square.png)
  
- **Note** Variations on the 3x3 magic square can be found by rotating the entries around the center number 5.
  
 ## 3. Logic
 - Since input is all times 3x3 matrix. 
 - Create a 2-D vector that contains all possible 8 magic square generated from 3x3 matrix.
 - Take input from keyboard
 - Sum the difference of each position on on array and magic squares
 - Whichever magic sauare gives least difference, that means this is the answer requiring least replacements wrt others.
 
 ## 4. Code
 ```c++
 int main() {
    vector<vector<int>> valid_squares = {             //All valid magic squares
      {8,1,6,3,5,7,4,9,2},
      {4,3,8,9,5,1,2,7,6},
      {2,9,4,7,5,3,6,1,8},
      {6,7,2,1,5,9,8,3,4},
      {6,1,8,7,5,3,2,9,4},
      {8,3,4,1,5,9,6,7,2},                <<<<<<<<<<Nearest magic square to input array
      {4,9,2,3,5,7,8,1,6},
      {2,7,6,9,5,1,4,3,8}
    };

    int a[9],j;
    for(int i=0;i<9;i++) cin>>a[i];                 //Take input array
    
    int best = 1000000;
    for(int i=0;i<8;i++){
        int diff = 0;
        for(j=0;j<9;j++)
          diff += abs(a[j]-valid_squares[i][j]);          //Difference of magic square vs input matrix

          cout<<"j="<<j<<",diff="<<diff<<endl;

        if (diff<best)
          best = diff;
    }
    cout<<best<<endl;
    return 0;
}
# ./a.out
5 3 4
1 5 8
6 4 2
i=0,diff=17
i=1,diff=31
i=2,diff=29
i=3,diff=13
i=4,diff=29
i=5,diff=7            <<<<This is answer. Because it has least differences means its nearest magic square to input.
i=6,diff=21
i=7,diff=33
7
 ```
 
 ## 6. Complexity
 - Considering n=9 elements in 3x3 matrix.
   - Space O(n<sup>2</sup>)
   - Time O(n<sup>2</sup>)
