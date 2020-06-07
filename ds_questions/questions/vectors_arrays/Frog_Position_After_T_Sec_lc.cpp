/*      Frog_Position_After_T_Sec.cpp

Situation/Task: Find probability to reach target node.

                 1
               / \  \
              2  3   7
             / \  \
            4   6  5

Given a undirected tree consisting of n vertices numbered from 1 to n. A frog starts jumping from the vertex 1. 
In one second, the frog jumps from its current vertex to another unvisited vertex if they are directly connected. 
The frog can not jump back to a visited vertex. In case the frog can jump to several vertices it jumps randomly 
to one of them with the same probability, otherwise, when the frog can not jump to any unvisited vertex it jumps 
forever on the same vertex. 

The edges of the undirected tree are given in the array edges, where edges[i] = [fromi, toi] means that exists an 
edge connecting directly the vertices fromi and toi.

Return the probability that after t seconds the frog is on the vertex target.

Example1:
Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target = 4
Output: 0.16666666666666666 
Explanation: The frog starts at vertex 1, jumping with 1/3 probability to the vertex 2 after second 1 and then jumping 
with 1/2 probability to vertex 4 after second 2. Thus the probability for the frog is on the vertex 4 after 2 seconds 
is 1/3 * 1/2 = 1/6 = 0.16666666666666666. 

Example2:
Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target = 7
Output: 0.3333333333333333
Explanation: The frog starts at vertex 1, jumping with 1/3 = 0.3333333333333333 probability to the vertex 7 after second 1.

Example3:
Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 20, target = 6
Output: 0.16666666666666666


********************Logic**********************
- Take a array of same size of vector.
  - This array stores number-of-children of a node.
        |3|2|1|0|0|0|0| 
         0 1 2 3 4 5 6          
        //Node-1(index=0)has 3 children
        //Node-2(index=1)has 2 children
        //Node-3(index=2)has 1 child

- 1st-Traversal:        O(n)
  - populate above array
- 2nd-Reverse-Traversal
  - Find parent of target node          O(n)
        -> As parent is found, find number of children of parent, Probabilty=1.0/no-of-children
  - Make present-parent as child and find parent of this child,
        -> As parent is found calculare probabilty as above.

Complexities:
Space: 2O(n)
Time: O(n)+O(n) = 2O(n)
***********************************************
*/

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

typedef pair<int,float> mypair;

//n=no of elements, edges=vector array, t=time, target=Target element
//double frogPosition(int n, vector<vector<int>>& edges, int t, int target){
void frogPosition(int n, vector<vector<int>>& edges, int t, int target){

        int ar[n] = {0}, p, c, parent;
        double prob=0;

        //Finding children of a node
        for(int i=0; i<edges.size(); i++){
                p = edges[i][0];
                c = edges[i][1];

                ar[p-1] += 1;
                /*if(target == c){
                        cout<<"Parent of "<<target<<" is "<<p<<endl;
                }*/
        }

        for(int i=0;i<n;i++){
                cout<<"Node["<<i+1<<"] has "<<ar[i]<<"children\n";
        }

        for(int i=edges.size()-1; i>=0; i--){
                p = edges[i][0];
                c = edges[i][1];

                if(target == c){
                        prob = 1.0/ar[p-1];
                        parent = p;
                        t--;
                }

                if(parent == c){
                        prob = prob*(1.0/ar[p-1]);
                        parent = p;
                        t--;
                }
                if(t<0){
                        prob=0;
                        break;
                }
        }
        cout<<"\nProbabiltity to reach "<<target<<" from Node[1]="<<prob<<endl;
}

int main(){
        vector<vector<int>> edges = {   //data1
                {1,2},
                {1,3},
                {1,7},
                {2,4},
                {2,6},
                {3,5}
        };
//      frogPosition(7,edges,2,4);
//      frogPosition(7,edges,1,7);
        frogPosition(7,edges,20,6);
}
/*
# ./a.out
Node[1] has 3children
Node[2] has 2children
Node[3] has 1children
Node[4] has 0children
Node[5] has 0children
Node[6] has 0children
Node[7] has 0children

Probabiltity to reach 6 from Node[1]=0.166667
*/
