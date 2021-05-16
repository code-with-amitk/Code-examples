## References
- **What?** Reference to an object is opposite of taking ownership of the value.
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

- **[Borrowing](Borrowing)**
