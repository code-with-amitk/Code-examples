**Climbing Stairs**
- [Approach-1, Recursion](#a1)
- [Approach-2, DP](#a2)
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
### Approach-1  //Brute Force. [Recursion](/DS_Questions/Algorithms)   (2<sup>n</sup>)
- **Logic**
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
- **Complexity**
  - **Space:** O(1)
  - **Time:** [Recursion=O(2<sup>n</sup>)](/DS_Questions)
- **Code**
```c++
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
- **Logic**
  - Above recursion solution calculates same subproblem again and again. Repeative subproblems, hence DP.
  - *1.* Take a dp_array sized n+1, Each element stores ways to reach nth stair.
  - _2._ Take `dp_array[last]=0, dp_array[last-1]=1, dp_array[last-2]=2`
  - _3._ Note `dp_array[n] = dp_array[n+1] + dp_array[n+2]`. Possible ways/combinations to reach end from nth stair would be sum of ways to reach end from n+1 & n+2.
```c
Let stairs = 5.
dp_array (size=6)  | 0 | 0 | 0 | 0 | 0 | 0 |
          stair      0   1   2   3   4   5

dp_array[5] = 0          //Means When we are at last stair, nothing to do. No jumps required.

dp_array[4] = 1          //Means From 4th stair to 5th stair, There is only 1 way, ie taking 1 step
dp_array   | 0 | 0 | 0 | 0 | 1 | 0 |
  stair      0   1   2   3   4   5

dp_array[3] = 2          //Means From 3rd stair to 5th stair, There are 2 ways 
                         //   taking jump of 2 stairs. 3rd->5th
			 //or taking 1 step, 3rd->4th->5th
dp_array   | 0 | 0 | 0 | 2 | 1 | 0 |
  stair      0   1   2   3   4   5

dp_array[2] = 3 = dp_array[3]+dp_array[4]  //From Stair 2, possible ways will be sum of possible ways from stair=3 + Stair=4
dp_array   | 0 | 0 | 3 | 2 | 1 | 0 |
  stair      0   1   2   3   4   5

dp_array[1] = 5 = dp_array[2]+dp_array[3]  //From Stair 1, possible ways will be sum of possible ways from stair=2 + Stair=3
dp_array   | 0 | 5 | 3 | 2 | 1 | 0 |
  stair      0   1   2   3   4   5

dp_array[0] = 8 = dp_array[1]+dp_array[2]  //From Stair 0, possible ways will be sum of possible ways from stair=1 + Stair=2
dp_array   | 8 | 5 | 3 | 2 | 1 | 0 |
  stair      0   1   2   3   4   5
  
//Note this is reverse Fibonacci Series  
```
- **Complexity**
  - **Space:** O(n+1)
  - **Time:** O(n)
- **Code**
  - No need to take recursive Function, we can calculate steps without it.
```c++
class Solution {
public:
  int climbStairs (int n) {       //n:Number of stairs
    if(n==1)
      return 1;
    if(n==2)
      return 2;
    if(n==3)
      return 3;
	
    vector<int> a(n+1,0);
    a[n-1] = 1;
    a[n-2] = 2;
    int k = n-3;

    while(k>=0) {
      a[k] = a[k+1]+a[k+2];
      k--;
    }
    return a[0];
  }
};

int main(){
  Solution s;
  std::cout << s.climbStairs (5);
}
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
