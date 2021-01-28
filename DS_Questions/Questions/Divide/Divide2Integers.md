## [Problem](https://leetcode.com/problems/divide-two-integers/)
- Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
- Return the quotient after dividing dividend by divisor.
- The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
- Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For this problem, assume that your function returns 231 − 1 when the division result overflows.

### Examples
```c
Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.

Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
```

## [Self Video](https://youtu.be/2Z3w5DEClGU)

### Logic
- Check Pre-conditions
  - if(dividend>INT_MAX) return INT_MAX
- Note sign of answer in bool `sign`.
- Make both dividend and divisor +ve
- Add divisor in divisor until reach dividend and store count.

### Code
```c
class Solution {
public:
  int divide(int dividend, int divisor) {

    if(dividend == INT32_MIN && divisor == -1) return INT32_MAX;
    if(divisor == 1) return dividend;

    int64_t i64Dividend, i64Divisor;
    bool sign = (dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0);

    i64Dividend = abs(dividend);
    i64Divisor = abs(divisor);

    try {

      if (!i64Divisor)
        throw 0;

      int64_t increment = i64Divisor;
      int count = 0;

      while(i64Divisor <= i64Dividend) {
        i64Divisor += increment;
        count++;
      }

      return sign ? count : -count;

    }catch(...){
      return 0;           //Divide by 0
    }
  }
};
int main(){
  Solution s;
  //cout<<s.divide(10,3);
  //cout<<s.divide(7,-3);
  //cout<<s.divide(7,3);
  //cout<<s.divide(0,1);
  //cout<<s.divide(0,0);
  //cout<<s.divide(-1,1);   //-1
  //cout<<s.divide(-1,-1);    //1
  //cout<<s.divide(-2147483648,-1);   //2147483648
  //cout<<s.divide(2147483647,1);   //2147483647
    cout<<s.divide(-2147483648,1);    //-2147483648
}
```
