## UDP Server
```c
int main(){
  int sockfd, recvBytes,i;          
  char buffer[1024];          
  struct sockaddr_in selfAddr, clientAddr;         
  socklen_t addr_size, client_addr_size;
  
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  serverAddr.sin_family = AF_INET;          
  serverAddr.sin_port = htons(7891);                      //Server Port
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");    //Server IP
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  bind(sockfd, (struct sockaddr *) &selfAddr, sizeof(selfAddr));          
  addr_size = sizeof clientAddr;

  while(1){            
    recvBytes = recvfrom(sockfd,buffer,1024,0,(struct sockaddr *)&clientAddr, &addr_size);
    for(i=0;i<recvBytes-1;i++){    
      buffer[i] = toupper(buffer[i]);    
    }
    sendto(sockfd,buffer,recvBytes,0,(struct sockaddr *)&clientAddr,addr_size);
  }
}
```
