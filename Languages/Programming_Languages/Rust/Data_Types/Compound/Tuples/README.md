## Tuple Type
- Grouping together a number of values of different types into one compound type.
- Tuples are fixed length, once declared, they cannot grow or shrink in size.
- **Destructring a Tuple?** Assigning tuple variable values to seperate variables to use.
- **Accessing tuple using index values?** we can access a tuple element directly by using a period (.) followed by the index of the value we want to access. 1st index is 0.
```rust
fn main() {
  let tup = (500, 6.4, 1);

  let tup1: (i32, f64, u8) = (500, 6.4, 1);             //optional type annotation added
  
  let (x, y, z) = tup;                                  //Destructring tuple

  println!("The value of y is: {}", y);                 //6.4
  
  //Accessing tuple using (.) and index
  let a = tup.0                                         //500
  let b = tup.1                                         //6.4
  let c = tup.2                                         //1
}
```
