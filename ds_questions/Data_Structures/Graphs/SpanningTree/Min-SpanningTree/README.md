 ## Min Spanning Tree
 - A ST where total weight of all edges is minimum. Has n-1 edges.
 
 ### How to find
  - Start from min weight edge
  - Go on connecting all min weight edges. 
  - Donot connect any edge that creates a cycle. We cannot connect cb.
 ```
    a --5-- b                                         b       a        
   3|   /4  |3                                        |3     3|         
    c --1-- d        c --1-- d        c --1-- d       c --1-- d                                    
```

### Algorithms

| Algo | Kruskal's | Prim's |
| --- | --- | --- |
| Time Complexity | O(E log V) | O(E + V log V) //slow |
| When to use | | Works faster in graph with many more edges than vertices |

#### A. PRIM's Algorithm  [Time Complexity = O(E + V log V) //slow wrt kruskal's]
- 1. Choose arbitrary vertex to start
- 2. Choose min weight edge that is not in(output mst), note that in mst.  
- 3. Repeat step-2 until all edges are in mst.
```
   ---            
  |   \/Loop                              [0] -2- [1] -4- [2]            [0] -2- [1]         
  --- [0] -2- [1] -4- [2]                  3\    4|       /2                                                                                                                                              /2
       3\    4|      /2      -Step-1->           [3]                                                                                                                                                  [3]
             [3]                          a. Remove loops &       b. Choose any arbitrary outgoing     
                                             parallel edges           & edge with min weight           

Step-2    [0] -2- [1] -4- [3]           [0] -2- [1] -4- [3]
        c. Choose min weighted                          /2
           edge going from [1]                        [3]
                                       d. Choose min weighted edge going from [1] or [0] or [3]
```

#### B. KRUSKAL'S Algorithm [Time Complexity = O(E log V)]
- Keep including minimum edges, as long as no cycles are formed. Once all vertices are covered, stop.
- Example
```
  -----
  |   \/Loop
  --- a ---------  b                        a --6---b                       a    b
  /   |            |    \                7/ |    /  | \5    
 e    |            |     f              e   3   4   2  f                e           f
  \   |            |    /                8\ | /     | /2    
      c --------- d                        c ---3-- d                       c    d
      | parallel  |                 Step-2: Write all vertices
       -----------                          since MST will hav
 Step-1: Remove all loops                   all vertices      
         & parallel edges                                     

 b                   a       b             a       b
 |                   |       |           7/|       |
 2  f                3       2             3       2
 | /2                |       | /2          |       | /2
 d                   c --3-- d             c --3-- d
Step-3:Include       Step-4: Include       Step-5: Include
minimum edges        next min edges       next min edges
```
