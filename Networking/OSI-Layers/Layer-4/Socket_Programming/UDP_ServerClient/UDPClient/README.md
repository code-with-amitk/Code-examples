## UDP Client
```c
int main(){
  int sockfd, portNum, nBytes;  
  char buffer[1024];  
  struct sockaddr_in serverAddr;  
  socklen_t addr_size;
  
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  
  serverAddr.sin_family = AF_INET;  
  serverAddr.sin_port = htons(7891);                    //Server Port
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  //Server IP
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  
  addr_size = sizeof (serverAddr);    

  while(1){
    printf("Type a sentence to send to server:\n");    
    fgets(buffer,1024,stdin);    
    printf("You typed: %s",buffer);

    nBytes = strlen(buffer) + 1;    
    sendto(sockfd,buffer,nBytes,0,(struct sockaddr *)&serverAddr,addr_size);    

    nBytes = recvfrom(sockfd,buffer,1024,0,NULL, NULL);       
    printf("Received from server: %s\n",buffer);
  }
}
```
