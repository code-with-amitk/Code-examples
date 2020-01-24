/*
Graph to be created:
	[0] -10- [1] -20- [2]
	   \	  |	 /
	   40\ 	  |30  /50
		 [3] 
		 
		 
1. Adjacency-Matrix representation:
	   0   1   2   3
	0  0   10  0   40
	1  10  0   20  30
	2  0   20  0   50
	3  40  30  50  0
a. Storage Using Arrays
b. Storage Using vectors


2. Adjacency list representation:
	0 -> 1,3
	1 -> 0,2,3
	2 -> 1,3
	3 -> 0,1,2
a. Using Doubly LL
b. Using Singly LL

***********************Logic**************************
 a. Storing Graph in vector
 Instead of taking 5x5 matrix we can take arrays of 5 vectors. vector<int> v[5];

|	   	|	       |	     |		   |	         |
| | | | | |.....| | | | | |....| | | | | |...| | | | | |...| | | | | |...| 
|0 1 2 3 4	|0 1 2 3 4     |0 1 2 3 4    |0 1 2 3 4    |0 1 2 3 4    |
|v[0]	   	|v[1]	       |v[2]         |v[3]	   |v[4]	 |

  v[0] = {1}		//Shows connections of Node 0 to other nodes
  v[1] = {0,2,3,4}	//Shows connections of Node 1 to other nodes
  v[2] = {1,3}		//Shows connections of Node 2 to other nodes
  v[3] = {1,2,4}	//Shows connections of Node 3 to other nodes
  v[4] = {0,1,3}	//Shows connections of Node 4 to other nodes

 b. Filling the vector:
 - In undirected graph vertex is bidirectional ie:
 if 0 is connected to 1. 1 will be connected to 0.
	 -> For Node 0 (v[0]) Fill elements: 1,4	v(0).push_back(1), v(0).push_back(4)
	 -> For Node 1 (v[1]) Fill elements: 0,2,3,4	v(1).push_back(0), v(1).push_back(2), v(1).push_back(3), v(1).push_back(4)
	 -> For Node 2 (v[2]) Fill elements: 1,3	v(2).push_back(1), v(2).push_back(3)
	 -> For Node 3 (v[3]) Fill elements: 1,2,4	v(3).push_back(1), v(3).push_back(2), v(3).push_back(4)
	 -> For Node 4 (v[4]) Fill elements: 0,1,2,3	v(4).push_back(0), v(4).push_back(1), v(4).push_back(3)
	
++++++++++THING TO NOTE+++++++++++++++
if v(0).push_back(1) exists then v(1).push_back(0) will also exist
if v(0).push_back(4) exists then v(4).push_back(0) will also exist
++++++++++++++++++++++++++++++++++++++

 c. Displaying the Graph:
  - Traverse each vector and display items having entry 1.
******************************************************
 */
#include<iostream>
#include<vector>
using namespace std;

void display(vector <int> graphVector[], int vectorsize){

    for(int i = 0; i < vectorsize; i++){ 
        cout << "\n Adjacency list of vertex " << i << " "; 

    	for (auto x : graphVector[i]){
        	cout << "-> " << x; 
	}
        printf("\n"); 
    } 
}

int main(){
	vector<int> v[5];
	v[0].push_back(1);	v[0].push_back(4);
	v[1].push_back(0);	v[1].push_back(2);	v[1].push_back(3);	v[1].push_back(4);
	v[2].push_back(1);	v[2].push_back(3);
	v[3].push_back(1);	v[3].push_back(2);	v[3].push_back(4);
	v[4].push_back(0);	v[4].push_back(1);	v[4].push_back(3);
	cout<<"AM created\n";

	display(v, 5);
}
/*
# g++ create_using_adjacency_matrix.cpp --std=c++11
Output:
# ./a.out 
AM created

 Adjacency list of vertex 0 -> 1-> 4

 Adjacency list of vertex 1 -> 0-> 2-> 3-> 4

 Adjacency list of vertex 2 -> 1-> 3

 Adjacency list of vertex 3 -> 1-> 2-> 4

 Adjacency list of vertex 4 -> 0-> 1-> 3

*/
