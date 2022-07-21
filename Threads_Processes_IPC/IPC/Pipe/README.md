**Pipe**
- [Advantages](#adv)
- [How pipe works](#work)
- **Code**
  - [1. One Child. Parent reading child writing](#one)
- [Pipe internal implementation](#internal)
- **Read Write Scenarios/cases for Pipe/FIFO**
  - Write
    - [1.1 Write on closed pipe/fifo](#case11)
    - [1.2 Write to full pipe/fifo](#case12)
  - Read
    - [2.1 Read from empty pipe/fifo](#case21)
    - [2.2 Read when write end closed](#case22)
  - Died
    - [3. Parent reading, child die](#case3)
    - [4. Parent reading, child closes write end of pipe/fifo](#case4)

## Pipe
System call create a pipe for one-way communication between parent and child

<a name=adv></a>
### Advantages of pipes over plain/regular files
- With a regular file also, a process could write all its output and hand it over to the next process.
- But processes has to lock and then signal(like a semaphore) to let each other know when they were done reading or writing.
- Pipes eliminate all this complexity, kernel does all internally.

<a name=work></a>
### How pipe works
```c
int fd[2];
pipe(fd)                            //Makes this array as pipe. fd[0]:read end, fd[1]:write end
Parent's |CS|DS|SS fd[2]|ptr_to_heap|

Parent's |CS|DS|SS fd[2]|ptr_to_heap| --fork() duplicates--> Child |CS|DS|SS fd[2]|ptr_to_heap|
//Now Two fd[2] exists after fork.

Parent reading{ 
  close(fd[1])          //close write end
}
Child Writing{  
  close(fd[0])          //close read end
}
```

## Code
<a name=one></a>
### 1. One Child. Parent reading child writing
```c  
//fd[0]     //read end
//fd[1]     //write end

#include <unistd.h>
#include <stdio.h>
#include <errno.h>              //For errno
#include <stdlib.h>              //exit()
#include <sys/wait.h>              //waitpid
#include <string>
#include <iostream>

void DumpAndExit(std::string str){
    std::cout << "Error : " << str << "\n";
    exit(0);
}

int main(){
  int fd[2], pid = -1, status;

  if (pipe(fd) < 0)
    DumpAndExit ("pipe");

  if ((pid = fork()) < 0)
    DumpAndExit ("fork");
  else if (pid == 0) {                              //Child
    sleep(1);
    std::cout << "child\n";
    close(fd[0]);                                   //Close read end
    write(fd[1], "Test", 4);                        //Writes on pipe
  } else {                                         //Parent
    std::cout << "parent\n";
    close(fd[1]);                                  //close write
    waitpid(pid, &status, 0);                                   //Parent will wait for child
    char buf[4] = {};
    read(fd[0], buf, sizeof(buf));                //reads from pipe
    printf ("Read from child: %s\n", buf);
  }
}

# ./a.out 
Read from child: Test
```

<a name=internal></a>
### Internal implementation of pipes
- using [dup2()](/Operating_Systems/Linux/Kernel/System_Calls)
- [compelte description](https://toroid.org/unix-pipe-implementation)
```c
$ strace -qf -e execve,pipe,dup2,read,write \
    sh -c 'echo hello | wc -c'
execve("/bin/sh", ["sh", "-c", "echo hello | wc -c"], …)
pipe([3, 4])                            = 0
[pid 2604795] dup2(4, 1)                = 1
[pid 2604795] write(1, "hello\n", 6)    = 6
[pid 2604796] dup2(3, 0)                = 0
[pid 2604796] execve("/usr/bin/wc", ["wc", "-c"], …)
[pid 2604796] read(0, "hello\n", 16384) = 6
[pid 2604796] write(1, "6\n", 2)        = 2
```

## Read Write Scenarios/cases for Pipe/FIFO
- **Note pipe is for Parent to child, FIFO for unrelated process also.**

### Write
<a name=case11></a>
#### 1.1 Write on closed pipe/fifo
- Since multiple processes can be associated with 1 FIFO. 
- If all file descriptors referring to the read end of a pipe have been closed, then a write(2) will cause a SIGPIPE signal to be generated for the calling process.
  - If the calling process ignores this signal, then write(2) fails with the error EPIPE.

<a name=case12></a>
#### 1.1 Write to full pipe/fifo
- If a process attempts to write to a full pipe, then write(2) blocks until sufficient data has been read from the pipe, allowing some space to write. 

### Read
<a name=case21></a>
#### 2.1 Read from empty pipe/fifo
- Parent/Process reading from empty pipe: read() blocks until data is available

<a name=case22></a>
#### 2.2 Read when write end closed
- Since multiple processes can be associated with 1 FIFO. 
- If all file descriptors referring to the write end of a pipe/fifo are closed, then an attempt to read() from the pipe will see end-of-file (read() will return 0).

### Died
<a name=case3></a>
#### 3. Parent reading, child die
- Write end of pipe is closed, parent will exit.

<a name=case4></a>
#### 4. Parent reading, child closes write end of pipe/fifo
- child closes write end close(`fd[1]`) Still child has not exited hence parent will wait on waitpid() for child to exit.
