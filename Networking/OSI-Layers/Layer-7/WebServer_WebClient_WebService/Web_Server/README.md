Web Server

## Web Server
### 1. Ngnix Web Server Best Practices(Used by Ngnix)
#### NGNIX(Can serve upto 56k concurrent connections) USES THESE(solves C10k problem) //https://www.aosabook.org/en/nginx.html
- 1. SO_REUSEPORT(also called Kernel Socket Sharding): Multiple threads can listen on (same socket+ip) combination. Load is spread evenly across multiple threads.

 2. NON_BLOCKING, ASYNC sockets.

 3. SSL-Terminators and Load Balancers.

 4. Skip kernel stack: Write custom driver to send pkt directly to Application, kernel stack is complicated and slow. 

How fast can this be? Intel has a benchmark where the process 80 million packets/second on a fairly lightweight server in user mode.

 5. MULTI-CORE: Some code gets slower on running with cores because code is written badly. We want to get faster as we add more cores.  Recommendations: Keep Data structures/core, Avoid atomic operation(those are expensive), Lock-free data structures

 6. MULTI-THREADED: What's thread model(Pipelined or worker?).

    -> Set processor affinity

 7. COMPRESS DATA: Use cache friendly data.

 8. EVENT TRIGGERED LIBRARIES: (Eg: libtevent) Use ET-libraries in-place of poll() or select(). poll() is better than select(). select can only monitor 1024(FD_SETSIZE) sockets.

 9. LOAD BALANCING IN WORKER THREADS: Ngnix defines accept_mutex directive(if enabled), worker processes will accept new connections by turn. Else all worker processes will be notified about new connections, and if volume of new connections is low, some of the worker processes may just waste system resources.

 10. NON_BLOCKING STATE MACHINE: 

What is state machine? State machine like the rules for chess. Each HTTP transaction is a chess game. On one side of the chessboard is the web server/master(predefined logic). On the other side is the remote client(web browser) that is accessing the site.

Blocking state machine? Master being powerful & knows all logic sits idle for huge amount of time. because web clients are slow(people reading pages, surfing internet).

Non-Blocking state machine? 

There was a game where Kiril Georgiev(chess player) played with 360 people simultaneously & 284 won 70 draws and 6 losses. Grandmaster can play with dozens of opponents at the same time. 

Each worker-thread is grandmaster here and plays with 1000s of web-clients.

     Ngnix provides separate state machines for different protocols. Eg: HTTP, POP, IMAP, SMTP

 11. TUNING KERNEL & NGNIX

KERNEL:

a. net.core.somaxconn: Maximum number of connections that can be queued for acceptance. Default=128, Maximum value=65535

b. net.core.netdev_max_backlog: Rate at which packets are buffered by the network card before being handed off to the CPU. Default is 128, Maximum value: 65535

c. sys.fs.file-max: no of opened files. Maximum: 1MB

12. NGNIX:

a. worker_processes: Number of worker processes/core. Default=1. For 56 cores, configure worker_process=56. It will server 56k connections

b. worker_connections: Number of connections served per worker. Default=512. max=1024

c. keepalive_timeout: How long an idle keepalive connection remains open

d. access_log: Disable if not required

-> 1 Ngnix can serve upto 56k connections.



SCALING WEB SERVER FOR 10 Million(1 Crore) CONNECTIONS (Solves C10M problem)
Control Plane: All functions/processes that determine which path to use for sending packet. Routing protocols, spanning tree, ldp,

Data/Forwarding Plane: All functions/processes that forward packets from one interface to another.        Kernel is doing both that is problem. 

 12. GIVE CONTROL PLANE TO KERNEL & DATA PLANE TO APPLICATION:

    A. PLACE DATA PLANE ON APPLICATION: Tasks packet handling, memory management, process scheduling should be handled by application.

        A1. Packet Scaling: Write Your Own Custom Driver To Bypass The Stack.

            - Packets is they go through kernel stack which is complicated and slow. Create direct path for packets to your application. Don’t let OS handle the packets. 

                - Examples: PF_RING, Netmap, Intel DPDK (data plane development kit) drivers. Intel has benchmark of 80 million packets/sec on lightweight server.

        A2. Memory Management:

            - Preallocate all memory all at once on startup.

            - Reduces page table size.

            - Co-locate Data: Don’t place data on different parts of memory via pointers. Each time you follow a pointer it will be a cache miss. 

    B. KERNEL HANDLES CONTROL PLANE. 
