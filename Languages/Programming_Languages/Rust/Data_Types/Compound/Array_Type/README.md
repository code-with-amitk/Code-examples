## Array Type
- Array elements are allocated contigiously on stack, unlike vectors which's allocated on heap.
- Unlike Tuple, every element of an array must have the same type.
- **Fixed length.** arrays in Rust have a fixed length
- Array are written as a comma-separated list inside square brackets
```rust
fn main() {
    let a = [1, 2, 3, 4, 5];
    
    let a: [i32; 5] = [1, 2, 3, 4, 5];
    
    let a = [3; 5];                     //[element, no-of-elements].  a = [3,3,3,3,3]
    
    //Accessing array elements
    let first = a[0];
    let second = a[1];    
}
```
