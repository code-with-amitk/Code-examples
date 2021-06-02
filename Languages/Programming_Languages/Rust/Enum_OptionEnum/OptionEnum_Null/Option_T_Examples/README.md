## Code
- **1. Initializing and using Option<`T`>**
```
fn main() {
    let a:Option<i32>= Some(2);
    let b:Option<i32>= None;

    println!("a:{:#?}",a);
    println!("b:{:#?}",b);
}    
$ main.exe
a:Some(
    2,
)     
b:None
```
- **2. We cannot add Option<`T`> to non Option<`T`>**
```rust
fn main() {
    let x: i8 = 5;
    let y: Option<i8> = Some(5);

    let sum = x + y;                //Compliation Error
}    
```
