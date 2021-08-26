**Cargo**
- [$ cargo build   //Build project](#build)
- [$ cargo doc     //Documentation](#doc)
  - [Sections in HTML Document](#sec)
- [$ cargo publish  //publish on crates.io](#pub)
- [$ cargo install  //install crate](#in)
- [Cargo Commands](Cargo_Commands)

<a name=what></a>
## Cargo
Rust’s build system and package manager. It downloads dependencies,libraries from `crates.io`(public repo for libraries).
Rust can also be build using cmake.

<a name=build></a>
### `$ cargo build`   //Build project
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

<a name=doc></a>
### `$ cargo doc`    //Documentation
- Documentation comments use three slashes, `///`.We place documentation comments just before the item we want to document.
- Crate Comments `//!` describes the purpose of my_crate.
```rs
//! # My Crate
//!
//! `my_crate` is a collection of utilities to make performing certain calculations more convenient.
/// Adds one to the number given.

struct Solution{ }

impl Solution {
/// add()
/// # Examples
/// ```
/// let a = 5, b=4;
/// let answer = Solution::add(a, b);
///
/// assert_eq!(9, answer);
/// ```
    fn add(a:i32, b:i32)->i32{
        a + b
    }
}

fn main() {
    println!("Hi");
}

$ cargo doc
  Documentation in target\doc
$ cargo doc --open                //Will open Front page of create root  
$ cargo test add()                //This will run test case in documentation
```
<a name=sec></a>
#### Sections in HTML Document
We can create sections in HTML using `#`. Some common sections: Examples, Panics, Errors, Safety

<a name=pub></a>
### `$ cargo publish` Publish crate on crates.io
We can publish crate on crates.io for others to use it.

**Steps to publish**
- _1._ Login to `https://crates.io/` using github account
- _2._ `https://crates.io/me/` Get API Key. Run cargo login with API key. This is authentication token and will be stored in `~/.cargo/credentials`
```rs
$ cargo login abcdefghijklmnopqrstuvwxyz012345
```
- _3._ Write code, Choose unique name, provide license and publish
```rs
$ vim src\test.rs
..
$ cat cargo.toml
[package]
name = "guessing_game"
version = "0.1.0"
authors = ["Your Name <you@example.com>"]
edition = "2018"
description = "A fun game where you guess what number the computer has chosen."
license = "MIT OR Apache-2.0"
[dependencies]

$ cargo publish

//republish, ie we have new version want to publish
- change version in cargo.toml
$ cargo publish       

//Remove particular version
$ cargo yank --vers 0.1.0
```

<a name=in></a>
### `$cargo install`
