**Channel**
- **Types of Channels**
  - [1. Synchronous](#sync)
    - **mpsc: multiple producer single consumer**
      - [1 Producer, 1 consumer](#1p1c)
      - [Multiple Producer 1 consumer](#mp1c)
  - [2. Asynchronous](#async)
    - [Create Message Queue](#cmq)

## Channel = [Pipe in Linux](/Threads_Processes_IPC/IPC).
- It has two halves: a transmitter(sender) and a receiver. 
  - **a. transmitter(Sender):** Put rubber ducks into the river. Senders can be cloned and shared among threads
  - **b. Receiver:** Gets the duck. Receivers can be cloned and shared among threads

## Types of channels

<a name=sync></a>
#### 1. Synchronous channel
- Sender waits on channel until reciever recieves the message.
- When all Senders or all Receivers are dropped, the channel becomes closed. When a channel is closed, no more messages can be sent, but remaining messages can still be received.
- **mpsc: multiple producer single consumer**

<a name=1p1c></a>
**1 Producer, 1 consumer**
```rs
use std::sync::mpsc;                            //mpsc: Multiple producer, Single Consumer.
use std::thread;

fn main() {
    let (tx, rx) = mpsc::channel();            //1. Created channel having 2 ends(transmitter, reciever)
    
    let tid1 = thread::spawn(                  //2. Thread-1(Transmitter) owns tx(using move) and sends val=test on it
        move || {
            let val = String::from("test");
            tx.send(val).unwrap();
            //println!("{}", val);              //We cannot use value after sending over channel, bcoz reciever might change it.
        }                                       //ie ownership is transferred.
    );
    
    println!("{}", rx.recv().unwrap());         //3. Thread-2(main) recieves message over rx end of channel.
}
$ cargo run
test
```

<a name=mp1c></a>
**Multiple Producer 1 consumer**
We will clone transmitting end of channel.
```rs
use std::sync::mpsc;
use std::thread;
use std::time::Duration;

fn main() {
    let (tx, rx) = mpsc::channel();
    let tx1 = tx.clone();
    
    thread::spawn(move || {
        let vals = vec![
            String::from("hi"),
            String::from("from"),
            String::from("thread1"),
        ];
        for val in vals {
            tx1.send(val).unwrap();                 //Sending over tx1
            thread::sleep(Duration::from_secs(1));
        }
    });

    thread::spawn(move || {
        let vals = vec![
            String::from("more"),
            String::from("messages"),               
        ];

        for val in vals {
            tx.send(val).unwrap();                    //Sending over tx
            thread::sleep(Duration::from_secs(1));
        }
    });

    for i in rx {
        println!("{}", i);
    }
}
$ cargo run
hi more thread1 from messages                       //See threads are executed in different order hence values recieved in different order
```

<a name=async></a>
### 2. Asynchronous channel (multi-producer, multi-consumer)
- Neither reciever, nor sender waits on channel(ie sender/reciever can send/recv and leave no need to wait).
- When all Senders or all Receivers are dropped, the channel becomes closed. When a channel is closed, no more messages can be sent, but remaining messages can still be received.
- **Kinds of channels**
  - **1. Bounded channel** with limited capacity.
  - **2. Unbounded channel** with unlimited capacity.
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

<a name=cmq></a>
#### Create Message Queue
```rs
Cargo.toml
[package]
name = "queue_using_channel"
version = "0.1.0"
edition = "2021"
[dependencies]
async-channel = "1.5.0"
tokio = { version = "1.16.1", features = ["full"] }

# src/main.rs
use async_channel::{Receiver, Sender};
#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
	// Create a channel that can transmit String values
    let (sender, receiver): (Sender<String>, Receiver<String>) = async_channel::unbounded();
    let message = "Hello, world!".to_string();

	// Send a message to the queue
	// await because sending a message is an asynchronous operation that may take some time to complet
    sender.send(message).await?;
    let received_message = receiver.recv().await?;
    println!("Received message: {}", received_message);
    Ok(())
}

$ cargo run
Received message: Hello, world!
```
