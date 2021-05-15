## String Type
- [string literals](../../StackHeap_CompileRuntime) are allocated on stack.
```rust
  let s:string = "test";
```
- **String** is allocated on Heap, ie we can store whatever big string we want in String type.
```rust
  let mut s = String::from("hello");      //Creating String from string literal
  s.push_str(", world!");                 //push_str() appends to string
  println!("{}", s);                      //This will print `hello, world!`
```

### [Deep copy, Shallow copy, move](Deep_Shallow_Move)
