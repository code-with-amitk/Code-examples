## Code
```c
# include <stdio.h>
#include <unistd.h>     //close()
#include <sys/socket.h>     //socket(), bind(), connect()
#include <netinet/in.h>     //sockaddr_in

int main() {
  int sockfd, newfd;        
  char buffer[1024];        
  struct sockaddr_in serverAddr, clientAddr;        
  socklen_t addr_size;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);                          //PORT
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");        //IP
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  bind(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
  listen(sockfd,5);        

  while(1){
    addr_size = sizeof (clientAddr);                
    newfd = accept(sockfd, (struct sockaddr *) &clientAddr, &addr_size);                
    strcpy(buffer,"Hello World\n");                
    send(newfd,buffer,13,0);            
    printf("Send data to client..%s\n\n",buffer);
    printf("Listening further..\n");
  }
  
  close(newfd);
  close(sockfd);
  return 0;
}
```
