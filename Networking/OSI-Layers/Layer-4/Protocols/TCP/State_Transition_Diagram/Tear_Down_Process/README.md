## Connection Tear Down
- [3-way-handshake](../) for connection Establishment.
- Data flow happens. Now tear down
- **1/2Close:** Client cannot send data, But can receive.
- **TIME_WAIT?**
  - Party sending the Final ACK waits for 2MSL(around 4 minutes, Default MSL=2minutes) before entering CLOSE State.
  - MSL is max segment lifetime(time for packet to remain in n/w at Max). 
  - Remember still Client is in 1/2 close mode, ie it can accept any delayed packets for this connection till 2MSL.
- shutdown vs close

|| shutdown() | close(sock_fd) |
|---|---|---|
|What|0=No Receive, 1=NoSend, 2=like close()|Closes data in both directions. Party calling close can neither send/recv data.|
|||(Sending)if tried to send.. Client will receive error. (Receiving) If server tries to send, It will receive error|

### Flow
```html
  TCP-Client                                                          TCP-Server
 shutdown(WR_ONLY)    Active-close

  state: FIN_WAIT-1           

          ------------------FIN m-------------------------->        Passive-close
           |Seq=10 | Ack=0 | control Bit = 000001 |                state: CLOSED_WAIT
                                                             //Server informs Application, client has closed. And sends ACK at his own

         <------------------ACK m+1--------------------------
          | SeqNo=11 | AckNo = 0 | Control Bits: 010000 |
Ok I received ACK, Let server send his FIN
    state: FIN_WAIT-2
                                                             Server waits for Application Signal to close. Means Application has sent all data, signals ok to Server
         <------------------FIN n--------------------------        state: LAST_ACK
          | SeqNo=5 | AckNo = 0 | Control Bits: 000001 |

    state: TIME_WAIT

          ------------------ACK n+1-------------------------->
          | SeqNo=6 | AckNo = 0 | Control Bits: 010000 |
                                                                  state: CLOSED
```
