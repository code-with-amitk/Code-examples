**Backtracking**
- **[Examples](#ex)**
- [BT Template](#tem) Problems solved using BT Template:
  - [Generate All Combinations](/DS_Questions/Questions/Permutation_Combination/Combinations)
  - [Generate All Parantheses](/DS_Questions/Questions/Strings/parantheses/Generate_All_Parantheses.md)
  - [N-Queen-Problem](/DS_Questions/Questions/vectors_arrays/2d-grid/N-Queens)
  - [Robot Room Cleaner](/DS_Questions/Questions/vectors_arrays/2d-grid/Robot_Room_Cleaner/)
  - [Sudoku Solver](/DS_Questions/Questions/vectors_arrays/2d-grid/Sudoku_Solver)
  - [Word Search in 2D grid](/DS_Questions/Questions/vectors_arrays/2d-grid/Word_Search_in_2D_Matrix/Word_Search_in_2D_Matrix.md)
  - Graph
    - [Detect cycle in Directed Graph](/DS_Questions/Questions/Graphs/Find/Directed_Graph/detect_cycle_in_directed_graph.md)  
- [Time Complexity](#t)

## [Backtracking LC Explore Cards](https://leetcode.com/explore/learn/card/recursion-ii/472/backtracking/2654/)
- Backtracking uses Recursion & it is an algorithmic paradigm aimed to improve the time complexity of the [Naive/Brute Force](..) **if possible**.
- Backtracking **can be imagined** same as tree traversal where we start from root node to search for solutions that are located at the leaf nodes.
- Each node represents a partial candidate to final solution, At each node. Once we can determine if a certain node cannot possibly lead to a final solution, we abandon the current node and backtrack to its parent node to explore other possibilities.
- **How?** Backtracking does not generate all possible solutions, it checks if condition fails, the solution is rejected and the next solution is tried.

<a name=ex></a>
### Examples
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
Most of BT problems can be solved using below pattern.
```c
    vec<> solution;
    void recursive_backtrack(int row, int col, &candidate){
      if (row == size && col == size){                  //Base case. We reached last cell
        solution = candidate;
        return;
      }
      
      for (candidate in candidate list) {
      
        if (candidate not valid) {
          continue;
        } 
        else                                                  //if Candidate is VALID
        {
          place_candidate (candidate);                         //Place this candidate on partial solution
          
          recursive_backtrack (next_candidate=candidate+1);    //Try next candidate
          
          remove (candidate);                                  //Mark this as unvisited, Unflag this node.
        }
      }
    }
    
    return-type solve (int n) {
      /*
        candidate:
          n-queen problem:         empty board
          Generate combinations:   empty string ""
          Suduko solver:           empty board
      */
        canditate = create-1st-candidate;
        recursive_backtrack (0, 0, candidate);             //Start from row=0,col=0
        return vecs_final_board;
    }
    
    main () {
      solve(n);
    }
```

<a name=t></a>
### Time Complexity
