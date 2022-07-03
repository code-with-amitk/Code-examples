**Socket Programming**
- **[Terms](#t)**
  - file, file descriptor, socket
  - [Byte order: Little, Big endian](#bo)
  - [inaddr_any](#ia)
- **Code**
  - [TCP Server, Client](#t)
  - [UDP Server, Client](#u)
  - [Raw Socket](raw_socket.md)
- **Blocking/NonBlocking**
  - [Blocking](#b)
  - [NonBlocking](#nb)
    - [Nonblocking Multichat server using select()](nonblocking_multichat_server.md)

<a name=t></a>
## Terms
- **File:** Everything is File(Network connection, a FIFO, a pipe, a terminal, a real on-the-disk file) Eg: & every file has a File Descriptor associated with it. 
- **File descriptor:** This is an integer associated with an open file. File can be a n, or just about anything else.
- **Socket?** Is a file descriptor used for communication. Types of sockets:
```c
      Protocol                  |     Features                  | Applications using
--------------------------------|-------------------------------|---------------------------
TCP(Stream Socket, SOCK_STREAM) | Reliable, connection-oriented | Telnet, HTTP
UDP(Datagram, SOCK_DGRAM)       | unreliable, connection-less   | multiplayer games, streaming audio, video conferencing, TFTP
RAW(SOCK_PACKET, SOCK_RAW)      | Send/recv packet on DL Layer  | IP, Transport, Application Headers are placed by the Application only

Other Types: /APIs_Structures/APIs/socket
```

<a name=bo></a>
### Byte Order
Means in which order computer stores the bytes in memory. 
- [Types of Byte order](/Languages/Programming_Languages/C/Bitwise/)
  - 1. Little Endian = N/W byte order
  - 2. Big Endian = Host Byte Order
- **Why required?** 
  - All computers store data differently. Internet Protocols says All data should be sent using N/W byte on internet then can be converted as per computer's storage endianess.
- **APIs** htons(), htonl(), ntohl(), ntohs()

<a name=ia></a>
### inaddr_any
if our server has multiple interfaces, Each interface have different IP address and we want to bind to all interfaces(ie all IP addresses), then instead of inet_addr() we should use inaddr_any
```c
serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");    //Binding port to localhost(127.0.0.1)
serverAddr.sin_addr.s_addr = INADDR_ANY;                //Binding port to all available IPs
```
- This is helpful for multihomed network(when server is connected to multiple networks).
```c
MULTIHOMED
  
N/W-1 ---192.168.0.14--
                      |
                    server -----95.95.2.21------ N/W-2
                      |
 N/W-3 ---16.21.4.5----
```

## Code
<a name=t></a>
### TCP Server, Client
[System calls: socket(), bind(), listen(), accept(), recv(), send(), close()](APIs_Structures/APIs/)
```c
///////////////////////////////TCP Server////////////////////////////
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

///////////////////////TCP Client//////////////////////////////
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

<a name=u></a>
### UDP Server, Client
```c
/////////////   Server  =>    socket(), bind(), recvfrom(), close()   ////////////////////
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

/////////////Client   =>    socket(), sendto(), close() /////////////////////////////////
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

## Blocking/Non-Blocking
<a name=b></a>
### Blocking (means sleep)
- By default all server-side socket API's are Blocking. socket(), read(), readfrom(), accept()
- At time of creation of sockets using socket() system call kernel makes the sockets as blocking

<a name=nb></a>
### Non-Blocking
- To make API non-blocking we use [select(), fcntl()](APIs_Structures)
- [Non Blocking multichat server](nonblocking_multichat_server.md)

- [**APIs:** accept(), bind(), close(), connect(), fcntl(), gethostname(), getpeername(), listen(), recv(), recvfrom(), select(), send(), sendto(), setsockopt(), shutdown(), socket()](APIs_Structures)
- **[Terms](Terms):** Byte Order, inaddr_any
