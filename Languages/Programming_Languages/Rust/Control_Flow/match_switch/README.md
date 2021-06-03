## match 
- This is similar to (switch + enum class) of c++.
- **match Example**
  - _1._ match is followed by expression to be evaluated
  - _2._ This is called _match arm_. `pattern => code`. Pattern is matched and corresponding code is executed. Each arm is seperated by `,`.
```rust
enum Color{
    Red,
    Black,
    White,
}
fn color_value(var:Color) -> u8 {
    match var{                        //1
        Color::Red => {               //2
            print!("Red");
            1
        }
        Color::Black => 2,
        Color::White => 3,
    }
}
fn main() {
    println!("{:#?}",color_value(Color::Red));
}
```
- **[Patterns that Bind to Values](Patterns_that_Bind_to_Values)**
