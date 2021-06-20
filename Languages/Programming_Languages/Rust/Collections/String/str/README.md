## str
- str is [Immutable Reference](/Languages/Programming_Languages/Rust/Reference_Borrowing). Immutable means which cannot be changed
```rust
    let a = "T11 is Consistency";
    let b:&str = &a[0..4];            //Type of string slice is immutable reference.
    println!("{}",b);                 //T11
    
//Function returning string slice
fn main() {
    let mut a = String::from("T11 is Consistency");
    let b = fun(&a);                                      //Function taking string reference
    println!("{}",c);
}

fn fun(s:&String) -> &str {                               //Function returning String Slice
    &s[0..4]
}
```
