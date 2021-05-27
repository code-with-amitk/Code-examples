## Polling APIs
- These APIs poll on socket for events.
  - [select()](../)
  - [poll(), ppoll()](poll_ppoll)
  - [epoll](epoll)
  - [libevent library](/Libraries/libevent)

||poll()|epoll()|
|---|---|---|
|For Single threaded|Good|Not good,will not outperform poll|
|No of sockets|Better for small no of sockets|Better for large number of sockets to monitor (at least 1,000)|
|Short lived connection(connection sends a few bytes of data and immediately disconnects)|Better|Not good. epoll() need to call extra system calls required to add the descriptor into epoll set|
