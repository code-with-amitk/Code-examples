**Named Pipe / FIFO**
- [FIFO vs Pipe](#comp)
- Properties
  - [1. fifo is not normal file](#notn)
  - [2. fifo is blocking](#block)
- [Code](#code)
- [Read Write Scenarios/Cases](#cases)
  

## Named Pipe (FIFO)
IPC mechanism for exchange of data b/w processes. Multiple processes can exchange data b/w them.
- **Fifo vs pipe**
```c
                          Fifo          |     Pipe
    --------- |-------------------------|---------------         
Name          | Have specific name      | These are unnamed
Communication | Any unrelated processes | B/w child & its parent
Existence     | exists in filesystem    | They vanish as process dies
```

### Properties
<a name=notn></a>
#### 1. Fifo is not normal file
kernel passes all data internally without writing it to the file. Thus file name merely serves as a reference point so that processes can access the pipe using the name.

<a name=block></a>
#### 2. fifo is Blocking 
The FIFO must be opened on both ends (reading and writing) before data can be passed.
  - Writer Process: Until process has not opened file for reading.
  - Reader Process: If we start reader 1st, it will block indefinitely until writer opens for writing

<a name=code></a>
### Code
**Reader**
```c
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int fd1;
    char str1[80], str2[80];

    char * myfifo = "/tmp/amit_myfifo";

    mkfifo(myfifo, 0666);

    while (1){
        fd1 = open(myfifo,O_RDONLY);
        read(fd1, str1, 80);

        printf("Read: %s\n", str1);
        close(fd1);
    }
    return 0;
}
//#gcc writer.c -o READER
#./READER
Read: amit
```
**Writer**
```c
int main(){
    int fd;
    char arr1[80], arr2[80];

    char * myfifo = "/tmp/amit_myfifo";
    mkfifo(myfifo, 0666);

    while (1){
        fd = open(myfifo, O_WRONLY);

        fgets(arr2, 80, stdin);

        write(fd, arr2, strlen(arr2)+1);
        close(fd);
    }
    return 0;
}
#endif

#./WRITER
amit

# ls -ltr /tmp/amit_myfifo
prw-r--r--. 1 root root 0 Feb 18 19:23 /tmp/amit_myfifo
- regular file
d directory
b block type special file
c character type special file
l symbolic link
p pipe
s socket
```

<a name=cases></a>
## [Read Write Scenario](/Threads_Processes_IPC/IPC/Pipe)
- The only difference between pipes and FIFOs is the manner in which they are created and opened. Once opened, I/O on pipes and FIFOs has exactly the same.
- See Pipe cases
