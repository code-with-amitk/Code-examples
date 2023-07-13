- **Comparison**
  - [std::thread::spawn() vs tokio::spawn()](#vs1)
  - [tokio::spawn() vs tokio::task::spawn_blocking()](#vs2)
  - [tokio::spawn vs tokio::task::spawn_local](#vs3)
- **Create Threads**
  - [1. std::thread::spawn() = OS Thread](#ts)
  - [2. tokio::spawn() = Green Threads](#tos)
  - [3. tokio::task::spawn_blocking() = Green Threads](#tosb)

### Comparison
<a name=vs1></a>
#### std::thread::spawn() vs tokio::spawn()
| | std::thread::spawn() | tokio::spawn |
|---|---|---|
| Provided by | Standards library | tokio runtime(executes within tokio runtime) |
| Blocking | yes(Runs independently of the Tokio runtime) | no |

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

### Creating Threads
<a name=ts></a>
#### 1. std::thread::spawn() = OS Thread
```rs
$ cargo new thread1

$ cat main.rs
use std::thread;
fn fun1() {
	println!("Thread-1");
}

fn main() {
	let handle1 = thread::spawn(fun1);                      //Thread-1
	let handle2 = thread::spawn(                           //Thread-2 created using closure       
		|| {
		    for i in 1..5 {
		    	println! ("Thread-2");
			thread::sleep (Duration::from_millis(1));
		    }
		}
	);
	handle1.join().unwrap();                           //Thread1, Thread2 are joinable. main will not exit without t1,t2
	handle2.join().unwrap();
}
$ cargo build
$ cargo run
```

<a name=tos></a>
#### 2. tokio::spawn() = [asynchronous](/Threads_Processes_IPC/Terms/README.md#as) [Green Thread](/Threads_Processes_IPC/Threads#usks)
- [tokio](/Languages/Programming_Languages/Rust/Tokio/)::spawn is 1 level up from threads. 
- These are user level non-blocking threads(ie if thread blocks on any call, due to async it will return immediately) means now thread will also not block.
- Use [move](/Languages/Programming_Languages/Rust/Functions) before closure if want closure to take ownership of the values it’s using rather than allowing Rust to infer that it should borrow the values
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
#### 3. tokio::task::spawn_blocking()
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
