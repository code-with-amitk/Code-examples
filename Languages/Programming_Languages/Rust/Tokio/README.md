- [Tokio](#tok)
- [tokio::spawn](#ts)
- [tokio::task::spawn_local](#ts)
- **Examples**
  - [Mini Redis](#mr)

<a name=tok></a>
### Tokio
- This is [asynchronous](/Threads_Processes_IPC/Terms) [runtime](https://www.quora.com/What-does-the-runtime-system-do-in-C) in rust, used for writing networking applications.
- [Runtime?](https://www.quora.com/What-does-the-runtime-system-do-in-C)
- **Spawning?** Execute concurrently to other tasks. The spawned task may execute on the current thread, or it may be sent to a different thread to be executed.
- **tokio::spawn() function**
  - This is used to asynchronously spawn a new concurrent task or "green thread" It allows you to execute asynchronous code concurrently, without blocking the main thread of execution.

#### [Creating Threads](/Threads_Processes_IPC/Threads/Code/Rust/README.md)
- tokio::spwan
- tokio::spawn_blocking

### Examples
<a name=mr></a>
#### Mini redis
- [await()](/Threads_Processes_IPC/Terms/README.md#aw)
```rs
  Client-Application  --connect-------->  Mini-Redis
  set key=hello,value=world -------------->
  get key=hello <--------------------------

//1. Run mini-[redis](/System-Design/Concepts/Cache/DB_Caches) server in terminal window
$ cargo install mini-redis
$ mini-redis-server

//2. Create Redis client application, connect, set/get key
$ vim Cargo.toml
[dependencies]
tokio = { version = "1", features = ["full"] }
mini-redis = "0.4"

$ cat main.rs
use mini_redis::{client, Result};
#[tokio::main]
pub async fn main() -> Result<()> {

/*Client::connect():
  Provided by the mini-redis crate
  Asynchronously establishes a TCP connection with the specified remote address
Return:  handle: after successful connection establishment
*/
    let mut handle = client::connect("127.0.0.1:6379").await?;  //Open a connection to the mini-redis address.
    handle.set("hello", "world".into()).await?;                 //Set the key "hello" with value "world"
    let result = handle.get("hello").await?;                    //Get key "hello"
    println!("got value from the server; result={:?}", result);
    Ok(())
}
$ cargo run
got value from the server; result=Some(b"world")
```
