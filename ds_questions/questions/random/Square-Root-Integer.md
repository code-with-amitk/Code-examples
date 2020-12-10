## [Problem](https://leetcode.com/problems/sqrtx/)
- Given an integar x, Compute and return the square root of x.
- If A is not a perfect square, return floor(sqrt(A)).
- DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY
- Examples
```c
Example 1:
Input: x = 4
Output: 2
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
```

### Method-1 (not recommended)
- Calculate i*i and check whether smaller or equal to no.
```c
int Solution::sqrt(int a) {
  if(a==1 || a==2 || a==3)
    return 1;

  uint32_t i=1;
  while(i*i <= a)
    ++i;

  if(i*i==a)
    return i;
  else
    return i-1;
  }
}
```

### Method-2 (Binary Search logn)
1. Assuming square root of num is always smaller than (num/2+1). We can always search sqrt(num) between 1 and (num/2+1). Hence take left=1, right=num/2+1 for binary search.
```c++
sqrt(5) = 2 < (5/2 + 1)
sqrt(16) = 4 < (16/2 + 1)
```
2. Find mid = left + right-left/2
```c++
  if (num == mid*mid)  
    //Found exact no
  else if (mid*mid < num)
    //then answer will be the last number whose square is less then num
  else
    //shift search window between (left and mid-1)
```
#### Code
```c++
int Solution::sqrt(int x) {
  if(x==1 || x==2 || x==3)
    return 1;

  long left = 1, right = x/2 + 1;       //1
  long ans = -1, mid = -1, temp = -1;
  
  while (left <= right) {
    mid = left + (right - left)/2;
    
    temp = mid*mid;
    
    if(temp == x){                       // x is perfect square so we return the mid
      return (int)mid;
    }
    else if(temp < x) {
      ans = mid;    
      left = mid+1;
     }
     else
     {
        right = mid-1;
     }
  }//while
  return (int)ans;
}
```
