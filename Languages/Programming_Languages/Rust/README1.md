- [1. What/Why Rust](#What)
  - [1.1 Rust vs All Languages](#All)
  - [1.2 Rust vs C++](#Rustcpp)

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

<a name="Rustcpp"></a>
### 1.2 Rust vs C++
- Safe parallelism wrt C++
- Pacakge Repository (crates) better
- Compiler Errors are more informative
- Memory and ownership checking     //Borrow checker
- Memory safety                    
  - No segfaults(no segfault reported in last 5 years)
  - No Memory leaks
  - No out of bounds read/writes
  - No double frees
  - No dangling pointers
  - No uninitialized variables
- No implicit copies as in C++
