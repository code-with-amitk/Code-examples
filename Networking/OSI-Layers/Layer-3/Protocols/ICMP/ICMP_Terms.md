## Terms
- **1. Ping Sweep?** Sending ICMP_Echo(Ping) request to all hosts in network in 1 command.
```html
    $ nmap    -sP   192.168.0.1-254                                        //-s: determine whether the host is up.
        Host 192.168.0.1 appears to be up.
        Host 192.168.0.2 appears to be up.
        Host 192.168.0.5 appears to be up.
        Nmap finished: 254 IP addresses (3 host up) scanned in 5.314 seconds
```

- **2. ICMP Redirect?**
  - Suppose host-1,router-1, router-2 lies on same LAN(ie connected using switch) and Host-1 want to send packet to Host-2. Host-1's Routing table shows route to reach Host-2 is using Router-2. But actually Router-1 need to send packet to Router-2 to send packet to internet since router-1 does not have nay interface connected to internet.
  Host-1 sends packet to router-1 to send packet to host-2. Router-1 will send pkt to  router-2 and ICMP_Redirect to host-1, telling route to Host-2 is shorter from mine.
```html
            Router-1            Router-2 -----------internet---------Host-2       
      -|--------|-------------------|------
    Host-1
```    
