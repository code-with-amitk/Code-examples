## Array Slice
- Read [String Slice]() to understand How slices are stored and their type
- Array Slice is taking piece of array.
- Type of Array slice is `&i[32]`
```rust
fn main() {
    let a = [1,2,3,4,5];
    let b = &a[1..3];             //Type of b is &[i32]
    println!("{}",b[0]);
}
```
