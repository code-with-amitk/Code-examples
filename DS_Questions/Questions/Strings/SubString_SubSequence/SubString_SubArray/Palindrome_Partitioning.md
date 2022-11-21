**Palindrome Partitioning**
- [Approach-1, Backtracking](#a1)

### [131. Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/description/)
- Given a string s, partition s such that every substring of the partition is a palindrome
- Return all possible palindrome partitioning of s.
```c
Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]
```
<a name =a1></a>
### Approach-1, Backtracking
#### Logic
- if we understand correctly, this question is not about substring, its about combinations, Input string need to be break so that all are palindromes.
```c
input = "aab".
Substrings =      //Question is not about substrings
  a,aa,aab
  a,ab
  b
```
- Backtrack Tree
```c
                                    []
                                    |
            ------------------------
            |                         
           {a}                  
            |
       -------------------------
     /        \           \     \
   {a}{a}     {a}{ab}     {aa}  {aab}
   /                       /
 {a}{a}{b}              {aa}{b}
 
Palindromic Combinations:
{a}{a}{b}, {aa}{b}
```
- _1._ Create substrings using backtracking
- _2._ Check whether substring is palindrome or not?
  - if its not palindrome, donot push substring on candidate vector
  - if palindrome, push on candidate vector
- _4._ if index `>` size of input array. Push candidate into output.

#### Code = [Backtracking Template](/DS_Questions/Algorithms/Backtracking#tem)
```cpp
using vecS = vector<string>;
using vecVecS = vector<vector<string>>;
class Solution {
    vecVecS out;
public:
    vecVecS partition(string input) {
        //1. Create Empty candidate
        vecS cand;
        int startIndex = 0;
        
        //2. Call recursive backtrack
        rb (input, startIndex, cand);
        return out;
    }

    void rb (string &input, int startIndex, vecS &cand) {
        // Base case
        if (startIndex >= input.size())
            out.push_back(cand);

        //3. Iterate through all letters, create substring and place them into candidate vector
        for (int i = startIndex; i < input.size(); ++i) {
        
            //4. Take substring and check it palindrome or not, if not its not candidate
            if (isPalindrome (input, startIndex, i)) {
                
                //5. Push substring into candidate vector
                cand.push_back(input.substr(startIndex, i - startIndex + 1));
                
                //6. Call rb() to search next candidate
                rb (input, i + 1, cand);
                
                //7. Remove last added substring from candidate vector
                cand.pop_back();
            }
        }
    }

    bool isPalindrome (string &input, int low, int high) {
        while (low < high) {
            if (input[low++] != input[high--])
                return false;
        }
        return true;
    } 
};
```
#### Complexity
- **Time**
- **Space**
