**Find All Paths From Source to Target**
- [Approach-1. BackTracking](#a1)
  - [Logic](#l1)
  - [Code](#c1)
  - [Complexity](#co1)

## [Find All Paths From Source to Target Node](https://leetcode.com/problems/all-paths-from-source-to-target/)
- Given a [directed acyclic graph (DAG)](/DS_Questions/Data_Structures/Graphs#dag) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
- `graph[i]` is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node `graph[i][j]`).
```c
Example-1
Input: graph = [[1,2],[3],[3],[]].
| 1,2 | 3 | 3 | {} |. Node 0 has 2 neighbours(1,2). Node 1 has 1 neighbour(3), Node 2 has 1 neighbour(3).
  0    1   2    3 
  
  0 ---> 1 ---> 3
  |             /\
  |----> 2 -----|

Output: [[0,1,3],[0,2,3]] 
There are two paths to reach dst 3 from src=0: 0 -> 1 -> 3 and 0 -> 2 -> 3.
```

<a name=a1></a>
### Approach-1, [BackTracking](/DS_Questions/Algorithms/Backtracking)
<a name=l1></a>
#### Logic
- At any given node, we reach each neighbor node recursively until we reach the target or there is no more node to hop on.
- Once we reach dst, we create vector and pushback in out.
- Later on, when recursive function falls back we start another exploration on another neighbouring node.
<a name=c1></a>
#### Code
```cpp
#include<iostream>
#include<vector>
using namespace std;
using Vec = vector<int>;
using VecVec = vector<Vec>;
class Solution {

public:
    void find_all_paths(int start, int dst, Vec& path, VecVec& out, VecVec& graph){
        int neighbour = -1;
        Vec start_path = path;
        
        //Iterate through all neighbours of a node
        for (int i=0;i<graph[start].size();++i){
            path = start_path;
            neighbour = graph[start][i];
            if (neighbour == dst){                //4. if neighbour of present node=dst, We found 1 path
                Vec temp = path;
                temp.push_back(dst);
                out.push_back(temp);              //Push path into output
            } else{
                path.push_back(neighbour);        //5. Else Traverse to neighbour of present node
                find_all_paths(neighbour, dst, path, out, graph);
            }
        }
    }
    VecVec allPathsSourceTarget(VecVec& graph) {    //Input graph is itself AdjacencyList
        int start=0, dst = graph.size()-1;          //1. Take start=0, dst node=size-1
        VecVec out;
        Vec path;
        path.push_back(start);                      //2. Start exploration from start node.
        find_all_paths(start, dst, path, out, graph);
        return out;
    }
};
int main() {
    Solution s;
    VecVec input = {{1,2},{3},{3},{}};
    //VecVec input = {{4,3,1},{3,2,4},{3},{4},{}};
    s.allPathsSourceTarget(input);
}
```
<a name=co1></a>
#### Complexity
- if n = no of nodes in graph.
- Max Possible Paths: At maximum, then there can be (2<sup>n-1</sup> - 1) paths from src to dst.
```c
Nodes   Graph                     Paths
  2     0 --> 1                 2^(2-1)-1 = 1
  
  3     0 ---> 1 --> 2          2^(3-1)-1 = 3
        |------------/\
        
        |-------------|
        |             \/
  4     0 ---> 1 ---> 2         2^(4-1)-1 = 7
        |     \/      /\
        |----> 3 ------|
```
- **Time Complexity:** (2<sup>n-1</sup> - 1)`*`n = 2<sup>N</sup>N. Since there can be path from every nth node to end.
- **Space Complexity:** (2<sup>n-1</sup> - 1)`*`n = 2<sup>N</sup>N
  - Since there can be max (2<sup>n-1</sup> - 1) paths from src to end. We need to store these many paths in vector.
  - N recursions will take n space. Since its consumes function stack.
