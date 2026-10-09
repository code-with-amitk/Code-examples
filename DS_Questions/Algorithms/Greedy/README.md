## Greedy Approach
- This is not algorithm, rather is a problem solving approach.
- A greedy algorithm makes the locally optimal choice at every step, hoping that these local choices lead to a globally optimal solution.
- Instead of looking ahead at future consequences or exploring multiple paths, a greedy algorithm takes the best immediate action available right now and never reverses its decision (no [backtracking](/DS_Questions/Algorithms/Backtracking)).
- Examples
  - Suppose we want to reach from A to D, greedy will choose AB(least cost/local optimal) to achieve global optimal.
```c
     B --------
   1/           |
  A -3--------- D
   2\           |
     C----------
```
- **Applications:** Kruskal’s MST, Prim’s MST, Dijkastra’s Shortest Path Algorithm, Knapsack Problem, Hufman coding, job sequencing etc
