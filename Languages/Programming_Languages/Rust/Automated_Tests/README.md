- [Automated Tests](#what)
- [Testing simple function](#tests)

<a name=what></a>
## Automated Tests
- In rust we can write test function with which we can test our existing code.
- When we run `cargo test` command, Rust builds a test runner binary that runs the functions annotated with the test attribute and reports on whether each test function passes or fails.

<a name=tests></a>
## Testing simple function
- _1._ Functions preceded by attribute `#[test]` is a test function. On running [cargo test](/Languages/Programming_Languages/Rust/Cargo_BuildSystem) Rust builds a test runner binary that runs the all functions annotated with the test attribute
- _2._ [assert!](/Languages/Programming_Languages/Rust/Functions)
```rs
fn greater_than_ten(a:u32)->bool {
    if a > 10 {
        return true;
    }
    false
}

#[test]                                  //1
fn test1(){
    assert!(greater_than_ten(5));       //assert!(false) will assert
}

$ cargo test

```
