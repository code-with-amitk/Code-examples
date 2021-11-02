- [Foreign Function Interface](#ffi)
- [FFI C to Rust](#c2r)
  - [1. Create static library in Rust](#s1)
  - [2. Generate Header file containing function declaration using cbindgen](#s2)

<a name=ffi></a>
## Foreign Function Interface / FFI
Calling C,C++,Ruby,other language(etc) code from rust or viceversa.

<a name=c2r></a>
### FFI C to Rust
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
