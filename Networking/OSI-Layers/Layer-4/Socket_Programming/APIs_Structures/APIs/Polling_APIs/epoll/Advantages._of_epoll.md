## Advantages
- *1. returns only the list of descriptors which triggered the events:*    
  - No need to iterate through 10,000 descriptors anymore to find that one which triggered the event!
- *2. Multithreaded support*
  - You can add sockets or remove them from monitoring anytime, even if another thread is in the epoll_wait function.
- *3. Multiple threads can wait on same epoll queue:*    
  - It is possible to have the multiple threads waiting on the same epoll queue with epoll_wait(), something we cannot do with [select/poll](..)
