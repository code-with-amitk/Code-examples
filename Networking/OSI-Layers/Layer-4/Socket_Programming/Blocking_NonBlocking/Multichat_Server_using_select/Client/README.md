## Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#define PORT 4950
#define BUFSIZE 1024

int main() {
  int sockfd, fdmax, i, nbyte_recvd;
  struct sockaddr_in server_addr;        
  char send_buf[BUFSIZE];        
  char recv_buf[BUFSIZE];        
  
  fd_set master;        
  fd_set read_fds;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {  
    perror("Socket");  
    exit(1);  
  }

  server_addr.sin_family = AF_INET;        
  server_addr.sin_port = htons(4950);        
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");        
  memset(server_addr.sin_zero, '\0', sizeof server_addr.sin_zero);

  if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) { 
    perror("connect"); 
    exit(1); 
  }

  FD_ZERO(&master);    
  FD_ZERO(&read_fds);
  
  FD_SET(0, &master);    
  FD_SET(sockfd, &master);
  
  fdmax = sockfd;
    
  while(1){
    read_fds = master;                
    if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1) { 
      perror("select"); 
      exit(1);
    }
    
    for(i=0; i <= fdmax; i++){
      if(FD_ISSET(i, &read_fds)){
        if (i == 0){    //stdin[0] stdout[1] stderr[2]
          fgets(send_buf, BUFSIZE, stdin);
          if (strcmp(send_buf , "quit\n") == 0) {
            exit(0); 
          }
          else
          {
            send(sockfd, send_buf, strlen(send_buf), 0);
          }
        }
        else
        {
          nbyte_recvd = recv(sockfd, recv_buf, BUFSIZE, 0);
          recv_buf[nbyte_recvd] = '\0';
          printf("%s\n" , recv_buf);
          fflush(stdout);
        }
      }
    }
  }
}
```
