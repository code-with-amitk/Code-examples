- [Tokio](#tok)
- [tokio::spawn](#ts)
- [tokio::task::spawn_local](#ts)
- **Examples**
  - [Mini Redis](#mr)

<a name=tok></a>
### Tokio
- This is [asynchronous](/Threads_Processes_IPC/Terms) [runtime](https://www.quora.com/What-does-the-runtime-system-do-in-C) in rust, used for writing networking applications.
- **Spawning?** 
  - Execute concurrently to other tasks
  - The spawned task may execute on the current thread, or it may be sent to a different thread to be executed

||tokio::spawn|tokio::task::spawn_loca|
|---|---|---|
|What|Spawns a new asynchronous task|task is Green Thread. Spawns a `!Send` future on the local task set.|
|Return|`[JoinHandle](super::JoinHandle)`||

<a name=ts></a>
### tokio::spawn
- [Runtime?](https://www.quora.com/What-does-the-runtime-system-do-in-C), [Tokio?](/Libraries/Tokio/)
```rs
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
