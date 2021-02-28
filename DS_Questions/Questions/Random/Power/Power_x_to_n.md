## [pow(x,n)](https://leetcode.com/problems/powx-n/solution/)
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

## 1. Approach-1  //Brute Force
> x<sup>n</sup>   2<sup>4</sup> 
- **Logic:** Multiply x, n times.
- **Complexity**
  - **Time:** O(n)
  - **Space:** O(1)
- **Code**
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

[Exponentiation by squaring](https://en.wikipedia.org/wiki/Exponentiation_by_squaring)
## 2. Approach-2  
### 2a. Recursive O(logn)
- **Logic:** Use product already calculated instead of calculating again.
  - *1.* 2<sup>4</sup> is not calculated as `2*2*2*2` But `4*4`.  n=4. log4 = 2
  - *2.* 2<sup>5</sup> is not calculated as `2*2*2*2*2` But `4*4*2`.  n=5. log4 + log1 = 3
- **Complexity**
  - **Time:** O(logn)
  - **Space:** O(logn). n=4, log4=2 recursive stacks will be created. n=8,log8=4 recursive stacks will be created.
- **Code**
```c++
double power(double x, long y) {   //x^y
  if (y==0)
    return 1.0;
    
  double half = power(x, y / 2);
  if (y % 2 == 0)
    return half * half;
  else
    return half * half * x;
}
    
double myPow(double x, int n) {
  long y = n;
  if (y < 0) {
    x = 1 / x;
    y = abs(y);
  }
  return power(x, y);
}
```

### 2b. Iterative
- **Complexity**
  - **Time:** O(logn)
  - **Space:** O(1)
- **Code**
```c++
double myPow(double x, int n) {
  long y = n;
  if (y < 0) {
    x = 1 / x;
    y = abs(y);
  }
  double out = 1;
  double current_product = x;
  for (long i = y; i ; i /= 2) {
    if ((i % 2) == 1)
      out = out * current_product;
  
    current_product *= current_product;
  }
  return out;
}
```
