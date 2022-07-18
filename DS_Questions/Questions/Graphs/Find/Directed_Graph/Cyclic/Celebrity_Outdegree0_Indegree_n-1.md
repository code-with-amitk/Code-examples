**Find the Celebrity**
- Approach-1 O(n<sup>2</sup>)
  - [Logic](#l1)
- Approach-2


### [Find the Celebrity](https://leetcode.com/problems/find-the-celebrity/)
- Suppose you are at a party with n people labeled from 0 to n - 1 and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know the celebrity, but the celebrity does not know any of them.
- Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is ask questions like: "Hi, A. Do you know B?" to get information about whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).
- You are given a helper function bool knows(a, b) that tells you whether A knows B. Implement a function int findCelebrity(n). There will be exactly one celebrity if they are at the party.
- Return the celebrity's label if there is a celebrity at the party. If there is no celebrity, return -1.
```c
  1 <-- 0
  /\    /\
   |    |
   |--- 2
Input: graph = [[1,1,0],[0,1,0],[1,1,1]]
Output: 1
Explanation: There are three persons labeled with 0, 1 and 2. graph[i][j] = 1 means person i knows person j, otherwise graph[i][j] = 0 means person i does not know person j. The celebrity is the person labeled as 1 because both 0 and 2 know him but 1 does not know anybody.
```

### Approach-1
<a name=l1></a>
#### Logic
- Create directed graph by calling knows() function for every node.
- if during graph creation, 2 nodes exists whose outdegree=0, return -1. Only 1 celebrity can exist
- Traverse thru every node in graph, check celebrity node exists as neighbour for every node, if not return -1.

#### Code
```cpp
/* The knows API is defined for you.
      bool knows(int a, int b); */
#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
using vecVecI = vector<vector<int>>;

class Solution {
    vecVecI v;
    unordered_map<int, unordered_set<int>> graph;
    bool knows(int a, int b){
        if(v[a][b])
            return true;
        return false;
    }
public:
    Solution(vecVecI v):v(v){}
    int findCelebrity(int n) {
        int celeb = 0, celebCount = 0;
        //Create Graph
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                if (i==j)
                    continue;
                if (knows(i,j)){
                    unordered_set<int> s;
                    auto it = graph.find(i);
                    if (it != graph.end())
                        s = it->second;
                    s.insert(j);
                    graph[i] = s;
                }
            }
            auto itr = graph.find(i);
            if (itr == graph.end()){
                celeb = i;
                celebCount++;
            }
            if (celebCount>1)       //There cannot be more than 1 celebrity
                return -1;
        }

        //Check all other nodes know the celebrity node.
        for (auto [i,j]:graph){
            auto it = j.find(celeb);
            if (it == j.end())
                return -1;
        }
        return celeb;
    }
};

int main() {
    //vecVecI v = {{1,1,0},{0,1,0},{1,1,1}};        //1
    //vecVecI v = {{1,0,1},{1,1,0},{0,1,1}};      //-1
    //vecVecI v = {{1,1,1},{1,1,0},{0,0,1}};      //-1
    //vecVecI v = {{1,0},{1,1}};      //0
    vecVecI v = {{1,0},{0,1}};      //-1
    Solution s(v);
    cout << s.findCelebrity(2);
}
```

### Approach-2
#### Logic //Asking only required questions
```c
  a --> b
  |---> c
  
if (knows(a,b)) {   //a knows b
  - Means a cannot be celebrity
} 
else {              //a does not know b
  //b cannot be celebrity, since all people should know celebrity
}
```








