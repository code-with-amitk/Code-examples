**Count ON Bits / Number of On bits in number is also called its Hamming Weight**
- Approach-1: Check every bit using left shift One. 32 Iterations
  - [Logic](#l1)
  - [Complexity](#c1)
  - Code
    - [C++](#cpp1)
    - [Rust](#r1)
- Approach-2: Bit Manipulation Trick
  - [Logic](#l2)
  - [Complexity](#c2)
  - Code
    - [C++](#cpp2)
    - [Rust](#r2)
- [Approach-3: `__builtin_popcount()`](#pc)
- Approach-4: Lookup Table
  - [Code 32 bit](#cpp32)
  - [Code 64 bit](#cpp64)


## [Self Youtube Video](https://www.youtube.com/watch?v=qB-7AH1pRO4)


### Approach-1: Check every bit using left shift 1
<a name=l1></a>
#### Logic
Check every 32 bits of number. If the bit is 1, we add one to the number of 1-bits. All times 32 iterations.
<a name=c1></a>
#### Complexity
- **Time:** O(1)
- **Space:** O(1)

#### Code
<a name=cpp1></a>
**C++**
```c
////32 bit number/////
    int CountOnes(uint32_t a){
        uint32_t i = 1, k = 1;
        int ones = 0;
        while (k++ != sizeof(uint32_t)*8) {           //sizeof(uint32_t) = 4
            if (a & i)
                ones++;
            i = i<<1;
        }
        return ones;
    }
    
/////64 bit number/////
    int CountOnes(uint64_t a){
        uint64_t i = 1, k = 1;
        int ones = 0;
        while (k++ != sizeof(uint64_t)*8) {           //sizeof(uint64_t) = 8
            if (a & i)
                ones++;
            i = i<<1;
        }
        return ones;
    }
```
<a name=r1></a>
**Rust**
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

### Approach-2: Bit Manipulation Trick
Unlike approach-1(where while loop is run 32 times always), Here we will run while loop only that many times, that we have on bits.
<a name=l2></a>
#### Logic
```c
Find on bits in number=556. Output=4.

556 = 0010  0010  1 1 0 0
555 = 0010  0010  1 0 1 1      //Step-1. Find n-1.
      no change     |
                    All bits to right of This LSB(which is setted=0) are setted to 1.
                    Nothing change in bits to left of LSB(setted=0)
                    
0010  0010  1100 
&                             //Step-2. Perform n&(n-1). No of on bits reduced by 1
0010  0010  1011
_________________
0010  0010  1000              //number of ON bits=3

Step-3: Perform same steps until number becomes 0.
```
<img src=counting_on_bits.png width=300/>

<a name=c2></a>
#### Complexity
- **Time** Depends on the number of 1-bits in number. In the worst case, all bits in n are 1-bits. In case of a 32-bit integer, the run time is O(1).
- **Space** O(1), since no additional space is allocated

#### Code
<a name=cpp2></a>
**C++**
```c
  int hammingWeight(uint32_t a) {
        int ones = 0;
        while (a) {
            ones++;
            a &= a-1;
        }
        return ones;
  }
```
<a name=r2></a>
**Rust**
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

<a name=pc></a>
### Approach-3. `__builtin_popcount()`
This function uses CPU specific instructions, which will always be orders of magnitude faster than any algorithm you manage to come up with.
```cpp
#include <stdio.h>
int main() {
    int n = 5;
    printf("Count of 1s in binary of %d is %d ", n, __builtin_popcount(n));
}
```

### Approach-4. Lookup Table
**What is lookup table?** This is precalculated table which stores number of on bits in a number.
```c
Number  Binary    On_Bits
 0        0         0
 1        1         1
 2        10        1
 3        11        2
 4        100       1
 5        101       2
 6        110       2
 7        111       3
 8        1000      1
 ..
 254      11111110  7
 255      11111111  8
 
Lookup Table  {0, 1, 1, 2, 1, 2, 2, 3, 1, .., 7, 8}       //size=256 bytes. 256*8=8192 bits
Number         0  1  2  3  4  5  6  7  8  ...254 255
```

<a name=cpp32></a>
#### Code (32 Bit integer)
- _1._ Create lookup table(at compile time), Iterate over every 8 bits(1 byte) of number and check in table.
```c
//////////Logic to generate lookup table at compile time//////////////
#define B2(n) n, n + 1, n + 1, n + 2
#define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)
#define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)
#define COUNT_BITS B6(0), B6(1), B6(1), B6(2)

uint32_t lookup[256] = { COUNT_BITS };

int CountOnes(uint32_t a){        
  return lookup [a & 0xff] +       //First 8 bits.
         lookup [a>>8 & 0xff] +    //Next 8 bits
         lookup [a>>16 & 0xff] +   //next 8 bits
         lookup [a>>24 & 0xff];    //Last 8 bits
}

int main() {
  cout << CountOnes(5);
}
```

<a name=cpp64></a>
#### Code (64 Bit integer)
