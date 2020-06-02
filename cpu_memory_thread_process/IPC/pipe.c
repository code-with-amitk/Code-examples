/*              pipe.c
  
Pipe: Pipe is a communication medium between two or more related or interrelated processes.

pipe(): System call create a pipe for one-way communication. 
        fd[0]->read end
        fd[1]->write end
fd[2] is duplicated for child also.

                Read           Write
        parent  fd[0](========)fd[1]
        child   fd[0](========)fd[1]

if parent is writing. parent need to close read end.
if child is reading. child need to close write end.
*/
#include<unistd.h>
#include <stdio.h>

void main(){
        int fd[2], pid;
        char buf[] = "test";

        if(pipe(fd)<0){
                printf("Error in creating pipe");
        }

        if((pid = fork()) < 0){
                printf("Error in fork");
        }

        if(pid == 0){
                //Child
                close(fd[1]);
                read(fd[0], buf, sizeof(buf));
                printf("Inside child recieved buf[%s]\n",buf);
        }else{
                //Parent
                close(fd[0]);
                write(fd[1], buf, sizeof(buf));
        }
}
/*
Ouput:
# ./a.out 
Inside child recieved buf[test]
*/
