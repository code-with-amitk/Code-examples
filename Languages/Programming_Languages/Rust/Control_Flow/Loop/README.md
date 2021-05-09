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

