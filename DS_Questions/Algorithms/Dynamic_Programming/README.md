**Dynamic Programming / Caching**
- [Types of Caching/DP](#t)
- [2. Identify whether this problem is DP?](#identify)
- [3. Methods in DP?](#methods)
- [4. Examples](#examples)
  - [4.1 Fibonacci Series](#fibonacci)
    - [4.1.1 Recursion](#recur)
    - [4.1.2 Dynamic Programming](#dp)
      - [4.1.2.1 C++](#cpp)
      - [4.1.2.2 Rust](#rust)
    - [4.1.3 Directly finding nth fibonacci series number](direct)



## Dynamic Programming / Tabular Method / Caching
- Storing values which can be used later.
- **When to apply**
  - In recursive algorithm, when subproblems is calculated again & again we cache those for future recursive calls. Eg: Fibonacci series
  - You have to study recursive algorithm and cache prev results into array or hash.
  - Recursion Time Complexity: Exponential, DP Time Complexity: Polynomial

<a name=t></a>
### Types of Caching/Methods in DP
**1. Top Down / Memoization:** Think how we can divide the problem for case N into subproblems. 
```c
let cache = {}
function memoization {
  if (n does not exist in cache)
    cache[n] = n + x;
  return cache[n];
}
```
- **2. Bottom up / Tabulation:** Steps
  - Think how to solve the problem for a simple case(eg: list with 1 element). 
  - Think how to solve the problem for 2 elements, then for 4 elements, and so on
  - Save solutions of subproblems(in array/hash) and refer it before recalculation.
    - If solved, return the saved value, saving further computation at this level

<a name="identify"></a>
### 2. Identify whether this problem is DP?
- **A. Overlapping Subproblems**
  - When recursive algorithm for the problem solves the same subproblems over and over again, we say that the optimization problem has overlapping subproblems.
- **B. Optimal Substructure**


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
