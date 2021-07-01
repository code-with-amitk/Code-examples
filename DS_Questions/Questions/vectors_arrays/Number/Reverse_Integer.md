## [Reverse Integer](https://leetcode.com/problems/reverse-integer/)
- Given a signed 32-bit integer x, return x with its digits reversed. 
- If reversing x causes the value to go outside the signed 32-bit integer range `[-2<sup>31</sup> = -2147483648, 2<sup>31</sup>-1 = 2147483647]`, then return 0.
- Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
- Examples
```c
Input: x = 123
Output: 321

Input: x = -123
Output: -321

Input: x = 120
Output: 21

Input: x = 0
Output: 0

Input: x = -2147483648
Output: 0

Input: x = 2147483647
Output: 0
```

### Approach-1    //Convert to string,reverse,convert back
- **Logic:** Note sign of input. Convert input to string. Reverse string, convert string back to int.
- __Complexity:__ 
  - **Time:** O(n). to_string() takes O(n), reverse() takes O(n), stringstream takes O(n)
  - **Space:** O(n), for string
- **Code**
```c++
class Solution {
public:
    int reverse(int a) {
        bool neg = false;
        if (a <= -2147483648)
            return 0;
        if (a<0) {
            neg = true;
            a *= -1;
        }
        string str = to_string(a);
        std::reverse(str.begin(), str.end());

        stringstream ss(str);
        int out;
        ss >> out;
        
        if(out>=2147483647)
            return 0;
        
        if (neg)
            out *= -1;        
        
        return out;
    }
};
```
