Channel



## Channel
- Channel is similar to [Pipe in Linux](/Threads_Processes_IPC/IPC).
- It has two halves: a transmitter and a receiver. 
  - **a. transmitter(Sender)** 
    - put rubber ducks into the river
    - Senders can be cloned and shared among threads
  - **b. Receiver** 
    - gets the duck.
    - Receivers can be cloned and shared among threads
- One part of your code calls methods on the transmitter with the data you want to send, and another part checks the receiving end for arriving messages.
- Types of channels
  - **[1. Asynchronous channel](async):** Neither reciever, nor sender waits on channel.
  - **[2. Synchronous channel](sync_channel):** Sender waits on channel until reciever recieves the message.
