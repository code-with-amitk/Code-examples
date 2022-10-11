**Evaluate Reverse Polish Notation**



### Evaluate Reverse Polish Notation
- Evaluate the value of an arithmetic expression in Reverse Polish Notation.
- Valid operators are `+, -, *, and /`. Each operand may be an integer or another expression.
- It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.
```c
Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

### Approach-1, Postfix conversion
- **What is Polish Notation?** This is prefix notation
```c
3+4 = +34
```
- **Reverse Polish Notation?** Postfix notation. Question is evaluate postfix expression
```c
3+4 = 34+
```
#### Logic
- To evaluate postfix expression, we use stack.
- Push operand(3,4) on stack
- Once operator is recieved, pop top 2 operands and apply operator on operands
```c
["2","1","+","3","*"]

Push on stack
| 1 |
| 2 |

Operator recieved: Pop top 2 and apply operator. Push on stack
| 3 |

Operand:
| 3 |
| 3 |

Operator: 3 * 3
| 9 |

Ans: 9
```
#### Code
```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<long> s;
        
        for (int i=0;i<tokens.size();++i) {
            if (tokens[i].size() == 1 && !isdigit(tokens[i][0])){
                long top1 = s.top(); s.pop();
                long top2 = s.top(); s.pop();
                long val;
                switch(tokens[i][0]){
                    case '+':
                        val = top1 + top2;
                        break;
                    case '-':
                        val = top2 - top1;
                        break;
                    case '/':
                        val = top2 / top1;
                        break;
                    case '*':
                        val = top1 * top2;
                        break;
                }//switch
                s.push(val);                
            }
            else {
                long a;
                stringstream ss(tokens[i]);
                ss >> a;
                s.push(a);
            }
        }
        return s.top();
    }
};
```
#### Complexity
- **Time:** O(n). n=strings on input.
- **Space:** O(m). m continious operands
