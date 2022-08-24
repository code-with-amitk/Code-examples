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
- _1._ Create graph[Hashmap of hashmap](/DS_Questions/Data_Structures/Graphs/Directed_Undirected#hmhm), visited array
- _2._ Pass graph, visited to dfs() function. 
    - Inside dfs(), 
    - _a._ Insert node into visited
    - _b._ if b is directly connected to a?
      - _c1._ Yes. return cost
      - _c2._ No. Check all connected neighbours of neighbour to be equal to dst.
        - _c21._ if neighbour is already visited(ie present in visited array). Do nothing
        - _c22._ jump to unvisited neighbour.
    - _d._ When all neighbours of present node are searched, delete present node from visited.

#### Pseudo code
```c
  a ---2.0----> b -----3.0----> c
  /\           | /\             |
  |---1/2.0----| |------1/3.0---|

main() {
  unordered_map<char, unordered_map<char, double>> umGraph;   //stores graph  //1
  unordered_set<char> visited;                                                //2
  dfs (a, c, cost);
}

double dfs (char src, char dst, double pro, umGraph, visited) {               //3
  visited.insert(src);                                                          //a
  auto it = umGraph.find(src);                                                  //b
  auto it1 = it->second.find(dst);                                              //c
  if (it1 != it->second.end())                                                  //c1
    return cost;
  else {                                                                        //c2
    for (all neighbours(k) of neighbour) {
      if (k is in visited array)                                                //c21
        continue;
      dfs (src=neighbour(k), dst, pro, graph, visited);                         //c22
    }
  }
  visited.erase(src);                                                           //d
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

