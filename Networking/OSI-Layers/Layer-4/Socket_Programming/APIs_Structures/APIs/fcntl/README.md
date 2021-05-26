### fcntl
```c
  sockfd = socket(PF_INET, SOCK_STREAM, 0);
  fcntl(sockfd, F_SETFL, O_NONBLOCK); 
```
- Now, socket need to be polled for information. 
- But poll is Very Bad IDEA, as it sucks CPU. 
- Good Idea is [select()](..). if there is no data, it's not allowed to block—it will return -1 and errno will be set to EAGAIN or EWOULDBLOCK
