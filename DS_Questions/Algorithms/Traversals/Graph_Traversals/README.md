**Traversals**
- **1. <ins>All Paths</ins> from src to dst**
  - [Unweighted DAG](#dag)
- **2. Single Source <ins>Shortest Path</ins>**
  - **2a. Weighted Graph**
    - [2a1. Dijkstra Algo. For +ve(non-negative) weights only](Dijkstra_Algo.md)
    - 2a2. Bellman Ford Algo. For +ve,-ve weights
  - **2b. Unweighted Graph: DFS**

## Graph Traversals
### 1. All paths from src to dst
<a name=dag></a>
#### Unweighted DAG
- [Approach-1: Backtracking](/DS_Questions/Questions/Graphs/Find/Directed_Graph/Acyclic)
```c
  0 ---> 1 ---> 3
  |             /\
  |----> 2 -----|

Output: [[0,1,3],[0,2,3]] 
There are two paths to reach dst 3 from src=0: 0 -> 1 -> 3 and 0 -> 2 -> 3.
```

## 2. Single Source <ins>Shortest Path</ins>
### 2a. Weighted Graphs
