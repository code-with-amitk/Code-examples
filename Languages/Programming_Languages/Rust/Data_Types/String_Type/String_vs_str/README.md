## String vs str
- [String?](..)

### str
- str is [Immutable Reference](/Languages/Programming_Languages/Rust/Reference_Borrowing).
- **1. [Type of String Slice is str](../String_Slice)** which is constant string reference.
- Example-1
```rust
fn main() {
    let a = "T11 is Consistency";
    let b:&str = &a[0..4];            //b is String slice and is of type str.
    println!("{}",b);                 //T11
```
- Example-2
```rust
fn main() {
    let mut a = String::from("T11 is Consistency");
    let b = fun(&a);                                      //Function taking string reference
    println!("{}",c);
}

fn fun(s:&String) -> &str {                               //Function returning String Slice
    &s[0..4]
}
```
- **2. Type of String literal is also str**
```rust
  let a : &str = "Test";
```
