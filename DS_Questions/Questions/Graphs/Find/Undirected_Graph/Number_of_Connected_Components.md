[Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)
- **Approach-1, Depth 1st Search**
  - [Logic](#logic)
  - [Complexity](#comp)
  - Code
    - [C++](#cpp1)
    - [Rust](#rs1)
- **Approach-2, Disjoint Set Union**
  - [Logic](#log2)
  - Code
    - [C++](#cpp2)

## Number of connected Components
- [Connected Components?](/DS_Questions/Data_Structures/Graphs)
- Graph contains n verteces. Given and an array edges where `edges[i] = [ai, bi]` indicates that there is an edge between ai and bi in the graph.
- Return the number of connected components in the graph.
```c
Example-1
  0 -- 1    3 -- 4
       |
       2
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
  
Example-2:
  0 -- 1 -- 2 -- 3 -- 4
Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
```

### Approach-1, Depth 1st Search
<a name=logic></a>
#### Logic
- _1._ Create Adjacency List(2-D Vector) representing graph using input.
```c
Input: [[0,1],[1,2],[3,4]]

adjacenyList 
        |     |      |     |    |     |
        |1    |0,2   |1    |4   |3    |
index   |0    |1     |2    |3   |4    |
0 is connected to 1
1 is connected to 0,2
2 is connected to 1
3 is connected to 4
4 is connected to 3
```
- _2._ Take bool array called visited, to track number of nodes traversed. size=no of nodes
- _3._ Start from 1st node, traverse all nodes using DFS(stack) until any unvisited node is left.
- _4._ Perform DFS using stack
- _5._ For every disjoint graph, perform DFS. Number of seperate DFS performed=connected Components.

<a name=comp></a>
#### Complexity
> E = No of Edges, V = No of Vertices

**Time:** O(E+V)
  - O(E): Create adjaceny matrix
  - O(V): Visting all nodes using visited bool array

**Space** O(E+V). visited array=V, AdjacencyList=E

#### Code
<a name=cpp1></a>
**C++**
```cpp
class Solution {
    using vec = vector<int>;
    using vecB = vector<bool>;
    using vecVec = vector<vec>;
    stack<int> st;

    void dfs(vecVec& adjList, vecB& visited, int start) {           //4
        st.push(start);

        while (st.empty() != 1) {
            int top = st.top(); st.pop();
            visited[top] = true;

            //Find neighbour
            for (int i = 0; i < adjList[top].size(); ++i) {
                if (!visited[adjList[top][i]]) {
                    st.push(adjList[top][i]);
                }
            }
        }
    }
public:
    int countComponents(int n, vecVec& edges) {
        if (!n)
            return n;

        int connectedComp = 0;
        vecB visited(n, 0);                                 //2
        vecVec adjList(n);

        for (int i = 0; i < edges.size(); ++i) {            //1
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        //If any unvisited node, Perform DFS
        for (int i = 0; i < n; ++i) {                        //3
            if (!visited[i]) {
                dfs(adjList, visited, i);
                connectedComp++;                            //4
            }
        }
        return connectedComp;
    }
}
int main()
{
    Solution o;
    //vector<vector<int>> v = { {0, 1},{1, 2},{3, 4} };    cout << o.countComponents(5, v);
    vector<vector<int>> v = { {0,1},{1,2},{2,3},{3,4} };    cout << o.countComponents(5, v);
}
```

<a name=rs1></a>
**Rust**
```rs
struct Solution{
}

impl Solution {
    pub fn dfs (adj_list : &Vec<Vec<usize>>, mut visited : &mut Vec<usize>, start : usize) {
        if visited[start] == 1 {
            return;
        }
        visited[start] = 1;
        for &i in &adj_list[start] {
            Self::dfs ( &adj_list, &mut visited, i);
        }
    }

    pub fn count_components(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        if n == 0 {
            return n as i32;
        }
        let mut connected_comp:i32 = 0;
        let mut visited:Vec<usize> = vec![0; n as usize];
        let mut adj_list:Vec<Vec<usize>> = vec![Vec::with_capacity(n); n];

        for i in edges.iter() {
            let a = i[0] as usize;
            let b = i[1] as usize;
            adj_list[a].push(b);
            adj_list[b].push(a);
        }

        for i in 0..n {
            let a = i as usize;
            if visited[a] == 0 {
                Self::dfs (&adj_list, &mut visited, a);
                connected_comp += 1;
            }
        }
        connected_comp
    }
}

#[cfg(test)]                               //Automated tests run with `cargo test`
mod all_tests {
    use super::*;

    #[test]
    fn test1 () {
        let mut v: Vec<Vec<i32>> = Vec::with_capacity(3*2);     //row*col
        v.push(vec!(0,1));  v.push(vec!(1,2));  v.push(vec!(3,4));
        assert_eq!(2, Solution::count_components(5, v));

        let mut v1: Vec<Vec<i32>> = Vec::with_capacity(4*2);     //row*col
        v1.push(vec!(0,1));  v1.push(vec!(1,2));  v1.push(vec!(2,3)); v1.push(vec!(3,4));
        assert_eq!(1, Solution::count_components(5, v1));
    }
}

fn main(){

}
$ cargo test
```

### Approach-2, Disjoint Set Union
[Disjoint set Union and Algorithm to calculate connected components](/DS_Questions/Data_Structures/Graphs)
- Example in code
```c
  0 -- 1    3 -- 4
       |
       2
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
```
<a name=log2></a>
#### Logic
- _1._ Create set containing all nodes 
- _2._ Initially all nodes are in different set
- _3._ Unite connected nodes, since they are connected using edge
  - _3a._ Find node1 in set
  - _3b._ Find node2 in set
  - _3c._ node1,node2 are connected with edge. Update entry of node1 to point to node2 in Set. ie create node2 as representative of node1 in Set.

#### Code
<a name=cpp2></a>
**C++**
Steps are defined [here](/DS_Questions/Data_Structures/Graphs)
```cpp
class Solution {
public:
    int countComponents(int n, vecV& edges) {
        int numComponents = 0;
        vec Set(n);                         //1
        
        for (int i = 0; i < n; i++)         //2
          Set[i] = i;

        for (auto i : edges)                //3
            Union(Set, i[0], i[1]);

        //
        for (int i = 0; i < n; i++) {
            cout  << Set[i]<<" ";
            if (Set[i] == i)
                numComponents++;
        }

        return numComponents;
    }
    void Union(vec& Set, int node1, int node2) {
      int val1 = Find(Set, node1);  //3a

      int val2 = Find(Set, node2);  //3b

      Set[val1] = val2;             //3c
    }

    int Find(vec& Set, int node) {
      //if node is found in Set, return node
        while (Set[node] != node) {
            node = Set[node];
        }
//        int fa = val;           //Compressed Find
//        //compressed find
//        while (hashSet[fa] != fa) {
//            int temp = hashSet[fa];
//            hashSet[fa] = parent;
//            fa = temp;
//        }
      return node;
    }    
};


int main()
{
    Solution o;
    vector<vector<int>> v = { {0, 1},{1, 2},{3, 4} };    cout << o.countComponents(5, v); //2
}
```
