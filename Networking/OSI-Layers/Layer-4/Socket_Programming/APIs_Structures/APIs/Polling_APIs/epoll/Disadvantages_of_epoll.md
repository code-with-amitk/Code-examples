## Disadvantages
- *1. More code to be written:*    
  - It is more complex to use, and requires you to write more code, and it requires more library calls comparing to other polling methods
- *2. Bad for short lived connections:*    
  - If your server has many short-lived connections which send or receive little traffic, epoll will likely take longer than poll to serve them
- *3. High performance processing logic is more complex:*    
  - More difficult to debug, especially for edge triggering which is prone to deadlocks if you miss extra read/write
- *4. Bad performance on smaller number of sockets:*    
  - epoll() works better on large number of sockets to monitor(at least 1,000)
  - with a smaller number epoll is not likely to have any performance benefits over poll and may actually worse the performance
