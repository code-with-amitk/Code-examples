## Recovering lost packet / TCP IR Option
- **How?**
  - Done using [TCP-IR(Instant Recovery) Option](../../TCP_Header).
  - Usage of IR is to inject a small number of checksum or XOR segments into TCP's stream so that a receiver can immediately recover lost segment(s) without the need for retransmissions.
- **Flow?**
  - *1.* Client,server exchanges TCP-IR option in 3 way handshake.
  - *2.* Client requests data server sends segment3 and segment4(lost in network).
  - *3.* After every RTT, server sends XOR Segment.
    - XOR Segment: Has encoded last segment sent, Same seqno as last segment sent, TCP Option=IR
  - *4.* Client recieves XOR and checks last recieved segment's Seqno, finds Segment4 is lost in network.
    - Client recovers lost segment4 from XOR sends ACK4.
```html
   TCP A (Client)                              TCP B (Server)                                             
           -----------SYN + TCP-IR_OPT----------->            //1
           <--------SYN/ACK + TCP-IR_OPT----------  
                                                    
           -----------Request------------------->             //2
           <--------Segment3(seq3)-------------------  
              Dropped <----Segment4(seq4)------------

           <-XOR Segment |Segment4|seq 4|TCP Option=IR|---       //3

  Option=IR, This is XOR
  I must have received Segment-4(seqno4).
  But I have reiceved Seqno3, so I lost segment4
  Ok, I will recover Segment-4 from this packet
          ----------ACK3, ACK4------------------->
```
