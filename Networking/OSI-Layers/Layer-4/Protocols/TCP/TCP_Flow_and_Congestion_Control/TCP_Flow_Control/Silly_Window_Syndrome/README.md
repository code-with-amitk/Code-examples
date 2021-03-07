## Silly Window Syndrome
- **What?** This is poor implementation of flow control. Sender or receiver window shrinks to silly size approx (1 byte). 
- **Reasons of SWS?**
  - *a. Sender re-transmitting 1 byte of data repeatedly:*
    - Let application is generating 1 byte of data(eg: telnet) and sender is transmitting it again and again. This makes the transmission process slow & inefficient. Solution:Nagle’s algorithm.
  - *b. Receiver accepting one byte of data repeatedly:* 
  - Consider the case when the receiver is unable to process all the incoming data, now receiver will advertise a small window size. The process continues and the window size becomes smaller and smaller. A stage arrives when it repeatedly advertises window size of 1 byte. Solution: Clark’s algo

## CLARK'S ALGORITHM
- Receiver should not send window update for 1 byte, receiver should wait until it has a decent amount of space available, then only he should advertise that window size to the sender.
