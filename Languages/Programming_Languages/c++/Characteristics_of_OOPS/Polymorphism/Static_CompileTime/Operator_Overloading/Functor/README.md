## A. Functor
- **What?**
  - A object of class which overloads `operator ()`. Ex: object(). Functors are objects only, Hence can store state. Compiler does not provide functors, we define explicitly.
- **Why?** wrt to normal functions since functors are objects they can store state. We need to use global or static variable to hold state if we want to use function.  
- **Types of functors in STL**
  - *1.Generator?* Functor that can be called with no argument. Eg: print_it
  - *2. Unary Functor?* Functor called with 1 argument
  - *3. Binary Functor?* Functor called with 2 arguments.
-  **Functor vs Normal Function**
  -  *1. Normal Function?* Cannot store state. Uses global,static to store state.
  -  *2. Functor?* Stores state. This is non-static pvt member(ie object specific), static(across all objects).
- **Functor code**
```c++
class A {
  int sv;             //STATE VARIABLE
public:
  A(int x):sv(x){}

  int operator () (int a) {     //class A overloads operator (), Now object of this class will be functor
    return a*sv;
  }
};
int main(){
  A obj(10);
  cout<<obj(3)<<endl;        //Using object as Function ie functor. //30
}
```
