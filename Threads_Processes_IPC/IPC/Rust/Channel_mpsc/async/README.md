**async channel**

### [async_channel](https://docs.rs/async-channel/latest/async_channel/index.html)
- **What?**
  - Similar to channel, its used for sender to reciever communication, but it async (ie sender/reciever can send/recv and leave no need to wait).
  - This is async multi-producer multi-consumer channel.
  - When all Senders or all Receivers are dropped, the channel becomes closed. When a channel is closed, no more messages can be sent, but remaining messages can still be received.

#### Kinds of channels
- **Bounded channel** with limited capacity.
- **Unbounded channel** with unlimited capacity.

#### Code
```rs
# Cargo.toml
[package]
name = "async_channel"
version = "0.1.0"
edition = "2018"

[dependencies]
async-channel = {version = "1.5"}
tokio = {version = "0.2.*", features = ["full"] }

# main.rs
use async_channel;
async fn fun() {
    let (s, r) = async_channel::unbounded();

    assert_eq!(s.send("Hello").await, Ok(())); //Sends a message into the channel.
    assert_eq!(r.recv().await, Ok("Hello"));   //Receives a message from channel. If the channel is empty, this method waits until there is a message.
}

fn main() {
    let mut rt = tokio::runtime::Runtime::new().unwrap(); //1. Start tokio runtime
    let local = tokio::task::LocalSet::new();
    local.block_on(&mut rt, async move { fun().await });
}
```
