## Cargo
- **What?** Rust’s build system and package manager. It downloads dependencies,libraries from `crates.io`(public repo for libraries).
  - Rust can also be build using cmake.

## Working with cargo
- **a. Create Project with Cargo**
  - *1.* Create a project using cargo. It creates `*.toml` and src directory
  - *2.* toml((Tom’s Obvious, Minimal Language)) is Cargo's configuration format.
  - *3. src directory* Contains source code
```rust
$ cargo new hello_cargo             //1. Create a project named hello_cargo
$ cd hello_cargo; dir
  <File>  Cargo.toml
  <DIR>   src
  
$ vim Cargo.toml                    //2
[package]
name = "hello_cargo"
version = "0.1.0"
authors = ["amitk"]
edition = "2018"

[dependencies]

$ cd src                            //3
$ cat main.rs           
fn main() {
    println!("Hello, world!");
}
```
- **b. Build project with cargo**
  - *1.* Executable is placed in `target/debug/hello_cargo`
```rust
# cargo build
# dir
target/debug/hello_cargo
```
