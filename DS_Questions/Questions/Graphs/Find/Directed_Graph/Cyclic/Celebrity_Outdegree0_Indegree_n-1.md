**Find the Celebrity**
- Approach-1 O(n<sup>2</sup>)
  - [Logic](#l1)
- Approach-2 O(n)
  - [Logic](#l)
  - [Complexity](#co)


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
<a name=l></a>
#### Logic //Asking only required questions
- From every `knows(a,b)` we derive information about a and b
```c
  a-->b     //a knows b means
  - a cannot be celebrity
  - b can be celebrity
  
  a   b     //a does not know b means
  - a can be celebrity
  - b cannnot be celebrity
```
- _1._ Find celebrity candidate.
  - Candidate should not know any one, but all should know candidate.
  - As we know there can be only celebrity.
  - if we found more than 1 celebrity candidate return -1.
```c
//1 is celebrity
  1 <-- 2
  /\
  |
  |--- 3

//No celebrity
  1 --> 2 --> 3 --> 4  

//No celebrity. Only 1 celebrity
  1 --> 2 --> 3    4
                   5
```
- _2._ if step-1 succeed, ie we found only 1 celebrity candidate.
  - Check for celebrity candidate
    - _a._ All people know him
    - _b._ He does not know anyone

<a name=co></a>
#### Complexity
- **Time:** O(n)
  - O(n): Find celebrity candidate
  - O(n): Check whether celebrity candidate is really a celebrity
- **Space:** O(1)

<a name=c></a>
#### Code
```cpp
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
        int celebCandidate = 0;
        
        for (int i=0;i<n;++i){            //1. Find celebrity candidate.
            if (i == celebCandidate)
                continue;
            if (knows(celebCandidate, i))   //1a. if present celebCandidate knows i, He cannot be celebrity
                celebCandidate = i;
        }
        
        if (isCelebrity(celebCandidate, n))   //2. Check whether candidate we selected is really a celebrity
            return celebCandidate;
        return -1;
    }
    bool isCelebrity(int celebCandidate, int n) {
        for (int i=0;i<n;++i) {                     //Iterate over all nodes
            if (i == celebCandidate)
                continue;

            //2a. if celebCandidate knows i. 
            // b. if i does not know celebCandidate.
            // in both above cases return false
            if (knows(celebCandidate, i) || (knows(i,celebCandidate) == false))
                return false;
        }
        return true;
    }
};

int main() {
    vecVecI v = {{1,1,0},{0,1,0},{1,1,1}};        //1
    //vecVecI v = {{1,0,1},{1,1,0},{0,1,1}};      //-1
    //vecVecI v = {{1,1,1},{1,1,0},{0,0,1}};      //-1
    //vecVecI v = {{1,0},{1,1}};      //0
    //vecVecI v = {{1,0},{0,1}};      //-1
    Solution s(v);
    cout << s.findCelebrity(2);
}
```
