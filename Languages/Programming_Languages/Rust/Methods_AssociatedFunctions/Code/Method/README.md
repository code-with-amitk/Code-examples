## Creating Method
  - *1.* Used for [dumping struct variables](../Data_Types/Compound/Struct/Dumping_Struct_Variables)
  - *2.* impl (implementation) block is used to define method within context of struct
  - *3.* 1st parameter is self. To refer struct variables we use self.
    - if we want to change inside structure use `mut &self`.
  - *4.* Called method using object.method_name() syntax.
```rust
use std::{string::String, u32};

#[derive(Debug)]                //1
struct Rectangle {
    len:u32,
    width:u32
}
impl Rectangle{                 //2
    fn area(&self) -> u32{            //3
        return self.len*self.width;   //3
    }
}

fn main() {
    let a = Rectangle {
        len:10,
        width:20
    };

    println!("{:#?}",a);
    println!("{}",a.area());          //4
}
```
