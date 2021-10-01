- [Copy Elision](#ce)
- **RVO(Return value optimization)**
  - [1. Without RVO](#wo) 
  - [2. With RVO](#w)
  - [3. 3. Disabling RVO with `-fno-elide-constructors` switch](#dr)
- **NRVO(Named Return Value Optimization)**
  - [Example](#ex)

<a name=ce></a>
## Copy Elision
- Compiler optimisation technique that eliminates unnecessary copying of objects.
- This mandatory omitting copy and move constructor by compiler even user asked to perform copy/move operation because copy/move creates unnecessary temporary objects.
- **How it works?**
  - The objects are constructed directly into the storage where they would otherwise be copied/moved to.
  - How to avoid copy elision? By using -fno-elide-constructors switch

## RVO(Return value optimization)
Compiler is allowed to avoid creating temporary objects for return values, even if they have side effects.
- **SIDE EFFECT?** function or expression is said to have a side effect if it modifies some variable(s) outside its local scope.
<a name=wo></a>
#### 1. Without RVO
```cpp
int fun(int a){
  return a;
}
int b(){
  int a[fun(10)];
}
```
*[How many temporary copies?](/assembly/Stack_frame_example.md)*
- In b(), Before call to fun(), 10 is copied in register rdi. Inside fun(), rdi is copied to stack of fun()
- a=10 is copied to register(rax) to be returned to b().
- if we note here, copying value to fun()'s stack(temporary copy) is an unecessary step.

<a name=w></a>
#### 2. With RVO
Instead of writing a to stack of fun() we place a directly onto stack of b(). Code for doing such optimization is written in complier itself.

<a name=dr></a>
#### [3. Disabling RVO with `-fno-elide-constructors` switch](https://shaharmike.com/cpp/rvo/)
```cpp
struct A{   // Note: All methods have side effects
        A() { cout << "c'tor" << endl; }
        ~A() { cout << "d'tor" << endl; }
        A(const A&) { cout << "copy c'tor" << endl; }
        A(A&&) { cout << "move c'tor" << endl; }
};

A ExampleRVO() {
          return A();
}

int main() {
          A s = ExampleRVO();
}

# g++ -fno-elide-constructors test.cpp
# ./a.out
c'tor
move c'tor
d'tor
move c'tor
d'tor
d'tor

# g++ test.cpp            //RVO not disabled by user, complier doing RVO.
c'tor
d'tor
```

## NRVO(Named Return Value Optimization)
Object with a name is returned but is not copied or used.
<a name=ex></a>
#### Example
```c++
int fun(int a){ 
  int c = a;
  return c;
}

int b(){
  int a[fun(10)];
}
```
