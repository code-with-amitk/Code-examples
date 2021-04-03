## Topological Sort / Topological Order
- Print/visit of directed graph such that for edge(ab) where a->b, a should be printed before b. TS is only possible for DAG(because DAGs don't have cycles and are directed).
  - in-degree: In directed graph number of incoming edges is called in-degree.
  - out-degree: number of outgoing edges.
```c
        5 --> 0 <-- 4     //in-degree of node[5]=0, node[0]=2
        |           |     //out-degree of node[5]=2, node[0]=0
        \/         \/
        2 --> 3 --> 1
```        
- **[Printing Toplogical sorted / Toplogical order using kahn algorithm](Printing_Topological_Sort_kahn_Algo.cpp)**
