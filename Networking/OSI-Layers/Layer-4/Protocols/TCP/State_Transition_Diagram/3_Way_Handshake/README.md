## 3 Way Handshake
- **PIGGYBACKING:** ACK's are piggybacked with normal traffic. Eg: 2nd Packet in 3way-handshake. It is used to synchronize sequence numbers. Fields Filled in 3 Way H: Seq no, Control bit, Options(MSS)
- **Why ISN is random in SYN?**
    - Bcoz of security. Prevent spoofing/man in middle attack. Sender generates a random no between (0 & 4294967295) bcoz sizeof ISN=32 bit.
    - Consider if all were generating seqno=0. It would be so easy for hacker to generate seno & sit in between & spoof connection.
- **Simultaneous Open:** Both sides sends SYN(to open connection) to other.

### Flow
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
