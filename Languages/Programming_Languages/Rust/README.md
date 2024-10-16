- What/Why Rust
  - [Rust vs All Languages](Comparison_Rust_vs_Other_Lang)
  - [Rust vs C++](Comparison_Rust_vs_Other_Lang)
- [Install on linux/windows](#install)
- [Stack=CompileTime is faster than Heap=Runtime](StackHeap_CompileRuntime)
- [Cargo: cargo build, cargo test, cargo doc, cargo publish](https://code-with-amitk.github.io/Languages/Programming/Rust/cargo.htm)
- [Asynchronous, block_on, await, async](/Threads_Processes_IPC/Terms)
- [Attributes: no_mangle, feature](Attributes)
- [Statements & Expressions](#statements)
- link:https://amitkumar50.github.io/Languages/Programming/Rust/#ownership[Ownership]
- [Reference = Borrowing](#bow)
- [Smart Pointers](#smart)
- [Data Types](#datatypes)
- [Collections: HashMap=unordered_map, HashSet=unordered_set, vector, string, str, minHeap, maxHeap, stack](Collections)
- [Iterators](#itr)
- [Keywords: Lazy, RWlock, self, Self](Keywords)
- [Class in Rust](#class)
- [Control Flow: for, loop, while, match=switch, if, if let](Control_Flow)
- [Containers: std::cell, RefCell](Containers)
- [Functions, Associated Functions=Methods, Closure=Lambda, impl block](Functions)
- [Frameworks: Actix_web](Frameworks)
- [Crates, Packages, Modules](#cpm)
- [Enum, Option<enum>](https://code-with-amitk.github.io/Languages/Programming/Rust/enum.html)
- [Error Handling](Error_Handling)
- [FFI, Foreign Function Interface, Shared Library](FFI)
- [Generic Types/Templates](#temp)
- [Trait = Interface = Virtual (not pure virtual)](#ti)
- [Automated Tests](#tests)
- [Custom Programs](#custom)
- [Design Guidelines](#dg)
- [Threading](#th)
- [macros](macros)
- [notify-rs](notify-rs)
- [Logging: env_Logger, log4rs](Logging)

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

<a name=bow></a>
### [Reference = Borrowing](https://code-with-amitk.github.io/Languages/Programming/Rust/References%20Borrowing/)
- Dangling Reference
- Mutable Reference. Mutable means changable. By default variables are immutable in rust
  - Mutable & immutable References in same scope not allowed
  - 2 Mutable references are not allowed in same scope
  - Mutable References are allowed in seperate scope
- Borrow checker
- [Lifetimes: lifetime elision](https://code-with-amitk.github.io/Languages/Programming/Rust/lifetime.html)

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
- [Modules](https://code-with-amitk.github.io/Languages/Programming/Rust/Modules.html)
  - _1._ Creating a module & accessing its function
  - _2._ super keyword
  - _3._ struct inside module
  - _4._ enum inside module
  - _5._ use keyword: use as, pub use / Reexporting

<a name=temp></a>
### [Generic Types/Templates](Generic_Types)

<a name=ti></a>
### [Trait = Interface = Virtual (not pure virtual)](https://code-with-amitk.github.io/Languages/Programming/Rust/Trait/)
* What is Triat: User defined triats, Traits provided by Rust (Copy, Clone, Default, Drop, Future)
* Passing trait as argument to function
* Returning trait from function
* Trait Bound (Using +, Using where clause)

<a name=tests></a>
### [Automated Tests](https://code-with-amitk.github.io/Languages/Programming/Rust/Automated%20Tests.html)
- Automated Tests, Examples(Simple Function, Modules for Test, Run test by name, Ignore some tests, async function tests), Unit test, Integration tests

<a name=custom></a>
### [Custom Programs](Custom_Programs)
- minigrep, 

<a name=dg></a>
### [Design Guidelines](Design_Guidelines)

<a name=th></a>
### [Threading](Threading)
- `Arc<T>`
