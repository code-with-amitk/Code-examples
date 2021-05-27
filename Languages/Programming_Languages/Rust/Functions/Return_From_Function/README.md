## Return Value from Function
- *a.* Type of return value is specified with `->`
- *b.* Last statement in function(without semicolon) is the return value.
- **Function returning a value**
```rust
fn main() {
  let y:i32 = fun (5);
  println!("fun y: {}", y);         //6
}
fn fun(x:i32) -> i32{              //a 
  println!("fun x: {}", x);
  6                                 //b
}
```
- *[Function returning a structure](Function_Returning_struct)*
- *[Function Taking struct as argument](Function_taking_struct)*
