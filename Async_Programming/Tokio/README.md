**Tokio**
- [Spawn a Task](#spawn)
  - [1. tokio::spawn()](#tos)
  - [2. tokio::task::spawn_blocking()](#tosb)
- Comparison
  - [futures::executor::block_on() vs tokio::task::spawn_blocking](#v1)

## Tokio
- This is [asynchronous](../) [runtime](https://www.quora.com/What-does-the-runtime-system-do-in-C) in rust, used for writing networking applications.
- [Runtime?](https://www.quora.com/What-does-the-runtime-system-do-in-C)

<a name=spawn></a>
### Spawning new Task. (Tasks/Green Thread != OS Thread)
  - Execute a task [concurrently]() with other tasks. Tasks are non-blocking.
  - The spawned task may execute on the current/different thread.

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

## Comparison
<a name=vs1></a>
### futures::executor::block_on() vs tokio::task::spawn_blocking()
> These are 2 different approaches to execute async tasks in tokio

|| futures::executor::block_on | tokio::task::spawn_blocking() |
|---|---|---|
|What|Run 1 future to completion and there is only thread within tokio<li>There are no other tasks on tokio</li>|<li>This spawn a blocking task into a separate thread from the Tokio runtime's thread pool.</li><li>while there can be other non-blocking tasks on tokio runtime</li>|

<a name=vs2></a>
#### tokio::spawn() vs tokio::task::spawn_blocking()
| | tokio::spawn | tokio::task::spawn_blocking() |
|---|---|---|
| What | spawn Non-blocking tasks within tokio runtime | spawn blocking tasks within tokio runtime |
| Where task is executed | Within the Tokio runtime's event loop | In separate thread from the Tokio runtime's thread pool |
| blocking | no | Yes. Perform CPU-bound or blocking operations without blocking the Tokio runtime's event loop |

<a name=vs3></a>
#### tokio::spawn vs tokio::task::spawn_local
||tokio::spawn|tokio::task::spawn_local|
|---|---|---|
|What|spawns async task|spawns async task|
|What|Spwaned Task can run on any thread managed by Tokio|Task should run on same thread that called tokio::spawn_local()|
|Return|`[JoinHandle](super::JoinHandle)`||
