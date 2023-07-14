- **Task != OS Thread**
- Ways to execute Async Tasks
  - [1. tokio::spawn()](#tos)
  - [2. tokio::task::spawn_blocking()](#tosb)
  - [3. futures::executor::block_on()](#bo)


### Task. (Tasks/Green Thread != OS Thread)
- Task can be [concurrently]() executed with other tasks. ie Tasks are non-blocking.
- Again, task may or may not execute on seperate thread.

#### Ways to spawn new task
<a name=tos></a>
**1. tokio::spawn()**
- [move](/Languages/Programming_Languages/Rust/Functions)
```rs
$ cat Cargo.toml
[package]
name = "tokio_spawn"
version = "0.1.0"
authors = ["amitk"]
edition = "2018"

[dependencies]
futures = { version = "0.3.*" }
tokio = {version = "0.2.*", features = ["full"] }

$ cat main.rs
use tokio::task;
fn fun_thread() {
    println!("thread-1");
}
#[tokio::main]
async fn main() {
    let join:JoinHandle<()> = task::spawn(async {		//spawn() returns `struct JoinHandle`
        fun_thread()
    });
    assert!(join.await.is_err());
}
$ cargo build
$ cargo run
thread-1
```

<a name=tosb></a>
#### 2. tokio::task::spawn_blocking()
```c
$ Cargo.toml
[dependencies]
futures = { version = "0.3.*" }
tokio = {version = "0.2.*", features = ["full"] }

$ main.rs
use tokio::task;

fn fun() {
  println!("fun");
}

async fn fun(arg) {
    let threadpool_future = task::spawn_blocking(||fun());    //3. Call blocking or CPU-intensive function in seperate thread
    todo!()
}

fn main() {
    let mut rt:Runtime = tokio::runtime::Runtime::new().unwrap();     //1. Start tokio runtime
    let local:LocalSet = tokio::task::LocalSet::new();
    local.block_on (&mut rt, async move {
      fun(arg).await
    });            //2. Spawn a future
}
```

<a name=bo></a>
#### 3. futures::executor::block_on() 
Block/sleep the caller until async function does not run to completion. block_on() returns [future](/Languages/Programming_Languages/Rust/Triat_Interface).
```rs
$ cat Cargo.toml
[dependencies]
futures = "0.3"

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
```
