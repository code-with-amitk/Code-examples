## [Decode String](https://leetcode.com/problems/decode-string/)
- Given an encoded string, return its decoded string.
- The encoding rule is: `k[string k[string]]`, where the string inside the square brackets is being repeated exactly k times. 
- Input string is always valid; No extra white spaces, square brackets are well-formed, etc.
- Examples
```c
Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"         //nested
Output: "accaccacc"
Explanation:  3[a2[c]] => 3[acc]  => accaccacc
          
Example 3:
Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
```

**Overall Logic**
- Since this is nested we will expand innermost string 1st
- Iterate over the string s, keep pushing each character to the stack until we get closing bracket `]`.
- Once we encounter the closing bracket `]`, Start decoding the pattern.

### Approach-1  //1 Stack

- **Logic:**
  - *1.* keep pushing every character on stack if its not `]`
```c
 Input = `3[a2[c]]`
 stack = 3 [ a 2 [ c 
                   /\
                   top
```
  - *2.* if character = `]`. Start popping and recreating stack
```c
  //Keep noting string
  strLast = c,        stack = 3 [ a 2 [ 
  
  //Ignore [
  stack = 3 [ a 2
  
  //Note the number and push those strLast on stack that many times
  num = 2,  stack = 3 [ a   //Note number
  stack = 3 [ a c c         //Pushing strLast 2 times
```
  - *3.* goto step 2.
- **Complexity** Consider input `3[a2[c]]`
  - **Time:** O(maximum_value_of_k <sup>count_of_k</sup> x n)
    - k = count of nested values. k=2, count_of_k=2(as there are 2 nested k's(a,c))
    - n = maximum length of input string
  - **Space:** O(sum(maximum_value_of_k <sup>count_of_k</sup> x n)
- **Code**
```c++
  string decodeString(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); ++i) {

      if (s[i] != ']')
        st.push(s[i]);
      else {

        //Get Last String, ie before ]
        string strLast = "";
        while (st.top() != '[') {
          strLast += st.top();
          st.pop();
        }

        //Remove [ from stack
        st.pop();

        //Get number, Repeat count
        //Number can be have multiple digits, Create it.
        int iBase = 1, iNum = 0;
        while (!st.empty() && isdigit(st.top())) {
          iNum = iNum + (st.top() - '0') * iBase;
          st.pop();
          iBase *= 10;
        }

        //Push strLast iNum of times on stack
        while (iNum != 0) {
          for (int i = strLast.size() - 1; i >= 0; --i) {
            st.push(strLast[i]);
         }
         --iNum;
        }
      }
    }

    //stack = a c c a c c a c c
    //                        top
        //Get top from stack and place before out
    string strOut;
    while (!st.empty()) {
      strOut = st.top() + strOut;
      st.pop();
    }
    return strOut;
  }
```
