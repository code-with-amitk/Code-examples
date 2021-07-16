- [What is pipe](#what)
- [Advantages of pipes](#adv)
- [How pipe works](#work)
- Code
  - [1. One Child. Parent reading child writing](#one)
- [How pipes are internally implemented](#internal)
- Read Write Scenarios/cases for Pipe/FIFO
  - Write
    - [1. Write on unopened pipe/fifo](#case1)
  - Read
    - [2. Read from unopened pipe/fifo](#case2)
  - Died
    - [3. Parent reading, child die](#case3)
    - [4. Parent reading, child closes write end of pipe/fifo](#case4)

<a name=what></a>
## Pipe
- System call create a pipe for one-way communication between parent and child

<a name=adv></a>
## Advantages of pipes
- **1. Over plain/regular files**
  - With a regular file also, a process could write all its output and hand it over to the next process.
  - But processes has to lock and then signal(like a semaphore) to let each other know when they were done reading or writing.
  - Pipes eliminate all this complexity, kernel does all internally.

<a name=work></a>
## How pipe works
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

void DumpAndExit(char* str){
    perror (str);
    printf ("errno: %d", errono);
    exit(0);  
}

int main(){
  int fd[2], pid = -1;

  if (pipe(fd) < 0)
    DumpAndExit ("pipe");

  if (pid = fork() < 0) {
    DumpAndExit ("fork");
  }
  else if (pid == 0) {                              //Child
    close(fd[0]);                                   //Close read end
    write(fd[1], "Test", 4);                        //Writes on pipe
  } else {                                         //Parent
    close(fd[1]);                                  //close write
    waitpid(-1);                                   //Parent will wait for child
    char buf[4] = {};
    read(fd[0], buf, sizeof(buf));                //reads from pipe
    printf ("Read from child: %s", buf);
  }
}

# ./a.out 
Read from child: Test
```

<a name=internal></a>
## Internal implementation of pipes
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

## Read Write Scenarios/Cases for Pipe/FIFO

## Read Write Scenarios/cases for Pipe/FIFO
- **Note pipe is for Parent to child, FIFO for unrelated process also.**
### Write
<a name=case1></a>
#### 1. Write on unopened pipe/fifo
- SIGPIPE is sent to process.

### Read
<a name=case2></a>
#### 2. Read from unopened pipe/fifo
- Parent reading from empty pipe: read() blocks until data is available

### Died
<a name=case3></a>
#### 3. Parent reading, child die
- Write end of pipe is closed, parent will exit.

<a name=case4></a>
#### 4. Parent reading, child closes write end of pipe/fifo
- child closes write end close(`fd[1]`) Still child has not exited hence parent will wait on waitpid() for child to exit.
