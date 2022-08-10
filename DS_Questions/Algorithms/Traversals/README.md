||BFS(Breadth First) |DFS(Depth First)|Bidirectional Search|
|---|---|---|---|
|Uses|Queue|Stack||
|What|Traverses the graph in breadth ie touch all neighbor nodes of starting node|Touch every node in path to reach deepest node and come back, instead of reaching all neighbors|Run 2 simultaneous BFS, one from each node. When their searches collide, we have found a path.|
|Complexity||O(V+E). V=nodes=vertices. E=edges||
|Applications|find all neighbor nodes of given node. Examples <ul><li>1.GPS Navigation system</li></ul><ul><li>2.Broadcasting information)</li></ul><ul><li>3. Web Crawlers</li></ul>|Shortest path||
