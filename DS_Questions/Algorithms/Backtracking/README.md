## Backtracking
- Backtracking uses Recursion & it is an algorithmic paradigm aimed to improve the time complexity of the [Naive/Brute Force](..) **if possible**.
- Backtracking **can be imagined** same as tree traversal where we start from root node to search for solutions that are located at the leaf nodes.
- Each node represents a partial candidate to final solution, At each node. Once we can determine if a certain node cannot possibly lead to a final solution, we abandon the current node and backtrack to its parent node to explore other possibilities.
- **How?** Backtracking does not generate all possible solutions, it checks if condition fails, the solution is rejected and the next solution is tried.

### Examples
#### Example-1
- We are given a set of words represented in the form of a tree. Find specific word.

**Brute Force Approach**

<img src=backtracking.jpeg width=500></img>

**BackTracking Approach**

<img src=backtracking1.jpeg width=500></img>

- **Example:** Finding path in a maze from start point to destination.
  - Select one way and try to move forward towards the destination.
  - if we reach a point where we can’t move towards the destination?
    - Backtrack on path and try to explore other paths.
