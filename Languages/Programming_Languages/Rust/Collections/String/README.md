## String
- *[string literal, string type, string slice](String_Literal_Type_Slice)*
- *[str](str)*
- string allocated on heap is shallow copy
```rust
  let s1:String = String::from("test");
  //let s2 = s1;                                //Shallow copy, ie s2,s1 both point to same memory. COMPLIER ERROR
  let s2 = s1.clone();                          //Deep Copy. Deep copy is costly operation.
  
  let a:i32 = 5;
  let b = a;                                  //Data on stack is always deep copied
```
