## Graph
- **What?** Collection of nodes/vertices with edges between some/all of them. Examples: Internet, City map, Person's Social Network, State machines. [Representation of Graphs: Adjacency Matrix, Adjacency List, Edge List](Questions/Representation)
```c
    0 ------- 1        //Nodes: 0,1,2,3
    |         |        //Edges ={01, 12, 23, 03}
    3 ------- 2    
```
- **[Terms?](Terms)** 
  - Cyclic/Acyclic
    - DAG(Directed Acyclic Graph)
  - Directionality(Bidirectional,Unidirectional)
  - Edge,Vertex.
  - Spanning Tree: Minimum Spanning Tree(Kruskal's, Prim's Algorithms)
  - Topological Sorting: Kahn Algorithm
  - Weighted Graph
- **[Questions](Questions)**
  - Mother Vertex Kosaraju
  - Graph Transpose
  - Directed Graph
  - **[Traversals](/DS_Questions/Algorithms/Traversals):** BFS, DFS, Shortest Path(Dijkstra, Floyd)
