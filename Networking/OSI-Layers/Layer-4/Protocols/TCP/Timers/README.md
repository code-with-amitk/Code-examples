**Timers**
- [1. RTO(Re-transmission timeout)](#rto)
- [2. Persistant timer(Prevent Deadlock)](#dead)
- [3. Keep Alive](#keep)
  - [TCP Long Lived Connection / Long Lived TCP](#ll)
- [4. Timed Wait](#timed)

## Timers
Timers are used for:
- Ensure excessive delays are not encountered during communications.
- identify dead connections

<a name=rto></a>
### 1. RTO(RE-TRANSMISSION TIMEOUT)
  - Default:3 milliseconds
  - For tracking lost segments. When a segment is sent, a RTO is started. If the segment is acknowledged before the timer expires, the timer is stopped.
  - If, on the other hand, the timer goes off before the acknowledgement comes in, the segment is retransmitted (and the timer is started again).    
    - RTT(ROUND TRIP TIME)/RTD(ROUND TRIP DELAY TIME)/PING TIME? Time taken for a packet reach destination + time for it's acknowledgement to be received. This time delay includes the propagation times for the paths between the two endpoints.
    - RTO CALCULATIONS?  RTO = RTTs + 4*RTTd
      - Measured RTT(RTTm): Time required for the segment to reach the destination and be acknowledged.
      - Smoothed RTT(RTTs): It is the weighted average of RTTm. RTTm is likely to change and its fluctuation is so high that a single measurement cannot be used to calculate RTO.   RTTs= (1-t)*RTTs + t*RTTm
      - Deviated RTT(RTTd):   RTTd= (1-k)*RTTd + k*(RTTm-RTTs)
      - Note: At every re-transmission RTO gets doubled.

<a name=dead></a>
### 2. Persistant Timer(PREVENTING DEADLOCK)
  - DEADLOCK?
    - Sender sends a segment, receiver receives packet and sends an acknowledgement with a window size of 0, telling the sender to wait.
    - Later, the receiver updates the window, but the packet with the update is lost. Now the sender and the receiver are each waiting for the other to do something. 
  - HOW TIMER WORKS?
    - On reception of ack with window-size=0, sender starts a persistent timer.
    - After timer is expired sender sends a probe of size = 1 byte. The probe causes the receiving TCP to resend the acknowledgment which was lost. 
    - Probe has a sequence number, but its sequence number is never acknowledged or can be ignored.

<a name=keep></a>
### 3. Keep Alive Timer (default = 2 hours) 
-_ Why?_ To identify dead connections
- _What?_
  - When a connection has been idle for a long time, the keepalive timer may go off to cause one side to check whether the other side is still there. 
  - [(Default = 2 hours) RFC-1122](https://www.rfc-editor.org/rfc/rfc1122#page-101). This RFC is written in 1989, most OSes has same value, but newer might have different.
  - This may the case, client connects server, does some exchange and then client crashes. Now connection remains open forever
- **How it works**?
  - Each time the server hears from a client, it resets this timer. If the server does not hear from the client after 2 hours, it sends a probe segment. 
  - If there is no response after 10 probes, each of which is 75 s apart, it assumes that the client is down and terminates the connection.
<a name=ll></a>
#### TCP Long Lived Connection?
TCP connection that is not terminated between client and server for days, even for years.But any connection living beyond few minutes is considered as LL.
- **Advantages:**
  - _1._ If webservice/server retrives data from DB, then LL connection avoids closing/re-establishing connections again & again.
  - _2._ Server can push data to client as it becomes available.
- **Applications?** LL TCP Connections are used in daily life, such as chat and messaging(MSN, Skype).

<a name=timed></a>
### 4. Time wait Timer    //Read Time_Wait state 1st
    - HOW IT WORKS?
      - Sender starts the time wait timer after sending the ACK for the second FIN segment. It allows to resend the final acknowledgement if it gets lost.
      - The value of time wait timer is usually set to twice the lifetime of a TCP segment.


