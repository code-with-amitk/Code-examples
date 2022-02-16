- [Backtracking](#bt)
- **Examples**
  - [Ex-1, 2](#ex1)
  - [N-Queen-Problem](/DS_Questions/Questions/vectors_arrays/2d-grid/N-Queens)
- [BT Template](#tem)

<a name=bt></a>
## [Backtracking](https://leetcode.com/explore/learn/card/recursion-ii/472/backtracking/2654/)
- Backtracking uses Recursion & it is an algorithmic paradigm aimed to improve the time complexity of the [Naive/Brute Force](..) **if possible**.
- Backtracking **can be imagined** same as tree traversal where we start from root node to search for solutions that are located at the leaf nodes.
- Each node represents a partial candidate to final solution, At each node. Once we can determine if a certain node cannot possibly lead to a final solution, we abandon the current node and backtrack to its parent node to explore other possibilities.
- **How?** Backtracking does not generate all possible solutions, it checks if condition fails, the solution is rejected and the next solution is tried.

### Examples
<a name=ex1></a>
#### Example-1
We are given a set of words represented in the form of a tree. Find word `AIM`.

- **Brute Force Approach**

<img src=backtracking.jpeg width=500></img>

**BackTracking Approach**

<img src=backtracking1.jpeg width=500></img>

#### Example-2: Finding path in a maze from start point to destination.
Select one way and try to move forward towards the destination. if we reach a point where we can’t move towards the destination?
  - Backtrack on path and try to explore other paths.

<a name=tem></a>
### Backtracking Template
There is a pattern about the backtracking algorithm, with which most of BT problems can be solved. Check [N-Queen problem uses this](/DS_Questions/Questions/vectors_arrays/2d-grid/N-Queens).
```c
    board sol;
    void recursive_backtrack(int row, int col, &board){
      if (row == size && col == size){                  //Base case. We reached last cell
        sol = board;
        return;
      }
      
      for (candidate in candidate list) {
      
        if (candidate not valid) {
          continue;
        } 
        else                                            //if Candidate is VALID
        {
          place_candidate (candidate);                  //Place this candidate on partial solution
          
          recursive_backtrack (candidate+1, &board);    //Try next candidate
          
          remove (candidate);                           //Remove this candidate
        }
      }
    }
    
    return-type solve (int n) {
        board = create-broad (0);
        recursive_backtrack (0, 0, board);               //Start from row=0,col=0
        return vecs_final_board;
    }
    
    main () {
      solve(n);
    }
```
