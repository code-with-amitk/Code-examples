**Find All Possible Recipes from Given Supplies**
- **Approach-1, Topological Sort**
  - [Logic](#l)
  - [Complexity](#c)
  - [Code](#co)
- **Multithreaded Approach**
  - [1. condition_variable = semaphore](#cv)
  - [2. std::atomic_flag = spinlock](#sl)
  - [3. mutex](#m)


### [Find All Possible Recipes from Given Supplies](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/)
- You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name `recipes[i]`, and you can create it if you have all the needed ingredients from `ingredients[i]`. Ingredients to a recipe may need to be created from other recipes, i.e., `ingredients[i]` may contain a string that is in recipes.
- You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.
- Return a list of all the recipes that you can create. You may return the answer in any order.
- Note that two recipes may contain each other in their ingredients.
```c
Example 1:
Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
  
Example 2:
Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
  
Example 3:
Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".
```

### Approach-1, Topological Sort
<a name=l></a>
#### Logic
- _1._ Create a graph of only recipies
```c
    recipes = {"bread","sandwich","burger"};
   ingredients = {{"yeast","flour"},{"bread","meat"},{"sandwich","meat","bread"}}; 
                |-------- flour         //supplies = {"yeast","flour","meat"};
                \/
    burger <-- bread <-- yeast
     /\ /\      \/
     |  |---- sandwitch
     |          /\
     Meat -------|

Create Graph of Reciepies(without supplies)
    burger <-- bread
     /\         \/
      |--------sandwitch
```
- _2._ Perform Topological sort on graph, note output in vector and return.

<a name=c></a>
#### Complexity
- **Time:** O(mn). //reciepes: n, ingredients: m
- **Space:** O(k + 2n). //supplies:k

<a name=co></a>
#### Code
**CPP**
```cpp
#include<iostream>
#include<vector>
#include<string>
#include<thread>
#include<mutex>
#include<atomic>
#include<condition_variable>
#include<unordered_map>
#include<queue>
#include<unordered_set>
using vecS = std::vector<std::string>;
using vecVecS = std::vector<vecS>;
using String = std::string;
using graph = std::unordered_map<String, std::unordered_set<String>>;

class Solution {
    graph g;
public:
    vecS findAllRecipes(vecS& recipes, vecVecS& ingredients, vecS& supplies) {
        vecS out;
        std::unordered_map<String, vecS> graph;
        std::unordered_set<String> s;
        for(auto&x : supplies)
            s.insert(x);            //store all the supplies in unordered set
		
        std::unordered_map<String,int> indegree;   //to store the indegree of all recipes
        for(auto&x : recipes)indegree[x] = 0;                      //initially take the indegree of all recipes to be 0
    
/*
    recipes = {"bread","sandwich","burger"};
   ingredients = {{"yeast","flour"},{"bread","meat"},{"sandwich","meat","bread"}}; 
                |-------- flour         //supplies = {"yeast","flour","meat"};
                \/
    burger <-- bread <-- yeast
     /\ /\      \/
     |  |---- sandwitch
     |          /\
     Meat -------|

Create Graph of Reciepies(without supplies)
    burger <-- bread
     /\         \/
      |--------sandwitch
*/
        //For every reciepe, check ingredients.
        //if ingredient is not a supply, That means it can be a recipe
        //And create a edge to reciepe from ingredient
        for(int i = 0; i < recipes.size(); i++){

            //Check all ingredients of this reciepe
            for(int j = 0; j < (int)ingredients[i].size(); j++){

                //Donot include any supplies in Graph
                if(s.find(ingredients[i][j]) == s.end()){
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }

/*
    indegree   |burger, 2|bread, 0|sandwitch, 1|
*/
        //KAHN'S ALGORITHM
        std::queue<String> q;
        for(auto&i : indegree){
            if(i.second == 0)
                q.push(i.first);
        }
/*
    burger <-- bread
     /\         \/
      |--------sandwitch
                                                out
    q |bread|                                   bread
    indegree   |burger, 1|sandwitch, 0|

    q |sandwitch|                               bread, sandwitch
    indegree   |burger, 0|

    q |burger|                                  bread, sandwitch, burger
*/
        while(!q.empty()){
            String front = q.front();
            q.pop();
            out.push_back(front);
            for(auto&i : graph[front]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }

        return out;
    }
};
int main() {
    //vecS recipes = {"bread","sandwich","burger"};
    //vecVecS ingredients = {{"yeast","flour"},{"bread","meat"},{"sandwich","meat","bread"}}; 
    //vecS supplies = {"yeast","flour","meat"};
    vecS recipes = {"bread"}; 
    vecVecS ingredients = {{"yeast","flour"}};
    vecS supplies = {"yeast","flour","corn"};
    Solution s;
    vecS out = s.findAllRecipes(recipes, ingredients, supplies);
    for (auto i:out)
        std::cout << i << ",";
}
```

### Multithreaded Approach
<a name=cv></a>
#### condition_variable
```cpp
#include<iostream>
#include<vector>
#include<string>
#include<thread>
#include<mutex>
#include<atomic>
#include<condition_variable>
#include<unordered_map>
#include<queue>
#include<unordered_set>
#include<atomic>
using vecS = std::vector<std::string>;
using vecVecS = std::vector<vecS>;
using String = std::string;
using graph = std::unordered_map<String, std::unordered_set<String>>;
bool bStart = false;
std::condition_variable cv;
std::mutex m;
using vecS = std::vector<std::string>;
using vecVecS = std::vector<vecS>;
using String = std::string;
using graph = std::unordered_map<String, std::unordered_set<String>>;
bool bStart = false;
std::condition_variable cv;

class Solution {
    graph g;
    std::unordered_map<String, vecS> graph;
    std::unordered_set<String> s;
    std::unordered_map<String,int> indegree;   //to store the indegree of all recipes
    vecS out;
public:
    vecS findAllRecipes(vecS& recipes, vecVecS& ingredients, vecS& supplies) {
         std::thread t1(&Solution::createGraph, this, ref(recipes), ref(ingredients), ref(supplies));
         std::thread t2(&Solution::kahnAlgo, this);
         t1.join();
         t2.join();
         return out;
    }

    void createGraph(vecS& recipes, vecVecS& ingredients, vecS& supplies) {
        std::mutex m;
        std::unique_lock<std::mutex> ulock(m);
        cv.wait(ulock, []{
            return (bStart==false);     //Wait condition should be true to go in
            }
        );

        for(auto&x : supplies)
            s.insert(x);            //store all the supplies in unordered set

        for(auto&x : recipes)       //initially take the indegree of all recipes to be 0
            indegree[x] = 0;

        //For every reciepe, check ingredients.
        //if ingredient is not a supply, That means it can be a recipe
        //And create a edge to reciepe from ingredient
        for(int i = 0; i < recipes.size(); i++){

            //Check all ingredients of this reciepe
            for(int j = 0; j < (int)ingredients[i].size(); j++){

                //Donot include any supplies in Graph
                if(s.find(ingredients[i][j]) == s.end()){
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }
        bStart = true;
        ulock.unlock();
        cv.notify_one();
    }

    //Perform topological sort on graph using KAHN'S ALGORITHM
    void kahnAlgo(){
        std::mutex m;
        std::unique_lock<std::mutex> ulock(m);
        cv.wait(ulock, []{
            return (bStart==true);     //Wait condition should be true to go in
            }
        );

    //indegree   |burger, 2|bread, 0|sandwitch, 1|
        std::queue<String> q;
        for(auto&i : indegree){
            if(i.second == 0)
                q.push(i.first);
        }

        while(!q.empty()){
            String front = q.front();
            q.pop();
            out.push_back(front);
            for(auto&i : graph[front]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        bStart = false;
        ulock.unlock();
        cv.notify_one();
    }
};
```

<a name=sl></a>
#### spinlock
```cpp
#include<iostream>
#include<vector>
#include<string>
#include<thread>
#include<mutex>
#include<atomic>
#include<condition_variable>
#include<unordered_map>
#include<queue>
#include<unordered_set>
#include<atomic>
using vecS = std::vector<std::string>;
using vecVecS = std::vector<vecS>;
using String = std::string;
using graph = std::unordered_map<String, std::unordered_set<String>>;
bool bStart = false;

class Spinlock{
  std::atomic_flag flag;
public:
  Spinlock(): flag(ATOMIC_FLAG_INIT)        //flag=false
  {}

  void lock(){
    while( flag.test_and_set() );           //flag=true
  }

  void unlock(){
    flag.clear();                          //flag=false
  }
};

class Solution {
    graph g;
    std::unordered_map<String, vecS> graph;
    std::unordered_set<String> s;
    std::unordered_map<String,int> indegree;   //to store the indegree of all recipes
    vecS out;
    Spinlock spinlock;
public:
    vecS findAllRecipes(vecS& recipes, vecVecS& ingredients, vecS& supplies) {
         std::thread t1(&Solution::createGraph, this, ref(recipes), ref(ingredients), ref(supplies));
         std::thread t2(&Solution::kahnAlgo, this);
         t1.join();
         t2.join();
         return out;
    }

    void createGraph(vecS& recipes, vecVecS& ingredients, vecS& supplies) {
        spinlock.lock();
        
        for(auto&x : supplies)
            s.insert(x);            //store all the supplies in unordered set

        for(auto&x : recipes)       //initially take the indegree of all recipes to be 0
            indegree[x] = 0;

        //For every reciepe, check ingredients.
        //if ingredient is not a supply, That means it can be a recipe
        //And create a edge to reciepe from ingredient
        for(int i = 0; i < recipes.size(); i++){

            //Check all ingredients of this reciepe
            for(int j = 0; j < (int)ingredients[i].size(); j++){

                //Donot include any supplies in Graph
                if(s.find(ingredients[i][j]) == s.end()){
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }
        spinlock.unlock();
    }

    //Perform topological sort on graph using KAHN'S ALGORITHM
    void kahnAlgo(){
        spinlock.lock();

    //indegree   |burger, 2|bread, 0|sandwitch, 1|
        std::queue<String> q;
        for(auto&i : indegree){
            if(i.second == 0)
                q.push(i.first);
        }

        while(!q.empty()){
            String front = q.front();
            q.pop();
            out.push_back(front);
            for(auto&i : graph[front]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        spinlock.unlock();
    }
};
```

<a name=m></a>
#### 3. mutex
```cpp
using vecS = std::vector<std::string>;
using vecVecS = std::vector<vecS>;
using String = std::string;
using graph = std::unordered_map<String, std::unordered_set<String>>;
bool bStart = false;

class os_implementaion{
public:
    class Mutex{
    protected:
        std::mutex m;       //In Win10 its CRITICAL_SECTION
    };
};
class os_mutex:private os_implementaion::Mutex{
public:
    os_mutex(){
        //Initialize mutex
    }
    ~os_mutex(){
        //Destroy mutex     pthread_mutex_destroy()
    }
    void lock(){
        m.lock();       //EnterCriticalSection()
    }
    void unlock(){
        m.unlock();
    }
};
class WorkerThreadPool {
    os_mutex m_mutex;
    bool m_blocked;
public:
    WorkerThreadPool(){}
    void lock(){
        m_mutex.lock();
        m_blocked = true;
    }
    void unlock(){
        m_mutex.unlock();
        m_blocked = false;
    }
};

class Solution {
    WorkerThreadPool w;
    graph g;
    std::unordered_map<String, vecS> graph;
    std::unordered_set<String> s;
    std::unordered_map<String,int> indegree;   //to store the indegree of all recipes
    vecS out;
public:
    vecS findAllRecipes(vecS& recipes, vecVecS& ingredients, vecS& supplies) {
         std::thread t1(&Solution::createGraph, this, ref(recipes), ref(ingredients), ref(supplies));
         std::thread t2(&Solution::kahnAlgo, this);
         t1.join();
         t2.join();
         return out;
    }

    void createGraph(vecS& recipes, vecVecS& ingredients, vecS& supplies) {
        w.lock();
        
        for(auto&x : supplies)
            s.insert(x);            //store all the supplies in unordered set

        for(auto&x : recipes)       //initially take the indegree of all recipes to be 0
            indegree[x] = 0;

        //For every reciepe, check ingredients.
        //if ingredient is not a supply, That means it can be a recipe
        //And create a edge to reciepe from ingredient
        for(int i = 0; i < recipes.size(); i++){

            //Check all ingredients of this reciepe
            for(int j = 0; j < (int)ingredients[i].size(); j++){

                //Donot include any supplies in Graph
                if(s.find(ingredients[i][j]) == s.end()){
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }
        w.unlock();
    }

    //Perform topological sort on graph using KAHN'S ALGORITHM
    void kahnAlgo(){
        w.lock();

    //indegree   |burger, 2|bread, 0|sandwitch, 1|
        std::queue<String> q;
        for(auto&i : indegree){
            if(i.second == 0)
                q.push(i.first);
        }

        while(!q.empty()){
            String front = q.front();
            q.pop();
            out.push_back(front);
            for(auto&i : graph[front]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        w.unlock();
    }
};
```
