**Is valid parantheses**
- [Approach-1, Stack. O(n)](#a1)
  - [Logic](#l)
  - [Complexity](#com)
  - Code
    - [CPP](#cpp)
    - [C](#c)
    - [Java](#j)
    - [Python](#p)
    - [Rust](#r)

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
<a name=a1></a>
### Approach-1, Stack. O(n)
#### Logic
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
#### Complexity
- TIME: O(n)
- SPACE: O(n)

#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
public:
    bool isValid(string s) {
        if (s.length()==1)
            return false;
        stack<char> st;
        for (auto&i:s) {
            if (i==')' || i=='}' || i==']') {
                if (!st.size())
                    return false;
                char top = st.top();
                if ((top == '(' && i != ')') ||
                    (top == '{' && i != '}') ||
                    (top == '[' && i != ']') )
                    return false;
                st.pop();
            } else
                st.push(i);
        }
        return !st.size() ? true : false;
        //return true;
    }
};
```
<a name=c></a>
**C**
```c
typedef struct stack {
    char arr[10001];
    int top;
}STACK;
STACK st;

void stack(){
    st.top = -1;
    memset(st.arr, 'a', sizeof(st.arr));
}
int size(){
    return st.top;
}
char top(){
    return st.arr[st.top];
}
void push(char c){
    st.arr[++st.top] = c;
}
void pop(){
    st.arr[st.top--] = 'a';
}

bool isValid(char * s) {
    stack();
    if (strlen(s) == 1)
        return false;

    for (int i=0;i<=strlen(s); ++i) {
        if (s[i]==')' || s[i]=='}' || s[i]==']') {
            if (size()<0)
                return false;
            char t = top();
            if ((t == '(' && s[i] != ')') ||
                (t == '{' && s[i] != '}') ||
                (t == '[' && s[i] != ']') ) 
                return false;
            pop();
        } else
            push(s[i]);
    }
    return !size() ? true : false;
}
```
<a name=j></a>
**Java**
```java
class Solution {
    public boolean isValid(String s) {
        if (s.length() == 1)
            return false;
        Stack<Character> st = new Stack<>();
        for (int i=0;i<s.length();++i){
            if (s.charAt(i)==')' || s.charAt(i) == '}' || s.charAt(i) == ']') {
                if (st.size() == 0)
                    return false;
                char top = st.peek();
                st.pop();
                if ((s.charAt(i)==')' && top != '(') ||
                    (s.charAt(i)==']' && top != '[') ||
                    (s.charAt(i)=='}' && top != '{')
                )
                    return false;
            } else
                st.push(s.charAt(i));
        }
        return st.size()>0 ? false : true;
    }
}
```
