 - [Why TCP](#why)
 - [TCP Characteristics](#char)
 - State Transition Diagram
  - [1. Connection Establishment: 3 way handshake](#estb)
  - _2. Data Flow_
  - [3. Connection Tear Down](#tear)
 
 <a name=why></a>
 ## TCP / Transmission Control Protocol
- Port to Port/Process to process delivery, Congestion & flow Control, Error detection.

<a name=char></a>
## [TCP Characteristics](Characteristics)

|Characteristic|Description|
|---|---|
|1. Relaible | Recovering lost packets, Achieved using seq numbers in header.|
|2. Connection Oriented |Send ACK after data transfer, connection estbd and tear down.|
|3. Ordered data |Data reaches intended destination in the same order it was sent.|
|4. Error Detection|Selective ACK(SACK)|
|5. Error Checking|Checksum|
|6. Recovering lost packet|[Using TCP IR Option](Characteristics/Lost_Packet_Recovery)|
|7. Flow control| Sliding window|
|8. Congestion Control|Provisioning, Traffic Aware routing, admission control, nagle algo, tcp delayed ack|
|9. Quality of service||
|10. Full duplex server|it can perform roles of both receiver and sender|
|11.Multiplexing|Using Port Numbers|
|12.Crash Recovery|Using SEQ Nos|


## State Transition Diagram
<a name=estb></a>
#### 1. Connection Establishment: 3 way handshake
- *PIGGYBACKING:* ACK's are piggybacked with normal traffic. Eg: 2nd Packet in 3way-handshake. It is used to synchronize sequence numbers. Fields Filled in 3 Way H: Seq no, Control bit, Options(MSS)
- *Why ISN is random in SYN?*
    - Bcoz of security. Prevent spoofing/man in middle attack. Sender generates a random no between (0 & 4294967295) bcoz sizeof ISN=32 bit.
    - Consider if all were generating seqno=0. It would be so easy for hacker to generate seno & sit in between & spoof connection.
- *Simultaneous Open:* Both sides sends SYN(to open connection) to other.
- **Flow**
```console
    TCP-Client                                                    TCP-Server
state: CLOSED                                                    state: CLOSED
    socket()                                                     socket()
                                                                 bind()
                                                                 listen()    //Passive-Open
                                                                 state: LISTEN
<<<<<<<<<<<<<<<<<<<CONNECTION-ESTABLISHMENT>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  connect()    //Active-Open
       ----------------SYN----------------------------->    //Syn packet is sent to synchronize Seq Numbers. 
       | SP | DP | ISN=10 | Ack-No=0 | Hdr_len | 000010 | Window-size | checksum |  MSS=4500 |
                                               Control Bit                          Options
  
    state : SYN_SENT                                            state: SYN_RCVD
  
        <----------------SYN + ACK-----------------------------
       | SP | DP | ISN=89| Ack-No=11 | Hdr_len | 010010 | Window-size | checksum | MSS=5000 |
                             
//Ack-No = 11 means I acknowledge your Seq No, But lets start from Seq No 89

        ----------------ACK----------------------------->
       | SP | DP | ISN=999| Ack-No= 90 | Hdr_len | 010000 | Window-size | checksum | MSS=5000 |
          
//Ack-No = 90 means I acknowledge your Seq No, But lets start from Seq No 999
          
    state : ESTABLISHED                                        state: ESTABLISHED   
            
<<<<<<<<<<<<<<<<<<<DATA-FLOW>>>>>>>>>>>>>>>>>>>>>>>>>>>>            
```

<a name=tear></a>
#### 3. Connection Tear Down
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

- **Flow**
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

<img src=TCP_State_Diagram.gif width=500 />

- *[TCP_Header](TCP_Header)*
- *[Characteristics](TCP_Characteristics):* Reliable, Connection Oriented, Error Detection & Recovery, Flow control, QOS, Full Duplex
- [State Transition Diagram](State_Transition_Diagram):
  - 3 Way Handshake: Why ISN is random in SYN?
  - Connection Tear Down Process
- [TCP Delay Control Timers](Delay_Control_Timers): RTO(Retransmission timeout), Persistent timer, Keep alive timeout, Time wait timer
- [Advantages, Disadvantages of TCP](Advantages_Disadv_of_TCP)
- [Improvements / Changes in TCP = QUIC Protocol](../Google_QUIC)


