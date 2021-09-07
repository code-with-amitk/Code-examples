**Asynchronous Programming in Rust**
- [async function](#as)
- [block_on()](#b)
- [await](#aw)

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

<a name=as></a>
### async function
Function prefixed with async & which will run asynchronously in rust.
```rs
async fn fun() {
    ...
}
```

<a name=b></a>
### block_on() 
Block/sleep the caller until async function does not run to completion. block_on() returns [future](/Languages/Programming_Languages/Rust/Triat_Interface).
```rs
use futures::executor::block_on;
async fn fun() {
    println!("hello, world!");
}
fn main() {
    block_on(fun());        //main() is blocked until fun() does not completes
}
```

<a name=aw></a>
### await
Inside [async function](#as) await is used to wait for another async function.
- **await vs block_on()** 
```c
                                        |   await          |        block_on()    |
----------------------------------------|------------------|----------------------|
Blocks current thread                   |     no           |          yes         |
wait for future to complete             |     yes          |          yes         |
Other tasks in async function can run?  |     yes          |          no          |
```
**Code**
```rs
$ cat Cargo.toml
[dependencies]
futures = "0.3"

//////Ex-1. block_on()//////////
$ cat main.rs
use futures::executor::block_on;
async fn fun1() { print!("fun1"); }
async fn fun2() { print!("fun2"); }
fn main() {
    block_on(fun1());                       //main() blocks until fun1(),fun2() does not compelte
    block_on(fun2());
}
$ main.exe
fun1 fun2

///////Ex-2. await()/////////////
$ cat main.rs
use futures::executor::block_on;
async fn fun1() { print!("fun1"); }
async fn fun2() { print!("fun2"); }

aync fn async_main() {                  //fun1(),fun2() can independently execute. async_main() can run other tasks independently as well.
    fun1().await;
    //other work
    fun2.await();
}

fn main() {
    block_on(async_main());
}
```
