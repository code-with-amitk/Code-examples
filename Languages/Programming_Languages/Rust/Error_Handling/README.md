- [1. What](#what)
  - [1.1 Recoverable Errors with Result](#recerrors)
    - [1.1.1 open() a file](#open)
    - [1.1.2 Providing error cases in open()](#err)

<a name=what></a>
# 1. Error Handling in Rust
- Rust considers every error in 2 categories.
  - _a._ Recoverable Errors with Result
  - _b._ Unrecoverable Errors with panic

<a name=recerrors></a>
## 1.1 Recoverable Errors with Result
- rust defines few of functions to return `enum Result<T,E>` when error happens.
```rust
enum Result<T, E> {
    Ok(T),              //T: Type of value returned in Success case
    Err(E),             //E: Type of error returned in failure case
}
```

<a name=open></a>
### 1.1.1 open() for opening a file
- _1._ res would be of type Result<T, E>
- _2._ Check file exists or not using `match` 
- _3._ **unwrap()** provides same functionality as match check(ie in 2). it unwraps the panic macro
- _4._ **expect()** expect provides a good error messages can convey your intent
```rust
use std::fs::File;
fn main() {
    let res = File::open("hello.txt");        //1
    match res {                               //2
        Ok(file) => file,
        Err(error) => panic!("Problem opening the file: {:?}", error),
    };
    
    let res1 = File::open("hello.txt").unwrap();  //3
    
    let res2 = File::open("hello.txt").expect("Failed to open hello.txt");      //4
}
$ ./test.exe
thread 'main' panicked at 'Problem opening the file: Os { code: 2, kind: NotFound, message: "The system cannot find the file specified." }', .\main.rs:16:23
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace
```

<a name=err></a>
### 1.1.2 Providing error cases in open()
  - _1._ Open the file. Match the result
  - _2._ if error occurred in opening the file
    - _2.1_ Error=file not found. Create the file and again check for error
    - _2.2_ For all other errors just panic
```rust
use std::fs::File;
use std::io::ErrorKind;

fn main() {
    let f = File::open("hello.txt");                                  //1
    match f {
        Ok(file) => file,
        Err(error) => match error.kind() {                            //2
            ErrorKind::NotFound => match File::create("hello.txt") {   //2.1
                Ok(fc) => fc,
                Err(e) => panic!("Problem creating the file: {:?}", e),
            },
            other_error => {                                           //2.2
                panic!("Problem opening the file: {:?}", other_error)
            }
        },
    };
}
```
