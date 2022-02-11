## Channel
- Channel is similar to [Pipe in Linux](/Threads_Processes_IPC/IPC).
- It has two halves: a transmitter and a receiver. The transmitter(sender) put rubber ducks into the river, and the receiver gets the duck.
- One part of your code calls methods on the transmitter with the data you want to send, and another part checks the receiving end for arriving messages.
- Types of channels
  - **[1. Asynchronous channel](async):** Neither reciever, nor sender waits on channel.
  - **[2. Synchronous channel](sync_channel):** Sender waits on channel until reciever recieves the message.
