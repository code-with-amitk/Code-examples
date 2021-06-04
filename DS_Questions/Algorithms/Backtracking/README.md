## Backtracking
- Backtracking is an algorithmic paradigm aimed to improve the time complexity of the [Naive/Brute Force](..) **if possible**.
- Backtracking does not generate all possible solutions, it checks if condition fails, the solution is rejected and the next solution is tried.
- **One of most Common Example:** Find the correct path in a maze from start point to destination.
  - Select one way and try to move forward towards the destination.
  - if we reach a point where we can’t move towards the destination?
    - Backtrack on path and try to explore other paths.
