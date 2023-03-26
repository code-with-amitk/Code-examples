**Combinations**
- [Approach-1, Backtracking](#a1)

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
### Approach-1, Backtracking
#### Logic
- [What is backtracking](/DS_Questions/Algorithms/Backtracking/)
- **How Backtracking is used here?**
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

#### Code (CPP)
[Backtracking Template](/DS_Questions/Algorithms/Backtracking#tem)
```c
#include<iostream>
#include<vector>
using namespace std;
using vecI = vector<vector<int>>;

class Solution {
    vecI out;
public:
    
    void backtrack(int curr, int n, int k, vector<int>arr){
        if(arr.size() == k){                //Base case
            out.push_back(arr);
            return;
        }

        for (int i=curr; i<=n; ++i) {       //Iterate through all candidates
            if (arr.size() >= k)             //if not valid candidate continue
                continue;
            else {                          
                arr.push_back(i);           //Place candidate
                backtrack(i+1, n, k, arr);  //Backtrack
                arr.pop_back();             //remove this candidate
            }
        }
    }

    vecI combine(int n, int k) {
        backtrack(1, n, k, vector<int>());
        return out;
    }
};

int main(){
    Solution s;
    vector<vector<int>> out = s.combine(4,2);
    for (vector<int> i:out){
        for (auto j:i)
            cout <<j<<" ";
        cout << "\n";
    }

}
$ ./a.out
1 2
1 3
2 3
2 4
3 4
```
<a name=rs></a>
#### Rust
```rs
```

#### Complexity
##### Time
- O(n!/(n-k)!k!)
- 4!/2!2! = 6
- Because loop only runs 6 times for <sup>4</sup>C<sub>2</sub> case.
##### Space
- `vector<int> arr` will always be of size k
- Again=6 ie O(n!/(n-k)!k!) because 6 function stacks are created in all.
