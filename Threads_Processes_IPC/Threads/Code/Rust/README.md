- **Comparison**
  - [`std::thread::spawn() vs tokio::spawn()`](#vs1)
- **Create Threads**
  - [1. `thread::spawn() = OS Thread`](#ts)

### Comparison
<a name=vs1></a>
#### `std::thread::spawn() vs tokio::spawn()`
| | `std::thread::spawn()` | tokio::spawn |
|---|---|---|
| Provided by | Standards library | tokio runtime(executes within tokio runtime) |
| Blocking | yes(Runs independently of the Tokio runtime) | no |


### Creating Threads
<a name=ts></a>
#### 1. `std::thread::spawn()` = OS Thread
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


