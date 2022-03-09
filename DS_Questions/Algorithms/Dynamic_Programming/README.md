**Dynamic Programming / Caching**
- [Identifying DP Problem / DP Problem Characteristics](#i)
- [Types of Caching/DP](#t)
  - [1. Top Down](#td)
  - [2. Bottom Up](#bu)
- [DP Template](#tem)
- Examples
  - [House Robber](/DS_Questions/Questions/vectors_arrays/Find_Search_Count/Find/Unsorted/Maximum/Max_Money_House_Robber.md)
  - [Climbing Stairs](/DS_Questions/Questions/Permutation_Combination/No_of_Ways_to_Climb_ith_Stairs_1or2Steps.md)
  - [Fibonacci Series](/DS_Questions/Questions/Number/Fibonacci_Number.md)
  - [Minimum Cost Climbing Stairs](/DS_Questions/Questions/Number/Minimum_Cost_Climbing_Stairs.md)
  - [Delete and Earn](/DS_Questions/Questions/Number/Delete_and_Earn_or_Max_Gains.md)


## [Dynamic Programming / Tabular Method / Caching LC Explore Cards](https://leetcode.com/explore/featured/card/dynamic-programming/630/an-introduction-to-dynamic-programming/4034/)
<a name=i></a>
### Identifying DP Problem / DP Characteristics / DP Properties
- _1. Overlapping subproblems:_ Does this problem involves solving a subproblem again and again. Is solution equals cumulation of smaller subproblems?
```c
                fib(5)
              /        \ 
             fib(4)      fib(3)
            /   \          /   \   
         fib(3) fib(2)     fib(2)  fib(1)
        /   \     /  \
   fib(2) fib(1) fib(1) fib(0) 

fib(2): function need to be executed 3 times
fib(2): function need to be executed 2 times
..
```
- _2. Optimal Substructure Property:_ if optimal(feasible) solution can be constructed from optimal solutions of its subproblems. ie smaller solution cumulate to give bigger solution.
- _3. Problem statement:_ **min/max/longest/largest/Nth Number**
  - Minimum cost, Maximum profit, No of ways, longest, Is it possible to reach a certain point etc
- _4. Greedy solution should not fit in:_ Test greedy, we should not reach solution using greedy.

<a name=t></a>
### Methods in DP

||Top Down / Memoization|Bottom Up / Tabulation|
|---|---|---|
|Uses| Recursion | Iteration |
|Faster| less | more than top down |
|Easier| more easier than BU||
|Implemented using|Recursive Function + HashMap|nested for loop + Array|

<a name=td></a>
#### 1. Top Down / Memoization 
Remembering/caching the results instead of calculating them again. 
```c
///// Pseudocode example Fibnacci series//////
memo = hashmap
Function F(integer i):
    if i is 0 or 1: 
        return i
    if i doesn't exist in memo:
        memo[i] = F(i - 1) + F(i - 2)
    return memo[i]
```
<a name=bu></a>
#### 2. Bottom up / Tabulation
Solution is built from base case and upward (uses Recursion).
```c
Example: Fibonacci sequence.
1. Start with base case, F(0) = 0, F(1) = 1
2. Calculate f(2) using f(0),f(1). Calculate f(3) using f(2),f(1) and so on

F = array of length (n + 1)
F[0] = 0
F[1] = 1
for i from 2 to n:
    F[i] = F[i - 1] + F[i - 2]
```

<a name=tem></a>
### DP Template
> Eg: [Climbing Stairs](/DS_Questions/Questions/Permutation_Combination/Climb_Stairs_1or2_steps.md)
- _1. Define State:_ state means reaching nth stair or nth number etc. Eg: state=number of ways to jump to nth stair
- _2. Function to return State:_ Write a function or data structure that will compute answer to the problem for every given state
```c
int dp(i) {     //For climbing stairs
  //returns number of ways to climb to ith step
}
```
- _3. Recurrence relation to transition between states:_
  - Number of ways to reach 30th stair = No of ways to reach 28th stair + No of ways to reach 29th stair
```c
  dp(i) = dp(i-1) + dp(i-2);
```
- _4. Base case:_ Try finding base case from problem itself and logical thinking.
  - Ask yourself, Number of ways to reach 1st step=1, No of ways to reach 2nd step = 2.
```c
start ___  ___
      1st  2nd
```
- _5. Cache/Memoize:_ Memorize the repeatative steps that are calculated and return result from cache.
