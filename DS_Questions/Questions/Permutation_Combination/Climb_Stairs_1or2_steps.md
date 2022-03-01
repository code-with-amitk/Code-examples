**Climbing Stairs**
- [Approach-1, Recursion. TLE. 2<sup>n</sup>](#a1)
- [Approach-2, DP. Time Complexity=O(n)](#a2)
- [Approach-3, Direct nth Fibancci number](#a3)


### [Climbing Stairs / Jumping Stairs](https://leetcode.com/problems/climbing-stairs/)
- There are n stairs, a person standing at the bottom wants to reach the top. 
- The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top.
<img src=https://media.geeksforgeeks.org/wp-content/uploads/nth-stair.png width=200/>

```c
Example-1:
Stairs = 2
ways:2 [1,1] [2]

Example-2:
Stairs = 3
ways:3. [1,1,1] [1,2] [2,1] 

Example-3:
Stairs = 4
Ways: 5. 1111, 211, 221, 212, 122
```
<a name=a1></a>
### Approach-1  //Brute Force. [Recursion](/DS_Questions/Algorithms)
#### Logic
- We take all possible step combinations i.e. 1 and 2, at every stair.
- if we reach last stair(return 1)
- if we reach beyond last stair(retun 0)
```c
                0        //From stair-0 we can go to 1 or 2
	     /     \
	   1        2     //From stair-1 we can go to 2 or 3, From stair-2 we can go to 3 or 4.
	  / \      / \
	 2   3     3   4   //so on. Calculating same subproblem again and again.
	/\   /\    /\  /\
       3 4   4 5   4 5 5 6
```
#### Complexity
- **Space:** O(1)
- **Time:** [Recursion=O(2<sup>n</sup>)](/DS_Questions)
#### Code
```cpp
class Solution {
    int stairs;
public:
    int climb(int i){
        if (i > stairs)                         //if we reach beyond number of stairs,return 0
            return 0;
        if (i == stairs)                        //if we reach last stair return 1
            return 1;
        return climb(i+1) + climb(i+2);         //We can only climb 1 or 2 steps
    }
    int climbStairs(int n) {
        stairs = n;
        return climb(0);
    }
};
int main(){
  int a=4;
  cout << climbStairs (4);
}
```
<a name=a2></a>
### Approach-2  //[Dynamic Programming](/DS_Questions/Algorithms)   //O(n)
#### Logic
- Above recursion solution calculates same subproblem again and again. Repeative subproblems, hence DP.
- We will follow [DP Template](/DS_Questions/Algorithms/Dynamic_Programming/README.md#tem)
- **[Steps using DP Template](/DS_Questions/Algorithms/Dynamic_Programming/README.md#tem)**
  - _1. Define State:_ Here state=number of ways to jump to ith stair
  - _2. Function to return State:_ Write a function or data structure that will compute answer to the problem for every given state
```c
int dp(i) {     //For climbing stairs
  //returns number of ways to climb to ith step
}
```
  - _3. Relationship between different states:_ Number of ways to reach 30th stair = No of ways to reach 28th stair + No of ways to reach 29th stair
```c
  dp(i) = dp(i-1) + dp(i-2);
```
  - _4. Base case:_ Ask yourself, Number of ways to reach 1st step=1, No of ways to reach 2nd step = 2.
```c
start ___  ___
      1st  2nd
```
  - _5. Cache/Memoize:_ Memorize the repeatative steps that are calculated and return result from cache.

#### Complexity
- **Space:** O(n+1)
- **Time:** O(n)
#### Code
```cpp
class Solution {
    unordered_map<int,int> um;
public:
    int dp(int i){			//Function returning state. state is number of ways to reach ith stair
        if (um.find(i) == um.end())
            um[i] = dp(i-1) + dp(i-2);

        return um[i];
    }
    
    int climbStairs(int n) {
        um[1] = 1;                  //No of ways to reach step-1 is 1
        um[2] = 2;                  //No of ways to reach step-2 are 2
        return dp(n);
    }
};
```
<a name=a3></a>
### Approach-3  //[Directly finding nth fibonacci series number](/DS_Questions/Algorithms/Dynamic_Programming)
- **Code**
```c++
class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double fibn = pow((1+sqrt5)/2,n+1) - pow((1-sqrt5)/2,n+1);
        return (int)(fibn/sqrt5);
    }
};
```
