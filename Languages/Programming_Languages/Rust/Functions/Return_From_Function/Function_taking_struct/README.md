## Function Taking struct as argument
- *1.* Passing Structure as Reference ie [BORROWING not taking ownership](/Languages/Programming_Languages/Rust)
- *2.* Accepting function as Reference
```rust
struct dimen {
    len:u32,
    width:u32
}

fn main() {
    let a = dimen {
        len:10,
        width:20
    };
    println!("{}",area(&a));    //1
}

fn area(b:&dimen) -> u32 {      //2
    b.len*b.width
}
```
