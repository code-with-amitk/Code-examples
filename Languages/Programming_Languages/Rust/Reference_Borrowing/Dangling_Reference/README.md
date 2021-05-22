## Dangling Reference
- **Dangling pointer?** Pointer points to memory, memory is freed and pointer is used.
- **Dangling reference?** Similar to Dangling pointer, when reference to a value is used, value is freed and reference is used after that.
- **C++:**
  - Problem: Since b is local variable and is freed as fun() goes out of scope.
```c++
int& fun() {    //Function returning reference
  int b = 10;
  return b;
}

int main() {
  int &a = fun();       //a is reference variable pointing to b, which does not exist
  cout << a;            
}
# g++ test.cpp        //No compile error
# ./a.out
  Segmentation Fault
```

- **Rust:** Complier does not allow DR.
```rust
fn fun() -> &i32 {
  let b = 10;
  &b                        //Reference is returned
}
fn main() {
  let a = fun();
}
# rustc test.rs
Compilation error

Solution: Return by value = Transfer ownership
fn fun() -> i32 {
  let b = 10;
  b                        
}
```
