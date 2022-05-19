- [Foreign Function Interface](#ffi)
- [1, FFI C/CPP to Rust](#c2r)
  - [A. Create static library in Rust](#s1)
  - [B. Generate Header file containing function declaration using cbindgen](#s2)
  - [C. Link rust static lib with Application](#s3)
- [2. FFI Rust to C](#r2c)
  - [A. Translate C Header file for Rust](#r1)
- [`#[naked]`](#nak)

<a name=ffi></a>
## Foreign Function Interface / FFI
<a name=c2r></a>
### [1. FFI C/CPP to Rust](https://docs.rust-embedded.org/book/interoperability/rust-with-c.html)         {Working}
Function defined in Rust, called from C/CPP.
<a name=s1></a>
#### A. Create static library in Rust
```rs
Open "Visual Studio Code"
$ cargo new ffi

//Rename src/main.rs to src/lib.rs          //1a

$ Cargo.toml
[package]
name = "ffi"
version = "0.1.0"
authors = ["amitk"]
edition = "2018"

[lib]
name = "ffi"
crate-type = ["staticlib", "lib"]           //1b. Change crate-type

$ cat src/lib.rs
#![crate_type = "staticlib"]

fn test() -> i32 {                          //1c. Function which needed to be called from C/C++ Code
    4
}

#[no_mangle]
pub extern "C" fn rust_function() -> i32 {  //1d. Add extern "C" function in rust. This will call Actual Rust function
  test();
}

$ cargo build                               //1e. Build static library.
$ ls ffi\target\debug
ffi.lib
```
<a name=s2></a>
#### B. Generate Header file containing function declaration using [cbindgen](https://github.com/eqrion/cbindgen)
```rs
pub fn rust_function() ---becomes---> void rust_function()

$ cargo install --force cbindgen                        //2a. Install cbindgen
$ touch cbindgen.toml                                   //create empty cbindgen.toml
ffi> cbindgen.exe --config cbindgen.toml --crate ffi --output ffi.h
ffi> more ffi.h
#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

extern "C" {

int32_t rust_function();

} // extern "C"
```

<a name=s3></a>
#### [C. Link rust static lib with Application](/Libraries/Static_Dynamic/#wins)

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

#### B. Create [static library(`test.lib`) in C++](/Libraries/Static_Dynamic/#wins)

#### C. Build.rs
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

<a name=nak></a>
### `#[naked]`
- This indicating the function should have [prologue/epilogue](/assembly/Memory_layout_of_object.md) emission disabled.
- Calling convention of a naked function is not guaranteed to match any calling convention the compiler is compatible with
