- [1. Count on Bits](#count)
  - [1.1 Iterative Approach](#itr)
    - [1.1.1 C++](#cpp)
    - [1.1.2 Rust](#rust)

<a name=count></a>
## 1. Count On Bits
<a name=itr></a>
### 1.1 Iterative Approach
- Do bitwise AND(&) of number with 1. Left shift 1.
<a name=cpp></a>
#### 1.1.1 C++
```c
    int CountOnes(int a){
        int i = 1, k = 1;
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
    pub fn count_bits(a: i32) -> Vec<i32> {
    let mut v = vec![0; (a as usize)+1];
    let mut ones:i32 = 0;
    let mut i:i32 = 1;
    let mut k:i32 = 1;

    for var in 1..a+1 {
        while k as usize != mem::size_of::<i32>()*8 {
            if var & i > 0 {
                ones += 1;
            }
            i = i << 1;
            k += 1;
        }
        v[var as usize] = ones;
        ones = 0;   
        i=1;
        k=1;
    }
    v
    }
}
```
