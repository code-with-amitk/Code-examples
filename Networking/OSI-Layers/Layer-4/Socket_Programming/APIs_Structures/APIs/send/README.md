### send()
```c
int no_of_bytes_send = send(int sockfd, const void `*msg`, int len, int flags) 
- Return: 
  - No of bytes sent(may be less than len).  
  - -1 on failure, sets errorno
```
- send() Can be used by both TCP & UDP.
```c
  if (num_of_bytes_send < len). 
    Its coder's responsibilty to send remaining data again
```
- **How it works internally:** Kernel uses kernel buffer to send/recv data.
