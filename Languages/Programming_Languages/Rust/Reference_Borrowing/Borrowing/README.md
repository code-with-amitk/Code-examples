## Borrowing
  - Ownership of value is kept by function when variable is passed by value.
  - When variable is passed by reference, we dont need to return values since we dont have ownership.
  - **Reference variable cannot be modified, Why?**
    - Since reference variables are borrowed and you cannot change the borrowed thing.
```rust
use std::{io, string};
fn main() {
  let s = String::from("test");
  fun(&s);
}
fn fun(s:&String){
  s.push_str("Hello");        //Compilation Error. References cannot be changed.
  println!("{}", s);
}
```

- **[Mutable References](Mutable References*)*
