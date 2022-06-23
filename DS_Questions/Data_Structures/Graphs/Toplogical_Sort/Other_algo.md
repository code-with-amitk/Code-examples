### Logic
```c
        5 --> 0 <-- 4     //in-degree of node[5]=0, node[0]=2. In directed graph number of incoming edges
        |           |     //out-degree of node[5]=2, node[0]=0. number of outgoing edges
        \/         \/
        2 --> 3 --> 1

a. Perform DFS, when there is no outdegree of node. Push on stack

                                                                        Stack       visited
start node=5. Perform DFS from Node=5 reach 0.                          
                 Since 0 has no outdegree. Push on stack                | 0 |        0
              2-3-1. Since 1 has no outdegree. Push on stack            | 0 1 |      0 1
      Node=3, while recursing back. 
              Does node=3 connects to any node whose outdegree=0
              and not visited? No, push node=3 on stack.                | 0 1 3 |    0 1 3
      node=2. while recursing back.                    
              Does node=2 connects to any node whose outdegree=0 
              and not visisted? No, push node=2 on stack.               |0 1 3 2|   0 1 3 2
      node=5. no unvisited node, whose outdegree=0.                     |0 1 3 2 5| 0 1 3 2 5
                                                                        | 0 1 3 2 5 4 |
                                                                                    top
b. Topological Sort: Remove elements from stack. 4 5 2 3 1 0
```
