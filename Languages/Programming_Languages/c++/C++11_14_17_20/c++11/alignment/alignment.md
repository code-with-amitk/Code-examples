## What is Alignment Requirement?
  - Every complete object type has a property called alignment requirement, which is an integer representing the number of bytes between successive addresses at which objects of this type can be allocated. The valid alignment values are non-negative integral powers of two.
  - Alignment can be retrieved for class/struct/union or enumeration. Cannot be applied to function parameter or exception parameter of a catch.
  
### A. ALIGNOF() or ALIGNMENT_OF() returns alignment of struct,class,union,variable,enum.
#### Example-1
```c++
int main(){
  struct S {
    char a;       //size=1, alignment=1
    char b;
  };             //size=2, alignment=1

  cout << sizeof(S) << alignof(S);         //2 1
  cout << sizeof(S) << alignment_of(S);    //2 1
}
```
#### Example-2
```
struct X {
  int n;    //size=4, alignment=4
  char c;   //size=1, alignment=1
  //three bytes padding
};    //size=8, alignment=4
```

## B. ALIGNAS() function for setting alignment.
  - Can be applied to any of these:
    - Variable, non-bitfield class data member, declaration or definition of a class/struct/union or enumeration.
  - Cannot be applied to:
    - Function parameters, exception parameter of a catch clause.
  - Invalid/ill-formed aligment declarations: 
    - alignas(3)
    - alignas(0) is always ignored
```
struct alignas(8) S {};
struct alignas(1) U { S s; }; // error: alignment of U would have been 8 without alignas(1)
```
