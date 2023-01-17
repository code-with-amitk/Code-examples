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
```
