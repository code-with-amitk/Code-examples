## int bind(int sockfd, const struct sockaddr_in `*my_addr`, addrlen)
- Assigns IP address to sockfd
- if we want Server should bind to IP on which machine is running do bind. 
- *Returns* -1 on failure, sets errorno
