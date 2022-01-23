**Traversals**
- **1. All Paths from src to dst**
  - [Unweighted DAG](#dag)
- **2. Single Source <ins>Shortest Path</ins>**

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
