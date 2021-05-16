## Mutable References
### A. Can be modified
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

### B. 2 Mutable references are not allowed in particular scope
  - *Why?* To avoid data race conditions. Race condition occurs when any of 3 behaviours happen:
    - Two or more pointers access the same data at the same time.
    - At least one of the pointers is being used to write to the data.
    - There’s no mechanism being used to synchronize access to the data.
```rust
  let mut s = String::from("hello");
  let r1 = &mut s;
  let r2 = &mut s;                            //Compilation Error
  println!("{}, {}", r1, r2);
```
  - *Mutable References are allowed in seperate scope*
```rustc
  let mut s = String::from("hello");
  {
    let r1 = &mut s;
  } // r1 goes out of scope here, so we can make a new reference with no problems.
  let r2 = &mut s;
```
