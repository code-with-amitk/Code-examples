## Socket Programming
- **File**
  - Everything is File(Network connection, a FIFO, a pipe, a terminal, a real on-the-disk file) Eg: & every file has a File Descriptor associated with it. 
- **File descriptor:** 
  - This is an integer associated with an open file.
  - file can be a n, or just about anything else.

## Socket 
- Is a file descriptor used for communication.
### Types of Sockets

||Protocol|Features|Applications using TCP|
|---|---|---|---|
|Stream Socket, SOCK_STREAM|TCP|reliable, connection-oriented|Telnet, HTTP|
|Datagram, SOCK_DGRAM|UDP|unreliable, connection-less|multiplayer games, streaming audio, video conferencing, TFTP|
|SOCK_PACKET, SOCK_RAW|RAW|Send/receives packet on DL Layer|IP, Transport, Application Headers are placed by the Application only|
