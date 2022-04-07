**DOS**
- [Examples of DOS](#ex)

## DOS / Denial of Service
- Intentional flooding/Overwhelming Web-Server's particular port. 
- This is similar to Jamming gate of shop by Unwanted people, restricting genuine/Original customers from entering into shop. 

<a name=ex></a>
### Examples of DDOS
<a name=icmp></a>
- **A. ICMP Flood/Ping Flood**
  - Overwhelming the server with ECHO_REQ messages from multiple devices(ddos). Server will respond and its CPU, resources consumed.
  - *How to Avoid Ping Flood?* 
    - *a.* Drop incoming ICMP packets.  OR  
    - *b.* Place a security G/W which drops the packet.
- **B. TCP/SYN FLOOD**
  - Intruder sends TCP/SYN packets from 1000 different forged IPs. Server opens TCP 1/2 connection, sending SYN+ACK back & waiting for ACK in queue.
- **C. Teardrop Attack**
- Sending  mangled IP fragments with overlapping, over-sized payloads to the target machine. This can crash various operating systems because of a bug in their TCP/IP fragmentation re-assembly code
- **D. Application Layer Flood**     
- **5. HTTP Post Flood**        
- **6. Nuke: old DoS attack:** Sending Ping(ICMP) flood until server gets complete stop/hang.
- **7. RUDY(R U Dead Yet):** Never-ending POST sending an arbitrarily large content-length header value.
- **8. Slow Read Attack:** 
  - Slow Read attack sends legitimate application layer requests but reads responses very slowly, thus trying to exhaust the server's connection pool. 
  - Slow reading is achieved by advertising a very small number for the TCP Receive Window size and at the same time by emptying clients' TCP receive buffer slowly. 
  - That naturally ensures a very low data flow rate.
- **9. Ping of Death**
- **10. UDP Flood:** Asking whether report from whether forecasting service and flodding AWS server with massive reports.
```c
  Bot                                         Whether_Forecasting_Service
    ---------Give Whether report to 1.1.1.1 ------->
                                                -------- Big Whether Report ------> AWS_App_Server(1.1.1.1)
```
- **11. Slow Loris Attack:** Deliberate Very slow client connects to server. Server holds sessions to sends data and client deliberalty delays and server resources are wasted.
