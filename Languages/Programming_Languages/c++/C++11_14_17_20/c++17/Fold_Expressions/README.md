## Fold Expression
- **Fold?** means reducing or compressing
- **Fold Expression?**
  - Reduces (folds) a parameter pack over a binary operator.
  - Provides way to apply binary operation to the elements of a parameter pack.
- **Syntax**
```c++
1. Unary left fold: pack-variable on right
  (... operator pack-variable)

2. Unary right fold: Pack-variable on left
  (pack-variable operator ...)

3. Binary right fold: Pack-variable on left
  (pack-variable operator ... operator initial-value)

4. Binary left fold: pack-variable on right
   (initial-value operator ... operator pack-variable)

pack-variable: unexpanded parameter pack expression
operator? any of the following 32 binary operators + - * / % ^ & | = < >  << >> += -= *= /= %= ^= &= |= <<= >>= == != <= >= && || , .* ->*. 
In a binary fold, both ops must be the same.
initial-value: 
  an expression that does not contain an unexpanded parameter pack and does not contain an operator with precedence lower than cast at the 
  top level (formally, a cast-expression)
```
