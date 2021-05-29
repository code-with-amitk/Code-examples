## Enum Holding Multiple Datatypes
- *1.* To print debugging information, we need to explicitly add annotation `#[derive(Debug)]` for enum.
- *2.* Enum data structure holding 2 variables:
  - IPv4 holding 4 u8 types.
  - IPv6 holding String type.
- *3.* Router1 variable created of type IPv4 and router2 of IPv6.
- *4.* Printing enum variables.
```rust
use std::{string::String, u32};

#[derive(Debug)]                //1
enum Address{                   //2
    IPv4(u8,u8,u8,u8),
    IPv6(String),
}

fn fun (addr1:&Address,addr2:Address) {         //4
    println!("IPv4 {:#?}",addr1);
    println!("IPv6 {:#?}",addr2);
}

fn main() {
    let router1:Address = Address::IPv4(10,11,12,13);               //3
    let router2:Address = Address::IPv6(String::from("::1"));
    fun(&router1,router2);
}

# rustc test.rs
# .\test.exe
IPv4 IPv4(
    10,
    11,
    12,
    13,
)
IPv6 IPv6(
    "::1",
)
```
