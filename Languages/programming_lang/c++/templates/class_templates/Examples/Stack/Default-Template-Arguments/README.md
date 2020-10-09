## Default Template Arguments
- **What** Define default values for template parameters.

## Creating Stack using (vector or Deque) based on Template argument.
### Things to Note
- *A.* Type of class is Stack<T, CONTAINER>, so whenever class is used its used as Stack<T, CONTAINER>
```c++  
      Stack (Stack<T, CONTAINER>const& obj);                            //copy ctr, takes reference of object
      Stack<T, CONTAINER>& operator = (Stack<T, CONTAINER>const& obj);  //assignment operator takes ref and returns ref
      void Stack<T, CONTAINER>::pop()
      void Stack<T, CONTAINER>::push(T const& a)
```      
- *B.* Name of class: Whenever only name of class is required(not type) template <T, CONTAINER> is not used.
```c++  
      virtual ~Stack()        //Destructor
```
- *C.* Virtual: Base class must provide definition of Virtual function. Derived class can define its own or use Base class function
- *D.* <T, CONTAINER> class name should be postfixed with template parameters, because its not a class its a Template.
- *E.* const:  C1. (T const&) Means taking reference of constant value.  C2. const member function means, its does not modify any data member
- *F.* Using class template: To use class template, we need to specify the template arguments explicitly.
- *G.* Space between >>. Space is required else this becomes overloaded operator.
- *H.* stack<int> obj: Creates a object intStack.  Only Member functions for int type are instantiated(ie created).

### Code
- **stack.h**
```c++
#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<deque>
using namespace std;

template<typename T, typename CONTAINER = vector<T> >   //G
class Stack {                                           //A
public:
  virtual void push(T const&);

  virtual void pop();

  virtual T top() const;

  inline bool Empty() const {
    return elements.empty();
  }

  inline Stack(CONTAINER& v):elements(v) {
    cout<<"Created. ";
    Display();
  }

  virtual ~Stack() {                                    //B
    cout<<"Destructor\n\n";
  }

  virtual inline void Display(){
    cout <<" Stack: ";
    for(auto i:elements)
      cout <<i<<" ";
    cout<<"\n";
  }
private:
  CONTAINER elements;    //vector<T> elements
  Stack (Stack<T, CONTAINER>const& obj);
  Stack<T, CONTAINER>& operator = (Stack<T, CONTAINER>const& obj);
};
```

- **stack.cpp**
```c++
#include "stack.h"

template<typename T, typename CONTAINER>
void Stack<T, CONTAINER>::pop() {                       //D
  if (Empty()) {
    throw out_of_range("Stack<>::top(): empty stack");
  }
  cout<<"Removing ("<<elements.at(0)<<") from";
  elements.pop_back();
  Display();
}

template<typename T, typename CONTAINER>
void Stack<T, CONTAINER>::push(T const& a) {        //C1
  elements.push_back(a);
  cout<<"Element ("<<a<<") pushed";
  Display();
}

template<typename T, typename CONTAINER>
T Stack<T, CONTAINER>::top() const {              //C2
  if (Empty()) {
    throw out_of_range("Stack<>::top(): empty stack");
  }
  cout << "Top: " << elements.back();
  cout<<"\n";
}

int main(){
    { //Stack of int using vector
      vector<int> v = {1,2,3,4};
      Stack<int> s(v);                      //Intantiating object with default CONTAINER
      s.push(5);
      s.pop();
      s.top();
    }
    { //Stack of doubles using deque
      deque<double> v = {1.1,2.1,3.1,4.1};
      Stack<double, deque<double> > s(v);   //F       //Intantiating object with Custom container
      s.push(5.1);
      s.pop();
      s.top();
    }
    { //Stack of strings using deque
      deque<string> v = {"a","b","c","d"};
      Stack<string, deque<string> > s(v);
      s.push("e");
      s.pop();
      s.top();
    }
}
```
