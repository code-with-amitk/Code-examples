## Code
```c
main() {
  int clientSocket;        
  char buffer[1024];        
  struct sockaddr_in serverAddr;        
  socklen_t addr_size;
  
  clientSocket = socket(AF_INET, SOCK_STREAM, 0);

  serverAddr.sin_family = AF_INET;        
  serverAddr.sin_port = htons(7891);                          //Server Port
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");        //Server IP
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);            

  addr_size = sizeof (serverAddr);        
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);
  recv(clientSocket, buffer, 1024, 0);        
  printf("Data received: %s",buffer);
}
```
