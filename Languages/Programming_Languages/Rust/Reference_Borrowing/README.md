## References
- **What?** 
  - Reference to an object is opposite of taking ownership of the value.
  - We cannot change reference, Why? See borrowing below
```rust
fn main() {
    let s1 = String::from("hello");             //String allocated on heap can be resized.
    let len = fun(&s1);                         //fun() taking reference
    println!("The length of '{}' is {}.", s1, len);
}

fn fun(s: &String) -> usize {
    s.len()
}
```

### Borrowing
  - Ownership = passed by value.
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

- **[Mutable References](Mutable_References)**

