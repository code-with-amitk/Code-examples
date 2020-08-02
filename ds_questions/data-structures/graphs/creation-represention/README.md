## Graph Representation

### 1. Adjacency Matrix/Lookup table
- **What** Each cell keeps how two nodes are connected.
  - For unweighted graph values are `1` 
  - For weighted graph values are cost/weights.
- **Advantages**    
  - Easy to represent    
  - Removing an edge takes O(1) time.
  - Queries like whether there is an edge from vertex `u` to vertex `v` takes O(1)

### Example
```
        a --> c 
        |     |
        |     \/
        ----> d <-- b
```
#### 1. Adjacency Matrix
a=0, b=1, c=2, d=3
  
| |  | 0 | 1 | 2 | 3 |
| --- | --- | --- | --- | --- | --- |
| a-> | 0 | 0 | 1 | 1 |
| b-> | 0 | 0 | 0 | 1 |
| c-> | 0 | 0 | 0 | 1 |
| d-> | 0 | 0 | 0 | 0 |

#### 2. Adjacency List: 
           a(0) -> c(2) -> d(3)
           b(1) -> d(3)
           c(2) -> d(3)

Edge List:         
          v[0] |2|3|		//a(0) has c(2),d(3) as edges
          v[1] |3|
          v[2] |3|
*/
#include"graph_representations.h"

void simpleGraph::adjacencyList(){
        l[0].push_back(2); l[0].push_back(3);
        l[1].push_back(3);
        l[2].push_back(3);
        cout<<"Adjacency List created\n";
}

void simpleGraph::adjacencyMatrix(){
        for(int i=0;i<4;i++)
                for(int j=0;i<4;i++)
                        a[i][j]=0;

        a[0][2]=a[0][3]=a[1][3]=a[2][3]=1;
        cout<<"Adjacency Matrix created\n";
}

void simpleGraph::edgeList(){
        v[0].push_back(2); v[0].push_back(3);
        v[1].push_back(3); v[2].push_back(3);
        cout<<"Edge List created\n";
}

int main(){
        intf *obj = new simpleGraph();
        obj->adjacencyMatrix();
        obj->edgeList();
        obj->adjacencyList();
}
/*
# ./a.out 
Adjacency Matrix created
Edge List created
Adjacency List created
*/


***************graph_representations.h******************
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class intf{     //OOD Principle: Program Interface & override in derv class
protected:
        int a[4][4];
        vector<int> v[4];
        list<int> l[3];
public:
        virtual void adjacencyMatrix()=0;
        virtual void adjacencyList()=0;
        virtual void edgeList()=0;
};

class simpleGraph:public intf{
public:
        simpleGraph(){}
        void adjacencyMatrix();
        void adjacencyList();
        void edgeList();
};
