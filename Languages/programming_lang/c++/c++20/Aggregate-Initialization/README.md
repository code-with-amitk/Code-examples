# What is Aggregate?
- Aggregate is any of following type:
  - array type
  - class type (struct or union) that has ***NO***
    - private, protected non-static data members
    - user-declared constructors (explicitly defaulted or deleted constructors are allowed)
    - virtual, private, or protected base classes
    - virtual member functions
    - default member initializers

# A. Aggregate initialization
- **What** It initializes aggregates. 
  - list-initialization (since C++11) 
  - direct initialization (since C++20)
- Syntax
```
T object {arg1, arg2, ...};	(2)	(since C++11)
T object = { .designator = arg1 , .designator { arg2 } ... };	(3)	(since C++20)
T object { .designator = arg1 , .designator { arg2 } ... };	(4)	(since C++20)
T object (arg1, arg2, ...);	(5)	(since C++20)
```
  
## A1. Designated initializers
- **What** The syntax forms (3,4) are known as designated initializers. 3,4 are called designators. Conditions:
  - Each designator must name a direct non-static data member of T.
  - Order of designator should be same as order of the data members of T.
- Example-1  
```
struct A { 
  int x; 
  int y; 
  int z; 
};
A a{.y = 2, .x = 1}; // error; designator order does not match declaration order
A b{.x = 1, .z = 2}; // ok, b.y initialized to 0
```

## A2. Character Arrays
- If the size of the array is specified and it is larger than the number of characters in the string literal, the remaining characters are zero-initialized.
```
char a[] = "abc";                 // equivalent to char a[4] = {'a', 'b', 'c', '\0'};
 
//unsigned char b[3] = "abc";     // Error: initializer string too long
unsigned char b[5]{"abc"};        // equivalent to unsigned char b[5] = {'a', 'b', 'c', '\0', '\0'};
 
wchar_t c[] = {L"кошка"}; // optional braces
//equivalent to wchar_t c[6] = {L'к', L'о', L'ш', L'к', L'а', L'\0'};
```
