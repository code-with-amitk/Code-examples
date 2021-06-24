## Dynamic Programming / Tabular Method  <== VERY EASY

- [What and How DP Works](#when)
- [Identify whether this problem is DP?](#identify)
- [Methods in DP?](#methods)
- [Examples](#examples)
 - [Fibonacci Series](#fibonacci)

<a name="when"></a>
## When to apply
- In recursive algorithm, when subproblems is calculated again & again we cache those for future recursive calls. Eg: Fibonacci series
- You have to study recursive algorithm and cache prev results into array or hash.
- Recursion Time Complexity: Exponential, DP Time Complexity: Polynomial

<a name="identify"></a>
## Identify whether this problem is DP?
 - **1. Overlapping Subproblems**
  - When recursive algorithm for the problem solves the same subproblems over and over again, we say that the optimization problem has overlapping subproblems.
- **2. Optimal Substructure**

<a name="methods"></a>
## Methods in DP
- __1. Bottom up / Tabulation:__ Steps
  - Think how to solve the problem for a simple case(eg: list with 1 element). 
  - Think how to solve the problem for 2 elements, then for 4 elements, and so on
  - Save solutions of subproblems(in array/hash) and refer it before recalculation.
    - If solved, return the saved value, saving further computation at this level
- __2. Top Down / Memoization:__
  - Think how we can divide the problem for case N into subproblems. 

<a name="fibonacci"></a>
## Fibonacci Series
- **Recursion**
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
- **DP**
```c
int a[n+1];
a[0]=0,a[1]=1,a[2]=2;
int f(int n)
  if (a[n] != -1)
    return a[n];
  a[n] = f(n-1) + f(n-2);
  return a[n];
}  
```
