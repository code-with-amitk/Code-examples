- What/Why Rust
  - [Rust vs All Languages](#All)
  - [Rust vs C++](#Rustcpp)
- [Install on linux/windows](#install)
- [Stack=CompileTime is faster than Heap=Runtime](StackHeap_CompileRuntime)
- [Cargo: cargo build, cargo test, cargo doc, cargo publish](Cargo_BuildSystem)
- [Asynchronous, block_on, await, async](/Threads_Processes_IPC/Terms)
- [Attributes: no_mangle, feature](Attributes)
- [Statements & Expressions](#statements)
- [Ownership](#own)
- [Reference = Borrowing](#bow)
- [Smart Pointers](#smart)
- [Data Types](#datatypes)
- [Collections: HashMap=unordered_map, HashSet=unordered_set, vector, string, str](Collections)
- [Iterators](#itr)
- [Keywords: Lazy, RWlock, self, Self](Keywords)
- [Class in Rust](#class)
- [Control Flow: for, loop, while, match=switch, if, if let](Control_Flow)
- [Containers: std::cell](Containers)
- [Functions, Associated Functions=Methods, Closure=Lambda, impl block](Functions)
- [Frameworks: Actix_web](Frameworks)
- [Crates, Packages, Modules](#cpm)
- [Enum](#enum)
- [Error Handling](Error_Handling)
- [FFI, Foreign Function Interface, Shared Library](FFI)
- [Generic Types/Templates](#temp)
- [Trait = Interface = Virtual (not pure virtual)](#ti)
- [Automated Tests](#tests)
- [Custom Programs](#custom)
- [Design Guidelines](#dg)
- [Threading](#th)
- [macros](macros)
- [Logging: env_Logger, log4rs](Logging)

### What/Why Rust
<a name="All"></a>
#### Rust vs All Languages
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

<a name="Rustcpp"></a>
#### Rust vs C++
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

<a name=install></a>
### Install
#### [Linux](https://doc.rust-lang.org/book/ch01-01-installation.html)
```c
$ curl --proto '=https' --tlsv1.2 https://sh.rustup.rs -sSf | sh
...
Rust is installed now. Great!   <<Rust Installed successfully
```

#### [Windows](https://www.rust-lang.org/tools/install)
- *a.* Download installer & install. Rust is installed in `C:\Users\amitk\.cargo`
- *b.* Open cmd prompt & check PATH variable is configured correctly or not.
```c
> C:\Users\amitk>rustc --version
rustc 1.51.0 (2fd73fabe 2021-03-23)
```

<a name=statements></a>
### Statements & Expressions
- **Statements:** These are instructions that perform some action and do not return a value. Example
```rs
  let y = 6;
```
- **Expressions:** Returns a value. Examples
```rs
fn main(){
  let x = fun();
}
fn fun() -> i32 {
  let y = 5;
  y + 1                   //Expression returning a value.
  //y + 1;                   //When ; is placed it becomes statement and will not return a value
}
```

<a name="own"></a>
### Ownership
- Variable or data can have single owner at a time. When a value is assigned to a variable, that variable becomes the owner of the value. When the owner goes out of scope, Rust automatically deallocates the memory used by the value.
- **Memory management approaches**
  - _1._ Some languages have garbage collection(java,python,ruby) that constantly looks for no longer used memory as the program runs 
  - _2._ C,C++ the programmer must explicitly allocate and free the memory.
  - _3._ Rust memory is managed through ownership with a set of rules that the compiler checks at compile time.
    - Ownership applies to memory allocated on heap(dynamically), Eg: String(), vector ie those are moved. For variable allocated on Stack (Eg: int, float) variable is copied.
```rust
fn main() {
  let s = String::from("hello");    //Allocated on HEAP
  fun(s);                           //s's value is MOVED into function and no longer valid here
  println!("s: {}", s);             //Complie time error
                                    
  let x = 5;                        //Allocated on STACK
  fun1(x);                          
  println!("x: {}", x);            //Ok, x=5

}
fn fun(some_string: String) { 
    println!("{}", some_string);
} //Here, some_string goes out of scope and `drop()` is called. The backing memory is freed.
```
- **Transferring Ownership In Return Value:** Returning values can also transfer ownership
```rust
fn main() {
  let s1 = fun1();                     //fun() moves its return value into s1
  let s2 = String::from("hello");
  let s3 = fun2(s2);                  //s2 is moved into fun2() which also moves its return value into s3
}

fn fun1() -> String {            //fun() will move its return value into the function that calls it
  let some_string = String::from("hello");
  some_string                   //some_string is returned ie moved
}

fn fun2(a_string: String) -> String {     
    a_string                  // a_string is returned and moves out to the calling function
}
```

<a name=bow></a>
### [Reference = Borrowing](References_and_Borrowing)
- Dangling Reference
- Mutable Reference. Mutable means changable. By default variables are immutable in rust
  - Mutable & immutable References in same scope not allowed
  - 2 Mutable references are not allowed in same scope
  - Mutable References are allowed in seperate scope
- Borrow checker
- Lifetimes: lifetime elision

<a name=smart></a>
### [Smart Pointers](Smart_Pointers)
- `Box <T>`, deref trait, drop triat
- `Rc<T>`, sharing ownership, Reference Counter, Reference counting

<a name=datatypes></a>
### [Data Types](Data_Types)
- Scalar / Primitive: int, Array slice, float, bool, char
- Compund Data Type: Array, Tuple, Option<String, i32>

<a name=itr></a>
### Iterators
next(), sum()

<a name=class></a>
### [Class in Rust](Class)
Constructor inside class, Functions inside class

<a name=cpm></a>
### [Crates, Packages, Modules](Crates_Packages_Modules)
- Crates, Packages
- Modules
  - _1._ Creating a module & accessing its function
  - _2._ super keyword
  - _3._ struct inside module
  - _4._ enum inside module
  - _5._ use keyword: use as, pub use / Reexporting

<a name=enum></a>
### [Enum](Enum)
- Option Enum

<a name=temp></a>
### [Generic Types/Templates](Generic_Types)

<a name=ti></a>
### [Trait = Interface = Virtual (not pure virtual)](Triat_Interface)
Trait bounds, Future, 

<a name=tests></a>
### [Automated Tests](Automated_Tests)
- Unit test, Integration tests

<a name=custom></a>
### [Custom Programs](Custom_Programs)
- minigrep, 

<a name=dg></a>
### [Design Guidelines](Design_Guidelines)

<a name=th></a>
### [Threading](Threading)
- `Arc<T>`
