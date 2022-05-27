- [What is Functor](#what)
  - [1. Types of Functor](#types)
  - [2. Functor vs Normal Function](#comp)
- [Predicate](#pred)
  - [1. Predicate Types](#ptypes)
  - [2. Examples](#ex)
    - [2.1 all_of()](#all_off)

<a name=what></a>
## Functor
- Overloading `operator ()`. Ex: object(). Functors are objects only, Hence can store state. Compiler does not provide functors, we define explicitly.
- If we want to store state within a function, use functor.
```cpp
class A {
  int a;             //STATE VARIABLE
public:
  A(int a):a(a){}
  int operator () (int x) {     //class A overloads operator(), Now object of this class will be functor
    return a+x;
  }
  double operator () (double x) { //Overloading Functor
    return a+x;
  }
};
int main(){
  A obj(1);
  cout << obj(3) <<endl;        //4
  cout << obj(5.2) <<endl;        //6.2
}
```

<a name=types></a>
### 1. Types of functors in STL
- *1.Generator?* Functor that can be called with no argument. Eg: print_it
- *2. Unary Functor?* Functor called with 1 argument
- *3. Binary Functor?* Functor called with 2 arguments.

<a name=comp></a>
### 2. Functor vs Normal Function
- *1. Normal Function?* Cannot store state. Uses global,static to store state.
- *2. Functor?* Stores state. This is non-static pvt member(ie object specific), static(across all objects).

<a name=pred></a>
## Predicate
- A class that implements functor `bool object()` that returns boolean value(true or false).
- Predicate is used with algorithms that takes container, predicate function(as input) and returns boolen result.

<a name=ptypes></a>
### 1. Predicate Types
- _1. Unary:_ Unary functor returning bool
- _2. Binary:_ Binary functor returning bool

<a name=ex></a>
### 2. Examples
```c
all_of(), any_of(), none_of: Take an array of elements, predicate as an input
                             Call predicate on individual input elements
                             return true if for all/any/none elements, predicate returns true

find_if()                  : Take sequence of elements, predicate as input
                             Return first element in the sequence, for which predicate returns value equal to true
```

<a name=all_off></a>
#### 2.1 all_off
- Syntax
```cpp
template< class InputIt, class UnaryPredicate >
constexpr bool all_of( InputIt first, InputIt last, UnaryPredicate p );
```
- Code
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  vector<int> v(10,2);    //10 vectors initialized to 2
  
  for(auto i:v)
    cout<<i<<" ";

  if(all_of(v.begin(), v.end(), [](int i){return i%2 == 0;})){
    cout<<"All nos are even";
  }
}

Output: All nos are even
```
