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
  - *2.* if character = `]`. Start popping(create tempString) until a number is encountered. Ignore `[`.
    - Once number is seen, Push tempString those many times again on stack.
```c
  //Create string after popping
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

### Approach-2  //Using 2 stacks. Faster than 100%
- **Logic:** Push all numbers on NumberStack and characters from input string on stringStack.
```c
input = 3[a2[c]]
```
  - *1.* if input character is number, copy on iNum.
```c
iNum = 3
```
  - *2.* if input character is `[`. Push iNum on NumberStack, currentString on StringStack. Make iNum=0,currString=""
  ```c
  stNumber    3
  stString    
  iNum=0
  currString = ""
  ```
  - *3.* if input character is character, create currString.
  ```c
  strCurr = a
  ```
   - *4.* Input character is number. Repeat step-1.
```c
stNumber    3
stString    
iNum = 2
currString = a
```
  - *5.* Input character is `[`. Repeat step-2.
```c
stNumber    3   2
               top
stString    a
iNum=0
currString = ""
```
  - *6.* Input charcter is char. Repeat step-3.
```c
stNumber    3   2
               top
stString    a
iNum=0
currString = c
```
  - *7.* Input character `]`. Start decoding the string
    - Create a temporary string = (strString + Repeat currString 2 times(ie stNumber.top())
    - Copy temporay string to currString
```c
strTemp = a + cc = acc

stNumber    3 
stString    
iNum=0
currString = acc

```
- **Complexity:** length of input string=n. Max number of nested strings = k.
  - **Time:** O(max_of_k x n)
  - **Space:** O(m +n). m=Number of letters from (a-z). n=Digits from (0-9).
- **Code**
```c
string decodeString(string s) {
  stack<int> stNumber;
  stack<string> stString;
  
  string strCurr;
  int iNum = 0;  
  
   for (auto ch : s) {

      if (isdigit(ch))  //if digit create number
        iNum = iNum * 10 + ch - '0';

      else if (ch == '[') {

        stNumber.push(iNum);  //Push created number on NumberStack

        stString.push(strCurr); //Push created string on StringStack

        strCurr.clear();
        iNum = 0;

      } else if (ch == ']') {

        string strTemp = stString.top();

        stString.pop();

        //Create string using number from stNumber
        for (int i = stNumber.top(); i > 0; --i)
          strTemp += strCurr;

        stNumber.pop();
        strCurr = strTemp;

      }

      else          //Keep appending characters from input to string
        strCurr += ch;

    }//for()

    return strCurr;
  }  
```

### Approach-3  //Using recursion stack
- **Logic:**
  - *1.* Iterate whole string until we find `]` character.
  - *2.* if digit is seen construct the number.
  - *3.* Call the recursive function again to calculate string part of input string.
```c
  strStringPart = s[index++];
```
- **Complexity:** n is the length of the string s.
  - **Time:** O(maxK x n)  //As in approach-2
  - **Space:** O(n). Space used by internal stack for recursion.
Space Complexity: \mathcal{O}(n)O(n). This is the space used to store the internal call stack used for recursion. As we are recursively decoding each nested pattern, the maximum depth of recursive call stack would not be more than nn
- **Code:**
```c++
  string Iterate(string& s, int& index){
    string strOut;

    while (index < s.length() && s[index] != ']'){
      if (isdigit(s[index])) {
        int iNum = 0;

        //Create Number from continious numerals
        while (index < s.length() && isdigit(s[index]))
          iNum = iNum*10 + s[index++] - '0';

        ++index;

        string strDecoded = Iterate(s, index);
        ++index;

        while(iNum-- > 0)
          strOut += strDecoded;
      }else
        strOut += s[index++];
    }
    return strOut;
  }

  string decodeString(string s) {
    int index=0;
    return Iterate(s, index);
  }
```
