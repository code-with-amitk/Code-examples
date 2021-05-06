## Variables
- **Immutable/const?** Whose value cannot be changed after creation. By default variables are immutable.
- **1. Example: Default variable is immutable**
```rust
fn main() {
    let x = 5;
    println!("x: {}", x);
    x = 6;
}

$ cargo run
 |     x = 6;
 |     ^^^^^ cannot assign twice to immutable variable
error: aborting due to previous error
```
- **2. Example, Making x a mutable**
```rust
fn main() {
    let mut x = 5;        //Making variable mutable using mut keyword
    println!("x: {}", x);
    x = 6;
}
$ cargo run
...
The value of x is: 5
The value of x is: 6
```
