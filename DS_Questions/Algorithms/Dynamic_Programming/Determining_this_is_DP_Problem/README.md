## How to determine this is DP problem
- 2 main properties of a problem that suggests that the given problem can be solved using DP.

### Case-1. Common Overlapping Sub-problems
- DP is not useful when there are no common overlapping subproblems. because there is no point storing the solutions if they are not needed again. Ex: recursive program for Fibonacci Numbers.
- **2 different ways to store the values:**
  - _1) Memoization (Top Down):_ program looks into a lookup table before computing solutions. 
  - _2) Tabulation (Bottom Up):_ build table from bottom up. we first calculate fib(0) then fib(1) then fib(2) then fib(3) and so on.

### Case-2: Optimal Substructure
- Shortest path of graph has this property. In given graph if we want to find shortest path from u to v.
```c
u --> a --> b --> x --> e --> f --> v
```
