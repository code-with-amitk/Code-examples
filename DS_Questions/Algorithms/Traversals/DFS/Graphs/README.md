**DFS**
- [Complexity](#co)
- [1. Recursive (Stack not used)](#rec)
- [2. Iterative (Stack used)](#itr)


## DFS
- Reach to deepest node from source vertex, until it reaches a vertex where it cannot go any deeper.
- When this happens, DFS will ‘backtrack’ and explore another unvisited neighbor(s), if any

<a name=co></a>
### Complexity
|Representation|Time|Space|
|---|---|---|
|Adjacency List|O(V+E) {V=vertices, E=edges}|O(V)|
|Adjacency Matrix|O(V<sup>2</sup>)|O(V)|

- **Why O(V+E)?**
  - Because for every node, we create stack(which contains neighbours of node). Neighbours are traversed using stack.
  - Then for new node, Stack is only create for unvisited nodes.
- **Why O(V)?** Stack to store vertices

<a name=rec></a>
### 1. Recursive DFS
**Question:** Find cost of reaching from node=a to node=b in Directed,Cyclic Graph.
#### Logic
- _1._ Create graph [Adjacency List](/DS_Questions/Data_Structures/Graphs#r), take visited array. Let DFS from node=0
- _2._ Pass graph, visited to dfs(start=0, graph, visited) function.
    - Inside dfs(), print node
    - _a._ Insert node into visited
    - _b._ Traverse to unvisited neighbours of node.
#### Code
```cpp
       0 --- 1 -- 2 --- 4
         \    |   /
           \  |  /
              3
   
#include<iostream>
#include<vector>
using vecI = std::vector<int>;
using vecB = std::vector<bool>;
using vecVecI = std::vector<vecI>;

class Solution {
public:
    void dfs(int node, vecI* graph, vecB& visited) {
        visited[node] = true;                             //4. Mark present node as visited & print
        std::cout << node << ",";
        
        //5. Traverse to unvisited neighbours
        for (int i=0; i<graph[node].size(); ++i){
            if (visited[graph[node][i]] == false)
                dfs(graph[node][i], graph, visited);
        }
    }
};

int main() {
    Solution s;
    
    vecI graph[5];                  //1. Create Adjacency list Graph
    graph[0].push_back(1);
    graph[0].push_back(3);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(0);
    graph[3].push_back(1);
    graph[3].push_back(2);
    graph[4].push_back(2);

    vecB visited(5, false);       //2. Take visited array for 5 nodes
    
    s.dfs(0, graph, visited);       //3. Start dfs from node=0
}
}
```

<a name=itr></a>
### 2. Iterative DFS
Reach to deepest node, instead of reaching all neighbors.
```c
        0 -- 1 -- 2     //Start=3, end=2
         \   |   /
           \ | /
             3

dfs=2,1,0,3  or  2,3   or   2,1,3
```
#### Logic
- *1.* Store the graph nodes in Adjacency List.
```c
  vector<int> v[4];
  v[0].push_back(1); v[0].push_back(3)
  v[1].push_back(0); v[1].push_back(2); v[1].push_back(3);
  v[2].push_back(1); v[2].push_back(3);
  v[3].push_back(0); v[3].push_back(1); v[3].push_back(2);
  
  | 1,3 | 0,2,3 | 1,3 | 0,1,2 |
     0      1      2      3
```
- *2.* Take following datastructures:
  - `bool visited[4]` //Storing all visited nodes
  - Stack for DFS Traversal.
  - Perform following operations until stack is empty
```c
 Push 1st element on stack
 Pop, Print top.
 Mark this node as visited.
 Find unvisited neighbours of this node. //Iterate through vector
   push_on_stack
   break;
```
#### Code
```c++
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void dfs(vector<int>& g[], int startingNode) {
  bool visited[4] = {0};
  stack<int> s;
  int u;

  s.push(startingNode);

  while (!s.empty()){           //empty() return bool

    u = s.top();         
    s.pop();

    visited[u] = true;
    cout<<u<<" ";

    for (auto i = g[u].begin(); i != g[u].end(); ++i){
      if (visited[*i] == false){
        s.push(*i);
        break;
      }
    }
  }//while()
}

int main() {
  vector<int> v[4];             //4 rows, variables cols

  v[0].push_back(1); v[0].push_back(3);                                 //v[0]={1,3}
  v[1].push_back(0);v[1].push_back(2); v[1].push_back(3);              //v[1]={0,2,3}
  v[2].push_back(1); v[2].push_back(3);                                 //v[2]={1,3}
  v[3].push_back(0); v[3].push_back(1); v[3].push_back(2);              //v[3]={0,1,2}

  int startingNode = 2;            //Let's start traversal from node=2
  cout << "Depth First Traversal:\n";
  dfs(v, startingNode);
}

/*
# ./a.out 
Starting node=2
Depth first Traversal
2 1 0 3
*/
```

