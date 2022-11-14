**Combination Sum 3**
- [Approach-1, Backtracking. Time:O(9!k / (9-k)!)](#a1)

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
#### Logic
- _1._ Take a counter=1 and increment it to fill values into vector candidate.
- _2._ Solution candidate will be `vector<int>` of size=3, keep on filling solution candidates and do --k, counter++
  - if (k==0) and sum(candidate_items == n) //note in solution list
  - Removed last placed counter on candidate
  - Move to next candidate.
```c
                                            1
                                           /  \
                                         1,2  1,3
                                        /       \
                                       /        -----------------------------------------
                                      /         1,3,4   1,3,5   1,3,6   1,3,7   1,3,8   1,3,9
                                     /                    *
    -----------------------------------------------
    |        |       |       |     |      |       |
  1,2,3    1,2,4   1,2,5   1,2,6  1,2,7   1,2,8  1,2,9
                             *  

    solve (k=3, n=9)
      vector<int> cand;
      rb(3, 9, cand, 1)
      
          
                                  rb(k=3, n=9, cand, counter=1)
                                    for (int i=counter; i<=9; ++i)
                                      cand={1} //cand.push_back(i)
                                      rb (--k, n=9, cand, counter=2)
                      
                              rb (k=2, n=9, cand, counter=2)
                                for (int i=counter; i<=9; ++i)
                                  cand={1,2} //cand.push_back(i)
                                  rb (--k, n=9, cand, counter=3)

                          rb (k=1, n=9, cand, counter=3)
                            for (int i=counter; i<=9; ++i) {
                              cand={1,2,3} //cand.push_back(i)
     ------------------------ rb (--k=0, n=9, cand, counter=4)
     |                        cand={1,2}  //cand.pop_back()
     |
     |                        cand={1,2,4}
     |   ---------------------rb (--k=0, n=9, cand, counter=5)
     |   |                    cand={1,2}  //cand.pop_back()
     |   |
     |   |                    cand={1,2,5}
     |   |    ----------------rb (--k=0, n=9, cand, counter=6)
     |   |    |               cand={1,2}  //cand.pop_back()
     |   |   \/
     |   |  rb (k=0, n=9, cand, counter=6)
     |   |
     |   |                    cand={1,2,6}
     |   |    ----------------rb (--k=0, n=9, cand, counter=7)
     |   |    |               cand={1,2}  //cand.pop_back()
     |   |
     |   |    |
     |   |    |
     |   |    \/
     |   |  
     |   |
     |   \/
     |  rb (k=0, n=9, cand, counter=5)
     |
    \/
  rb (k=0, n=9, cand, counter=4)
    if (k==0) {
      if (sum(cand) == n)
        //store output
      return
    }
```
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
#### Complexity
- **Time:** O(9!k / (9-k)!)
```c
  1,2,3   1,2,4   1,2,5   1,2,6   1,2,7   1,2,8   1,2,9       //9-k
  1,3,4   1,3,5   1,3,6   1,3,7   1,3,8   1,3,9               //9-k-1
  1,4,5   1,4,6   1,4,7   1,4,8   1,4,9                       //9-k-2
  1,5,6   1,5,7   1,5,8   1,5,9                               //9-k-3
  1,6,7   1,6,8   1,6,9                                       //9-k-4
  1,7,8   1,7,9                                               //9-k-5
  1,8,9                                                       //9-k-6
  
  2,3,4   2,3,5   2,3,6   2,3,7   2,3,8   2,3,9               //9-k-1
                                                              ...
                                                              //9-k-6
```
- **Space:** O(k). `vector<int>` to hold candidate list in every function call.
