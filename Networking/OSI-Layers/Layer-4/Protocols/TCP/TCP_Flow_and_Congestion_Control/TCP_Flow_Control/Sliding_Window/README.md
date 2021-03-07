## Sliding Window
- TCP sender maintains a window, it sends all packets/seq-nos which are present in window, waits for all ACKs to arrive.
- *Window Size:* 
  - This is Number of bytes that can be stuffed into Pipe by Sender at one time. OR this is max amount of data that can be sent without wait for ACK.
- *How Window size is decided?* 
  - In a connection between a client and a server, the client tells the server the number of bytes it is willing to receive at one time from the server; this is the client's receive window, which becomes the server's send window.
- Protocol working:
  - Transmit all new segments in Window. Wait for ACK to come(Several packets can be ACKed in 1 ACK).
- Two Operations on Window:     
  - *a.* Sliding(Slide Window to Indicated position).    
  - *b.* Setting Window Size(Set window size to value advertised in ACK).

```html
    Receiver/Web Client                                         Server/Web Server
I can receive 4096 bytes at a time
          ---| TCP-Header SEQNO=90 Window-size=4096 |---->   ok sending 4 segments. 1024 each
                                                             1   2   3   4   5   6   7   8   9   10
                                                             |   window  |
           <---| TCP-Header SEQNO=1| +  | data=1024 |---- 
           <---| TCP-Header SEQNO=2| +  | data=1024 |---- 
           <---| TCP-Header SEQNO=3| +  | data=1024 |----  
           <---| TCP-Header SEQNO=4| +  | data=1024 |----  

  Don't send any packets  
           ---| TCP-Header  ACK=0 window-size=0 |--->          ok waiting for ACKS
           ---| TCP-Header  ACK=4 window-size=2048 |-->      1   2   3   4   5   6   7   8   9   10
                                                                             |win|
           <---| TCP-Header SEQNO=6| +  | data=1024 |---- 
           <---| TCP-Header SEQNO=7| +  | data=1024 |---- 
```
