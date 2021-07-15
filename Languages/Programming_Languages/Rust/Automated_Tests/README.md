- [Automated Tests](#what)
- [Test Examples](#ex)
  - [1. Simple function](#sim)
  - [2. All tests inside module](#mod)

<a name=what></a>
## Automated Tests
- In rust we can write test function with which we can test our existing code.
- When we run `cargo test` command, Rust builds a test runner binary that runs the functions annotated with the test attribute and reports on whether each test function passes or fails.

<a name=ex></a>
## Test Examples

<a name=sim></a>
### 1. Simple function
- _1._ Functions preceded by attribute `#[test]` is a test function. On running [cargo test](/Languages/Programming_Languages/Rust/Cargo_BuildSystem) Rust builds a test runner binary that runs the all functions annotated with the test attribute
- [assert!(), assert_eq!(), assert_ne!()](/Languages/Programming_Languages/Rust/Functions)
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

<a name=mod></a>
### 2. All tests inside module
- _2._ Inside all_tests module outside code cannot be seen, we use glob here so anything we define in the outer module is available to this all_tests module.
```rs
struct rect {
    len:u32,
    bre:u32
};
impl rect {
    fn can_hold (&self, var:rect) -> bool {
        if self.len > var.len && self.bre > var.bre {
            return true
        }
        false
    }
}

mod all_tests {
    use super::*;                          //2
    [#test]                                //1
    fn test_fun () {
        let var1 = rect {
            len:5,
            bre:5
        };
        let var2 = rect {
            len:3,
            bre:3
        };
        assert_eq!(var1.can_hold(&var2), false);       //can_hold(self=var1, var=var2)
    }
}
$ cargo test
```
