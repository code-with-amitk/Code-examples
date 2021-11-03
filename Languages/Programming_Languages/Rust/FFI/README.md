- [Foreign Function Interface](#ffi)
- [FFI C to Rust](#c2r)
  - [1. Create static library in Rust](#s1)
  - [2. Generate Header file containing function declaration using cbindgen](#s2)
- [FFI Rust to C](#r2c)

<a name=ffi></a>
## Foreign Function Interface / FFI
Calling C,C++,Ruby,other language(etc) code from rust or viceversa.

<a name=c2r></a>
### [FFI C to Rust](https://docs.rust-embedded.org/book/interoperability/rust-with-c.html)
<a name=s1></a>
#### 1. Create static library in Rust
```rs
Open "Visual Studio Code"
$ cargo new ffi

//Rename src/main.rs to src/lib.rs          //Step-1a

$ Cargo.toml
[package]
name = "ffi"
version = "0.1.0"
authors = ["amitk"]
edition = "2018"

[lib]
name = "ffi"
crate-type = ["staticlib", "lib"]           //Step-1b: Change crate-type

$ cat src/lib.rs                            //Step-1c: Add extern "C" function in rust
#[no_mangle]
pub extern "C" fn rust_function() {
  println!("Hi");
}

$ cargo build                               //Step-1d: Build static library.
$ ls ffi\target\debug
ffi.lib
```
<a name=s2></a>
#### 2. Generate Header file containing function declaration using cbindgen
- rust_function() declaration to be used in c++ code.
- using [cbindgen](https://github.com/eqrion/cbindgen)
```rs
pub fn rust_function() ---becomes---> void rust_function()

$ cargo install --force cbindgen        //Step-2a. Install cbindgen
//create empty cbindgen.toml
ffi> cbindgen.exe --config cbindgen.toml --crate ffi --output ffi.h
ffi> more ffi.h
#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

extern "C" {

void rust_function();

} // extern "C"
```

<a name=r2c></a>
### FFI Rust to C
#### 1. Translate C Header file for Rust
**Method-1: Manually reading and translating(Not recommended)**
- **`#[repr(C)]`**?
  - By default, Rust does not guarantee order, padding, or the size of data included in a struct Hence we should instructs the Rust compiler to always use the same rules C does for organizing data within a struct.
- **cty?**
  - To map primitive data types defined in cty, which will map types from C to types in Rust.
```c
$ cat test.h
typedef struct st {
  int x;
}COOL_ST;
void fun(int i, char c, COOL_ST* cs);

test.h would be translated to =>

#[repr(C)]
pub struct COOL_ST {
    pub x: cty::c_int,
}
pub extern "C" fn fun(
    i: cty::c_int,
    c: cty::c_char,
    cs: *mut COOL_ST,
);
```

**Method-2: Using [bindgen](https://github.com/rust-lang/rust-bindgen) tool**

#### 2. Create [static library(`test.a`) in C++]()

#### 3. 
