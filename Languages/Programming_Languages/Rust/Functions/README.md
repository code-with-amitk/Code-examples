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
- **Functions returning a value:**
  - *a.* Type of return value is specified with `->`
  - *b.* Last statement in function(without semicolon) is the return value.
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

## [Statements & Expressions](Statements_Expressions)
