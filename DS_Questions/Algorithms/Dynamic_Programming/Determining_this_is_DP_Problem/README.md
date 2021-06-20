## How to determine this is DP problem
- 2 main properties of a problem that suggests that the given problem can be solved using DP.

### Case-1. Overlapping Subproblems
- When recursive algorithm for the problem solves the same subproblems over and over again, we say that the optimization problem has overlapping subproblems.

### Case-2: Optimal Substructure
- Shortest path of graph has this property. In given graph if we want to find shortest path from u to v.
```c

u --> a --> b --> x --> e --> f --> v
  \        /             \        /
    c -- d                   g
If a node x lies in the shortest path from a source node u to destination node v then the shortest path from 
u to v is combination of shortest path from u to x and shortest path from x to v.    
```
