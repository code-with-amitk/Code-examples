- **Evaluate Division**
  - [Logic](#l)
  - [Code](#co)

### [Self Video Explanation](https://youtu.be/_RLSvZaM7mY)

### [Evaluate Division](https://leetcode.com/problems/evaluate-division/)
- Input Given 2 arrays equations and values, where `values[i]` represent the `equation Ai / Bi = values[i]`.
- Given some queries, `queries[j] = [Cj, Dj]` where we need to find Cj / Dj = ?.
- Return the answers to all queries. If a single answer cannot be determined, return -1.0.
- Examples:
```c
Example 1:
Input: equations = [["a","b"],["b","c"]], 
       values    =  [2.0,3.0], 
       queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
```

<a name=l></a>
### Logic
- _1._ Equation can be represented as graph node and values as cost between them
```c
  a ---2.0----> b -----3.0----> c
  /\           | /\             |
  |---1/2.0----| |------1/3.0---|
  
costs:  a->b = 6.0.   b->a = 1/6,   b->c = 3.0    c->b = 1/3
Queries:
  a->c = 2x3 = 6
  b->a = .5
  a->e = -1 //non-existant
  a->a = 1
  x->x = -1 //non-existant
```
- _2._ Store the directed graph `unordered_map<string, unordered_map<string, double>>`
```c
a can reach b in cost=2
b can reach c and a in costs 3,.05
c can reach b in cost 1/3
  | key      |key             |key        |
  |    |-----|   |------------|   |-------|
  | a  | b,2 | b | c,3 | a,1/2| c | b,1/3 |
  |    |-----|   |------------|   |-------|
  |          |                |           |
```
- _3._ Iterate over queries, if src=target(insert 1.0), src or target not found (insert -1.0), else dfs
```c
  vector<double> out;
  for (auto i : quries) {
    src = i[0], target = i[1];
    if (src not found || target not found)
      out.push_back(-1.0);
    else if (src == target)
      out.push_back(1.0);
    else 
      Perform DFS
  }
```
- _4._ Perform Depth 1st search
  - _a._ Take `unordered_set<string> visited`, Make current node as visited.
  - _b._ On every call of dfs()
    - if target is directly connected return cost
    - else
      - check all neighbours of current node
        - if neighbour is in visited list
          - continue to next neighbour
        - dfs(product = product`*`cost)
```c
  dfs (curr, target, product) {
    visited.insert(curr);             //a
    if target_directly_connected      //b
      return product * cost;
    else {
      for (all neighbours of current node) {
        if (neighbour_is_in_visited_list)   //Check next neighbour
          continue;
        dfs (product*cost)
      }
    }
    
    visited.remove(curr);         //Remove current node from visited
    return ret;
  }//dfs
``` 
<a name=co></a>
### Code
```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<map>
using namespace std;
using VecVecString = vector<vector<string>>;
using VecDouble = vector<double>;
using umStringDouble = unordered_map<string, double>;
using usString = unordered_set<string>;

class Solution {
    unordered_map<string, umStringDouble> umGraph;
public:
    VecDouble calcEquation(VecVecString equations, VecDouble& values, VecVecString queries) {
        vector<double> out;

        //Create Graph
        for (int i = 0; i < equations.size(); ++i) {
            umGraph[equations[i][0]].insert(make_pair(equations[i][1], values[i]));
            if (values[i] != 0)
                umGraph[equations[i][1]].insert(make_pair(equations[i][0], 1 / values[i]));
        }

        for (auto i : queries) {
            //i[0]:src, i[1]:dst
            auto it = umGraph.find(i[0]);
            auto it1 = umGraph.find(i[1]);
            if (it == umGraph.end() || it1 == umGraph.end())
                out.push_back(-1.0);
            else if (i[0] == i[1])
                out.push_back(1.0);
            else {
                unordered_set<string> visited;
                out.push_back(dfs(i[0], i[1], 1.0, visited));
            }
        }
        return out;
    }
private:
    double dfs(string curr, string target, double pro, unordered_set<string> visited) {
        visited.insert(curr);
        double ret = -1.0;

        //Find node is graph
        auto it = umGraph.find(curr);

        //Find neighbour of current node in graph
        auto it1 = it->second.find(target);

        //if target is directly connected, return cost
        if (it1 != it->second.end())
            ret = pro * it1->second;
        else {
            //Check all neighbours of curr node
            for (auto i : umGraph[curr]) {
                string nextNode = i.first;
                auto itr = visited.find(nextNode);
                if (itr != visited.end())
                    continue;
                ret = dfs(nextNode, target, pro * i.second, visited);
                if (ret != -1.0)
                    break;
            }
        }
        
        visited.erase(curr);
        return ret;
    }
};
int main() {
    Solution s;
    //VecVecString equ = { {"a","b"},{"b","c"} };
    //VecDouble val = { 2.0,3.0 };
    //VecVecString que = { {"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"} };

    VecVecString equ = { {"x1","x2"},{"x2","x3"}, {"x3", "x4"}, {"x4","x5"}};
    VecDouble val = { 3.0,4.0,5.0,6.0 };
    VecVecString que = { {"x1","x5"},{"x5","x2"},{"x2","x4"},{"x2","x2"},{"x2","x9"}, {"x9","x9"}};
    VecDouble out;
    out = s.calcEquation(equ, val, que);
}```
