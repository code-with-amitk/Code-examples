### Code
- Child writing, parent reading
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
    printf("Inside child recieved buf[%s]\n",buf);
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
