- [What is Cargo](#what)
- [Working with Cargo](#work)
  - [1. Create Project using cargo](#create)

<a name=what></a>
## Cargo
Rust’s build system and package manager. It downloads dependencies,libraries from `crates.io`(public repo for libraries).
Rust can also be build using cmake.

<a name=work></a>
## Working with cargo

<a name=create></a>
### 1. Create Project with Cargo
- Create a project using cargo. It creates `*.toml` and src directory
  - toml((Tom’s Obvious, Minimal Language)) is Cargo's configuration format.
  - src directory contains source code
```rs
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
<a name=build></a>
### 2. Build project with cargo
Executable is placed in `target/debug/hello_cargo`
```rs
# cargo build
# dir
target/debug/hello_cargo
```
