## Dynamic Programming / Tabular Method  <== VERY EASY

- [What and How DP Works](#when)
- [Identify whether this problem is DP?](#identify)
- [Methods in DP?](#methods)

<a name="when"></a>
## When to apply
- In recursive algorithm, when subproblems is calculated again & again we cache those for future recursive calls. Eg: Fibonacci series
- You have to study recursive algorithm and cache prev results into array or hash.
- Recursion Time Complexity: Exponential, DP Time Complexity: Polynomial

<a name="identify"></a>
## Identify whether this problem is DP?
 - **1. Overlapping Subproblems**
  - When recursive algorithm for the problem solves the same subproblems over and over again, we say that the optimization problem has overlapping subproblems.
- **2. Optimal Substructure**

<a name="methods"></a>
## Methods in DP
- __1. Bottom up / Tabulation:__ Steps
  - Think how to solve the problem for a simple case(eg: list with 1 element). 
  - Think how to solve the problem for 2 elements, then for 4 elements, and so on
  - Save solutions of subproblems(in array/hash) and refer it before recalculation.
    - If solved, return the saved value, saving further computation at this level
- __2. Top Down / Memoization:__
  - Think how we can divide the problem for case N into subproblems. 
