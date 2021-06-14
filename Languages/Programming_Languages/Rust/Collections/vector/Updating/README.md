## Updating a Vector
- Since variables in rust is [immutable by default](/Languages/Programming_Languages/Rust), we need to make them mutable to update.
```rust
    let mut v = Vec::new();
    v.push(5);
    v.push(6);
    v.push(7);

OR 

    let mut v:Vec<i32> = vec![1,2];     //if mut is removed it gives Compilation error
    v = [3,4,5].to_vec();

    for a in v.iter() {
        print!("{} ", a);           //3 4 5
    }

```
