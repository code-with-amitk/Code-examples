**Asynchronous Programming in Rust**
- [async function](#as)
- [block_on()](#b)

## Asynchronous Programming
To write asynchronous function in rust we need to perform these 3 tasks:
- _1._ Start the [Runtime](https://www.quora.com/What-does-the-runtime-system-do-in-C) ([Tokio](/Libraries/Tokio/) or async_std or smol etc)
- _2._ Spawn a [Future](/Languages/Programming_Languages/Rust/Triat_Interface)
- _3._ Call blocking or CPU-intensive function in seperate thread
```rs
$ Cargo.toml
[dependencies]
futures = { version = "0.3.*" }
tokio = {version = "0.2.*", features = ["full"] }

$ main.rs
use tokio::task;

fn fib_cpu_intensive(n: u32) -> u32 {
    match n {
        0 => 0,
        1 => 1,
        n => fib_cpu_intensive(n - 1) + fib_cpu_intensive(n - 2),
    }
}

async fn fun(arg) {
    let threadpool_future = task::spawn_blocking(||fib_cpu_intensive(30));    //3
    todo!()
}

fn main() {
    let mut rt:Runtime = tokio::runtime::Runtime::new().unwrap();     //1. Start runtime
    let local:LocalSet = tokio::task::LocalSet::new();
    local.block_on (&mut rt, async move {fun(arg).await});            //2
}
```

### block_on() 
This will block/sleep current thread until [future]() is not run to completion.
```rs
use futures::executor::block_on;

async fn hello_world() {
    println!("hello, world!");
}

fn main() {
    let future = hello_world();     // Nothing is printed
    block_on(future);               // `future` is run and "hello, world!" is printed
}
```

- `.await` is used to write Asynchronous function in Rust, it transforms block of code into a state machine that implements a [Future trait](/Languages/Programming_Languages/Rust/Triat_Interface).
- async function returns [Future](/Languages/Programming_Languages/Rust/Triat_Interface).
```rs
$ cat Cargo.toml
[dependencies]
futures = "0.3"

$ cat test.rs
async fn do_something() {
/* ... */ 
}
```
