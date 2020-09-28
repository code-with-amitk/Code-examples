## explicit keyword
- **What is Implicit conversion?** 
  - Compiler converts data-type to class object which is wrong.
  - Example-1: fun() takes object as argument but we passed int and compiler did conversion internally. This is done using default constructor(1).
```c++
class A {
  int a;

  public:
     A(int b) : a(b) {}             //1
    int get( ) {
      return a;
    }
};

void fun (A obj) {
  int x = obj.get ();
  cout << x;
}

int main() {
  fun (3);
}
# g++ test.cpp;./a.out
3
```
- **Explicit** 
  - explicit can only come in front of constructor.
  - Prefixing the explicit keyword before constructor prevents the compiler for using that constructor for implicit conversions. Above code will give error, we need.
```c++
class A {
  ...
  public:
     explicit A(int b) : a(b) {}             //CONSTRUCTOR PREFIXED with EXPLICIT stops implicit conversion
  ...
};
int main() {
  fun (A(3));
}
```
