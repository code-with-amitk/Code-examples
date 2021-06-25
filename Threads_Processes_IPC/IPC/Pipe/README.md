- [What is pipe](#what)
- [Advantages of pipes](#adv)
- [How pipe works](#work)
- [Code](#code)
  - [1. One Child. Parent reading child writing](#one)
- [Read/Write Cases](#cases)

<a name=what></a>
## Pipe
- **What?** System call create a pipe for one-way communication between parent and child

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

<a name=code></a>
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

<a name=cases></a>
## Cases
- **Read**
  - _Parent reading from empty pipe:_ read() blocks until data is available
  - _Parent waiting on read()_
    - _1. child dies:_ Write end of pipe is closed, parent will exit
    - _2. child closes write close(`fd[1]`):_ Still child has not exited hence parent will wait on waitpid() for child to exit
- **Write**
  - _Process attempts to write to full pipe:_ write() blocks until sufficient data has been read from pipe
