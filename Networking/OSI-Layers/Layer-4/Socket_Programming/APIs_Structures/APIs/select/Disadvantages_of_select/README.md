## Disadvantages
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
