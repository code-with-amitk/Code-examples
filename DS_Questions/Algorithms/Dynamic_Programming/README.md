**Dynamic Programming / Caching**
- [Identifying DP Problem / DP Problem Characteristics](#i)
- [Types of Caching/DP](#t)
  - [1. Top Down](#td)
  - [2. Bottom Up](#bu)
- [DP Template](#tem)
- [4. Examples](#examples)
  - [4.1 Fibonacci Series](#fibonacci)
    - [4.1.1 Recursion](#recur)
    - [4.1.2 Dynamic Programming](#dp)
      - [4.1.2.1 C++](#cpp)
      - [4.1.2.2 Rust](#rust)
    - [4.1.3 Directly finding nth fibonacci series number](direct)


## [Dynamic Programming / Tabular Method / Caching LC Explore Cards](https://leetcode.com/explore/featured/card/dynamic-programming/630/an-introduction-to-dynamic-programming/4034/)
<a name=i></a>
### Identifying DP Problem / DP Characteristics
- _1. Overlapping subproblems:_ When subproblems is calculated again & again(overlapping subproblems) we cache those for future recursive calls. Eg: Fibonacci series
- _2. Optimal Substructure:_ an optimal solution can be formed from optimal solutions
- Problem statement: min/max/longest/largest
  - Minimum cost, Maximum profit, No of ways, longest, Is it possible to reach a certain point etc

<a name=t></a>
### Methods in DP

||Top Down / Memoization|Bottom Up / Tabulation|
|---|---|---|
|Uses| Recursion | Iteration |
|Faster| less | more than top down |
|Easier| more easier than BU||
|Implemented using|Recursive Function + HashMap|nested for loop + Array|

<a name=td></a>
#### 1. Top Down / Memoization 
Remembering/caching the results instead of calculating them again. 
```c
///// Pseudocode example Fibnacci series//////
memo = hashmap
Function F(integer i):
    if i is 0 or 1: 
        return i
    if i doesn't exist in memo:
        memo[i] = F(i - 1) + F(i - 2)
    return memo[i]
```
<a name=bu></a>
#### 2. Bottom up / Tabulation
Solution is built from base case and upward (uses Recursion).
```c
Example: Fibonacci sequence.
1. Start with base case, F(0) = 0, F(1) = 1
2. Calculate f(2) using f(0),f(1). Calculate f(3) using f(2),f(1) and so on

F = array of length (n + 1)
F[0] = 0
F[1] = 1
for i from 2 to n:
    F[i] = F[i - 1] + F[i - 2]
```

<a name=tem></a>
### DP Template
> Eg: [Climbing Stairs](/DS_Questions/Questions/Permutation_Combination/Climb_Stairs_1or2_steps.md)
- _1. Define State:_ Variable(s) which can define a scenario. Eg: state=number of ways to jump to ith stair
- _2. Function to return State:_ Write a function or data structure that will compute answer to the problem for every given state
```c
int dp(i) {     //For climbing stairs
  //returns number of ways to climb to ith step
}
```
- _3. Relationship between different states:_ 
  - Number of ways to reach 30th stair = No of ways to reach 28th stair + No of ways to reach 29th stair
```c
  dp(i) = dp(i-1) + dp(i-2);
```
- _4. Base case:_ Ask yourself, Number of ways to reach 1st step=1, No of ways to reach 2nd step = 2.
```c
start ___  ___
      1st  2nd
```
- _5. Cache/Memoize:_ Memorize the repeatative steps that are calculated and return result from cache.

<a name="examples"></a>
## 4. Examples
<a name="fibonacci"></a>
### 4.1 Fibonacci Series //Just write recursion stack on copy
<a name="recur"></a>
#### 4.1.1 Recursion
```c
1 2 3 5 8 13 21 34
0 1 2 3 4 5  6  7

int f(int n){
  if (n==0) return 0;
  if (n==1) return 1;
  return f(n-1) + f(n-2);
}
int main() {
 cout << f(7);
}
                       f(7)
                        ret f6+f5
                   f6
                    ret f5+f4
              f5
               ret f4+f3  -------> f3 again calculated
          f4
           ret f3+f2    ---------> This f2 is again calculated
      f3
       ret f2+f1------------> This f1 is again calculated
   f2
    ret f1+f0
 f1           f0
  ret 1        ret 0
```
<a name="dp"></a>
#### 4.1.2 Dynamic Programming
<a name="cpp"></a>
##### 4.1.2.1 C++ Code
```c
int a[n+1];
class Solution {
public:
    int f(int n, vector<int>& dp) {
        if (dp[n] != -1)
            return dp[n];
        dp[n] = f(n-1, dp) + f(n-2, dp);
        return dp[n];        
    }
    
    int fib(int n) {
        if (n==0)
            return 0;
        if (n==1 || n==2)
            return 1;
        
        vector<int> dp(n+1, -1);
        dp[0] = 0, dp[1] = dp[2] = 1;
        
        return f(n, dp);    
    }
};
```
<a name="rust"></a>
##### 4.1.2.2 Rust Code
```rust
impl Solution {
    pub fn fib(n: i32) -> i32 {
        if n == 0 {
            return 0;
        }
        if n == 1 || n == 2 {
            return 1;
        }

        let k:usize = n as usize;
        let mut dp = vec![-1; k+1];
        dp[0 as usize] = 0; dp[1 as usize] = 1;
        dp[2 as usize] = 1;   

        pub fn fun(k: usize, dp:&mut Vec<i32>) -> i32{
            if dp[k] != -1 {
                return dp[k];
            }

            dp[k] = fun(k-1,dp) + fun(k-2,dp);
            dp[k]
        }

        fun(k, &mut dp)        
    }
}
```
<a name=direct></a>
#### 4.1.3 Directly finding nth fibonacci series number
<img src=nth-fibonacci.JPG width=400/>
