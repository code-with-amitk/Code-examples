## For loop
```rust
fn main() {
  let a = [1, 2, 3, 4, 5];
  for b in a.iter() {
    println!("val: {}", b);
  }
}
val: 1
val: 2
val: 3
val: 4
val: 5
```

## Reversing the range
```rust
fn main() {
  for b in (1..4).rev(){
    println!("val:{}",b);
  }
}
# rustc test.rs
# ./test.exe
val:3
val:2
val:1
```
