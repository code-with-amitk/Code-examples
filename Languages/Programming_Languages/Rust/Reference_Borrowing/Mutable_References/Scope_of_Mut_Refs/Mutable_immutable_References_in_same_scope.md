## Mutable & immutable References in same scope
- Mutable & immutable references are not allowed in same scope.
```rust
    let mut v = vec![1, 2, 3, 4, 5];

    let first = &v[0];

    v.push(6);                                    //Compilation Error

    println!("first:{}", first);
```
- **Compilation Error Why?**
  - The code might look like should work. 
  - This error is due to the way vectors work. adding a new element onto the end of the vector might require allocating new memory and copying the old elements to the new space. 
  - if there isn’t enough room to put all the elements next to each other where the vector currently is. In that case, the reference to the first element would be pointing to deallocated memory. 
  - The borrowing rules prevent programs from ending up in that situation.
