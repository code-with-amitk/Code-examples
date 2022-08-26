**Is Graph Bipartite?**
- Approach, DFS
  - [Logic (Coloring the Nodes)](#l)
  - [Complexity](#co)
  - [Code](#c)


### Bipartite / Bigraph?
- A bipartite(bigraph) is a graph whose nodes can be divided into two disjoint and independent sets {U},{V} such that:
  - Every edge present in orignal graph connects atleast 1 vertex in {U} to one in {V}
- Graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
- undirected graph, no self edges, no parallel edges, can have disjoint sets
- Example
```c
 0 ------- 1		//This is bigraph
 |         |
 3 ------- 2
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3},
            so that every edge present in original graph connects atleaset 1 node in both sets.
  
  1     3   Set-1
  | \ / |   
===========  
  | / \ |
  0     2   Set-2
```

### Approach-1, DFS + Coloring
<a name=l></a>
#### Logic (coloring)
> All same colored nodes are in same set. if 1 node comes in set which is of different color then we cannot seperate nodes into 2 distinct sets.
- _1._ Input is already in form of Adjacency list we need not to create seperate graph for it.
- _2._ Color starting node as Red, then color neighbours as opposite color.
- _3._ Reach neighbour and repeat step-1.
- _4._ if we reach any node and find that its neighbour is of same color (return false).

<img src=bipartitegraph.jpg width=300/>

<a name=co></a>
#### Complexity
- **Time:** O(V+E). V=vertices=nodes. E=neighbours=edges. [How time comp is O(V+E)](/DS_Questions/Algorithms/Traversals/DFS/Graphs/)
- **Space:** O(V). [How space comp is O(V)](/DS_Questions/Algorithms/Traversals/DFS/Graphs)

<a name=c></a>
#### Code
```cpp
using vecI = std::vector<int>;
using vecVecI = std::vector<vecI>;
using vecB = std::vector<bool>;

class Solution {
public:
    bool isBipartite(vecVecI& graph) {
        int size = graph.size();
		
        vecI color(size, -1);	//-1: No color, 0:Red, 1:Blue

	//Iterate through all nodes even if we have disconnected graph, 
        for (int i = 0; i < size; ++i) {
		
	  //if node is not colored
	  //bitwise xor of equal numbers of 0
          if (!(color[i]^-1)) {
			
	    //if node is uncolored
	    //Color it Red & Push on stack. DFS
            stack<int> st;
            color[i] = 0;
            st.push(i);

            while (!st.empty()) {
              int u = st.top();	st.pop();

	      //Traverse All neighbours of node
              for (int neigh : graph[u]) {
					
		//if neighbor is uncolored, Color neighbor opposite of present Node's color & push on stack
		//bitwise xor of equal numbers of 0
                if (!(color[neigh]^-1)) {
                
		  //if color[u]==1, Bitwise with 1 becomes = 0
		  //if color[u]==0, Bitwise with 1 becomes = 1
		  //Toggle 1st bit
                  color[neigh] = color[u] ^ 1;
                  st.push(neigh);
                } else if (!(color[neigh]^color[u])) { //if neighbour's color and my color are same return false
                  return false;
                }
              }
            }
          }
        }
        return true;
    }
};
```
