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
> x<sup>n</sup> 2<sup>4</sup> 
- **Logic:** Multiply x, n times.
- **Complexity**
  - **Time:** O(n)
  - **Space:** O(1)
- **Code**
```c++
double myPow(double x, int n) {
  if(not n)
    return 1;
    
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

## 2. Approach-2  //Fast power O(logn)
