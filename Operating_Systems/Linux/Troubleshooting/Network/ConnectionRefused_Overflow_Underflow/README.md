## Overflow/Underflow/Connection Refused

### 1. Number of TCP/UDP connections to/from my machine?
  - **netstat**
```c
# netstat  -plunt        ///Show TCP/UDP statistics of all interfaces. /-p: show pid, -a: all interfaces, -n: show Numeric, -t: tcp, -u: udp
# netstat -ant | awk '{print $NF}' | grep -v '[a-z]' | sort | uniq -c        //Get number of active connections
# netstat -ntu | awk '{print $5}' | cut -d: -f1 | sort | uniq -c | sort -n    //Get number of connections per ip address
# netstat -lantp | grep ESTABLISHED |awk '{print $5}' | awk -F: '{print $1}' | sort -u    //Get all IP Address connected to your host
# watch "netstat -plan|grep :80|awk {'print \$5'} | cut -d: -f 1 | sort | uniq -c | sort -nk 1"    //Monitor open connection to web server on port 80, count and sort it by IP
```
  - **sar**
```c
# sar -n TCP, ETCP, DEV 1                    //-n: report network statistics
```
### 2. Are packets getting dropped at Hardware Level?
```c
# ip -s link
    1. lo:<loopback,up> mtu 65536 qdisc noqueue state UNKNOWN
     link/loopback 00:00:00:00:00 brd 
     RX: bytes packets errors dropped overrun mcast
      29362 254 0 0 0 0
     TX: bytes packets errors dropped overrun mcast
      29362 254 0 0 0 0
    2. eth0:<BROADCAST,MULTICST,UP,LOWER_UP> mtu 1500 qdisc pfifo_fast state UP qlen 1000
     link/loopback 00:00:00:00:00 brd 
     RX: bytes packets errors dropped overrun mcast        <<<<<<dropped
     293621212 334555 5 235242 0 0
     TX: bytes packets errors dropped overrun mcast
     11212112 124555 89 121312 0 0
```
### 3. Is Network Bandwidth(bits/second) low and Latency(RTT) high?
  - **qperf**
```c
# qperf -t 60 --use_bits_per_sec <destination-ip> tcp_bw
   bw = 2.65 Gb/sec
# qperf -vvs <destination-ip> tcp_lat
   latency  = 173 us
   msg_rate = 5.79 K/sec
 ```
### 4. Error message from server?
```c
# tcpdump -n -i {interface} -s 0 -w /tmp/test.cap    //n: Don't convert host addresses to short-names. 
```
