 - [Why TCP](#why)
 - [TCP Characteristics](#char)
 - Advantages, Disadvantages of TCP
   - [Advantages](#adv)
   - [Disadvatanges](#dis)
 - State Transition Diagram
   - [1. Connection Establishment: 3 way handshake](#estb)
   - _2. Data Flow_
   - [3. Connection Tear Down](#tear)
- [TCP Header](TCP_Header)
- Delay Control Timers
  - [1. RTO(Re-transmission timeout)](#rto)
  - [2. Persistant timer(Prevent Deadlock)](#dead)
  - [3. Keep Alive](#keep)
  - [4. Timed Wait](#timed)
- [Improvements / Changes in TCP = Google_QUIC Protocol](/Networking/OSI-Layers/Layer-4/Protocols)

 
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


## Advantages, Disadvantages of TCP
### Advantages
- Same as characteristics

<a name=dis></a>
### Disadvantages
- *1.* Transport semantics are not application specific and finally application has to bear burden of solving them. Examples:
  - Application-1 want to send message with unlimited boundaries.
  - Application-2 want to send message with preserved boundaries.
  - Application-3 want better control over network path. May be error recovery per 10 hopes etc.
 
- **2. Congestion Control is Problem** 
  - *2a.* Congestion Control is based on packet losses as a signal of congestion. More packets getting lost we need congestion control.
    - This maybe a not good Congestion signal and can be replaced by anything else. Eg:
      - Packet Transmission error rate
        - Since networks are getting faster and faster, Developers are revisting Congestion control.
    - Solution: [QUIC](../../Google_QUIC/Features_Characteristics)

- *3.* Slow Start
  - During TCP-3-way handshake window size exchanged is relatively small, cannot be Max.
  - In [Flow control(Sliding Window)](Characteristics/Flow_and_Congestion_Control/TCP_Flow_Control/Sliding_Window) window size shrinks to smallest.
  - This can be especially disadvantageous when downloading larger streams of data. 
    - GOOGLE PROPOSED SOLUTION: [QUIC](/Networking/OSI-Layers/Layer-4/Protocols)

- **4. Image, Stream Blockings / Head of Line Blocking Issue**
  - Consider webpage has 2 images, image-1 is lost while image-2 is recieved. TCP will try getting image-1 and block. 
  - Similar problem will be seen when streaming video using TCP. Once the Segment is lost, the TCP will try retrieving even if other Segments of the video are watchable.
    - Solution: QUIC

- *5.* 3 Way Handshake can take large time on large latency devices, low BW Network. Eg:
  - Web server connecting to slow mobile device.
    - Solution: [QUIC](/Networking/OSI-Layers/Layer-4/Protocolsw)

- *6.* TCP may not work faster in LAN, its designed for WAN.

- *7.* Cannot distinguish between Packet lost and retransmission in wireless network.
  - In wireless network packet losses are there(more wrt to wired).


## State Transition Diagram
<img src=TCP_State_Diagram.gif width=500 />

<a name=estb></a>
### 1. Connection Establishment: 3 way handshake
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
### 3. Connection Tear Down
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

## Delay Control Timers
TCP uses several timers to ensure that excessive delays are not encountered during communications.

<a name=rto></a>
#### 1. RTO(RE-TRANSMISSION TIMEOUT)
  - Default:3 seconds
  - For tracking lost segments. When a segment is sent, a RTO is started. If the segment is acknowledged before the timer expires, the timer is stopped.
  - If, on the other hand, the timer goes off before the acknowledgement comes in, the segment is retransmitted (and the timer is started again).    
    - RTT(ROUND TRIP TIME)/RTD(ROUND TRIP DELAY TIME)/PING TIME? Time taken for a packet reach destination + time for it's acknowledgement to be received. This time delay includes the propagation times for the paths between the two endpoints.
    - RTO CALCULATIONS?  RTO = RTTs + 4*RTTd
      - Measured RTT(RTTm): Time required for the segment to reach the destination and be acknowledged.
      - Smoothed RTT(RTTs): It is the weighted average of RTTm. RTTm is likely to change and its fluctuation is so high that a single measurement cannot be used to calculate RTO.   RTTs= (1-t)*RTTs + t*RTTm
      - Deviated RTT(RTTd):   RTTd= (1-k)*RTTd + k*(RTTm-RTTs)
      - Note: At every re-transmission RTO gets doubled.

<a name=dead></a>
#### 2. PERSISTENT TIMER(PREVENTING DEADLOCK)
  - DEADLOCK?
    - Sender sends a segment, receiver receives packet and sends an acknowledgement with a window size of 0, telling the sender to wait.
    - Later, the receiver updates the window, but the packet with the update is lost. Now the sender and the receiver are each waiting for the other to do something. 
  - HOW TIMER WORKS?
    - On reception of ack with window-size=0, sender starts a persistent timer.
    - After timer is expired sender sends a probe of size = 1 byte. The probe causes the receiving TCP to resend the acknowledgment which was lost. 
    - Probe has a sequence number, but its sequence number is never acknowledged or can be ignored.

<a name=keep></a>
#### 3. KEEP ALIVE TIMER (default = 2 hours) 
- WHAT?
  - When a connection has been idle for a long time, the keepalive timer may go off to cause one side to check whether the other side is still there. 
  - This may the case, client connects server, does some exchange and then client crashes. Now connection remains open forever
- How it works?
  - Each time the server hears from a client, it resets this timer. If the server does not hear from the client after 2 hours, it sends a probe segment. 
  - If there is no response after 10 probes, each of which is 75 s apart, it assumes that the client is down and terminates the connection.

<a name=timed></a>
#### 4. TIME WAIT TIMER    //Read Time_Wait state 1st
    - HOW IT WORKS?
      - Sender starts the time wait timer after sending the ACK for the second FIN segment. It allows to resend the final acknowledgement if it gets lost.
      - The value of time wait timer is usually set to twice the lifetime of a TCP segment.


