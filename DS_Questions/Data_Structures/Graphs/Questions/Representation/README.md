## Graph Representation
```c++
        a --> c 
        |     |
        |     \/
        ----> d <-- b
```

### 1. Adjacency Matrix/Lookup table
- **What** Each cell keeps how two nodes are connected. For unweighted graph values are `1`. For weighted graph values are cost/weights.
- **Advantages** Easy to represent, Removing an edge takes O(1) time, Queries like whether there is an edge from vertex `u` to vertex `v` takes O(1)
> a=0, b=1, c=2, d=3
```c
   a   b   c   d
a  0   0   1   1    
b  0   0   0   a
c  0   0   0   1
d  0   0   0   0
```

### 2. Adjacency List
- **What** Each node keeps list of neighbors. Data structures can be Arrays, vectors, ll etc.
- **Advantages** Save space, only stores connected nodes, while AM stores 0 if edge is not present.
```c++
Graph:
        0
      / | \
     1  2  3
            \
             4
vector<int> input = [-1, 0, 0, 0, 3]    //size=5

Representation using AdjList: represented using array of vectors.      vector<int> AdjList[5]
  AdjList[0] => 1,2,3    //node0
  AdjList[1] => 0        //node1
  AdjList[2] => 0        //node2
  AdjList[3] => 0, 4     //node3
  AdjList[4] => 3        //node4
```
  
### 3. Edge List
```c++
   v[0] |2|3|		//a(0) has c(2),d(3) as edges
   v[1] |3|
   v[2] |3|

  v[0].push_back(2); v[0].push_back(3);
  v[1].push_back(3); v[2].push_back(3);
```   
