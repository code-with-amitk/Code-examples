**Minimum Flips to Make a OR b Equal to c**
- [Approach-1. Check all bits of a,b,c. O(32)](#a1)
  - [Logic](#l)
  - Code
    - [CPP](#cpp)
    - [Python](#py)
    - [Rust](#r)

### [Self Video](https://youtu.be/ou1AI88dJ1Y)

### [1318. Minimum Flips to Make a OR b Equal to c](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/)
Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.
```c
Example 1:
Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)

Example 2:
Input: a = 4, b = 2, c = 7
Output: 1

Example 3:
Input: a = 1, b = 2, c = 3
Output: 0
```

<a name=a1></a>
### Approach-1. Check all bits of a,b,c. O(32)
<a name=l></a>
#### Logic
- Find bit at every position in a,b,c from left
```
a = 2 = 0010
b = 6 = 0110
c = 5 = 0100
```
- In number=c
  - if (number_c_bit=0)
    - if (b_bit==1) //We need to change it to 0. flip++
    - if (a_bit==1) //We need to change it to 0. flip++
  - if (number_c_bit=1)
    - if (b_bit==0 && a_bit==0) //We need to change any one of them to 1. flip++
<a name=com></a>
#### Complexity
- **Time:** O(32). Always we need to check all bits of 3 numbers
- **Space:** O(1)
#### Code
<a name=cpp></a>
**CPP**
```c
class Solution {
public:
    int minFlips(int a, int b, int c) {
        unsigned int a1=a, b1=b, c1=c, d=1;

        int flips = 0;
        // Check digits of numbers
        for (int i=0;i<32;i++){
            if ((d&c1) == 0) {
                if (d&a1)
                    flips++;
                if (d&b1)
                    flips++;
            }
            else {  //d&c1 = 1
                if (((d&a1) != d) && ((d&b1) != d))
                    flips++;
            }
            d=d<<1;
        }
        return flips;
    }
};
```
<a name=py></a>
**Python**
```py
class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        a1:unsigned = a;
        b1:unsigned = b;
        c1:unsigned = c;
        d = 1;
        flips = 0;
        for i in range(1,32):
            if ((d&c1) == 0):
                if (d&a1):
                    flips += 1;
                if (d&b1):
                    flips +=1;
            else:  #d&c1 = 1
                if (((d&a1) != d) and ((d&b1) != d)):
                    flips+=1;
            d=d<<1;
        return flips;
```
<a name=r></a>
**Rust**
```rs
impl Solution {
    pub fn min_flips(a: i32, b: i32, c: i32) -> i32 {
        let a1:u32 = a as u32;
        let b1:u32 = b as u32;
        let c1:u32 = c as u32;
        let mut d:u32 = 1;
        let mut flips:i32 = 0;

        for i in 1..32 {
            if (d&c1) == 0 {
                if d&a1 == d{
                    flips += 1;
                }
                if d&b1 == d{
                    flips += 1;
                }
            }
            else {  //d&c1 = 1
                if ((d&a1) != d) && ((d&b1) != d) {
                    flips += 1;
                }
            }
            d=d<<1;
        }
        flips
    }
}
```
