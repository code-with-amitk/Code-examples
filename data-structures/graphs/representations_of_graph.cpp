/*
	different_ways_to_create_graph.cpp

Graph to be created:
	[0] -10- [1] -20- [2]
	   \	  |	 /
	   50\ 	  |30  /40
		 [3] 
		 
		 
***************1. Adjacency-Matrix******************
1a. Using Arrays
	   0   1   2   3
	0  0   10  0   50
	1  10  0   20  30
	2  0   20  0   40
	3  50  30  40  0
*************************************************	

***************2. Adjacency-List******************
2a. Using vectors
v[0] | 0,10 | 3,50 |
v[1] | 0,10 | 2,20 | 3,30 |
v[2] | 1,20 | 3,40 |
v[3] | 0,50 | 1,30 | 2,40 |

2b. Using Singly LL

2c. Using Doubly LL
*************************************************

 */
#include<iostream>
#include<vector>
#include<forward_list>
#include<list>
using namespace std;

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
	vector<mypair> v[4];
	v[0].push_back(mypair(0,10));	v[0].push_back(mypair(3,50));
#endif

#ifdef forward_list		//Singly LL
	forward_list<mypair> fl[4];
	fl[0].push_front(mypair(0,10));		fl[0].push_front(mypair(3,50));
#endif	

#ifdef doubly_ll
	list<mypair> dll[4];	//Doubly LL
	dll[0].push_back(mypair(0,10));		dll[0].push_back(mypair(3,50));
#endif	
}
