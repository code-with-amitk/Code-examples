## if Expression
- *a.* Paranthesis are mandatory in if-else block
- *b.* `()` is not required around if block.
- **Example**
```rust
fn main() {
  let a:i32 = 5;
  if a < 7 {
    println!("Yes");
  }else{
    println!("No");
  }
}  
# rustc test.rs
# ./test.exe
Yes
```

## Rust does not convert non-bool to bool 
  - This code give compilation error, Since It expects expression to be bool.
  - *Good Thing:* Unlike (C/C++), Rust does not try converting a(non-boolean) to bool
```rust
fn main() {
  let a = 3;                //a should be bool               
  if a {
    println!("Yes");
  }
}
# rustc test.rs
Compilation Error.

////////////This will work/////////////
fn main() {
    let a = 3;
    if a != 0 {
        println!("Yes");
    }
}
```

## else if expression
```rust
fn main() {
    let number = 6;

    if number % 4 == 0 {
        println!("number is divisible by 4");
    } else if number % 3 == 0 {
        println!("number is divisible by 3");
    } else if number % 2 == 0 {
        println!("number is divisible by 2");
    } else {
        println!("number is not divisible by 4, 3, or 2");
    }
}
```
