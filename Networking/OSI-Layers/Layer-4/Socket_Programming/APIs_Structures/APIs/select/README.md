### select
- select can monitor on several File descriptors(sockets, files, devices) using FD_ISSET()
- select() is Polling Mechanism. 
- We are a Single-Threaded server and want to listen for incoming connections as well as keep read/write on existing connections.
```c
number_of_file_desc_setted  = select(int maxfd+1, fd_set `*readfds`, fd_set `*writefds`, fd_set `*exceptfds`, struct timeval `*timeout`)

Parameters?
  - struct timeval? Time to wait for Event
    struct timeval{
      int tv_sec;     //seconds
      int tv_usec;    //micro sec
    };
  timeval = 0;       //select returns Immediately after polling all fds in your set
  timeval = NULL;  //select will never timeout, Means it will wait until 1st fd is ready
  
Return Value? Total number of fds which are set in 3 sets {readfds, writefds, exceptfds}

FD_SET(int fd, fd_set *set)               //Add fd to the set.        
FD_CLR(int fd, fd_set *set)               //Remove fd from the set.        
FD_ISSET(int fd, fd_set *set)             //Return true if fd is in the set.        
FD_ZERO(fd_set *set)                      //Clear all entries from the set. 
```  
#### Advantages of select
- *1. Portable:*    
  - Since select is very old, every OS which has network support and nonblocking sockets will have a working select implementation.
  - poll is only available on Windows Vista and above, below versions(Eg: Windows XP) do not have select.
- *2. Timeout handling:*
  - select can handle the timeouts withing the one nanosecond precision while both poll and epoll can only handle the one millisecond precision.

#### Disadvantages
> Not good fit in multi-threaded Application.

- *1. wasting CPU cycles in iterating through descriptors:*
  - To find out which descriptors raised the events you have to manually iterate through all the descriptors in the fd_set and call FD_ISSET on each one of them. 
  - When we have 2000 descriptors in fd_set and only one(may be last) is active, we are wasting CPU cycles each time in iteration.
- *2. Only can support 1024 Descriptors*
  - Maximum number of the supported descriptors is defined by the FD_SETSIZE constant=1024 in Linux.
  - We can change this limit in `sys/select.h`, but it might not be portable to other OSes.
- *3. Closing socket by another thread:*
  - If thread-1 is working on 1 Socket Fd and thread 2 closes it, Result is unspecified.
  - As per man page “If a file descriptor being monitored by select() is closed in another thread, the result is unspecified”.
- *4. Everytime Calculate largest FD+1*
  - Its extra burden to calculate the largest descriptor number and provide it as a function parameter everytime.

#### How select makes Application non-blocking?
- Let's suppose we have an application doing read/write.
- if select() not used, then application would have blocked on send(), and all incoming data would not be recieved using recv() rather it would keep accumulating in i/p buffer.
