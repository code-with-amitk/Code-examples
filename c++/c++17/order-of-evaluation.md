if c = a+b
- '+' is operand
- a,b are operators

## Order of Evaluation
- OoE means order in which expression is evaluated.
- In both C,C++ Compilers, Order of evaluation of any part of any expression, including order of evaluation of function arguments is unspecified. 
- There is no concept of left-to-right or right-to-left evaluation in C,C++.

## Associativity of Operators
- AoO means how operators are evaulated with operands, ie placing of brackets.
- associativity of operators is different from order of evaluation.
- Example: 
    - Operator **+** has left to right associativity, hence
    - a() + b() + c() is parsed as (a() + b()) + c()
    - But Note, order of evaluation is compiler dependent Hence c() may be evaluated first, last, or between a() or b() at run time.

Code Example
```C++
#include <cstdio>
int a() { return std::puts("a"); }
int b() { return std::puts("b"); }
int c() { return std::puts("c"); }
int main() {
    return a() + b() + c(); // all 6 permutations of output are allowed
}
Output:
a
b
c
```

