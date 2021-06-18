### DAG(Directed Acyclic Graph)
  - Directed graph without cycles graph. 
  - DAG will surely have 1 vertex with indegree=0 and 1 vertex with outdegree=0, because it does not have cycle.
```c
    a  ---->  b        //In-degree: Number of edges coming to the vertex. Eg: in-degree for c is 2
    |        \/        //Out-degree: Number of edges going out of vertex. Eg: out-degree for a is 2
    ------->  c
```
  - **Search Complexity** 
    - Average case O(V+E). V=vertices, E=Edges
    - Best case. O(logE). 
      - Using DFS, two parallel tree traversals, one preorder traversal and other postorder traversal.
