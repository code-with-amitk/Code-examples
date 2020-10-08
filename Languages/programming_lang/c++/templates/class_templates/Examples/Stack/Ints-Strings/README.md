### Notes
- Type of class:
  - Type is stk<T>, so whenever class is used its used as stk<T>. Example
```c++  
      stk (stk<T>const& obj);                 //copy ctr, takes reference of object
      stk<T>& operator = (stk<T>const& obj);  //assignment operator takes ref and returns ref
      void stk<T>::pop()
      void stk<T>::push(T const& a)
```
  - Name of class: Whenever only name of class is required(not type) template <T> is not used.
```c++  
      stk(vector<T>& v)     //Constructor
      virtual ~stk()        //Destructor
```
- **A,B,C,D,E** are placed in code below
- **A. Virtual:**
  - *1.* Base class must provide definition of Virtual function
  - *2.* Derived class can define its own or use Base class function
- **B. <T>** class name should be postfixed with template parameter <T>, because its not a class its a Template.
- **C. const**
  - *C1.* (T const&) Means taking reference of constant value
  - *C2.* const member function means, its does not modify any data member
- **D. Using class template** To use class template, we need to specify the template arguments explicitly.
- **E. stack<int> obj**
  - Creates a object intStack.
  - Only Member functions for int type are instantiated(ie created).
  -  If a class template has static members, then functions are instantiated only once.

## [Self youtube Video](https://youtu.be/hggsO0nMVL8)

### stack.h
```c++
#pragma once

#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<typename T>
class stk {
public:
  virtual void push(T const&);      //A
  virtual void pop();
  virtual T top() const;
  inline stk(vector<T>& v):elements(v) {
    cout<<"Created. ";
    Display();
  }
  virtual ~stk() {
    cout<<"Destructor\n\n";
  }
  virtual inline void Display(){
    cout <<" Stack: ";
    for(auto i:elements)
      cout <<i<<" ";
    cout<<"\n";
  }
private:
  vector<T> elements;
  stk (stk<T>const& obj);
  stk<T>& operator = (stk<T>const& obj);
};
```

### stack.cpp
```c++
#include "stack.h"
template<typename T>
void stk<T>::pop() {              //B
  cout<<"Removing ("<<elements.at(0)<<") from";
  elements.erase(elements.begin());
  Display();
}

template<typename T>
void stk<T>::push(T const& a) {       //C1
  elements.insert(elements.begin(),a);
  cout<<"Element ("<<a<<") pushed";
  Display();
}

template<typename T>
T stk<T>::top() const {             //C2
  if (!elements.empty())
    cout << "Top: " << elements.at(0);
  else
    throw out_of_range("Stack<>::top(): empty stack");
  cout<<"\n";
}

int main(){
    {
      //Stack of strings
      vector<string> str = {"Never","Give", "Up"};
      stk<string> s1(str);
      s1.push("No");
      s1.pop();
      s1.top();
    }
    { //Stack of int
      vector<int> v = {1,2,3,4};                //D
      stk<int> s(v);                            //E
      s.push(5);
      s.pop();
      s.top();
    }
}
```

### Compile and run
```c++
# g++ stack.cpp  -I.
# /a.out
Created.  Stack: Never Give Up
Element (No) pushed Stack: No Never Give Up
Removing (No) from Stack: Never Give Up
Top: Never
Destructor

Created.  Stack: 1 2 3 4
Element (5) pushed Stack: 5 1 2 3 4
Removing (5) from Stack: 1 2 3 4
Top: 1
Destructor
```
