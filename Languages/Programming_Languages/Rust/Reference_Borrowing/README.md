## Borrowing = References
- **Ownership = passed by value**
- **Borrowing?** 
  - When variable is passed by reference(ie borrowed), we dont have ownership, hence variable cannot be changed.
  - Borrowing is opposite of taking ownership of the value.
```rust
use std::{io, string};      
fn main() {
  let s = String::from("test");   //String allocated on heap can be resized.
  fun(&s);                        //fun() taking reference
}
fn fun(s:&String){
  s.push_str("Hello");           //Compilation Error. References(borrowed objects) cannot be changed.
  println!("{}", s);
}
```
- **[Mutable References](Mutable_References):** To change borrowed objects(ie references)
- **[Dangling Reference](Dangling_Reference)**

