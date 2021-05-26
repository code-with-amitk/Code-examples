### no_of_bytes_send = send(int sockfd, const void `*msg`, int len, int flags) 
- Can be used by both TCP & UDP
```c
  if (num_of_bytes_send < len). 
    Its coder's responsibilty to send remaining data again
```
- Return: 
  - No of bytes sent(may be less than len).  
  - -1 on failure, sets errorno
