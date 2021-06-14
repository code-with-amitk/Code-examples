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
