### [Minimum Remove to Make Valid Parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)
- Remove unmatching Bracket.
- Examples
```
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"              //"lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Input: s = "a)b(c)d"
Output: "ab(c)d"

Input: s = "))(("
Output: ""                      //An empty string is also valid.

Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"

### Logic    
1. Construct a stack
    - if '('    
        - Push index of '(' on stack
    - if ')' 
        if(stack is not empty)
                pop top of stack.
        else
                //This is non-matching bracket
                Place '$' on original string
2. Iterate thru stack.
        Place '$' in string at positions got in stack.
3. Take a empty new string
4. Iterate through input string
        if (element != '$')
                insert element into new string

### COMPLEXITY:
- Time:   3O(n)
  - O(n): Creating stack
  - O(n): Traversing stack & placing '$'
  - O(n): Traversing string and creating new string
- Space:  O(n)
  - O(n): Stack   //worst case. (((((((
  - O(0): new string      //For worst case this size=0

### Code
```c
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
        string minRemoveToMakeValid (string str) {
                stack<int> s;

                for( int i = 0; i < str.size(); i++ )
                {
                        if (str[i] == '(')
                        {
                                s.push(i);
                        }
                        else if (str[i] == ')')
                        {
                                if (!s.empty()) //nonempty stack
                                        s.pop();
                                else
                                        str[i] = '$';
                        }
                }

                while (s.empty() != 1)
                {
                        str [s.top()] = '$';
                        s.pop();
                }

                string ret;
                for (auto i : str){
                        if (i != '$')
                                ret.push_back (i);
                }
                return ret;
        }
};

int main(){
//      string str = "(((((((a)";
//      string str = "))((";
//      string str = "lee(t(c)o)de)";
        string str = "-1";
        Solution s;
        cout<<s.minRemoveToMakeValid(str);
}
```
