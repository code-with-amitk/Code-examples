- [Is IP Reachable](#1)

<a name=1></a>
### 1. Is IP Reachable
```c
1. Is server Pingable
    # ping -c 5 ip-address | hostname        //Linux. Sends ECHO-REQ & recieve ECHO-REP.
    # ping /n 2 ipAddress                            //WINDOWS. Send 2 ECHO-REQ
    
2. Can remote port be connected    
    # telnet ip-address port        //insecure, connects in plain text
      connected
    GET / HTTP/1.1
    host: webserver.com            //Get home page from webserver    
    
3. Do src-machine have route to dst-ip?
traceroute: Show all routers in-between from src to dst computer. Sends ICMP(over UDP). TTL(IP Header) is modified. Traceroute does not use TCP.

  # traceroute ip-address            
    Hop  RTT1    RTT 2   RTT 3   Name/IP Address
    10   81 ms   74 ms   74 ms   205.134.225.38
    *     *        *       *           *           //* denote the packet loss.
    //Hop: Hop number along the route
    //RTT(Round Trip Time): Time for packet to reach this hop and come back. 3 columns, 
    since traceroute sends 3 separate packets to hop. RTT for a hop should be nearly same.
    ssh works but traceroute show *? Firewall may have blocked ICMP packets allowing ssh/tcp packets.
    
4. Does kernel routing table have route to dst?
  route command? This command shows kernel ip routing table of host. We can add route using "route add"
  # route
    kernel ip routing table
    Dest        G/W            Genmask        Flags    Metric    Ref    User-Intf
    default    <>                0.0.0.0            UG        100        0        ens192
    10.x.y.z   <>            255.255.254.0    U          100         0        ens192        <<<< No entry for x.y.z.q    
```

### [ConnectionRefused Overflow Underflow](ConnectionRefused_Overflow_Underflow)
  - *1.* Number of TCP/UDP connections to/from my machine (netstat)
    - Get number of active connections
    - Get number of connections per ip address
    - Get all IP Address connected to your host
  - *2.* Are packets getting dropped at Hardware Level (ip -s link)?
  - *3.* Is Network Bandwidth(bits/second) low and Latency(RTT) high (qperf)?
  - *4.* tcpdump

