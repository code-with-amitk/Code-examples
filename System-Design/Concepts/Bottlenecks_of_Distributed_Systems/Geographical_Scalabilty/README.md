  ##  Geographical Scalabilty
  - **Synchronous/Blocking Communication not good on WAN** socket is created as blocking and blocks on read()/write() system calls. client will block until reply from server.
    - **LAN** This approach works on LAN, where server will send responses faster.
    - **WAN** On WAN, client server are seperated by(lossy, limited Bandwidth internet), which may cause client to block indefinetly.
    - Solution: Writing non-blocking applications. `fcntl(sockfd, F_SETFL, O_NONBLOCK);`
