- **Generate Parentheses**
  - [Approach-1: Backtracking](#a1)
  - [Logic](#l)
  - Code
    - [CPP](#c1)

### [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)
- Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
- Well formed parantheses are those which are properly closed, ie opening and closing brackets should be matched.
```c
Example 1:
Input: n = 1
Output: ["()"]
Invalid Output: )(

Example 2:
Input: n = 2
Output: (()), ()()
Invalid Outputs: ())(, ))((

Example 3:
Input: n = 3
Output: ((())), (()()), (())(), ()(()), ()()()
```
