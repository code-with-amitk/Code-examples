## Floating-Point Types
- Floating point are of 2 sizes f32(32 bit), f64(64 bit). 
- f64 is default. Why f64 is default, because on modern CPUs f64 is roughly the same speed as f32 but is capable of more precision.
```rust
fn main() {
    let x = 2.0;          //f64

    let y: f32 = 3.0;     //f32
}
```
- **All operations are supported on float**
```rust
fn main() {
    let sum = 5.2 + 10.1;               //addition

    let difference = 95.5 - 4.3;        //subtraction

    let product = 4 * 30;               //multiplication

    let quotient = 56.7 / 32.2;         //division

    let remainder = 43 % 5;             //remainder
}
```
