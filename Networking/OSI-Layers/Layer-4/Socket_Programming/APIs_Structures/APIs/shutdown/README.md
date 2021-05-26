### int shutdown(fd, int howto) 
- TCP 1/2 close feature.
- howto
  - SHUT_RD: No more data can be read from socket
  - SHUT_WR: No data can be written to socket
  - SHUT_RDWR: same as close  
