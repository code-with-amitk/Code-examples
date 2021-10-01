## Blocking
- means sleep
- By default all server-side socket API's are Blocking. [socket(), read(), readfrom(), accept()](../APIs_Structures)
- At time of creation of sockets using socket() system call kernel makes the sockets as blocking

### Creating Non Blocking Socket
- *[1. fcntl()]
- *[2. select()](../APIs_Structures)*
