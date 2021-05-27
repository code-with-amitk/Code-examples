## Advantages of select
- *1. Portable:*    
  - Since select is very old, every OS which has network support and nonblocking sockets will have a working select implementation.
  - poll is only available on Windows Vista and above, below versions(Eg: Windows XP) do not have select.
- *2. Timeout handling:*
  - select can handle the timeouts withing the one nanosecond precision while both poll and epoll can only handle the one millisecond precision.
