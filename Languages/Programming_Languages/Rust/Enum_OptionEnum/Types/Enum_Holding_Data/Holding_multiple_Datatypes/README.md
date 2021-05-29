## Enum Holding Multiple Datatypes
- *1.* To print debugging information, we need to explicitly add annotation `#[derive(Debug)]` for enum.
- *2.* Enum data structure holding 3 variables:
  - NoIP does not hold any data.
  - IPv4 holding 4 u8 types.
  - IPv6 holding String type.
- *3.* Router1 variable created of type IPv4, router2 of IPv6, disconnectedIP of no ip.
- *4.* Printing enum variables.
```rust
use std::{string::String, u32};

#[derive(Debug)]                //1
enum Address{                   //2
    NoIP,
    IPv4(u8,u8,u8,u8),
    IPv6(String),
}

/*THIS IS EQUIVALENT TO:
struct NoIP;
struct IPv4 {
    a: i32,
    b: i32,
    c: i32,
    d: i32,
}
struct IPv6 {
    e:String
}    
*/

fn fun (addr1:&Address,addr2:Address, addr3:Address) {         //4
    println!("IPv4 {:#?}",addr1);
    println!("IPv6 {:#?}",addr2);
    println!("Disconnected {:#?}",addr3);
}

fn main() {
    let router1:Address = Address::IPv4(10,11,12,13);               //3
    let router2:Address = Address::IPv6(String::from("::1"));
    let disconnectedDevice:Address = Address::NoIP;
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
Disconnected NoIP
```

