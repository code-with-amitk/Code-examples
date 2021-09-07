**Polling APIs**
  - [select()](../)
  - [poll(), ppoll()](#p)
    - [Advantages](#ap)
    - [DisAdvantages](#dp)
  - [epoll](#e)
    - [epoll() vs poll(), select()?](#evs)
    - [epoll() vs poll()](#evp)
    - [Advantages](#ae)
    - [Disadvantages](#de)
  - [libevent library](/Libraries/libevent)

## Polling APIs
These APIs poll on socket for events.

<a name=p></a>
### 2. poll(), ppoll()
```c
int poll(struct pollfd *fds, nfds_t nfds, int timeout)
int ppoll(struct pollfd *fds, nfds_t nfds, const struct timespec *tmo_p, const sigset_t *sigmask);
```
**Why?** 1. Newer than [select](..) hence better designed fixes much of select problems. 2. For high performance networking server.
- Code
```c
    struct pollfd fds[2];
    fds[0].fd = sock1;    fds[0].events = POLLIN;    //// Monitor sock1 for input
    fds[1].fd = sock2;    fds[1].events = POLLOUT;    //// Monitor sock2 for output
    int ret = poll( &fds, 2, 10000 );    // Wait 10 seconds
    if (ret == -1)    //poll failed
    else{
        // If we detect the event, zero it out so we can reuse the structure
        if ( pfd[0].revents & POLLIN ){    pfd[0].revents = 0;    //Input event on sock1    }
        if (pfd[1].revents & POLLOUT){    pfd[1].revents = 0;    //Output event on sock2    }
    }    
```
<a name=ap></a>
#### Advantages of poll()
> poll was mainly created to fix the pending problems select

- *1. No hard limit on the number of descriptors poll can monitor:*
  - so the limit of 1024(which select() has) does not apply here.
- *2. Does not modify the data passed in the struct pollfd data:*    
  - Therefore it could be reused between the poll() calls as long as set to zero the revents member for those descriptors which generated the events.
- *3. more fine-grained control of events comparing to select:*    
  - For example, it can detect remote peer shutdown without monitoring for read events.

<a name=dp></a>
#### Disadvantages of poll()
- *1. Not present on Microsoft Windows older than Vista*
- *2. poll timeout has the 1millisec precision:*    
  - While select has nano-seconds
*3.  wasting CPU cycles in iterating through descriptors:*    
  - Same as select, need to iterate through whole list to find out which socket has event trig-erred on it. It will get slow when 1000+ descriptors are present.
  - Solution: 

## 3. epoll()
- This is newest in Linux(Only in linux), added in kernel in 2002. 
- **Why?** Best performance on 1000+ sockets and multithreaded server.

<a name=evs></a>
#### epoll() vs poll(), select()?
  - it keeps the information about the currently monitored descriptors and associated events inside the kernel, and exports the API to add/remove/modify those. 
  - To use epoll, much more preparation is needed.

<a name=evp></a>
#### epoll() vs poll()
```c
                       |    poll()                      |     epoll()
-----------------------|--------------------------------|------------------------------  
For Single threaded    | Good                           | Not good,will not outperform poll
No of sockets          | Better for small no of sockets | Better for large number of sockets to monitor (at least 1,000)
Short lived connection | Better                         | Not good. epoll() need to call extra system calls
(connection sends a few|                                |  required to add the descriptor into epoll set
bytes of data &       
disconnects)
```

<a name=ae></a>
#### Advantages of epoll()
- *1. returns only the list of descriptors which triggered the events:*    
  - No need to iterate through 10,000 descriptors anymore to find that one which triggered the event!
- *2. Multithreaded support*
  - You can add sockets or remove them from monitoring anytime, even if another thread is in the epoll_wait function.
- *3. Multiple threads can wait on same epoll queue:*    
  - It is possible to have the multiple threads waiting on the same epoll queue with epoll_wait(), something we cannot do with [select/poll](..)
<a name=de></a>
#### Disadvantages of epoll()
- *1. More code to be written:*    
  - It is more complex to use, and requires you to write more code, and it requires more library calls comparing to other polling methods
- *2. Bad for short lived connections:*    
  - If your server has many short-lived connections which send or receive little traffic, epoll will likely take longer than poll to serve them
- *3. High performance processing logic is more complex:*    
  - More difficult to debug, especially for edge triggering which is prone to deadlocks if you miss extra read/write
- *4. Bad performance on smaller number of sockets:*    
  - epoll() works better on large number of sockets to monitor(at least 1,000)
  - with a smaller number epoll is not likely to have any performance benefits over poll and may actually worse the performance
