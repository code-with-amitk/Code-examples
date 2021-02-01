## Check Host reachable
- Provided list of IPs and ports check if the host is accessible on that particular port?
- addresses.txt
```c
IP      Port
192.168.0.1 22
192.168.0.2 22
```

## Approach
- **Logic**
  - *1.* Read IP, Port from file
  - *2.* TCP Connect to IP, port. if connect() returns 0 means success, if connect() returns -1 means failure.
- **Complexity**
  - **Time:** O(n+k). n=Number of lines inside addresses.txt. k=Time taken for RTT in TCP connect
  - **Space:** [O(1)](https://github.com/amitkumar50/Code-examples/tree/master/DS_Questions)
- **Code**
```c
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include <stdio.h>
#include <unistd.h>     //close()
#include <sys/socket.h>     //socket(), bind(), connect()
#include <netinet/in.h>     //sockaddr_in
#include <string.h>     //memset
#include <arpa/inet.h>  //inet_addr()

bool Connect(std::string& strIP, std::string& strPort){
  int sockfd;
  struct sockaddr_in serverAddr;
  socklen_t addrLen;
  int iPort;
  std::istringstream(strPort) >> iPort;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(iPort);
  serverAddr.sin_addr.s_addr = inet_addr(strIP.c_str());
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  addrLen = sizeof serverAddr;
  bool ret = false;

  //Connection Successful
  if(connect(sockfd, (struct sockaddr*)&serverAddr, addrLen) != -1)
    ret = true;

  close(sockfd);
  return ret;
}

int main(){
  //Check input file is present
  std::ifstream f("addresses.txt");
  if (not f){
    std::cout<<"Input file not present";
    return 0;
  }
  std::string strLine, strWord;
  std::string strIP, strPort;

  //Parse the file
  //Ignore 1st line since its header
  std::getline(f, strLine);

  int i=0;
  while(f.eof() == 0){
    std::getline(f, strLine);

    //Tokenize IP and Port
    std::stringstream oSS(strLine);
    while(std::getline(oSS, strWord, ' ')){
      if (i==0){  //IP Address
        strIP = strWord;
      }
      if (i==1){  //Port
        strPort = strWord;
        if(Connect(strIP, strPort))
          std::cout<<" Success!!"<<std::endl;
        else
          std::cout<<" Failed."<<std::endl;
      }
      ++i;
    }
    i=0;
    strWord.clear();
    strIP.clear();
    strPort.clear();
  }
  f.close();      
```
