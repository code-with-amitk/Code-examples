## [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)
- Longest valid continious valid paratheses
- Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
- Examples
```c
Ex1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Ex 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Ex 3:
Input: s = "()(()"
Output: 2
Explanation: The lvp substring is "()", because '(' seperates the continous lvp.

Ex 4:
Input: s = "((()))()"
Output: 8
Explanation: nested paraenthses are considered valid
```
- **Longest Continious Valid Substrgin will always have Even Length**

### Approach-1    //Brute Force, O(n<sup>3</sup>), Time Limit Exceed
- **Logic:** 
  - *1.* We will check every possible Even length sub-string. Example
    - index (0 to 1), (0 to 3), (1 to 2), (1 to 3) ... so on
  - *2.* if Even length sun-string is valid, we note the length.
  - *3.* Compare with maxlen and return
```console
)()())
012345

//Complete sub-string is checked for validity.
//A substring starting with ')' can never by valid.
            Valid   maxlen
0-1 )(      No                            //Sub-string starting with ')' cannot be valid
0-3 )()(    No
0-5 )()())  No
1-2 ()      Yes     2                    //Valid
1-4 ()()    Yes     4
2-3 )(      No
2-5 )())    No
3-4 ()      Yes     2
4-5 ))      No
```
- **Complexity**
  - **Time:** O(n<sup>3</sup>). 3 for loops
  - **Space:** O(n). Stack, if complete input string is valid.
- **Code**
```c++
class Solution {
  bool isValid(string A) {
    stack<char> st;
    for (int i=0; i<A.size(); ++i){
      if (A[i] == '(')
        st.push(A[i]);
      else if (!st.empty() && st.top() == '(')
        st.pop();
      else
        return false;
    }
    return st.empty();      //if stack is empty, return true
  }
public:
  int longestValidParentheses(string A) {
    int maxlen = 0;
    for (int i=0; i<A.size(); i++) {
      for (int j=i+2; j<=A.size(); j+=2) {
        if (isValid(A.substr(i,j-i)))
          maxlen = max(maxlen, j-i);
      }
    }
    return maxlen;        
  }
};
```
