- [Foreign Function Interface](#ffi)
- [FFI C to Rust](#c2r)

<a name=ffi></a>
## Foreign Function Interface / FFI
Calling C,C++,Ruby,other language(etc) code from rust or viceversa.

<a name=c2r></a>
### FFI C to Rust
**Step-1:** Create static library in Rust containing function definition, defined in Rust.
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
**Step-2:** Generate Header file containing function(rust_function()) declaration to be used in c++ code using [cbindgen](https://github.com/eqrion/cbindgen)
```rs
pub fn rust_function() ---becomes---> void rust_function()

$ cargo install --force cbindgen        //Step-2a. Install cbindgen
```
