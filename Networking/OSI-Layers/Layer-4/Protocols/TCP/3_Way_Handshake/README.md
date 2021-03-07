## 3 Way Handshake

```html
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
```
