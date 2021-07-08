- [1. Count ON Bits](#count)
  - [1.1 Check every bit using left shift One. 32 Iterations](#check)
    - [1.1.1 C++](#cpp)
    - [1.1.2 Rust](#rust)
  - [1.2 Bit Manipulation Trick](#trick)
    - [1.2.1 Logic](#logic)
    - [1.2.2 Code](#bcode)
      - [1.2.2.1 C++](#bcpp)
      - [1.2.2.2 Rust](#brust)



<a name=count></a>
## 1. Count ON Bits
- Number of On bits in number is also called its Hamming Weight.

<a name=check></a>
### 1.1 Check every bit using left shift 1
- Check each of the 32 bits of the number. If the bit is 1, we add one to the number of 1-bits.
- All times 32 iterations.
- **Complexity**
  - **Time:** O(1)
  - **Space:** O(1)
<a name=cpp></a>
#### 1.1.1 C++
```c
    int CountOnes(uint32_t a){
        uint32_t i = 1, k = 1;
        int ones = 0;
        while (k++ != sizeof(int)*8) {
            if (a & i)
                ones++;
            i = i<<1;
        }
        return ones;
    }
```
<a name=rust></a>
#### 1.1.2 Rust
```rs
use std::mem;
impl Solution {
    pub fn hammingWeight (n: u32) -> i32 {
        let mut i:u32 = 1;
        let mut k:u32 = 1;
        let mut ones:i32 = 0;
        while k as usize != mem::size_of::<u32>()*8+1 {
            if n & i > 0 {
                ones += 1;
            }
            i = i << 1;
            k += 1;
        }
        ones
    }
}
```

<a name=trick></a>
## 1.2 Bit Manipulation Trick
- Unlike 1.1 approach(where while loop is run 32 times always), Here we will run while loop only that many times, that we have on bits.
<a name=logic></a>
### 1.2.1 Logic
  - Consider we need to find Hamming Weight(On bits) in number n=556 (which is 4).
  - _a._ Find n-1. n-1=555. How n-1 is different from n?
    - Least Significant Bit of n is setted to 0.
    - Bits to right of Least Significant Bit of n are setted to 1
    - Rest all bits(ie to right of LSB) of n are as such in n-1.
  - _b._ Perform Bitwise `&` on n, n-1. 
    - if we perform bitwise &, Number of on bits reduces by 1. And that is what we needed.
    - As on bits recudes by 1, we not the count and perform same steps for other on bits.
  - _c._ Increment count of ones by 1.
```c
A.
556 = 0010  0010  1100
555 = 0010  0010  1011

  0010    0010    1  1  0  0      //556
    |       |        |    |
  < no change>      LSB set to 1
    |       |        |    |
  0010    0010    1  0  1  1      //555

B.                        
556 = 0010  0010  1100
      &
555 = 0010  0010  1011
      _________________
      0010  0010  1000      //Observe On Bits are reduced by 1
      
C. 
ones=1
```
<img src=counting_on_bits.png width=500/>

<a name=bcode></a>
### 1.2.2 Code
<a name=bcpp></a>
#### 1.2.2.1 C++
```c
class Solution {
public:
    int hammingWeight(uint32_t a) {
        int ones = 0;
        while (a) {
            ones++;
            a &= a-1;
        }
        return ones;
    }
};
```
<a name=brust></a>
#### 1.2.2.2 Rus
```rs
impl Solution {
    pub fn hammingWeight (n: u32) -> i32 {
        let mut ones:i32 = 0;
        let mut a:u32 = n;
        while a != 0 {
            ones += 1;
            a &= a - 1;
        }
        ones
    }
}
```
