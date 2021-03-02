## Machine not Reachable
- **1. Is server Pingable?**
```c
    # ping -c 5 ip-address | hostname        //Linux. Sends ECHO-REQ & recieve ECHO-REP.
    # ping /n 2 ipAddress                            //WINDOWS. Send 2 ECHO-REQ
```    
- **2. Can remote port be connected?**
```c
    # telnet ip-address port        //insecure, connects in plain text
      connected
    GET / HTTP/1.1
    host: webserver.com            //Get home page from webserver
```
- **3. Do src have route to dst?**
  - **traceroute:**
    - Show all routers in-between from src to dst computer. Sends ICMP(over UDP). TTL(IP Header) is modified.
    - Traceroute does not use TCP.
```c
# traceroute ip-address            
    Hop  RTT1    RTT 2   RTT 3   Name/IP Address
    10   81 ms   74 ms   74 ms   205.134.225.38
    *     *        *       *           *           //* denote the packet loss.
    //Hop: Hop number along the route
    //RTT(Round Trip Time): Time for packet to reach this hop and come back. 3 columns, 
    since traceroute sends 3 separate packets to hop. RTT for a hop should be nearly same.
    ssh works but traceroute show *? Firewall may have blocked ICMP packets allowing ssh/tcp packets.
```
- **4. Does kernel routing table have route to dst?**
  - **route?** This command shows kernel ip routing table of host. We can add route using "route add"
```c
# route
    kernel ip routing table
    Dest        G/W            Genmask        Flags    Metric    Ref    User-Intf
    default    <>                0.0.0.0            UG        100        0        ens192
    10.x.y.z   <>            255.255.254.0    U          100         0        ens192        <<<< No entry for x.y.z.q
```
