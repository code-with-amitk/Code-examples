## Breadth 1st Search (uses Queue)
```console
Graph: 	0 -- 1 -- 2		//4 Nodes, 5 edges
         \   |	 /
	     3
Traversal 0 1 3 2             
```
### Logic
- *1.* Graph stored as Adjacency list.
```c
  vector<int> v[4]
  
  | 1,3 | 0,1,3 | 1,3 | 0,1,2 |
    0 	    1      2      3
```
- *2.* Take `bool visited[4] = {0}` to store which nodes are visited, which are not.
- *3.* Take `queue<int>` and push 1st node=0 on it
- *4.* Perform these until queue is not empty
```console
  Pop, Print queue top
  Iterate through all neighbours of top
  if(neighbour != visited)
		mark visited 
		push neighbour on queue
```
### Complexity
- **Time:** O(N+E)
  - N=No of vertices, E=No of edges
- **Space:** O(2N) = O(N)
  - N=Taking visited nodes. N-1=Considering all nodes are connected to node=0. Queue will have N-1 nodes.
### Code
```c++
void BFS(vector<int>& g, int startingNode) {
  bool visited[4]={false};
  queue<int> q;
  
  q.push(startingNode);           //Push 0
  visited[startingNode] = true;      //Mark 0 as visited

  while(q.empty() != 1){

    cout<<q.front();          //Print Front
    q.pop();

    for(auto i = g[u].begin(); i != g[u].end(); i++){             //Traverse popped Node's Neighbours

      //*i is entry in Adjacency list, 0 -> 1,3. Connected nodes
      if(visited[*i] == 0){                     //For all unvisited neighbours
        visited[*i] = true;                     //Mark retrieved node as visited.
        q.push(*i);                            //Push neighbour on queue.
      }//if
    }//for
  }//while
}

int main() {
  vector<int> v;               //Vector storing Adjacecy Matrix of graph

  v[0].push_back(1);      v[0].push_back(3);
  v[1].push_back(0);      v[1].push_back(2);      v[1].push_back(3);
  v[2].push_back(1);      v[2].push_back(3);
  v[3].push_back(0);      v[3].push_back(1);      v[3].push_back(2);

  cout<<"BFS Traversal\n";
  BFS(v, 0);
}

/*
Output:
# ./a.out
BFS Traversal
0 1 3 2
*/
```
