BFS / Level Order Traversal
- [When to apply](#w)
- [BFS Template](#t)
- Examples
  - [Level order Traversal of Binary Tree](DS_Questions/Data_Structures/Trees/BinaryTree/Traversal/Spiral/LeftToRight_LevelByLevel/README.md#a1)
  - [Race Car](/DS_Questions/Questions/Graphs/Find/Directed_Graph/Cyclic/RaceCar.md) 

### BFS / Level Order Traversal {Using Queue}
Graph/Tree is traversed level by level.
```c
Graph: 	0 -- 1 -- 2		//Output: 0 1 3 2
         \   |	 /
	     3
Tree:
        12
       /  \
      10  30
     /    / \
   14   25   40
             /
            50
O/P ->  12 
        10 30 
        14 25 40 
        50
```

<a name=w></a>
#### When to Apply
Any of these conditions:
- _a._ Find shortest distance to dst node.
  - While finding shortest distance you cannot use DFS, because node can be just next hop away.

<a name=t></a>
#### BFS Template
```c
main() {
	unordered_set<int> visited;
	
	//1. Push 1st/start node into queue and mark visited
	queue<int> q;
	q.push(12); 	visited.insert(12);

	//2. Traverse whole graph/tree using queue
	while (!q.empty()) {
		int size = q.size();
		
		//3. Traverse all nodes on level
		for (int i=0;i<size;++i) {
			int ele = q.front();	q.pop();
		
			//4. Insert all children of present node, if not visited
			//   And mark Child itself as visited
			for (int k=child; k<children; ++k){
				if (visited.find(k) == visited.end()) {
					q.push(k);
					visited.insert(k);
				}
			}
		}
		//Increment the level count
		level++;
	}
}
```
