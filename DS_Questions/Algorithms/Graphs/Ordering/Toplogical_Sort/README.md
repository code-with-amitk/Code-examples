**Topological Sort / Topological Order**
- [What](#w)
- [Algorithm](#algo)
- [Question on Topological Sort](#q)

### Topological Sort / Topological Order
- In [DAG](DS_Questions/Data_Structures/Graphs/README.md#dag), Print/visit of directed graph such that for edge(ab) where a->b, a should be printed before b.
- Some events should happen before next. Example:
  - _1._ When selecting courses in college, some advanced courses have prerequisites that require you to take some introductory courses first.
```c
course-A ---> course-B ---> course-C	//Topological order would be A,B,C. ie to reach C, course-A should be completed
```

<a name=algo></a>
#### Algorithm
- 1. Find outdegrees(number of incoming edges) of all nodes in graph. Nodes with outdegree=0(are called source nodes).
```c
        5 --> 0 <-- 4     //in-degree of node[5]=0. Number of incoming edges
        |           |     //out-degree of node[5]=2. Number of outgoing edges
        \/         \/
        2 --> 3 --> 1

Expected output:  Ascending order of outdegrees
 5 4 2 3 1 0      OR
 4 5 3 2 1 0

outdegrees
    | 2 | 2 | 1 | 1 | 0 | 0 | <- outdegrees
      0   1   2   3   4   5   <-nodes
```
- _2._ Push all outdegree=0 nodes into queue.
```c
  queue q |4 5|
```
- _3._ Perform until queue not empty.
```
while (queue is not empty)
  - Pop queue front = 4
output  <4>
  - Reduce outdegree of all nodes connected to 4 by 1.  (0,1)
outdegrees
    | 1 | 1 | 1 | 1 | <- outdegrees
      0   1   2   3   <-nodes
  - Scan outdegree again, if any node has outdegree==0, push in queue.

  - Pop front of queue = 5
output  <4, 5>
  - Reduce outdegree of all nodes connected to 5 by 1.  (0,2)
outdegrees
    | 0 | 1 | 0 | 1 | <- outdegrees
      0   1   2   3   <-nodes
  - Scan outdegree again, if any node has outdegree==0, push in queue.  (0,2)

queue q |0 2|

  - Pop front of queue = 0
output  <4, 5, 0>
  - Reduce outdegree of all nodes connected to 0 by 1. 
outdegrees
    | 1 | 1 | <- outdegrees
      1   3   <-nodes

  - Pop front of queue = 1
output  <4, 5, 0, 1>
  - Reduce outdegree of all nodes connected to 1 by 1. 
outdegrees
    | 1 | 0 | <- outdegrees
      1   3   <-nodes
- Scan outdegree again, if any node has outdegree==0, push in queue. (3)

queue q |3|

  - Pop front of queue = 3
output  <4, 5, 0, 1, 3>
  - Reduce outdegree of all nodes connected to 3 by 1. 
outdegrees
    | 0 | <- outdegrees
      1   <-nodes

output  <4, 5, 0, 1, 3>
```

<a name=q></a>
#### Question on Topological Sort
  - [1. Find Minimum Height Tree](/DS_Questions/Questions/Graphs/Find/Undirected_Graph/Minimum_Height_Tree/)
  - [2. Course Schedule II](/DS_Questions/Questions/Graphs/Find/Directed_Graph/Cyclic/CoursesSchedule-2_Topological_Sort.md)
  - [3. Detect Cycle in Directed Graph](/DS_Questions/Questions/Graphs/Find/Directed_Graph/Cyclic/Detect_cycle_in_directed_graph.md)
  - [4. Order of alphabets in Alien Dictionary](/DS_Questions/Questions/Graphs/Find/Directed_Graph/Order_of_alphabets_in_Alien_Dictionary.md)
