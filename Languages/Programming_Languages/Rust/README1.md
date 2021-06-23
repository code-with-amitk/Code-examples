- [1. What/Why Rust](#What)
  - [1.1 Rust vs All Languages](#All)
  - [1.2 Rust vs C++](#Rustcpp)
- [2. Ownership & Borrowing](#owbo)
  - [2.1 Ownership](#own)
  - [2.2 Reference = Borrowing](#bow)
    - [2.2.a Mutable Reference](#mutref)

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

<a name="owbo"></a>
## 2. Ownership & Borrowing

<a name="owo"></a>
### 2.1 Ownership
- **What?** Means code/variable owns a memory and is allowed to free it.
- How Rust Handles it? Rust keeps track of things, who owns what and you cannot free a memory which you donot own.
  
<a name="bow"></a> 
### 2.2 Borrowing = Reference (&var)
- **What?** Means passing the reference of a variable. Borrowing means that needed to be returned(we cannot change).
```rust
fn print( a : &Vec<i32>) {
  println!("{}"a.len());            //1
  //a.push(2);                      //Compilation error. We cannot change borrowed. Changing immutable
}
fn main() {
  let mut v = Vec::new();
  v.push(1);
  print(&v);                         //Borrowed not moved
  println!("{}", v[0]);              //1
}
```

<a name="mutref"></a>
#### 2.2.a Mutable Reference
- We know a borrowed item cannot be changed, but mutable reference can be changed.
  - *1.* Declare mutable variable
  - *2.* Create mutable Reference using `&mut`
  - *3.* Accept mutable reference using `some_string: &mut String`
```rust
fn print( a : &mut Vec<i32>) {        //3
  a.push(2);
}
fn main() {
  let mut v = Vec::new();             //1
  v.push (1);
  print (&mut v);                     //2
  println! ("{}", v[0]);
}
# rustc test.rs
# test.exe
```
