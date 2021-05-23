## Functions
- Function definition starts with fn.
- Coding convention followed in Rust is snake case ie underscores.
- See another_fun() is defined after main() that means only function definition is required, place(above or below main()) does not matter.
- **Parameters in function:** Type Annotation is mandatory in function parameters.
```rust
fn main() {
  println!("Main\n");
  another_fun (5, 6);
}
fn another_fun(x:i32, y:i32){               //Type annotation mandatory
  println!("Another_fun x: {}", x);
  println!("Another_fun y: {}", y);
}
```
- *[Returning from Function:](Return_From_Function)* value, reference, struct

## [Statements & Expressions](Statements_Expressions)
