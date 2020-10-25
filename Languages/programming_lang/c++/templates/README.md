## Template/Generic Programming
### What?
  - Writing a code that is independent of particular type.
  - Template is compiler abstraction.
  - Compiler creates the overloaded functions(specialization) for each type at compile time. Eg seperate for long int, short int, int, double, string.
  - Specialization 
    - Benefits: Makes code type-safe.
    - Drawbacks: increases sizeof object file(But not much because compiler achieves using optimizations & inlining).
    
### Types of templates?

|Type|What|
|---|---|
|1.Function Template|Generic function that can be called/worked without particular type|
|2.Class Template|<ul><li>a. Class having Generic Member variables,  Generic Member functions</li></ul><ul><li>b. Compiler cannot deduce template parameter type(s) for class template. We need to tell compiler the data types we would be using</li></ul>|
|3.Template specialization|<ul><li>Giving special implementation for specific data type of class and Generic for all others</li></ul><ul><li>Types: Explicit/Full Specialization, Partial Specialization</li></ul>|

- **Example: Function Template** Template parameter type not specified.
```c++
template < typename T >
T maxof(T a, T b) {
  return (a>b)?a:b;
}

int main() {
	cout << maxof ( 4, 5 ) <<endl;  				<<<<<<<<<< Template parameter type not specified.
}
```
- **Example: Class template** Template parameter type specified.
```c++
template < typename T >
class A {
  A a, b;                    //Generic Member variables
public:
  A (T x, T y) : a(x), b(y) {}
  A add () { return a + b; }
};

int main() {
  A <int> obj(5,6);              <<<<<<<<<<<<<< Template parameter type specified.
  cout<<obj.add()<<endl;
}
```
