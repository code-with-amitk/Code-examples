**Directed, Undirected**
- **Undirected Unweighted**
  - [2-D vector](#u1)
- **Directed/1Way**
  - **Unweighted**
    - [2-D Vector (Only for numeral nodes)](#d1)
    - [HashMap of Linked List](#d2)
  -  **Weighted**
     - [Hashmap of Hashmap](#d3)

## Undirected/Digraph/Bidirectional Unweighted
Both sides know each other.  `[1] -- [2] -- [3]`
<a name=u1></a>
##### 1a. 2-D vector
```cpp

   1 -- 0 -- 3 -- 4
        |
        2  
  vector<vector<int>> al[5];
  al[0].push_back(1); al[0].push_back(2); al[0].push_back(3); => 1,2,3    //node0
  al[1].push_back(0);                                                     //node1
  al[2].push_back(0);                                                     //node2
  al[3].push_back(0); al[3].push_back(4);                                 //node3
  al[4].push_back(3);                                                     //node4
  
      |     |   |   |     |   |
      |1,2  |0  |0  |0,4  |3  |
index  0     1   2   3     4
```


## 2. Directed Graph/1 Way
1 side know other but viceversa not true. `[a] --> [b] --> [c]`. Ex: a. Fans knows celebrity but other side does not. b.  On Facebook the graph of friends is undirected.

### Directed Unweighted
<a name=d1></a>
#### 2a. 2-D Vector (Only for numeral nodes)
```c
  1 --> 2 --> 3
        |
       \/
       0  
vector<vector<int>> a[4];
a[0].push_back(-1);
a[1].push_back(1);
a[2].push_back(0); a[2].push_back(3);
a[3].push_back(-1);

//This will not work if alphabetical nodes are there in graph. Will not work.
  a --> b --> c 
        |
	\/
	d
```
<a name=d2></a>
#### 2b. HashMap of Linked List
```c
0 ---> 1 ---> 3
|             /\    //Graph
-----> 2 -----|

      |->1->2            -->3 
|     |  |        |     |        |
| 0 | /\ | 1 | \/ | 2 | /\ | 3 | |    unordered_map<int, list<int>>
|        |      |
                |->3
 
                           //from to
vector<vector<int>> v = { {0, 1},{0, 2},{1, 3},{2, 3}};
unordered_map<int, list<int>> um;

for (int i = 0; i < v.size(); ++i) {
  list<int> l;
  int from = v[i][0];
  int to = v[i][1];
  
  if (um.find(from) != um.end()){	//Node exists
  	l = it->second;
  } else {			//Node need to be created
  	um[from] = l;
  }
  l.push_back(to);
}
```

### Directed Weighted Cyclic graph. Paths have cost.
<a name=d3></a>
#### 2c. Hashmap of Hashmap
```c
  a ---2.0----> b -----3.0----> c
  /\           | /\             |
  |---1/2.0----| |------1/3.0---|
  
costs:  a->b = 6.0.   b->a = 1/6,   b->c = 3.0    c->b = 1/3

             //src                 //dst,  cost
unordered_map<string, unordered_map<string, double>>

src    dst cost
a       b  2.0
b       c  3.0
b       a  1/2
c       b  1/3

  | key      |key             |key        |
  |    |-----|   |------------|   |-------|
  | a  | b,2 | b | c,3 | a,1/2| c | b,1/3 |
  |    |-----|   |------------|   |-------|
  |          |                |           |

vector<vector<string>> eq = {{"a","b"},{"b","c"}};
vector<double> cost = { 2.0,3.0 };
unordered_map<string, unordered_map<string, double>> umGraph;

//Create Graph
for (int i = 0; i < eq.size(); ++i) {
  umGraph[eq[i][0]].insert(make_pair(eq[i][1], cost[i]));
  if (cost[i] != 0)
    umGraph[eq[i][1]].insert(make_pair(eq[i][0], 1 / cost[i]));
}
```
