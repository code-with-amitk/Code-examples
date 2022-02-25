**Is valid parantheses**
- [Logic](#l)
- [Complexity](#com)
- [Code](#c)

### [Valid Parantheses](https://leetcode.com/problems/valid-parentheses/)
- Input string can contain any of these '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
- An input string is valid if:
  - Open brackets must be closed by the same type of brackets.
  - Open brackets must be closed in the correct order.
- Examples:
```c
1. Input: "()"          Output: true
2. Input: "()[]{}"      Output: true
3. Input: "(]"          Output: false
4. Input: "([)]"        Output: false
5. Input: "(((((((()"   Output: false
```
<a name=l></a>
### Logic
```c
a. if 1st character is ')',']','}' return false
b. Take a stack.
    if '(' or '[' or '{' 
        push on stack
    else
        if stack is empty 
            return false
        else
            top = top of stack.
            if top=='(' && present-element != ')' 
                //same for all elements
                return false
```        
<a name=com></a>
### Complexity
- TIME: O(n)
- SPACE: O(n)

<a name=c></a>
### Code        
```c
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
        bool isValid(string st) {

                if(!st.size())
                        return true;
                if(st[0] == ')' || st[0] == ']' || st[0] =='}')
                        return false;

                stack<char> s;
                char top;

                for(auto i:st){

                        if(i=='(' || i=='[' || i=='{')
                                s.push(i);
                        else{
                                if(s.empty()!= 1){
                                        top = s.top(); s.pop();
                                }else
                                        return false;

                                if((top == '(' && i != ')') ||
                                   (top == '[' && i != ']') ||
                                   (top == '{' && i != '}'))
                                        return false;
                        }
                }
                if(s.size())
                        return false;
                return true;
        }
};

int main(){
//      string s = "()[]{}";
//      string s = "())";
//      string s = "([)]";      
//      string s = "(((((((()";
//      string s = "";
//      string s = "(((((())))))";
//      string s = "([)]";
//      string s = "]";
        string s = "()";
        Solution a;
        cout<<a.isValid(s);
}
```
