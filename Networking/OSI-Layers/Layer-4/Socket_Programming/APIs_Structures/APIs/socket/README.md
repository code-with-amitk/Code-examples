## sockfd = socket(int domain, int type, int protocol)         
- **Return value?** -1 on failure, sets errorno. Fd on success
- By default creates Blocking socket.

### Arguments of socket()
- **A. Communication Domain:** selects the protocol family which will be used for communication. Values:
  - AF_INET(IPv4)
  - AF_INET6(IPv6)
  - AF_UNIX:
    - Unix domain sockets use the file system as their address name space. 
    - Processes reference Unix domain sockets as file system inodes, so two processes can communicate by opening the same socket.
  - AF_LOCAL(Unix domain sockets/IPC sockets): 
    - For exchanging data between processes executing on the same host operating system
  - AF_APPLETALK(Appletalk)
  - PF_INET(this is historical and same as AF_INET)
```c
#define PF_INET     AF_INET
```
  - PF_FILE = PF_LOCAL
    - This designates the local namespace, in which socket addresses are local names    
  - PF_NETLINK
    - Communication b/w kernel and user. Netlink is used to transfer information between kernel modules and user space processes.  It consists of a standard sockets based interface for user processes and an internal kernel API for kernel modules. The internal kernel interface is not documented in this man page. Also there is an obsolete netlink interface via netlink character devices.
- **B. Type:**  
  - SOCK_STREAM(TCP)
  - SOCK_DGRAM(UDP)
  - SOCK_SEQPKT(SCTP)
  - SOCK_RAW(Raw Sockets. Here Transport Layer Protocol is not required)
- **C. Protocol:**
  - IPPROTO_TCP
  - IPROTO_UDP
  - IPPROTO_SCTP

### Commands 
- See list of open sockets `netstat`
