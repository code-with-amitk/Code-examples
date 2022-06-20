DFS

### DFS
#### Algorithm
- Start at distinguished source vertex.
- Every time DFS hits a branching point (a [vertex](/DS_Questions/Data_Structures/Graphs/) with more than one neighbors), DFS will choose one of the unvisited neighbor(s) and visit this neighbor vertex.
- DFS repeats this process and goes deeper until it reaches a vertex where it cannot go any deeper.
- When this happens, DFS will ‘backtrack’ and explore another unvisited neighbor(s), if any
