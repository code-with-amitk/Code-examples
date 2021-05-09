## loop
- Loop executes infinitely until we press Control^C.
```rust
fn main() {
    loop {
        println!("again!");
    }
}
# rustc test.rs
# ./test.exe
again!
again!
again!
again!
^Cagain!
```

## Returning Values from Loops
```rust
fn main() {
    let mut counter = 0;

    let result = loop {
        counter += 1;

        if counter == 10 {
            break counter * 2;
        }
    };

    println!("The result is {}", result);               //Output=20
}
```

