**Create Threads**
- [1. thread::spawn() = OS Thread](#ts)
- [2. tokio::spawn() = Green Threads](#tos)

### [Rust](/Languages/Programming_Languages/Rust)
- Use [move](/Languages/Programming_Languages/Rust/Functions) before closure if want closure to take ownership of the values it’s using rather than allowing Rust to infer that it should borrow the values

<a name=ts></a>
#### 1. thread::spawn() = OS Thread
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
