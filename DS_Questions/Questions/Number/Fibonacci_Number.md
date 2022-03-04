**Fibonacci Number**
- [Approach-1, Recursion, TLE](#a1)
- **Approach-2, Dynamic Programming. O(n)**
  - [Logic](#l)
  - Code
    - [CPP](#cpp)
    - [Rust](#rs)
  - [Complexity](#co)
- [Approach-3, Directly finding nth fibonacci number](#a3)

### Fibonacci Number
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, 
starting from 0 and 1. That is,
```c
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
```

<a name=a1></a>
### Approach-1, Recursion
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

<a name=a2></a>
### Approach-2 / Dynamic Programming
- [Why DP is suitable here?](/DS_Questions/Algorithms/Dynamic_Programming/README.md#i)
<a name=l></a>
#### Logic
We will follow [DP Template](/DS_Questions/Algorithms/Dynamic_Programming/README.md#tem)
- _1. Define State:_ Deriving nth number
- _2. Function to return state:_ 
  - ie Function to return nth Fib number.
  - Recurrence relation to transition between states.
```c
int dp(int i) {
  dp(i) = dp(i-1) + dp(i-2);
}
```
- _3. Base case:_
```c
int dp(int i) {
  if (i==0 || i==1)
    return i;
}
```
- _4. Cache/Memoize:_ Use vector, provides better cache locality.

#### Code
<a name=cpp></a>
##### CPP
```c
class Solution {
public:
    int dp(vector<int>& vecFibNumber, int i){

        if (vecFibNumber[i] == -1)
            vecFibNumber[i] = dp(vecFibNumber, i-1) + dp(vecFibNumber, i-2);

        return vecFibNumber[i];
        
    }
    int fib(int n) {
        if (n ==0 || n==1)
            return n;
        
        vector<int> vecFibNumber(n+1, -1);
        vecFibNumber[0] = 0;
        vecFibNumber[1] = 1;
        
        return dp(vecFibNumber, n);
    }
};
```
<a name=rs></a>
##### Rust
```rs
impl Solution {
    pub fn dp (vecFibNumber: &mut Vec<i32>, i: usize) -> i32 {
        
        if vecFibNumber[i] == -1 {
            vecFibNumber[i] = Self::dp(vecFibNumber, i-1) + Self::dp(vecFibNumber, i-2);
        }
        
        vecFibNumber[i]
    }
    
    pub fn fib(n: i32) -> i32 {
        if n == 1 || n == 0 {
            return n;
        }
        
        let k:usize = n as usize;
        let mut vecFibNumber = vec![-1; k+1];
        
        vecFibNumber[0 as usize] = 0;
        vecFibNumber[1 as usize] = 1;
        
        Self::dp (&mut vecFibNumber, n as usize)
    }
}
```

#### Complexity
- **Time:** O(n-2). For nth number we jump n-2 stacks. O(n-2) = O(n)
- **Space:** O(n)
  - (n-2) Function stacks. For nth number we jump n-2 stacks. O(n-2) = O(n)
  - (n+1) Vector size.

<a name=a3></a>
### Approach-3 Directly finding nth fibonacci series number
<img src=nth-fibonacci.JPG width=400/>
