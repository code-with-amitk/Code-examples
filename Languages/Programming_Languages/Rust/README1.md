- [1. What/Why Rust](#What)
  - [1.1 Rust vs All Languages](#All)
  - [1.2 Rust vs C++](#Rustcpp)
- [2. Ownership & Borrowing](#bow)

<a name="What"></a>
## 1. What/Why Rust
<a name="All"></a>
### 1.1 Rust vs All Languages
- No Garbage collector               //Garbage collector is runtime heavy
- No monolithic runtime.
- Statically typed(with type inference), Catching the bugs at compile time reduces runtime crashes. Compiler does lot of heavy lifting.
  - No Type confusion
    - Pointer to int cannot be assigned to pointer to float
  - improves code quality, security, no runtime errors
- Thread safety
  - No data races: No 2 threads doing same thing to shared resource Wow!!
- Memory and ownership checking     //Borrow checker
- No need to call delete(),free(). Rust knows when memory is not used.

<a name="Rustcpp"></a>
### 1.2 Rust vs C++
- No implicit copies as in C++
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
```rust
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

<a name="bow"></a>
## 2. Ownership & Borrowing
- **Ownership?** Means code/variable owns a memory and is allowed to free it.
  - How Rust Handles it? Rust keeps track of things, who owns what and you cannot free a memory which you donot own.
