## epoll
- This is newest in Linux(Only in linux), added in kernel in 2002. 
- **Why epoll?** Best performance on 1000+ sockets and multithreaded server.
- **How epoll() different from poll(), select()?**
  - it keeps the information about the currently monitored descriptors and associated events inside the kernel, and exports the API to add/remove/modify those. 
  - To use epoll, much more preparation is needed.
- *[Advantages of epoll](Advantages_of_epoll.md), [Disadvantages of epoll](Disadvantages_of_epoll.md)*
