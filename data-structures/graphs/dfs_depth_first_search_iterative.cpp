/*
Depth First Traversal: Reach to deepest node, instead of reaching all neighbors.
        
        1 ---->  0  ----> 3
        /\      |/\       |
        |       | |       |
        |       | |       \/
        2 <-----   ------ 4

dfs will print: 0 2 1 3 4

We can store graph using 2 methods
Method-1: Adjacency Matrix:
         0   1   2   3   4
        ------------------
      0 |0   0   1   0   1
      1 |1   0   0   0   0
      2 |0   1   0   0   0
      3 |0   0   0   0   1
      4 |1   0   0   0   0

Method-2: Adjacency-list        //USED HERE
        0 -> 2,4
        1 -> 0,
        2 -> 1
        3 -> 4
        4 -> 1

***********************Logic**********************
1. Creating Adjacency List: Take vector array to store Adjacency list.
vector<int> v[5];

2. For Depth 1st Search
 - Take a stack. push startingnode on stack.
 - Take a boolen array for marking visitedNodes.
 - Perform these operations until stack is empty
        - Pop top of stack. store value in temp
        - if this node(temp) is not visited, 
                Mark node as visited in boolen array.
                Print to node's value
        - Iterate through Adjacency List(AL) of popped node(temp).
                if value retrieved from AL not visited:
                        Push retrived value from AL to stack.

Note:
 Stack is filled using AL of popped node.
**************************************************

*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void dfs(vector<int> v[], bool visitedNodes[], int startingNode){

        stack<int> s;
        int temp;

        s.push(startingNode);

        while (!s.empty()){

                temp = s.top();         s.pop();

                if (visitedNodes[temp] == false){
                        cout << temp << " ";
                        visitedNodes[temp] = true;
                }

                for (auto i = v[temp].begin(); i != v[temp].end(); ++i){
                        if (visitedNodes[*i] == false)
                                s.push(*i);
                }
        }

}

int main()
{
        vector<int> v[5];
        v[0].push_back(3);      v[0].push_back(2);              //v[0]={3,2}
        v[1].push_back(0);                                      //v[1]={0}
        v[2].push_back(1);                                      //v[2]={1}
        v[3].push_back(4);                                      //v[3]={4}
        v[4].push_back(0);                                      //v[4]={0}

        bool visitedNodes[5] = {0};

        int startingNode = 0;                           //Let's start traversal from node=0

        cout << "Following is Depth First Traversal\n";
        dfs(v, visitedNodes, startingNode);

        return 0;
}

/*
Output:
# ./a.out 
Following is Depth First Traversal
0 2 1 3 4
*/
