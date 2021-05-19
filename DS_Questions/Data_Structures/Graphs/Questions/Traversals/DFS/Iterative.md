## Depth First Traversal
- Reach to deepest node, instead of reaching all neighbors.
```c
        0 -- 1 -- 2
         \   |   /
           \ | /
             3
                


Starting node=2, dfs=2 1 0 3
```

### Logic
- *1.* Store the graph nodes in Adjacency List.
```
        vector<int> v[4];
```
- *2.* Take following datastructures:
  - `bool visited[4]` //Storing all visited nodes
  - Stack for DFS Traversal.
  - Perform these operations until stack is empty
```c
 Push 1st element on stack
 Pop top. store value in u.
 Print and mark this node as visited
 Find unvisited neighbours of this node. //Iterate through vector
   push_on_stack
   break;
```
