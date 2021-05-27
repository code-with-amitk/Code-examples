## How listen works internally
- **Kernel maintains 2 queues**
  - *1. Incomplete connection queue:* 
    - Sockets for which server has sent [SYN+ACK](/Networking/OSI-Layers/Layer-4/Protocols/TCP/State_Transition_Diagram) but not recieved final ACK. [state=SYN_SENT](/Networking/OSI-Layers/Layer-4/Protocols/TCP/State_Transition_Diagram)
    - Or Sockets for which server has recieved SYN and not sent SYN,ACK.
    - Once Final ACK is recieved, socket is moved to Completed Connection Queue.
  - *2. Completed connection queue:* 
    - Sockets for which server has recieved final ACK, ie 3 way handshake is completed. [state=ESTABLISHED](/Networking/OSI-Layers/Layer-4/Protocols/TCP/State_Transition_Diagram)
- Total Len of Connection queue = `1.5 x BACKLOG` //Berkley kernel implementation
```c
  Client                Server
  connect() ----SYN_i----> Incomplete Connection Queue
            <--SYN_j + ACK(i+1)-  Starts RTT(187 msec)  //Berkley kernel
            
            --ACK(j+1)-----> Moved to Compelted Connection Queue
```
- **Server busy cannot send SYN+ACK and ICQ keeps growing**
  - Server will not send RST since server may find room in future and can respond to client.
