- [Foreign Function Interface](#ffi)
- [1, FFI C/CPP to Rust](#c2r)
  - [A. Create static library in Rust](#s1)
  - [B. Generate Header file containing function declaration using cbindgen](#s2)
- [2. FFI Rust to C](#r2c)
  - [A. Translate C Header file for Rust](#r1)

<a name=ffi></a>
## Foreign Function Interface / FFI
Calling C,C++,Ruby,other language(etc) code from rust or viceversa.

<a name=c2r></a>
### [1. FFI C/CPP to Rust](https://docs.rust-embedded.org/book/interoperability/rust-with-c.html)
Function defined in Rust, called from C/CPP.
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
### 2. FFI Rust to C
Function defined in C called from Rust.
<a name=r1></a>
#### A. Translate C Header file for Rust
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

#### 2. Create [static library(`test.a`) in C++](/Libraries/Static_Dynamic)

#### 3. Build.rs
Place this in root of package, cargo will compile & run before building cargo pacakge.
```rs
fn main() {

    // Tell Cargo that if the given file changes, to rerun this build script.
    println!("cargo:rerun-if-changed=src/hello.c");
    // Use the `cc` crate to build a C file and statically link it.
    cc::Build::new()
        .file("src/hello.c")
        .compile("hello");
}
```
