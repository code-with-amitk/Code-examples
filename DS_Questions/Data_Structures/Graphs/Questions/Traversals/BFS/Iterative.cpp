/*	breadth_1st_traversal_iterative.cpp		//Amit Read Algo. Whole day is spent on this.

Task: Print nodes of graph in BFS fashion, where starting node is 0

        
Method-1: Adjacency Matrix:
	 0  1  2  3
	------------
     0 | 0  1  0  1
     1 | 1  0  1  1
     2 | 0  1  0  1
     3 | 1  1  1  0
	
Method-2: Adjacency-list	//USED HERE
	0 -> 1,3
	1 -> 0,2,3
	2 -> 1,3
	3 -> 0,1,2

****************Logic********************
1. Create graph using vector<int>

2. Breadth 1st Traversal(starting from Node=0):
  a. Take a array to store which nodes in graph are visited,This is mandatory step. else we will revolve in circles.
  	visited[4] = {0}
	
  b. Take a queue.
     - Push starting node on queue.	q.push(0)
     

		
Complexity
*******************************************
https://www.geeksforgeeks.org/bfs-using-stl-competitive-coding/      
 */


