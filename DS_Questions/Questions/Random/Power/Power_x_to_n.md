**pow(x,n)**
- [Approach-1. Brute Force. TLE](#a1)
- [Approach-2. Dynamic Programming](#a2)
  - [Logic](#l)
  - [Complexity](#com)
  - Code
    - [CPP](#cpp)
    - [Python](#py)


### [50. pow(x,n)](https://leetcode.com/problems/powx-n/solution/)
- Implement pow(x, n), which calculates x raised to the power n (i.e. x<sup>n</sup>).
- Examples:
```c
Input: x = 2.00000, n = 10
Output: 1024.00000

Input: x = 2.10000, n = 3
Output: 9.26100

Input: x = 2.00000, n = -2
Output: 0.25000   //Explanation: 1/4 = 0.25
```

<a name=a1></a>
### 1. Approach-1  //Brute Force
#### Logic
- Multiply x, n times.
#### Complexity
- **Time:** O(n)
- **Space:** O(1)
#### Code
```c++
double myPow(double x, int n) {
  if(not n)
    return 1.0;
  double d = x;
  bool neg = false;
  if(n<0){
    neg = true;
    n = abs(n);
  }
  while(n>1){
    d *= x;
    n--;
  }
  return neg ? 1.0/d : d;
}
```

<a name=a2></a>
### Approach-2. Dynamic Programming
#### Logic
- _1._ Take `unordered_map<double,double>` representing key=power & resulting number as value.
  - Look into unordered_map before calculating the value, if not present(fill it), if present(take it)
```c
(x=2, n=10)
unordered_map  <key, value>
                  0    1
                  1    2
                  2    4
                  5    32
```
- _2._ In every function call half the number and check in unorderd_map.
#### Complexity
- **Time:** O(logn). We jump in half of number, hence it's similar to bst search.
- **Space:** O(logn).

#### Code
<a name=cpp></a>
**CPP**
```c++
class Solution {
    unordered_map<double, double> um;
    double num;
public:
    double fun (int n) {
        uint32_t quo = n/2, remainder = n%2;
        if (!n)
            return 1;
        if (n==1)
            return num;

        auto it = um.find(quo);
        if (it == um.end())
            um[quo] = fun(quo);
        
        if (!remainder)
            return um[quo]*um[quo];

        return num*um[quo]*um[quo];
    }
    double myPow(double x, int n) {
        num = x;
        if (n < 0)
            num = 1/x;
            n = abs(n);
        return fun (n);
    }
};
```

<a name=py></a>
**Python**
```py
class Solution:
    def __init__(self):
        self.um = {}
 
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            x = 1/x
            n = -n
        return self.fun(x, n)

    def fun(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n == 1:
            return x

        if n // 2 not in self.um:                #n//2 means quotient
            self.um[n // 2] = self.fun(x, n//2)

        if n % 2 == 0:
            return self.um[n // 2] * self.um[n // 2]
        if n % 2 == 1:
            return x * self.um[n // 2] * self.um[n // 2]
```
