## Associated Function
- *1.* Declared associated function returning Object with specific value.
- *2.* To call associated function :: is used.
```rust
use std::{string::String, u32};

#[derive(Debug)]
struct Rectangle {
    len:u32,
    width:u32
}
impl Rectangle{
    fn fun(len:u32) -> Rectangle{     //1
        Rectangle {
            len,
            width:len
        }
    }
}

fn main() {
    println!("{:#?}",Rectangle::fun(10));       //2
}

# rustc test.rs
# ./test.exe
Rectangle {
    len: 10,
    width: 10,
}
```
