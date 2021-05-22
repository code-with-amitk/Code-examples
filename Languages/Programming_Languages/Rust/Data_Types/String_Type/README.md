## String Type
- [string literals](../../StackHeap_CompileRuntime) are allocated on stack.
```rust
  let s:string = "test";
```
- **String** is allocated on Heap, ie can be resized.
```rust
  let mut s = String::from("hello");      //Creating String from string literal
  s.push_str(", world!");                 //push_str() appends to string
  println!("{}", s);                      //This will print `hello, world!`
```

### [Deep copy, Shallow copy, move](Deep_Shallow_Move)
### [String Slice](String_Slice)
