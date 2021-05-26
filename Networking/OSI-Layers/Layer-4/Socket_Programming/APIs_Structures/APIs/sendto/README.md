### no_of_bytes_send = sendto(int sockfd, const void `*msg`, int len, unsigned int flags, const struct sockaddr `*dest_addr`, socklen_t tolen)
- UDP send. Has 2 extra parameters destination Address struct, length
- Return: 
  - No of bytes sent(may be less than len).  
  - -1 on failure, sets errorno
