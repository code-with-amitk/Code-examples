- **Task != OS Thread**
- **Ways to create Async Tasks**
  - [1. tokio::spawn()](#tos)
  - [2. tokio::task::spawn_blocking()](#tosb)
  - [3. futures::executor::block_on()](#bo)
- **Comparison**
  - Tokio tasks
    - [spawn() vs spawn_blocking()](#vs1)
    - [spawn() vs spawn_local()](#vs2)
  - Future vs Tokio
    - [block_on() vs spawn_blocking()](#vs3)


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

///////////////////////////////////////////////
$ cat main.rs
use tokio::task;
fn fun() {
    println!("thread-1");
    std::thread::sleep::from_sec(10);
}
#[tokio::main]
async fn main() {

    /* spawn() returns `struct JoinHandle`
        This is similar to joining a thread in other programming languages.
        It allows you to wait for the task to complete and 
        obtain the result or handle any potential errors.
    */
    let handle = task::spawn(async {
        fun()
    });
    match handle {
        Ok(_) => {
            // Task completed successfully
            println!("Task completed successfully");
        }
        Err(e) => {
            // Task encountered an error
            println!("Task encountered an error: {:?}", e);
        }
    }
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

## Comparison
### Tokio::tasks
> tokio::spawn(), tokio::task::spawn_blocking(), tokio::task::spawn_local

<a name=vs1></a>
#### spawn() vs spawn_blocking()
| | spawn() | spawn_blocking() |
|---|---|---|
| What | spawn Non-blocking tasks within tokio runtime | spawn blocking tasks within tokio runtime |
| Where task is executed | Within the Tokio runtime's event loop | In separate thread from the Tokio runtime's thread pool |
| blocking | no | Yes. Perform CPU-bound or blocking operations without blocking the Tokio runtime's event loop |

<a name=vs2></a>
#### spawn() vs spawn_local()
||spawn()|spawn_local()|
|---|---|---|
|What|spawns async task|spawns async task|
|What|Spwaned Task can run on any thread managed by Tokio|Task should run on same thread that called tokio::spawn_local()|
|Return|`[JoinHandle](super::JoinHandle)`||

<a name=vs3></a>
#### block_on() vs spawn_blocking()
> future::executor::block_on(), tokio::task::spawn_blocking() These are 2 different approaches to execute async tasks in tokio

|| block_on() | spawn_blocking() |
|---|---|---|
|What|Run 1 future to completion and there is only thread within tokio<li>There are no other tasks on tokio</li>|<li>This spawn a blocking task into a separate thread from the Tokio runtime's thread pool.</li><li>while there can be other non-blocking tasks on tokio runtime</li>|
