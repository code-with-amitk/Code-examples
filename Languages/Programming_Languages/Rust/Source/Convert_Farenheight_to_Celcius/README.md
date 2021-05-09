## Convert Farenheight to Celcius
- Formula for conversion:
```c
  (Farenheight - 32.0) * 5.0 / 9.0 = Celcius
```
- **Code**
```rust
fn main() {
  println! ("Enter Temp in farenheight \n");
  
  //Take input as String
  let mut str_input = String::new();
  io::stdin().
    read_line(&mut str_input).
    expect("Failed to read");
    
  //Convert String to float
  let a:f32 = str_input.
                trim().
                parse().
                expect("Failed to convert");

  //Calculate Celcius
  let b:f32 = (a - 32.0)*5.0/9.0;
  
  println!("Temp in Celcius: {}", b);
}
```
