/*      binary_maze.cpp

Situation/Task: Given a maze, where 1 represents blocked and 0 represents allowed paths.
- Find minimum distance needed to reach from S to D. Diagonal movement is not allowed

Example:
        0 1 2 3 4 5 6
     0  1 1 1 1 1 1 1
     1  0 0 S 0 0 0 0
     2  1 1 0 1 0 1 0
     3  1 1 0 1 0 D 0
     4  1 1 1 1 1 0 1
     
    0-0-S-0-0-0-0
        |   |   |
        0   0   0
        |   |   |
        0   0-D-0     

Source(S)=(1,2). Destination(D)=(3,5)
There are 2 paths from source to Destination.
Minimum Distance = 5

***********Logic(DFS, Stack)**************
a. Take visited[5][7], cost[5][7] matrices.
b. Start from point S(1,2). 
  - Check all adjacent 0 points, fill on stack.
C. while (stack!empty)
        pop top
        mark popped as visited.
        Check all adjacent 0 points of present node, Fill in stack.
        cost calculation:
                -> On cost matrix, check least cost on any of 4 adjacent cells
                        mycost=least_cost +1
d. Minimum distance(int, int):
   Take the point.
   Find least number present in my adjacent cells from cost array(except -1)


Complexities:
Space: 3*O(nm)+m(for stack)     //where nxm matrix is present (n=rows, m=colomns)
Time: 4*O(n)    //Because 4 operations are required to check adjacent nodes
******************************************
*/

#include <bits/stdc++.h>
using namespace std;
int ROW=5;
int COL=7;
typedef pair<int, int> mypair;
stack<mypair> s;
int cost[5][7];
bool visited[5][7];
int a[5][7];
int LeastCost=0;

//Checks Binary Maze
void checkAllAdjacentZero(int a[5][7], int x, int y){
        if(x>0 && (a[x-1][y]==48) && visited[x-1][y]==false)
                s.push(mypair(x-1,y));

        if(x<ROW && (a[x+1][y]==48) && visited[x+1][y]==false)
                s.push(mypair(x+1,y));

        if(y>0 && (a[x][y-1]==48) && visited[x][y-1]==false)
                s.push(mypair(x,y-1));

        if(y<COL && (a[x][y+1]==48) && visited[x][y+1]==false)
                s.push(mypair(x,y+1));
}

//Checks cost matrix
void findCost(int x, int y){
        //Calculate minimum cost around me, except -1
        if(x>0 && (cost[x-1][y] > LeastCost))
                LeastCost = cost[x-1][y];

        if(x<ROW && (cost[x+1][y] > LeastCost))
                LeastCost = cost[x+1][y];

        if(y>0 && cost[x][y-1] > LeastCost)
                LeastCost = cost[x][y-1];

        if(y<COL && cost[x][y+1] > LeastCost)
                LeastCost = cost[x][y+1];

        cost[x][y] = LeastCost+1;
        LeastCost=0;
}

//Print least cost near me and print
int findLeastCostNearMe(int x, int y){
        int maxi=INT_MAX;

        if(x>0 && ((cost[x-1][y] < maxi) && (cost[x-1][y] != -1)))
                maxi = cost[x-1][y];

        if(x<ROW && ((cost[x+1][y] < maxi) && (cost[x+1][y] != -1)))
                maxi = cost[x+1][y];

        if(y>0 && ((cost[x][y-1] < maxi) && (cost[x][y-1] != -1)))
                maxi = cost[x][y-1];

        if(y<COL && ((cost[x][y+1] < maxi) && cost[x][y+1] != -1))
                maxi = cost[x][y+1];

        return maxi;
}

int DFS(int a[5][7], int sx, int sy, int dx, int dy){

        for(int i=0;i<ROW;i++){
                for(int j=0;j<COL;j++){
                        visited[i][j]=0;
                        cost[i][j]=-1;
                }
        }

        s.push(mypair(sx,sy));                  //O(1)
        
        cout<<"On stack:\n";
        while(s.empty() != 1){                  //O(1)

                mypair k = s.top();     s.pop();

                cout<<k.first<<","<<k.second<<endl;

                visited[k.first][k.second] = true;

                findCost(k.first, k.second);            //4 operations

                checkAllAdjacentZero(a,k.first,k.second);       //4 operations
        }

        cout<<"Cost Matrix\n";
        for(int i=0;i<ROW;i++){
                for(int j=0;j<COL;j++){
                        cout<<cost[i][j]<<" ";
                }
                cout<<endl;
        }

        //Find the least cost value near me.
        return(findLeastCostNearMe(dx, dy));
}

int main(){
        int sx, sy, dx, dy, row, col;
        char c;

        cout<<"Enter row, col";
        cin>>row>>col;

        for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                        cin>>c;
                        a[i][j]=c;

                        if(c=='S'){sx=i;sy=j;}          //Starting point
                        if(c=='D'){dx=i; dy=j;}         //Destination point
                }
        }

        int af = DFS(a, sx, sy, dx, dy);
        cout<<"cost to reach = "<<af<<endl;

        return 0;
}

/*
# ./a.out 
Enter row, col5 7
1 1 1 1 1 1 1
0 0 S 0 0 0 0
1 1 0 1 0 1 0
1 1 0 1 0 D 0
1 1 1 1 1 0 1
On stack:
1,2
1,3
1,4
1,5
1,6
2,6
3,6
2,4
3,4
1,1
1,0
2,2
3,2
Cost Matrix
-1 -1 -1 -1 -1 -1 -1 
3 2 1 2 3 4 5 
-1 -1 2 -1 4 -1 6 
-1 -1 3 -1 5 -1 7 
-1 -1 -1 -1 -1 -1 -1 
cost to reach = 5
*/
