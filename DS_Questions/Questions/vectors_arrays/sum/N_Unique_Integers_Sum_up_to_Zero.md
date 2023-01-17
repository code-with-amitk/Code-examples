**N Unique Integers Sum up to Zero**
- [Approach-1, Fill from both ends](#a1)
  - [Logic](#l)
  - [Complexity](#com)
  - Code
    - [CPP](#cpp)
    - [Rust](#r)

### 1304. Find N Unique Integers Sum up to Zero
- Given an integer n, return any array containing n unique integers such that they add up to 0.
```c
Example 1:
Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4], [-2,-1,0,1,2]
```

<a name=a1></a>
### Approach-1, Fill from both ends
#### Logic
- Take a vector of size n, Fill with 0
- Start from both ends and keep filling -3,3. -2,2. -1,1 and so on
<a name=com></a>
#### Complexity
- Time: O(n)
- Space: O(1)
#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n,0);
        int left = 0, right = n - 1, start = 1;
        while (left < right) {
            res[left++] = start;
            res[right--] = -start;
            start++;
        }
        return res;
    }
};
```
<a name=r></a>
**Rust**
```rs
impl Solution {
    pub fn sum_zero(n: i32) -> Vec<i32> {
        let mut left = 0;
        let mut right = n-1;
        let mut start = 1;
        let mut out = vec![0; n as usize];
        loop {
            if left > right || left == right {
                break;
            }
            out[left as usize] = start;
            out[right as usize] = -start;
            left += 1;
            right -= 1;
            start += 1;
        }
        out
    }
}
```
<a name=j></a>
**Java**
```j
class Solution {
    public int[] sumZero(int n) {
        int start = 1, left = 0, right = n-1;
        int[] out = new int[n];
        while (left < right) {
            out[left++] = start;
            out[right--] = -start;
            ++start;
        }
        return out;
    }
}
```
<a name=p></a>
**Python**
```py
class Solution:
    def sumZero(self, n: int) -> List[int]:
        start = 1
        left = 0
        right = n-1
        out = [0] * n
        while left < right:
            out[left] = start
            out[right] = -start
            left += 1
            right -= 1
            start += 1
        return out
```
<a name=c></a>
**C**
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){
    int left=0, right=n-1, start=1;
    int *out = (int*) malloc (sizeof(int)*n);
    //memset(int*, value, byte_sized_array). Hence passed bytes
    memset(out, 0, sizeof(int)*n);
    while (left < right){
        out[left++] = start;
        out[right--] = -start;
        start++;
    }
    *returnSize = n;
    return out;
}
```
