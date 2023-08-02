**Combinations**
- [Approach-1, Backtracking](#a1)
  - [Logic](#l)
  - [Complexity](#com)
  - Code
    - [CPP](#cpp)
    - [Python](#py)
    - [Rust](#rs)

## [Self Video. Use if you forgot](https://youtu.be/QkKRtiyHXA8)

### [77. Combinations](https://leetcode.com/problems/combinations/)
- [What is Combination](/DS_Questions/Questions/Permutation_Combination)
- Given two integers n and k, return all possible combinations of k numbers out of the range `[1, n]`. You may return the answer in any order.
```c
Example 1:
Input: n = 4, k = 2     //Choose 2 numbers out of (1,2,3,4)
Output: 1,2   1,3   1,4   2,3   2,4   3,4

Example 2:
Input: n = 1, k = 1     //Choose 1 number out of 1
Output: [[1]]
```

<a name=a1></a>
### Approach-1, [What is Backtracking](/DS_Questions/Algorithms/Backtracking/)
<a name=l></a>
#### Logic
- **Why Backtracking here?**
  - We will take 1 number at a time, fix it at its place then generate all combinations for it. (Eg: Generate all combinations of 1)
  - Then we will move to 2nd number (ie 2) and generate all combinations of it.
```c
1234
Fix 1:               1
  Add 2:            <1,2>
  Remove 2, Add 3:  <1,3>   //This remove part is Backtracking
  Remove 3, Add 4:  <1,4>

Fix 2:               2
  Add 3:            <1,3>
  Remove 3, Add 4:  <1,4>

Fix 3:               3
  Add 4:            <1,4>
```

<a name=com></a>
#### [Complexity of Bt](/DS_Questions/Algorithms/Backtracking/README.md)
**Time**
- O(n!/(n-k)!k!)
- 4!/2!2! = 6
- Because loop only runs 6 times for <sup>4</sup>C<sub>2</sub> case.
**Space**
- `vector<int> arr` will always be of size k
- Again=6 ie O(n!/(n-k)!k!) because 6 function stacks are created in all.

#### Code using [Backtracking Template](/DS_Questions/Algorithms/Backtracking#tem)
<a name=cpp></a>
**CPP**
```cpp
using vecI = vector<vector<int>>;

class Solution {
    vecI out;
    int n;
    int k;
public:
    
    void backtrack(int start, vector<int>& cand_set){
        if(cand_set.size() == k){             //Base case
            out.push_back(cand_set);
            return;
        }

        for (int i=start; i<=n; ++i) {       //Iterate through all candidates
            cand_set.push_back(i);           //Place candidate
            backtrack(i+1, cand_set);  //Backtrack
            cand_set.pop_back();             //remove this candidate
        }
    }

    vecI combine(int n1, int k1) {
        n = n1;
        k = k1;
        int start = 1;
        vector<int> cand_set = {};
        backtrack(start, cand_set);
        return out;
    }
};
```

<a name=py></a>
**Python**
```rs
class Solution:
    def __init__(self):
        self.n = 0
        self.k = 0
        self.out = [[]]

    def bt(self, start: int, cand_set: List[int]):
        if len(cand_set) == self.k:
            self.out.append(cand_set.copy())
            return

        for i in range(start, self.n+1):
            cand_set.append(i)
            self.bt(i+1, cand_set)
            cand_set.pop()

    def combine(self, n1: int, k1: int) -> List[List[int]]:
        self.n = n1
        self.k = k1
        cand_set = []
        start = 1
        self.bt (start, cand_set)

        # out = [[],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
        # Return from index 1 to end
        return self.out[1:]
```

<a name=rs></a>
**Rust**
```rs
```
