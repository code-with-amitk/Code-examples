## State Transition Diagram
- *1.* [Connection Establishment: 3 way handshake](3_Way_Handshake)
- *2.* Data Flow
- *3.* [Connection Tear Down](Tear_Down_Process)

```html
    TCP-Client                                                    TCP-Server
STATE==>CLOSED                                                   STATE==>CLOSED
    socket()                                                     socket()
                                                                 bind()
                                                                 listen()    //Passive-Open
                                                                 STATE==>LISTEN
    connect()//Active Open ------SYN------------->
STATE==>SYN_SENT                                                  STATE==>SYN_RCVD
STATE==>SYN_RCVD  <---------SYN,ACK----------
                  ---------ACK--------------->
STATE==>ESTABLISHED                                               STATE==>ESTABLISHED
      //See Teardown for other States
```

<img src=TCP_State_Diagram.gif width=500 />
