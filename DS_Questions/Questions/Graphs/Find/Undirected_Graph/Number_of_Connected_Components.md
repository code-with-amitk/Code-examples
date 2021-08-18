[Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)
- **Approach-1, Depth 1st Search**
  - [Logic](#logic)
  - [Complexity](#comp)
  - Code
    - [C++](#cpp1)
    - [Rust](#rs1)
- **Approach-2, Disjoint Set Union**
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
[What is Disjoint set Union and Algorithm to calculate connected components](/DS_Questions/Data_Structures/Graphs)
- Example in code
```c
  0 -- 1    3 -- 4
       |
       2
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
```
#### Code
<a name=cpp2></a>
**C++**
Steps are defined [here](/DS_Questions/Data_Structures/Graphs)
```cpp
class Solution {
public:

    //node1 and node2 are always connected, We need to combine them
    int combine(vector<int> &set, vector<int> &size, int node1, int node2) {
        node1 = find(set, node1);
        node2 = find(set, node2);
        
        if (size[node1] > size[node2]) {
          size[node1] += size[node2];
          set[node2] = node1;
        } else {
          size[node2] += size[node1];
          set[node1] = node2;
        }
        return 1;
    }
    
    int countComponents(int n, vecVec& edges) {
      vector<int> set(n);
      
      for (int i = 0; i < n; i++) {             //Step-1
        set[i] = i;
      }
      
      int components = n;
      for (int i = 0; i < edges.size(); i++) {                  //Step-2
        if (edges[i][0] != edges[i][1])
          components -= combine(set, size, edges[i][0], edges[i][1]);
      }      
    }
};


int main()
{
    Solution o;
    vector<vector<int>> v = { {0, 1},{1, 2},{3, 4} };    cout << o.countComponents(5, v); //2
}
```
