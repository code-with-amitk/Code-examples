**Backtracking**
- [Template](#t)
- [Problems](#p)
- [Time Complexity](#t)

## [Backtracking LC Explore Cards](https://leetcode.com/explore/learn/card/recursion-ii/472/backtracking/2654/)
- Backtracking uses Recursion & it is an algorithmic paradigm aimed to improve the time complexity of the [Naive/Brute Force](..) **if possible**.
- Backtracking **can be imagined** same as tree traversal where we start from root node to search for solutions that are located at the leaf nodes.
- Each node represents a partial candidate to final solution, At each node. Once we can determine if a certain node cannot possibly lead to a final solution, we abandon the current node and backtrack to its parent node to explore other possibilities.
- **How?** Backtracking does not generate all possible solutions, it checks if condition fails, the solution is rejected and the next solution is tried.

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

<a name=t></a>
### Backtracking Template
Most of BT problems can be solved using below pattern.
```c
    vec<> solutions;
    
    void recursive_backtrack(int row, int col, &candidate){
      if (base_case reached){                  //Base case.
        solutions.push_back (solution);        //Copy solution-1 into solutions vector
        return;
      }
      
      for (candidate in candidate list) {
        if (candidate not valid)
          continue;
        else {                                                    //VALID candidate
          solution.push_back (candidate);                         //Place this candidate on 1 solution
          recursive_backtrack (next_candidate=candidate+1);      //Try next candidate
          remove (candidate);                                    //Mark this as unvisited, Unflag this node.
        }
      }
    }
    
    return-type solve (int n) {
        create-1st-candidate;
        recursive_backtrack (start, end, 1stcandidate);             //Start from row=0,col=0
        return vecs_final_board;
    }
    
    main () {
      solve(n);
    }
```

<a name=p></a>
### Backtracking Problems 
- **Combinations**
  - [Generate All Combinations](/DS_Questions/Questions/Permutation_Combination/Combinations)
  - Combination Sum
    - [Combination Sum](/DS_Questions/Questions/Permutation_Combination/Combinations/Combination_sum/)
    - [Combination Sum II. Time: O(2<sup>n</sup>)](/DS_Questions/Questions/Permutation_Combination/Combinations/combination_sum_2)
    - [Combination Sum III. Time: O(9!k / (9-k)!)](/DS_Questions/Questions/Permutation_Combination/Combinations/combination_sum_3.md)
    - [Letter Combinations of a Phone Number](/DS_Questions/Questions/Permutation_Combination/Combinations/Letter_Combinations_of_a_Phone_Number/)
  - [Jump Game](/DS_Questions/Questions/vectors_arrays/Find_Search_Count/Find/Unsorted/Jump_Game_1.md)
- [Generate All Parantheses](/DS_Questions/Questions/Strings/parantheses/Generate_All_Parantheses.md)
- [N-Queen-Problem. Time:O(n!)](/DS_Questions/Questions/vectors_arrays/2d-grid/N-Queens)
- [Fair Distribution of Cookies](DS_Questions/Questions/vectors_arrays/Find_Search_Count/Find/Unsorted/Minimum/Fair_Distribution_of_Cookies.md)
- Palindrome
  - [Palindrome Partitioning](/DS_Questions/Questions/Strings/SubString_SubSequence/SubString_SubArray/Palindrome_Partitioning.md)
- **Permutations**
  - [All Permutations](/DS_Questions/Questions/Permutation_Combination/Permutations/All_permutations.md)
  - [All Unique Permutations](/DS_Questions/Questions/Permutation_Combination/Permutations/All_Unique_Permutations.adoc)
  - [Next Greater Permutation](/DS_Questions/Questions/Permutation_Combination/Permutations/Next_Greater_Permutation.md)
  - [Alternating Parity Permutation](/DS_Questions/Questions/Permutation_Combination/Permutations/alternating-parity-permutation.md)
- [Robot Room Cleaner](/DS_Questions/Questions/vectors_arrays/2d-grid/Robot_Room_Cleaner/)
- [Subsets](/DS_Questions/Questions/vectors_arrays/Order_Arrangment/Find_All_Subsets.md)
- [Sudoku Solver](/DS_Questions/Questions/vectors_arrays/2d-grid/Sudoku_Solver)
- [Word Search in 2D grid. Time:O(2<sup>n</sup>)](/DS_Questions/Questions/vectors_arrays/2d-grid/Word_Search_in_2D_Matrix/Word_Search_in_2D_Matrix.md)
- **Graph**
  - [Detect cycle in Directed Graph](/DS_Questions/Questions/Graphs/Find/Directed_Graph/detect_cycle_in_directed_graph.md)

<a name=t></a>
### Time Complexity
- BT is unfolded as a **DFS traversal in a n-ary tree**.
- **Time Complexity:** (Max Number of nodes on 1 level) x (Number of levels).
- So, How many number of nodes?
```c
  1st iteration = n elements
  T = target value
  O(n ^ T)
```
- Varies on approach taken by backtracking algo.
  - O(mn): Word Search in Maze
  - O(2<sup>n</sup>) < O(n!)
