- [Rust vs All Languages](#all)
- [Rust vs C++](#rcpp)
  - [1. Memory safety Using Ownership & borrow checker](#a1)


<a name=all></a>
### Rust vs All Languages
- No Garbage collector(Java,python has garbage collectors)               //Garbage collector is runtime heavy
- No monolithic runtime.
- Statically typed(with type inference), Catching the bugs at compile time reduces runtime crashes. Compiler does lot of heavy lifting.
  - No Type confusion
    - Pointer to int cannot be assigned to pointer to float
  - improves code quality, security, no runtime errors
- Thread safety
  - No data races: No 2 threads doing same thing to shared resource Wow!!
- Memory and ownership checking     //Borrow checker
- No need to call delete(),free(). Compiler will insert free()/delete() knows when memory is not used.

<a name=rcpp></a>
### Rust vs C++
<a name=a1></a>
#### Memory safety Using Ownership & borrow checker
- What is ownership
- Use-after-free or data races are detected at compile-time in rust using 
```c
Example:
///////////C++ Code///////
int main() {
  vector<int> a = {1,2,3};
  vector<int> b = &a;      //Borrowed
  a.push_back(4);          //Works, no error
}

////////Rust/////////////////
fn main() {
  let mut a = vec![1,2,3];
  let mut b = &a;          //Borrowed
  a.push_back(4);          //Compilation Error. This avoid 
}
```
- No implicit copies as in C++
- Rust uses LLVM complier which has inherent advantages over g++
- No invisible copy constructors, move operators etc (as in c++). Whatever is runtime cost that's visible in code.
- Safe parallelism wrt C++
- Pacakge Repository (crates) better
- Compiler Errors are more informative
- Memory safety                    
  - No segfaults(no segfault reported in last 5 years)
  - No Memory leaks
  - No out of bounds read/writes
  - No double frees
  - No dangling pointers
  - No uninitialized variables
- Default in rust is move not copy
```rs
fn print(a:Vec<i32>) {
  println!("{}"a.len());
}
fn main() {
  let mut v = Vec::new();
  v.push(1);
  print(v);                               //Now v is moved not copied.
  //println!("{}", v[0]);                 //Compiler error
}
```
