## ODR(One Definition rule)
### What 
- These are  constraints placed on the redeclaration of various entities in C++.

### ODR Rules
- Following should be defined only 1 time across **whole program**:
  - Member functions
  - Static data members
  - non-inline functions.
  - Global variables
- Following should be defined once per **Translation Unit**  
  - Class types (including structs and unions)
  - inline functions
