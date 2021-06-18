## Spanning Tree
- **What?** Subgraph derived from Graph satisfying these conditions:
  - No cycles(ie it is acyclic), Since it a tree
  - Should connect all vertices with minimum number of edges.
- **Properties of ST**
  - 1 graph can have many spanning trees.
  - Graph can be weighted or unweighted
  - Every connected and undirected Graph G has at least 1 ST.
  - A disconnected graph does not have any ST, as it cannot be spanned to all its vertices.
  - Number of Spanning Trees, for graph having `n` vertices = n<sup>n-2</sup>
  - Number of edges, for graph having `n` vertices = n - 1

### Example
```
    a ------ b               a ----- b              a ------ b           a --- b
    |    /   |                       |              |                      \
    |   /    |               c ----- d              c ------ d               \
    c  ----- d                                                           c --- d
    Main Graph                1 ST                  Another ST          Another ST
```

### Applications of ST
- **A. Civil Network Planning**: City network as a huge graph and now plans to deploy telephone lines in such a way that in minimum lines we can connect to all city nodes.    
- **B. Computer Network Routing Protocol**
