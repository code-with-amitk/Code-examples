**Reverse Substrings Between Each Pair of Parentheses**
- [Approach-1, Using `vector<int>` O(n<sup>2</sup>)](#a1)
- [Approach-2, stack O(n<sup>2</sup>)](#a2)

### [1190. Reverse Substrings Between Each Pair of Parentheses](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/)
- You are given a string s that consists of lower case English letters and brackets.
- Reverse the strings in each pair of matching parentheses, starting from the innermost one.
- Your result should not contain any brackets.
```c
Example 1:
Input: s = "(abcd)"
Output: "dcba"

Example 2:
Input: s = "a(u(love)i)b"
Output: "ailoveub"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
a(u evol i)b
a(iloveu)b
ailoveub
```

<a name=a1></a>
### Approach-1, Brute Force. O(n<sup>2</sup>)
#### Logic
- _1._ Take output string, `vector<positions>`
  - Push all alphabets on `string out`
  - Push positions of opening brackets. We judge position of bracket using present length of out
```c
 a ( u ( l o v e ) i )  b
 0 1 2 3 4 5 6 7 8 9 10 11

i     out     vector<int> positions = out.size()
0      a
1             1
2      au
3             2
4     aul
5     aulo
6     aulov
7     aulove

```
- _2._ As closing bracket is seen, Reverse alpha from end to (last_element_on_position)
```c
closing bracket at index = 8
Reverse
  reverse (alpha.begin()+ position.back(), alpha.end())
```

#### Complexity
- **Time**
- **Space:**
#### Code
**CPP**
```cpp
class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> positions;
        string out;
        for (int i=0;i<s.size();++i){
            if (s[i] == '(')
                positions.push_back(out.size());
            else if (s[i] == ')'){
                int j = positions.back();
                positions.pop_back();
                reverse(out.begin()+j, out.end());
            } else
                out += s[i];
        }
        return out;
    }
};
```

<a name=a2></a>
### Approach-2. Stack. O(n<sup>2</sup>)
#### Logic
- _1._ Take a stack of string. `stack<string>`
- _2._ Keep building string until we find `(`. On finding `(` push string to stack
```c
a(u(love)i)b

stack |  u   |
      |  a   |
       ------
out = love
```
- _3._ On finding ')'
  - pop last element from stack
  - reverse present out
  - Add both above, store in out
```c
  pop last = u
  reverse out = evol
  Add = uevol

stack | a |
       ---
```
#### Complexity
- **Time:** O(n<sup>2</sup>). Traverse and build string. Reverse string on finding `)`
- **Space:** O(n)
#### Code
**CPP**
```cpp
class Solution {
public:
    string reverseParentheses(string s) {
        // out to store output string
        string out;
        stack<string> st;
        for (int i=0; i<s.length(); ++i){
            if (s[i] == '(') {    //Finding `(` push string to stack
                st.push(out);
                out.clear();
            } else if (s[i] == ')'){
                // Finding ')'
                // pop last element from stack
                // reverse present out
                // Add both above, store in out
                reverse(out.begin(), out.end());
                out = st.top() + out;
                st.pop();
            } else            // Keep building string until we find `(`. 
                out += s[i];
        }
        return out;
    }
};
```
