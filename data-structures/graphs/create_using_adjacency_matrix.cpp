/*
Graph to be created:
	0---1
	|  /|\
	| / | 2
	|/  |/
	4---3

Adjacency Matrix:
	 0   1   2   3   4
	------------------
      0	|0   1   0   0   1	<-row1
      1	|1   0   1   1   1	<-row2
      2	|0   1   0   1   0	<-row3
      3	|0   1   1   0   1	<-row4
      4	|1   1   0   1   0	<-row5

***********************Logic**************************
 a. Storing Graph in vector
 Instead of taking 5x5 matrix we can take arrays of 5 vectors. vector<int> v[5];

|	   	|	       |	     |		   |	         |
| | | | | |.....| | | | | |....| | | | | |...| | | | | |...| | | | | |...| 
|0 1 2 3 4	|0 1 2 3 4     |0 1 2 3 4    |0 1 2 3 4    |0 1 2 3 4    |
|v[0]	   	|v[1]	       |v[2]         |v[3]	   |v[4]	 |

  v[0] = Shows connections of Node 0 to other nodes
  v[1] = Shows connections of Node 1 to other nodes
  v[2] = Shows connections of Node 2 to other nodes
  v[3] = Shows connections of Node 3 to other nodes
  v[4] = Shows connections of Node 4 to other nodes

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
