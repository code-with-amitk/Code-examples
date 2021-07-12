- [What is Graph](#what)
- [Representation of Graph](#repr)
  - [1. Adjacency Matrix/Lookup table](#adjm)
  - [2. Adjacency List](#adjl)
  - [3. Edge List](#edgelist)
- [Terms](#terms)
  - [1. Diameter/Eccentricity](#dia)
  - [2. Edge/Arc/Line](#edge)
  - [3. Radius](#radius)
  - [4. Topological Sort / Topological Order](#ts)
  - [5. Vertex/Node](#vertex)
  - [6. Connected Components](#cc)
- [Types of Graphs](#types)
  - [1. Cyclic/Acyclic](cyclic)
    - [1.1 DAG/Directed Acyclic Graph](#dag)
  - [2. Directed/Undirected](directed)
  - [3. Spanning Tree](#st)
    - [3.1 Min Spanning Tree](#mst)
  - [4. Weighted/Unweighted Graph](#weighted)


<a name=what></a>
## Graph
- Collection of nodes/vertices with edges between some/all of them. 
- Examples: Internet, City map, Person's Social Network, State machines.
```c
    0 ------- 1     4         //Nodes: 0,1,2,3,4,5
    |         |               //Edges ={01, 12, 23, 03}
    3 ------- 2     5
```

<a name=repr></a>
## Representation of Graph
```c++
        a --> c 
        |     |
        |     \/
        ----> d <-- b
```
<a name=adjm></a>
### 1. Adjacency Matrix/Lookup table
- Each cell keeps how two nodes are connected. For unweighted graph values are `1`. For weighted graph values are cost/weights.
- *Advantages* Easy to represent, Removing an edge takes O(1) time, Queries like whether there is an edge from vertex `u` to vertex `v` takes O(1)
```c
   a   b   c   d     //a=0,b=1,c=2,d=3
a  0   0   1   1    
b  0   0   0   a
c  0   0   0   1
d  0   0   0   0
```
<a name=adjlist></a>
### 2. Adjacency List
- Each node keeps list of neighbors. Data structures can be Arrays, vectors, ll etc.
- *Advantages* Save space, only stores connected nodes, while AM stores 0 if edge is not present.
```c++
Graph:
   1 -- 0 -- 3 -- 4
        |
        2  
vector<int> input = [-1, 0, 0, 0, 3]    //size=5

Representation using AdjList: represented using array of vectors.      vector<int> AdjList[5]
  AdjList[0].push_back(1);
  AdjList[0].push_back(2);
  AdjList[0].push_back(3); => 1,2,3    //node0

  AdjList[1].push_back(0);             //node1
  
  AdjList[2].push_back(0);             //node2
  
  AdjList[3].push_back(0);         
  AdjList[3].push_back(4);             //node3

  AdjList[4].push_back(3);             //node4
```
<a name=edgelist></a>
### 3. Edge List
```c++
   v[0] |2|3|		//a(0) has c(2),d(3) as edges
   v[1] |3|
   v[2] |3|

  v[0].push_back(2); v[0].push_back(3);
  v[1].push_back(3); v[2].push_back(3);
```

<a name=terms></a>
## Terms
<a name=dia></a>
### 1. Diameter/Eccentricity
Greatest distance between any pair of vertices.
<a name=edge></a>
### 2. Edge/Arc/Line
Links connecting the nodes. Links can be directed/undirected, weighted/unweighted. Weight also means cost.
<a name=radius></a>
### 3. Radius 
Minimum eccentricity of any vertex.
<a name=ts></a>
### 4. Topological Sort / Topological Order
  - Print/visit of directed graph such that for edge(ab) where a->b, a should be printed before b. TS is only possible for DAG. because DAGs don't have cycles and are directed.
  - in-degree: In directed graph number of incoming edges is called in-degree.
  - out-degree: number of outgoing edges.
```c
        5 --> 0 <-- 4     //in-degree of node[5]=0, node[0]=2
        |           |     //out-degree of node[5]=2, node[0]=0
        \/         \/
        2 --> 3 --> 1
```        
<a name=vertex></a>
### 5. Vertex/Node
Interconnected objects are called vertices.
<a name=vcc></a>
### 6. Connected Components? 
Here 3
```c
1---2    4--5   6
    |
    3
```

<a name=types></a>
## Types of Graphs
<a name=cyclic></a>
### 1. Cyclic/Acyclic
- *Cyclic:* If graph has cycle.  
- *Acyclic:* No cycles in graph. When following the graph from node to node, you will never visit the same node twice.
<a name=dag></a>
#### 1.1 DAG(Directed Acyclic Graph)
- Directed graph without cycles graph. DAG will surely have 1 vertex with indegree=0 and 1 vertex with outdegree=0, because it does not have cycle.
```c
    a  ---->  b        //In-degree: Number of edges coming to the vertex. Eg: in-degree for c is 2
    |        \/        //Out-degree: Number of edges going out of vertex. Eg: out-degree for a is 2
    ------->  c
```
- **Search Complexity** 
  - Average case O(V+E). V=vertices, E=Edges
  - Best case. O(logE). Using DFS, two parallel tree traversals, one preorder traversal and other postorder traversal.

<a name=directed></a>
### 2. [Directed/Undirected]
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
#### 3.1 Min Spanning Tree
- A ST where total weight of all edges is minimum. Has n-1 edges.
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
