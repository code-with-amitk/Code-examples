**Maximum Score from Performing Multiplication Operations**
- [Approach-1 DP](#a)
  - [Identifying is this DP Problem?](#i)
  - [Logic](#l)

### Maximum Score from Performing Multiplication Operations
- We are given 2 arrays nums(size=n), multipliers(size=m). n>=m
```c
nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
- nums: Number can be choosen from left or right
- multiplier: Number is always choosen from left.
```
- We need to find maximum sum after multiplying numbers from nums, multipliers. **Constriant**:
  - **`nums[i]:`** Choose one number=x from either the start or the end of the array nums.
  - **`multipliers[i]`:** Always choose next number from left in this array.
  - Add `multipliers[i] * x` to your score.
  - Remove x from the array nums.
```c
nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
output=102
                -5x-10  50       [-3,-3,-2,7,1]     [-5,3,4,6]
                  |
                -3x-5   50+15=65    [-3,-2,7,1]        [3,4,6]
                  |
                -3x3    65-9=56        [-2,7,1]        [4,6]
                /   \
             DP/     \Greedy
        1x4=4+56=60   1x6=6+56=62
        [-2,7] [6]   [-2,7] [4]
            |          |
      7x6=42+60=102  7x4=28+62=90
ans=102
```

<a name=a></a>
## Approach-1, DP
<a name=i></a>
### [Identifying is this DP Problem?](/DS_Questions/Algorithms/Dynamic_Programming#i)
- _1. Problem statement: min/max/longest/largest/Nth Number?_ Yes
- _2. Greedy solution does not fit in?_ Yes
- _3. 2. Optimal Substructure Property:_ if optimal(feasible) solution can be constructed from optimal solutions of its subproblems. Yes

<a name=l></a>
### [Logic = DP Template](/DS_Questions/Algorithms/Dynamic_Programming#tem)
- _1. Define State:_ Maximum product at index=i after selecting (left or right) from `nums[i]` and left most from `multiplier[i]`.
- _2. Function to return State:_ Function to calculate max product at every index.
int dp(i, left) {
  return (max product at step i);
}
3. _Recurrence relation to transition between states:_
```c
  max_product_at_index_i = max(left_of_nums*left_most_of_multiplier,  //next operation nums=i+1, multiplier=left+1
                              right_of_nums*left_most_of_multiplier)  //next operation i=
  dp(i) = max (nums[i]*multiplier[i],
               nums[size-1]*multiplier[i]);
               
               max(mult*nums[left] + dp(i + 1, left + 1), 
                   mult*nums[right]+ dp(i + 1, left))
```
4. Base case: Try finding base case from problem itself and logical thinking.
Ask yourself, Number of ways to reach 1st step=1, No of ways to reach 2nd step = 2.
start ___  ___
      1st  2nd
5. Cache/Memoize: Memorize the repeatative steps that are calculated and return result from cache.
