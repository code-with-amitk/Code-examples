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
let (s, r) = async_channel::unbounded();

assert_eq!(s.send("Hello").await, Ok(()));    //Sends a message into the channel.

assert_eq!(r.recv().await, Ok("Hello"));    //Receives a message from channel. If the channel is empty, this method waits until there is a message.
```
