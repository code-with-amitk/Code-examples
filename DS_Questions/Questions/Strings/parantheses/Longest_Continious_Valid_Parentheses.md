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

### Rule
- LCVSS(logest continious Valid Sub String) will always have Even Length
- LCVSS will always start from `(` and end at `)`. Sub-String starting with `)` or ending with `(` are invalid.

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

### Approach-2        //Stack. Time:O(n), Space:O(n)
- **Logic**
  - *1.* Take a `stack<int>` to store indexes of elements of incoming string. Push `-1` on stack initially.
  - _2._ if element == `(` 
    - push index on stack
  - _3._ if element == `)`
    - Pop
    - if (stack !empty)
      - maxlen = max(maxlen, currentIndex - top)
    - else
      - push current index on stack
```c
input string = "()))()()"
                01234567

index  Element    stack         maxlen
                   -1             0
0       (          -1 0         
1       )          -1            1 - -1 = 2
2       )           2
3       )           2 3
4       (           2 3 4
5       )           2 3 4       5 - 3 = 2
                    2 3
..                    
```
- **Complexity**
  - **Time:** O(n)
  - **Space:** O(n)
- **Code**
```c++
int longestValidParentheses(string A) {
  stack<int> st;                        //1
  st.push (-1);
  int maxlen = 0;
  for (int i=0; i<A.size(); ++i) {
    if (A[i] == '(')                    //2
      st.push(i);
    else {                              //3
      if (!st.empty())
        st.pop();
      if (!st.empty())
        maxlen = max(maxlen, i - st.top());
      else
        st.push(i);
    }
  }
  return maxlen;
}
```

### Approach-3        //2 pass solution, Time:O(n). Space: O(1)
- **Logic**
  - Take 2 counters left & right. 
  - Traverse the string from the left to right 
    - if `A[i] == (` ++left 
    - if `A[i] == )` ++right 
    - if (left == right) 
      - Calculate the length of the current valid string and keep track of maximum length substring found so far. 
    - If right > left
      - left = 0, right = 0  
  - Traverse string from right to left and similar procedure is applied.
- **Complexity**
  - **Time:** O(n)
  - **Space:** O(1)
- **Code**
```c++
int longestValidParentheses(String s) {
  int left = 0, right = 0, maxlen = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(')
      left++;
    else
      right++;

    if (left == right)
      maxlen = max(maxlen, 2 * right);
    else if (right >= left)
      left = right = 0;  
  }

  //Same process from right
  left = right = 0;
  
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s.charAt(i) == '(')
      left++;
    else
      right++;
    if (left == right)
      maxlen = max(maxlen, 2 * left);
    else if (left >= right)
      left = right = 0;
  }
  return maxlen;
}
```

### Approach-4        //Dynamic Programming. Time:O(n), Space:O(n)
- **Logic**
  - *1.* Take dp array, where ith element represents length of longest valid continious substring(lvcss) ending at index=i. Initialize to 0.
    - 2. Donot calculate lvcss if string ends at `(`, since lvcss cannot end at `(`
- **Code**
```c++
int longestValidParentheses(string A) {
  int maxlen = 0;
  vector<int> dp(A.size(), 0);

  for (int i=0; i<A.size(); ++i) {
    if (A[i] == ')') {
      if (A[i-1] == '('){
        dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
      }
      else if (i - dp[i-1] > 0 && A[i - dp[i-1] -1] == '('){
        dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
      }
    }
    maxlen = max(maxlen, dp[i]);
  }
  return maxlen;
}
```
