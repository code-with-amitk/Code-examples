/*	breadth_1st_traversal_iterative.cpp		//Amit Read Algo. Whole day is spent on this.

Task: Print nodes of graph in BFS fashion, where starting node is 0
Graph: 	0 -- 1 -- 2		//4 Nodes, 5 edges
	 \  |	/
	    3
        
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
     
  c. Perform these until queue is not empty
     - u = Pop_top_of_queue
     - print u
     - Iterate through all neighbours of u
     	if(neighbour ! visited)
		mark visited 
		push neighbour on queue
		
Complexity:O(V+E)		
V=No of vertices,  E=No of edges
*******************************************
https://www.geeksforgeeks.org/bfs-using-stl-competitive-coding/      
 */

void BFS(vector <int> g[], int startingNode){
        bool visited[4]={false};

        queue<int> q;
        int u;

        q.push(startingNode);           //Push 0

        visited[startingNode] = true;      //Mark 0 as visited

        while(q.empty() != 1){

                u = q.front();       q.pop();
               cout<< u << " ";

                for(auto i = g[u].begin(); i != g[u].end(); i++){ //Traverse popped Node's Neighbours

                        //*i is entry in Adjacency list, 0 -> 1,3. Connected nodes

                        if(visited[*i] == 0){                     //For all unvisited neighbours

                                visited[*i] = true;               //Mark retrieved node as visited.

                                q.push(*i);                            //Push neighbour on queue.

                        }
                }
        }
}

int main()
{
        vector<int> v[4];               //Vector storing Adjacecy Matrix of graph

        v[0].push_back(1);      v[0].push_back(3);
        v[1].push_back(0);      v[1].push_back(2);      v[1].push_back(3);
        v[2].push_back(1);      v[2].push_back(3);
        v[3].push_back(0);      v[3].push_back(1);      v[3].push_back(2);

        cout<<"BFS Traversal\n";
        BFS(v, 0);

        return 0;
}

/*
Output:
# ./a.out
BFS Traversal
0 1 3 2
*/
