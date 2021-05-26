###  SETSOCKOPT(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int))
- Used to set socket options.
- **Socket options:**
  - *A. SO_REUSEADDR:* 
    - Sometimes, you might notice, you try to rerun a server and bind() fails, claiming "Address already in use.
    - This means ip+port is still in use, With this option application can bind again to same ip+port.
  - *B. SO_REUSEPORT:* 
    - Allows to bind n sockets to same application. Similar to calling n number of binds in TCP Server code.
