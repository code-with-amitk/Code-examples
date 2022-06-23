- [What is Graph](#what)
- **[Representation of Graph](#r)**
  - [1. Adjacency List](#l)
  - [2. Edge List](#el)
  - [3. Adjacency Matrix/Lookup table](#m)
- **[Terms: Degree, Diameter, Edge/Arc/Line, Radius, Topological Sort, Vertex/Node, Connected Components](#t)**
- **Types of Graphs**
  - [1. Cyclic/Acyclic](#cyclic)
    - [1a. DAG/Directed Acyclic Graph](#dag)
  - [2. Directed/Undirected](/DS_Questions/Data_Structures/Graphs/Directed_Undirected)
  - [3. Spanning Tree](#st)
    - [3a. Min Spanning Tree](#mst)
  - [4. Weighted/Unweighted Graph](#weighted)
- **Operations**
  - [Disjoint Set Union](#dis)
    - [Application => Connected Component in Graph](#app)


<a name=what></a>
## Graph
Collection of nodes/vertices with edges between some/all of them. Examples: Internet, City map, Person's Social Network, State machines.
```c
    0 ------- 1     4         //Nodes: 0,1,2,3,4,5
    |         |               //Edges ={01, 12, 23, 03}
    3 ------- 2     5
```

<a name=r></a>
## Representation of Graph
<a name=l></a>
#### 1. Adjacency List	//Often used
- Each node keeps list of adjacent neighbours.
- Data structures can be vectors, ll etc. Advantages: Save space, only stores connected nodes.
```c
    3 -- 1
    | \
    |   \
    0 -- 2

        2,3   3    0,3   0,1,2  <Linked list
	/\    /\    /\    /\
        |     |     |     |
Nodes | 0  |  1  |  2  |  3  |  <vector

      |key value   |           |             |               |
      | 0 | [2,3]  |  1 | [3]  |  2 | [0,3]  |  3 | [0,1,2]  |  <<HashTable
      |            |           |             |               |
```
<a name=el></a>
#### 2. Edge List
- Each node keeps [edges](#t)
```cpp
    3 -- 1
    | \
    |   \
    0 -- 2

   v[0] |2|3|		//0 has edges to 2,3
   v[1] |3|		//1 has edge to 3
   v[2] |0|3|           //2 has edges to 0,3
   v[3] |0|1|2|         //3 has edges to 0,1,2

  v[0].push_back(2); v[0].push_back(3);
  v[1].push_back(3); v[2].push_back(3);
```
<a name=m></a>
#### 3. Adjacency Matrix/Lookup table/2D Matrix
- Shows whether node has connection to other node or not. `0 means No, 1 means yes`
- For weighted graph values are cost/weights.
- *Advantages* Easy to represent, Removing an edge takes O(1) time, Queries like whether there is an edge from vertex `u` to vertex `v` takes O(1)
```c
    3 -- 1
    | \
    |   \
    0 -- 2
    
   0   1   2   3
0  0   0   1   1    
1  0   0   0   1
2  1   0   0   1
3  1   1   1   0
```

<a name=t></a>
## Terms
#### Degree
- _Undirected Graph:_ Number of edges incident on it.
- _Directed Graph:_ 
  - _Indegree of Node:_ Number of edges leading into that node.
  - _Outdegree:_ the number of edges leading away from node.

#### Diameter/Eccentricity
Greatest distance between any pair of vertices.

#### Edge/Arc/Line
Links connecting the nodes. Links can be directed/undirected, weighted/unweighted. Weight also means cost.

#### Radius 
Minimum eccentricity of any vertex.

#### Topological Sort / Topological Order
- Print/visit of directed graph such that for edge(ab) where a->b, a should be printed before b.
- TS is only possible for [DAG](#dag). because DAGs don't have cycles and are directed.
- Some events should happen before next. Ex: Getting ready in morning (socks before shoes, undergarments before pants).
- [Logic, Code Topological Sort](/DS_Questions/Data_Structures/Graphs/Toplogical_Sort)
```c
        5 --> 0 <-- 4     //in-degree of node[5]=0, node[0]=2. In directed graph number of incoming edges
        |           |     //out-degree of node[5]=2, node[0]=0. number of outgoing edges
        \/         \/
        2 --> 3 --> 1
```

#### Vertex = Node
Interconnected objects are called vertices.

#### Connected Components?
This is subgraph in which each pair of nodes is connected with each other via a path. Here 3
```c
1---2    4--5   6
    |
    3
```
[Finding connected Components: 1. DFS, 2. Disjoint set union](/DS_Questions/Questions/Graphs/Find/Undirected_Graph)

## Types of Graphs
<a name=cyclic></a>
### 1. Cyclic/Acyclic
- *Cyclic:* If graph has cycle.  
- *Acyclic:* No cycles in graph. When following the graph from node to node, you will never visit the same node twice.
<a name=dag></a>
#### 1a. DAG(Directed Acyclic Graph)
- Directed graph without cycles graph. DAG will surely have 1 vertex with indegree=0 and 1 vertex with outdegree=0, because it does not have cycle.
```c
    a  ---->  b        //In-degree: Number of edges coming to the vertex. Eg: in-degree for c is 2
    |        \/        //Out-degree: Number of edges going out of vertex. Eg: out-degree for a is 2
    ------->  c
```
- **Search Complexity** 
  - Average case O(V+E). V=vertices, E=Edges
  - Best case. O(logE). Using DFS, two parallel tree traversals, one preorder traversal and other postorder traversal.

<a name=st></a>
### 3. Spanning Tree
Subgraph derived from Graph satisfying these conditions:
  - No cycles(ie it is acyclic), Since it a tree
  - Should connect all vertices with minimum number of edges.
- **Properties of ST**
  - 1 graph can have many spanning trees.
  - Graph can be weighted or unweighted
  - Every connected and undirected Graph G has at least 1 ST.
  - A disconnected graph does not have any ST, as it cannot be spanned to all its vertices.
  - Number of Spanning Trees, for graph having `n` vertices = n<sup>n-2</sup>
  - Number of edges, for graph having `n` vertices = n - 1
- Example
```
    a ------ b               a ----- b              a ------ b           a --- b
    |    /   |                       |              |                      \
    |   /    |               c ----- d              c ------ d               \
    c  ----- d                                                           c --- d
    Main Graph                1 ST                  Another ST          Another ST
```
- **Applications of ST**
- *A. Civil Network Planning:* City network as a huge graph and now plans to deploy telephone lines in such a way that in minimum lines we can connect to all city nodes.    
- *B. Computer Network Routing Protocol*

<a name=mst></a>
#### 3a. Min Spanning Tree
A ST where total weight of all edges is minimum. Has n-1 edges.
- **Finding Min Spanning Tree?**
  - Start from min weight edge
  - Go on connecting all min weight edges. 
  - Donot connect any edge that creates a cycle. We cannot connect cb.
 ```c
    a --5-- b                         b               b       a        
   3|   /4  |3                        |3              |3     3|         
    c --1-- d        c --1-- d        c --1-- d       c --1-- d                                    
```
- **Algorithms for finding Min Spanning Tree**
```c
             Algo | Kruskal's  | Prim's
  --------------- |----------- | -------
  Time Complexity | O(E log V) | O(E + V log V) //slow 
  When to use     |            | Works faster in graph with many more edges than vertices 
```
- **A. PRIM's Algorithm**  //Time Complexity = O(E + V log V) //slow wrt kruskal's
  - _1._ Choose arbitrary vertex to start
  - _2._ Choose min weight edge that is not in(output mst), note that in mst.  
  - _3._ Repeat step-2 until all edges are in mst.
```c
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

- **B. KRUSKAL'S Algorithm** //Time Complexity = O(E log V)
  - Keep including minimum edges, as long as no cycles are formed. Once all vertices are covered, stop.
  - Example
```c
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
<a name=weighted></a>
### 4. Weighted/Unweighted Graph
- *Weighted?* If edges has cost/weight. Ex: flight fuel cost between cities.        
- *Unweighted?* if the edges do not have weights.
```c
   0 --50-- 1
 10|        |20
   3 --50-- 2
```

## Operations
<a name=dis></a>
### Disjoint set Union
Some applications involve grouping n distinct elements/nodes into a collection of disjoint sets. These applications often need to perform two operations: 
  - Finding the unique set that contains a given element OR
  - uniting two sets. 

_Datastructure:_ disjoint-set data structure maintains a collection S = {S1,S2,S3 ..} of disjoint dynamic sets. Each set has a REPRESENTATIVE element(which is member of set).

_Operations:_ 
  - UNION(x, y): unites the dynamic sets that contain x and y, say Sx and Sy, into a new set that is the union of these two sets.
  - FIND-SET(x): returns a pointer to the representative of the (unique) set containing x.

<a name=app></a>
#### Application => [Connected Component in Graph]()
> When the edges of the graph are static(not changing over time—we) can compute the connected components faster by using depth-first search.

4 Connected components in graph.
```c
  a --- b     e -- f    h     j
  |  /  |     |         |
  c     d     g         i
  
Vertices(V) = a,b,c,d,e,f,g,h,i,j
Edges(E) = 
  (a,b), (a,c), (b,d), (b,c)
  (e,f), (e,g)
  (h,i)  
```
- Algo Steps
```c
  Edge Processed |               Collection of Disjoint Sets
-----------------|---------------------------------------------
                 | {a} {b} {c} {d} {e} {f} {g} {h} {i} {j}           //Step-1: Place each vertex/node in it's own set
   (a,b)         | {a,b}   {c} {d} {e} {f} {g} {h} {i} {j}           //Step-2: For each edge(u,v), combine the sets containing u and v
   (a,c)         | {a,b,c}     {d} {e} {f} {g} {h} {i} {j}
   (b,d)         | {a,b,c,d}       {e} {f} {g} {h} {i} {j}
   (b,c)         | {a,b,c,d}       {e} {f} {g} {h} {i} {j}
   (e,f)         | {a,b,c,d}       {e,f}   {g} {h} {i} {j}
   (e,g)         | {a,b,c,d}       {e,f,g}     {h} {i} {j}
   (h,i)         | {a,b,c,d}       {e,f,g}     {h,i}   {j}
```
- Pseudo code
```c
connected_components(graph g) {
  for vertex/node(V) in graph    //Step-1
    make_set (V)
    
  for edge(u,v) in graph {          //Step-2. Combine edges(u,v) into 1 set
    if (find_set(u) != find_set(v))
      union(u,v)
  }
}  

SAME-COMPONENT.u; /
1 if FIND-SET.u/ == FIND-SET./
2 return TRUE
3 else return FALSE
```
