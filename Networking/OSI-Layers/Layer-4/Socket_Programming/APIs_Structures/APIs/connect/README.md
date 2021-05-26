### int connect(int sockfd, struct sockaddr `*serv_addr`, int addrlen)
- Only for TCP. UDP is connectionless, makes little sense to connect. 
- return values:
  - 0 on success
  - -1 on failure and errno is set
