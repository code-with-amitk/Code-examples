## int listen(fd, BACKLOG)
- *backlog*
  - Max no of pending connections in queue, before kernel starts rejecting new connections.
  - if clients are getting `connection refused`, increase backlog. Though [select()](..) has limit to listen on 1024 connections only.
- *Return*
  - 0 on success, or -1 on error
  - ECONNREFUSED returned to client If server queue is full.
- In [TCP State Diagram](/Networking/OSI-Layers/Layer-4/Protocols/TCP) server is moved to LISTEN state.
