## INTERNET CONTROL MESSAGE PROTOCOL
- **Why?** Used by network devices(eg routers) to send Messages(Error, informational) indicating(Success or failure) when communicating with another IP address. On receiving ICMP message, ICMP error message need to be delivered to application responsible for transmitting the IP packet. No TCP or UDP port number associated with ICMP packets as these numbers are associated with the transport layer.
Commands using ICMP? ping, traceroute.

### ICMP packet format?     
> | MAC | IP | ICMP-pkt |
```c
    <----------------------             ICMP HEADER            -------------------------><---------------------                        DATA        --------------------------------------->
    |                                                                                                                      |
    | Type(1 byte) | Code(1 byte) | Checksum(2 byte) | Rest of header(4 bytes) |  Copy-of-entire-IPv4-Header | (8 to 576 bytes) of IPv4 packet that caused error |
```
- **ICMP HEADER**
```
    Type: 0:Echo_Rep, 1,2:Unassigned, 3:Destination Unreachable, 4:Source Quench, 5:Redirect, 6,7:unused, 8:Echo_Req, 11:Time limit exceed, 20:Traceroute
    Code: Subtype inside type. Example:  Type-3:Destination Unreachable has 15 subtypes.  0:network unreachable, 1:Host unreachable, 3:protocol unreachable etc
    Checksum: Calculated for error checking, calculated from the ICMP header and data with value 0 substituted for this field
    Rest of Header: Contents based on Type and code.
```    
- **DATA:**
  - Copy of the entire IPv4 header + First (8 to 576 bytes) of data from the IPv4 packet that caused the error message.


### PING SWEEP? 
- Sending ICMP_Echo(Ping) request to all hosts in network in 1 command.
```c
    $ nmap    -sP   192.168.0.1-254                                        //-s: determine whether the host is up.
        Host 192.168.0.1 appears to be up.
        Host 192.168.0.2 appears to be up.
        Host 192.168.0.5 appears to be up.
        Nmap finished: 254 IP addresses (3 host up) scanned in 5.314 seconds
```

### ICMP REDIRECT? 
- Suppose host-1,router-1, router-2 lies on same LAN(ie connected using switch) and Host-1 want to send packet to Host-2. Host-1's Routing table shows route to reach Host-2 is using Router-2. But actually Router-1 need to send packet to Router-2 to send packet to internet since router-1 does not have nay interface connected to internet.
  Host-1 sends packet to router-1 to send packet to host-2. Router-1 will send pkt to  router-2 and ICMP_Redirect to host-1, telling route to Host-2 is shorter from mine.
```c  
            Router-1            Router-2 -----------internet---------Host-2       
      -|--------|-------------------|------
    Host-1
```    

- COMMON FLAWS IN ICMP: See ICMP Vulnerabilities.
