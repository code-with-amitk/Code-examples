## epoll
- This is newest in Linux(Only in linux), added in kernel in 2002. 
- *How epoll() different from poll(), select()?*
  - it keeps the information about the currently monitored descriptors and associated events inside the kernel, and exports the API to add/remove/modify those. 
  - To use epoll, much more preparation is needed.
Advantages:
1. returns only the list of descriptors which triggered the events:    No need to iterate through 10,000 descriptors anymore to find that one which triggered the event!
2. can add sockets or remove them from monitoring anytime:    You can add sockets or remove them from monitoring anytime, even if another thread is in the epoll_wait function.
3. Multiple threads can wait on same epoll queue:    It is possible to have the multiple threads waiting on the same epoll queue with epoll_wait(), something you cannot do with select/poll
When to use epoll()?
    - Your application runs a thread poll which handles many network connections by a handful of threads.
