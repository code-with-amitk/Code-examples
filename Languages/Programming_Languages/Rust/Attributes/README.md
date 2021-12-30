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
### 2. [feature](https://doc.rust-lang.org/cargo/reference/features.html) = Conditional Compilation
This provides enabling/disabling of source code (similar to `#ifdef`)
```rs
$ main.rs 
#[cfg(feature = "foo")]           //1. Define Conditional Compilation. fun() is inside #ifdef
fn fun(){
    println!("fun");
}
fn main() {
    #[cfg(feature = "foo")]       //2. calling fun()
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
default = ["foo"]              //3. By default, all features are disabled unless explicitly enabled.
foo = []                       //4. Add feature(or condition) which need to be enabled

$ cargo build --features "foo" //5. Cargo build needed to be done with feature
fun
Hello World!
```
