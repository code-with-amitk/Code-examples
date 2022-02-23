- **Generate Parentheses**
  - [Approach-1: Backtracking](#a1)
  - [Logic](#l)
  - Code
    - [CPP](#c1)

### [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)
- Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
- Well formed parantheses are those which are properly closed, ie opening and closing brackets should be matched.
```c
Example 1:
Input: n = 1
Output: ["()"]
Invalid Output: )(

Example 2:
Input: n = 2
Output: (()), ()()
Invalid Outputs: ())(, ))((

Example 3:
Input: n = 3
Output: ((())), (()()), (())(), ()(()), ()()()
```

<a name=l></a>
### Logic
[See How we generate all combinations using backtracking.](DS_Questions/Questions/Permutation_Combination/Combinations/Generate_All_Combinations.md). Candidates are numbers, which were added & removed at end.
- But here candidates are parantheses `(` and `)`.
```c
For n=2, We can only add 2 (( and 2 )).

1. Keep adding ( until we have added 2.
((
2. Keep adding ) until we have added 2.
(())
3. if total parantheses == 4  //This is 1 solution, note it
  out = "(())"
  
4. Remove last added parantheses ie Backtrack.
(()
5. Remove last added parantheses ie Backtrack.
((
6. Remove last added parantheses ie Backtrack.
(
  //Now add ) so on
```

### Code
- We will use [backtracking template](/DS_Questions/Algorithms/Backtracking)
<a name=c1></a>
#### C++
```c
#include<vector>
#include<string>
#include<iostream>
using namespace std;
using vs = vector<string>;
class Solution {
    vs out;
public:
    void backtrack(string curr, int open, int close, int max){
    
        //Total = open parantheses + closing parantheses
        if (curr.size() == max*2){
            out.push_back(curr);
            return;
        }

        if (open < max) {                                   //3. if this is valid candidate
            curr.append("(");                               //4. Place this candidate on partial solution
//            cout << curr << "\n";
            backtrack(curr, open+1, close, max);            //5. Try next candidate
            curr.erase(curr.length()-1);                    //6. Remove this candidate
//            cout << curr << "\n";
        }
        if (close < max && close+1<= open) {
            curr.append(")");
//            cout << curr << "\n";
            backtrack(curr, open, close+1, max);
            curr.erase(curr.length()-1);
//            cout << curr << "\n";
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";                         //1. Create 1st Candidate
        backtrack(curr, 0, 0, n);                 //2. Call backtrack
        return out;
    }
};
int main (){
    Solution s;
    vs o = s.generateParenthesis(2);
    for  (auto i:o)
        cout << i << ", ";
}
```
