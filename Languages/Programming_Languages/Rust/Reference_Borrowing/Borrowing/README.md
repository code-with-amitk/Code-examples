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

### Mutable References
- **A. Can be modified**
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

- **B. 2 Mutable references are not allowed in a scope**
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
