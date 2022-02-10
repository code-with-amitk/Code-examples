Automated Tests
- **Examples**
  - [Simple function](#sim)
  - [All tests inside module](#mod)
  - [Running tests by name](#byname)
  - [Ignoring some tests, ie should not be run](#ignore)
  - [async function test](#as)
- Unit Tests, Integration Tests
  - [1. Unit Tests](#unit)
  - [2. Integration Tests](#int)

## Automated Tests
In rust we can write test function with which we can test our existing code. 
- With *[cargo](/Languages/Programming_Languages/Rust/Cargo_BuildSystem) test* command, Rust builds a test runner binary that runs the functions annotated with the test attribute and reports on whether each test function passes or fails.

## Test Examples

<a name=sim></a>
#### Simple function
Functions preceded by attribute `#[test]` is a test function. [assert!(), assert_eq!(), assert_ne!()](/Languages/Programming_Languages/Rust/Functions)
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
#### All tests inside module
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

<a name=byname></a>
#### Running tests by name
```rs
pub fn add_two(a: i32) -> i32 {
    a + 2
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn add_two_and_two() {
        assert_eq!(4, add_two(2));
    }

    #[test]
    fn add_three_and_two() {
        assert_eq!(5, add_two(3));
    }

    #[test]
    fn one_hundred() {
        assert_eq!(102, add_two(100));
    }
}

$ cargo test add_three_and_two          //Will only run test=add_three_and_two
$ cargo test one                        //Will run all test cases having one in them
```

<a name=ignore></a>
#### Ignoring some tests, ie should not be run
ignore attribute will not run the test.
```rs
#[test]
fn it_works() {
    assert_eq!(2 + 2, 4);
}

#[test]
#[ignore]
fn expensive_test() {
    ..
}

$ cargo test
$ cargo test -- --ignored             // If we want to run only the ignored tests
```

<a name=as></a>
#### async function test
```rs
# Cargo.toml
[package]
name = "async_test"
version = "0.1.0"
edition = "2018"
[dependencies]
actix-rt = "*"

# main.rs
fn main() {}

async fn fun(s: &str) -> String{
    "Hello".to_string()
}

#[cfg(test)]
#[allow(non_snake_case)]
mod tests {
    use super::*;
  
    #[actix_rt::test]
    async fn fun_test() {
      assert_eq!(fun("a").await, "Hello".to_string());
    }
}
$ cargo test
```

## Unit Tests, Integration Tests
<a name=unit></a>
### 1. Unit Tests
- These tests are placed in same src file where source code is placed.
- The convention is to create a module named **tests** in each file to contain the test functions and to annotate the module with cfg(test).
- `#[cfg(test)]` annotation on the tests module only runs with `cargo test` command not with `cargo build`, saving Compile time.
- Also tests module annotated with `#[cfg(test)]` is not included in compiled artifact hence space not increased.

<a name=int></a>
### 2. Integration Tests
- These are placed in DIFFERENT DIRECTORY. These don’t need the `#[cfg(test)]` annotation.
- These tests use our library in the same way any other code would, which means they can only call functions that are part of your library’s public API. ie `pub fn fun()..`
- We need to create a tests directory at the top level of our project directory, next to src. We can then make as many test files as we want to in this directory, and Cargo will compile each of the files as an individual crate.
```rs
project
  |- src
  |- tests      //Cargo will look for integration test files in this directory
      |- test1
      |- test2
```
- If our project is a binary crate that only contains a src/main.rs file and doesn’t have a src/lib.rs file, WE **CANNOT** create integration tests in the tests directory. Why?
  - Only library crates expose functions that other crates can use; binary crates are meant to be run on their own.
