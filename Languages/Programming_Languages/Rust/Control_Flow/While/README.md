## While loop
```rust
fn main() {
  let mut a = 3;

  while a != 0 {
    println!("a:{}", a);

    a -= 1;
  }
}
# rustc test.rs
# test.exe
a:3
a:2
a:1
```
