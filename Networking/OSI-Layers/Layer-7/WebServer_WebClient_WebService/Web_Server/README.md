**Web Server**

## Web Server
### 1. Ngnix Web Server Best Practices(Used by Ngnix)
#### NGNIX(Can serve upto 56k concurrent connections) USES THESE(solves C10k problem) //https://www.aosabook.org/en/nginx.html
- _1. SO_REUSEPORT_(also called Kernel Socket Sharding): Multiple threads can listen on (same socket+ip) combination. Load is spread evenly across multiple threads.
- _2. NON_BLOCKING_, ASYNC sockets.
- _3. SSL-Terminators and Load Balancers._
- _4. Skip kernel stack:_ Write custom driver to send pkt directly to Application, kernel stack is complicated and slow. 
  - How fast can this be? Intel has a benchmark where the process 80 million packets/second on a fairly lightweight server in user mode.
- _5. MULTI-CORE:_ Some code gets slower on running with cores because code is written badly. We want to get faster as we add more cores.  Recommendations: Keep Data structures/core, Avoid atomic operation(those are expensive), Lock-free data structures
- _6. MULTI-THREADED:_ What's thread model(Pipelined or worker?). Set processor affinity
- _7. COMPRESS DATA:_ Use cache friendly data.
- _8. EVENT TRIGGERED LIBRARIES:_ (Eg: libtevent) Use ET-libraries in-place of poll() or select(). poll() is better than select(). select can only monitor 1024(FD_SETSIZE) sockets.
- _9. LOAD BALANCING IN WORKER THREADS:_ Ngnix defines accept_mutex directive(if enabled), worker processes will accept new connections by turn. Else all worker processes will be notified about new connections, and if volume of new connections is low, some of the worker processes may just waste system resources.
- _10. NON_BLOCKING STATE MACHINE: _
  - What is state machine? State machine like the rules for chess. Each HTTP transaction is a chess game. On one side of the chessboard is the web server/master(predefined logic). On the other side is the remote client(web browser) that is accessing the site.
  - Blocking state machine? Master being powerful & knows all logic sits idle for huge amount of time. because web clients are slow(people reading pages, surfing internet).
  - Non-Blocking state machine? 
    - There was a game where Kiril Georgiev(chess player) played with 360 people simultaneously & 284 won 70 draws and 6 losses. Grandmaster can play with dozens of opponents at the same time. 
    - Each worker-thread is grandmaster here and plays with 1000s of web-clients.
    - Ngnix provides separate state machines for different protocols. Eg: HTTP, POP, IMAP, SMTP

- _11. TUNING KERNEL & NGNIX_ KERNEL:
  - _a. net.core.somaxconn:_ Maximum number of connections that can be queued for acceptance. Default=128, Maximum value=65535
  - _b. net.core.netdev_max_backlog:_ Rate at which packets are buffered by the network card before being handed off to the CPU. Default is 128, Maximum value: 65535
  - _c. sys.fs.file-max:_ no of opened files. Maximum: 1MB
- _12. NGNIX:_
  - _a. worker_processes_: Number of worker processes/core. Default=1. For 56 cores, configure worker_process=56. It will server 56k connections
  - _b. worker_connections:_ Number of connections served per worker. Default=512. max=1024
  - _c. keepalive_timeout:_ How long an idle keepalive connection remains open
  - _d. access_log:_ Disable if not required
- 1 Ngnix can serve upto 56k connections.



#### SCALING WEB SERVER FOR 10 Million(1 Crore) CONNECTIONS (Solves C10M problem)
- **Control Plane:** All functions/processes that determine which path to use for sending packet. Routing protocols, spanning tree, ldp,
- **Data/Forwarding Plane:** All functions/processes that forward packets from one interface to another.        Kernel is doing both that is problem. 
- _12. GIVE CONTROL PLANE TO KERNEL & DATA PLANE TO APPLICATION:_
  - _A. PLACE DATA PLANE ON APPLICATION:_ Tasks packet handling, memory management, process scheduling should be handled by application.
    - _A1. Packet Scaling:_ Write Your Own Custom Driver To Bypass The Stack. Packets is they go through kernel stack which is complicated and slow. Create direct path for packets to your application. Don’t let OS handle the packets. 
      - Examples: PF_RING, Netmap, Intel DPDK (data plane development kit) drivers. Intel has benchmark of 80 million packets/sec on lightweight server.
    - _A2. Memory Management:_
      - Preallocate all memory all at once on startup.
      - Reduces page table size.
      - Co-locate Data: Don’t place data on different parts of memory via pointers. Each time you follow a pointer it will be a cache miss. 

  - _B. KERNEL HANDLES CONTROL PLANE_
