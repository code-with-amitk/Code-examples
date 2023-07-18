**Stack**
- [Implement stack](#im)

### Stack
- Rust provides stack-like data structure called Vec.
<a name=im></a>
#### Implement stack
- Push at end, pop from end.
```rs
fn main() {
    let mut stack: Vec<i32> = Vec::new();

    // Push elements to the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // pop() removes elements from end
    while let Some(top) = stack.pop() {
        println!("Popped element: {}", top);
    }
}
```
