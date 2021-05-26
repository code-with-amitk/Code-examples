### int accept(int sockfd, struct sockaddr `*client_addr`, socklen_t `*addrlen`)
- Extract 1st connection from Connection Queue & return newfd. 
- Return:
  - -1 on failure, sets errorno (EAGAIN (resource temporarily unavailable))
