## Mutable References
- **1. Can be modified**
  - *1.* Declare mutable variable
  - *2.* Create mutable Reference using `&mut`
  - *3.* Accept mutable reference using `some_string: &mut String`
```rust
use std::{io, string};

fn main() {
  let mut s = String::from("test");             //1
  fun(&mut s);                                  //2
}
fn fun(s: &mut String){                         //3
  s.push_str("Hello");
  println!("{}", s);
}
# rustc test.rs
# test.exe
```

- **2. [Scope of Mutable References](Scope_of_Mut_Refs)**
