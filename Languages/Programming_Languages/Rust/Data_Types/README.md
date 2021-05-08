## Data Types in Rust
- Rust is STATICALLY-TYPES language(means type of variable should be known at compile time).
- *In Normal cases.* Compiler usually finds from value which is assigned.
- *Type Annotation?*  When many types are possible. Eg: String converted to a int using parse(), we must add a type annotation to tell type to complier.
```rust
  let a = 1;        //a inferred int
  let b = "get";    //b inferred string
  
  let c:u32 = "42".parse().expect("Not a number!");            //Type Annotation u32
```
- **Data Types in Rust**
  - *[1. Scalar: int, float, bool, char](Scalar)*
  - *[2. Compund: Tuple, Array](Compund)*
