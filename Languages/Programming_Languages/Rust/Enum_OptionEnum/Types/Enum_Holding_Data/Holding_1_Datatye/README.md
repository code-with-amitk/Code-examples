## Enum holding 1 datatype
- *1.* To print debugging information, we need to explicitly add annotation `#[derive(Debug)]` for enum.
- *2.* Enum variable can store string data.
- *3.* Creating enum variable having string data(192.0.0.1)
- *4.* Passing enum variable to function and printing.
```
use std::{string::String, u32};

#[derive(Debug)]                //1
enum Address{                   //2
    IPv4(String),
    IPv6(String),
}

fn fun (addr:&Address) {          //4
    println!("{:#?}",addr);
}

fn main() {
    let router1:Address = Address::IPv4(String::from("192.168.1.1"));   //3
    fun(&router1);
}

# rustc test.rs
# .test.exe
IPv4(
    "192.168.1.1",
)
```
