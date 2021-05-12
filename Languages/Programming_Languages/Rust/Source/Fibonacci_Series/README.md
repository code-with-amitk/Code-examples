## Fibonacci Series
```rust
use std::io;

fn main() {
    println!("Enter nth number of fabinacci series");

    //Take string input
    let mut str_input = String::new();
    io::stdin().read_line(&mut str_input).expect("Failed to read");

    //Convert string to float
    let u32Input:u32 = str_input.trim().
                parse().expect("Failed to convert");
    
    //Start from 1
    let mut a = 1;
    let mut b = 2;
    let mut c;
    println!("{}",a);
    println!("{}",b);
    let mut count = 1;
     loop{
        c = a+b;
        println!("{}",c);
        a=b;
        b=c;
        if count==u32Input {
            break;
        }
        count += 1;
     }
}
# rustc test.rs
# test.exe
```
