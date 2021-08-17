**Cargo**
- [Build project using cargo](#build)
- [Cargo Commands](Cargo_Commands)

<a name=what></a>
## Cargo
Rust’s build system and package manager. It downloads dependencies,libraries from `crates.io`(public repo for libraries).
Rust can also be build using cmake.

<a name=build></a>
### Build project using cargo
toml((Tom’s Obvious, Minimal Language)) is Cargo's configuration format. src directory contains source code
```rs
//1. Create a project named hello_cargo. it creates cargo.toml, src directory
$ cargo new hello_cargo             
$ cd hello_cargo; dir
  <File>  Cargo.toml
  <DIR>   src

$ vim Cargo.toml                    
[package]
name = "hello_cargo"
version = "0.1.0"
authors = ["amitk"]
edition = "2018"
[dependencies]

$ cd src; cat main.rs           
fn main() {
    println!("Hello, world!");
}


//2. Build project. exe is placed in target/debug
# cargo build                                                   //opt-level = 0
    Finished dev [unoptimized + debuginfo] target(s) in 0.0s
$ cargo build --release                                         //opt-level = 3
    Finished release [optimized] target(s) in 0.0s
# dir
target/debug/hello_cargo
```
