//	different_ways_to_create_graph.cpp

/*
	UNDIRECTED-GRAPH_REPRESENTATION
	
	[0] -10- [1] -20- [2]
	   \	  |	 /
	   50\ 	  |30  /40
		 [3] 
1a. Using Arrays		//Adjacency-Matrix= O(n2)
	   0   1   2   3
	0  0   10  0   50
	1  10  0   20  30
	2  0   20  0   40
	3  50  30  40  0

2a. Using vectors		//Edge List
v[0] | 0,10 | 3,50 |
v[1] | 0,10 | 2,20 | 3,30 |
v[2] | 1,20 | 3,40 |
v[3] | 0,50 | 1,30 | 2,40 |

3a. Using Singly LL		//Adjacency List = O(V+E) V-vertices,E-edges
3b. Using Array of Doubly LL
list<mypair> dll[4];
See Memory layout:
https://stackoverflow.com/questions/46320526/array-of-linked-lists-in-c-initializing-and-inserting
*/


#include<iostream>
#include<vector>
#include<forward_list>
#include<list>
using namespace std;

#ifdef UNDIRECTED_GRAPH
typedef pair<int,int> mypair;
int main(){

#ifdef arrays
	int g[4][4] = {{0,10,0,50},
		       {10,0,20,30},
		       {0,20,0,40},
		       {50,30,40,0},
		      };
#endif
	
#ifdef vector
	vector<mypair> v[4];		//VECTOR
	v[0].push_back(mypair(0,10));	v[0].push_back(mypair(3,50));
#endif

#ifdef forward_list		//Singly LL
	forward_list<mypair> fl[4];
	fl[0].push_front(mypair(0,10));		fl[0].push_front(mypair(3,50));
#endif	

#ifdef doubly_ll
	list<mypair> dll[4];	//Array of Doubly LL
	dll[0].push_back(mypair(0,10));		dll[0].push_back(mypair(3,50));
#endif	
}
#endif



/*	DIRECTED_WEIGHTED_GRAPH_REPRESENTATION

	[1] --1---> [2]
	|
	1
	|
	\/
	[3]----1---->[4]

1: vector-of-vector/2-D-vector	|src,dst,dis|		//Adjacency-List
	|     |     |     |
	|1,2,1|1,3,1|3,4,1|
	|v[0] |v[1] |v[2] |
*/

int main(){
#ifdef VECTOR-OF-VECTOR	
	vector<vector<int>> v = {{1,2,1},{1,3,1},{3,4,1}};
	
	//v.size=3
        for(int i = 0; i < v.size(); i++)		//Traversing elements
                for(int j = 0; j < v[j].size(); j++)
                        cout<<v[i][j]<<" ";		//1 2 1 1 3 1 3 4 1 
#endif	
}
