**Maximum Score from Performing Multiplication Operations**

### Maximum Score from Performing Multiplication Operations
- We are given 2 arrays nums(size=n), multipliers(size=m). n>=m
```c
nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
```
- We need to find maximum sum after multiplying numbers from nums, multipliers. Constriant:
  - Choose one number=x from either the start or the end of the array nums.
  - Add `multipliers[i] * x` to your score.
  - Remove x from the array nums.
```c
nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
output=102.
                          nums              multipliers                sum
             -5 x -10    [-3,-3,-2,7,1]     [-5,3,4,6]                 50
             -3 x -5     [-3,-2,7,1]        [3,4,6]                    65
Choice1      1 x 6     [-3,-2,7,1]        [3,4,6]                    65


                -5x-10  50    [-3,-3,-2,7,1]     [-5,3,4,6]
                  |
                -3x-5   65    [-3,-2,7,1]        [3,4,6]
        Greedy /     \DP               Greedy          DP
            1x6 71    -3x3 56     [-3,-2,7] [3,4]   [-2,7,1] [4,6]
             |
            7x4 99     1x4 60     [-3,-2] [3]       [-2,7] [6]
             |
           -2x3 93     7x6 102
ans=102
```
