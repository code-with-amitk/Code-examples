DFS
- [Algorithm](#a)
- [Complexity](#c)


## DFS
<a name=a></a>
### Algorithm
- Start at distinguished source vertex.
- Every time DFS hits a branching point (a [vertex](/DS_Questions/Data_Structures/Graphs/) with more than one neighbors), DFS will choose one of the unvisited neighbor(s) and visit this neighbor vertex.
- DFS repeats this process and goes deeper until it reaches a vertex where it cannot go any deeper.
- When this happens, DFS will ‘backtrack’ and explore another unvisited neighbor(s), if any

<a name=c></a>
### Complexity
#### Time
- For Graph represented using Adjacency List:O(V+E). V=vertices(nodes), E=edges
- For Graph represented using Adjacency Matrix:O(V<sup>2</sup>)
#### Space
O(V). Stack to store vertices
