## Default Statement in match
- Rust does have default same as switch and represented by underscore `_`.
- **Example Code**
  - _a._ Switch is defined using match
  - _b._ Default case is represented using `_`. For everything except 1,7 this will be executed.
```rust
//#[derive(Debug)]
fn find(var:u8) -> u8 {
    match var{                          //a
        1 => {println!("one");
            1
        },
        7 => {println!("seven");
            7
        },
        _ => {println!("default");        //b
            255
        }
    }
}
fn main() {
    println!("{:#?} ",find(3));
}

$ rustc test.rs
$ test.exe
default
255
```
