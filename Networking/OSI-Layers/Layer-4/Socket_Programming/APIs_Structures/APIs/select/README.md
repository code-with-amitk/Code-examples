### number_of_file_desc_setted  = select(int maxfd+1, fd_set `*readfds`, fd_set `*writefds`, fd_set `*exceptfds`, struct timeval `*timeout`)
- **What?** We are a Single-Threaded server and want to listen for incoming connections as well as keep read/write on existing connections.
- **[Disadv](Disadvantages_of_select)**
- **[Adv](Adv_of_select)**
  - With select() we can monitor several sockets at same time using FD_ISSET().
```c
  FD_SET(int fd, fd_set *set)               //Add fd to the set.        
  FD_CLR(int fd, fd_set *set)               //Remove fd from the set.        
  FD_ISSET(int fd, fd_set *set)             //Return true if fd is in the set.        
  FD_ZERO(fd_set *set)                      //Clear all entries from the set. 
```  
- **Return Value?** Total number of fds which are set in 3 sets {readfds, writefds, exceptfds}
- **struct timeval?** Time to wait for Event
```c
  struct timeval{
    int tv_sec; //seconds
    int tv_usec;    //micro sec
  };
  timeval = 0;       //select returns Immediately after polling all fds in your set
  timeval = NULL;  //select will never timeout, Means it will wait until 1st fd is ready
```
- **How select makes Application non-blocking?**
  - Let's suppose we have an application doing read/write.
  - if select() not used, then application would have blocked on send(), and all incoming data would not be recieved using recv() rather it would keep accumulating in i/p buffer.
