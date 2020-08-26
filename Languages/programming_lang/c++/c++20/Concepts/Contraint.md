## Contraint
- **What** 
  - Defines the requirement on template argument used in concept.
  - This is a sequence of logical operations and operands.
  - They can appear within requires-expressions (see below) and directly as bodies of concepts.
  
### Types of Contraints
#### 1. Conjunctions
- The conjunction of two constraints is formed by using the && operator in the constraint expression
```c++
template <class T>
concept SignedIntegral = Integral<T> && std::is_signed<T>::value;
```

#### 2. Disjunctions
- The disjunction of two constraints is formed by using the || operator in the constraint expression.
```c++
template <class T = void>
    requires EqualityComparable<T> || Same<T, void>
struct equal_to;
```

#### 3. Atomic Constraints

