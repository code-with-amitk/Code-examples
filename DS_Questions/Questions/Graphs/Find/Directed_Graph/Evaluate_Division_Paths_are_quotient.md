- **Evaluate Division**
  - [Logic](#l)
  - [Code](#co)

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
  | a  | b,2 | b | c,3 | a,0.5| c | b,1/3 |
  |    |-----|   |------------|   |-------|
  |          |                |           |
```
- _3._ Traverse DFS, to all neighbours from src, 
  - if dst is found return path costs
  - else 
    - insert `unordered_set<string> neighbours`
    - Check neigbhour of neighbour
```
Find a/z (src=a, dst=z)

 a --> b --> c
 |
 |------> e --> f
\/
d

check()                 //At node a
if (z is neighbour of a)
  return path_cost

//Confirmed z is not neighbour of a
for (all neighbours of a)
    unordered_set.insert(neighbour)
    check(this_neighbour)           //check_this_neighbour_is_dst?
    
check()                 //Node b
if (z is neighbour)
  no
for (all neighbours of b)
    unordered_set.insert(c)
    check(c)                 //check_this_neighbour_is_dst?

check()                 //Node c
if (z is neighbour)
  no
for (all neighbours of c)
  //No neighbours of c
return 0;  
```
<a name=co></a>
### Code
```cpp
using namespace std;
using VecVecString = vector<vector<string>>;
using VecDouble = vector<double>;
using umStringDouble = unordered_map<string, double>;
using usString = unordered_set<string>;

class Solution {
public:
    VecDouble calcEquation(VecVecString equations, VecDouble& values, VecVecString queries) {

        unordered_map<string, umStringDouble> m;
        vector<double> out;

        //2. Create Directed Graph using Hash-map
        for (int i = 0; i < values.size(); ++i) {
            m[equations[i][0]].insert(make_pair(equations[i][1], values[i]));
            if (values[i] != 0)
                m[equations[i][1]].insert(make_pair(equations[i][0], 1 / values[i]));
        }

        for (auto i : queries) {
            usString s;
            double tmp = check(i[0], i[1], m, s);
            if (tmp) 
                out.push_back(tmp);
            else 
                out.push_back(-1);
        }
        return out;
    }

private:
    double check(string src, string dst,
        unordered_map<string, umStringDouble>& m,
        usString& s)
    {
        //Found key
        if (m[src].find(dst) != m[src].end()) 
            return m[src][dst];

        //Key not found
        for (auto i : m[src]) {
            if (s.find(i.first) == s.end()) {
                s.insert(i.first);
                double tmp = check(i.first, dst, m, s);

                if (tmp) 
                    return i.second * tmp;
            }
        }
        return 0;
    }
};
```
