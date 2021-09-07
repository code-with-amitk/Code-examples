**Asynchronous Programming in Rust**

## Asynchronous
- `.await` is used to write Asynchronous function in Rust, it transforms block of code into a state machine that implements a [trait](..) called Future.
- async function returns Future Value.
```rs
$ cat Cargo.toml
[dependencies]
futures = "0.3"

$ cat test.rs
async fn do_something() {
/* ... */ 
}
```
