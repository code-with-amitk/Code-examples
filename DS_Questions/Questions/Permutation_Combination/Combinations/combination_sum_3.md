**Combination Sum 3**
- [Approach-1, Backtracking](#a1)

### [216. Combination Sum III](https://leetcode.com/problems/combination-sum-iii/description/)
- Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
  - Only numbers 1 through 9 are used.
  - Each number is used at most once.
- Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
- Examples
```c
Example-1:
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7.  //There are no other valid combinations.

Example-2:
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
```

<a name=a1></a>
### Approach-1. Backtracking
- [What is Backtracking, Backtracking Template](/DS_Questions/Algorithms/Backtracking)
#### Code
```c
using vecI = vector<int>;
using vecVecI = vector<vector<int>>;
class Solution {
    vecVecI out;
public:
    int sum(vecI& v) {
        int s = 0;
        for (auto&i:v)
            s += i;
        return s;
    }
    void rb (int k, int n, vecI& cand, int counter) {
    
        //3. Base case. When k becomes=0, Place candidate on output
        if (k==0) {
            if (sum(cand) == n)
                out.push_back(cand);
            return;
        }
        if (counter > 9)
            return;
            
        //4. Iterate through all candidates
        for (int i=counter; i<=9; ++i) {
        
            // Place this candidate on 1 solution
            cand.push_back(i);
            
            // Try next candidate
            rb (k-1, n, cand, i+1);
            
            // Remove present candidate
            cand.pop_back();
        }
    }
    vecVecI combinationSum3(int k, int n){
        //1. Create 1st Candidate
        vecI cand;
        
        //2. Start from start=k, go till end=n
        rb (k, n, cand, 1);
        
        return out;
    }
};
```
