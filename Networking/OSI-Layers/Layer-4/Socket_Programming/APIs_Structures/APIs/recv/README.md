### no_of_bytes_read = recv(int sockfd, void `*buf`, int len, int flags)
- Can be used for both TCP and UDP
- Return value:
  - -1 on failure, sets errorno
  - 0: remote side closed connection
