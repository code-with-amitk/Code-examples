**Rust Attributes**
- [1. no_mangle](#nm)
- [2. feature](#f)

## Attribute
An attribute is sort of data that is interpreted by its name and compiler version. Types of attributes:
- **1. Inner Attributes `#![crate_type = "lib"]`** 
  - Written with Bang(!) preceded by `#`. 
- **2. Outer Attributes `#[test]`**

<a name=nm></a>
### 1. no_mangle
- Rust compiler does [name mangling of function names](/Languages/Programming_Languages/c++/#nm).
- This directive tells complier not to mangle the name.

<a name=f></a>
### 2. feature
```rs
$ main.rs 
#[cfg(feature = "foo")]      //Conditional Compilation
fn fun(){
    println!("fun");
}
fn main() {
    #[cfg(feature = "foo")]
    fun();
    
    println!("Hello, world!");
}

$ Cargo.toml
[package]
name = "cfg_features"
version = "0.1.0"
authors = ["kumara"]
edition = "2018"

[features]
default = ["foo"]              //By default, all features are disabled unless explicitly enabled.
foo = []                      //Need to be defined feature here

$ cargo build --features "foo" //Building feature
fun
Hello World!
```
