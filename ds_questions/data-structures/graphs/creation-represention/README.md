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
  
| |  | 0 | 1 | 2 | 3 |
| --- | --- | --- | --- | --- | --- |
| a-> | 0 | 0 | 0 | 1 | 1 |
| b-> | 1 | 0 | 0 | 0 | 1 |
| c-> | 2 | 0 | 0 | 0 | 1 |
| d-> | 3 | 0 | 0 | 0 | 0 |
  
### 2. Adjacency List
- **What** Each node keeps list of neighbors. Data structures: Arrays, vectors, ll etc.
- **Advantages** Save space, only stores connected nodes, while AM stores 0 if edge is not present.
```c++
   a(0) -> c(2) -> d(3)
   b(1) -> d(3)
   c(2) -> d(3)

  vector<int> v[4];
  l[0].push_back(2); l[0].push_back(3);
  l[1].push_back(3);
  l[2].push_back(3);
```
  
#### 3. Edge List
```c++
   v[0] |2|3|		//a(0) has c(2),d(3) as edges
   v[1] |3|
   v[2] |3|

  v[0].push_back(2); v[0].push_back(3);
  v[1].push_back(3); v[2].push_back(3);
```   
