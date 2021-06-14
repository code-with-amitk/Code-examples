## Pipe
- System call create a pipe for one-way communication between parent and child
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

### [Code](Code)
- See Code 1st

|Case|Result
|---|---|
|Process reading from empty pipe|read() blocks until data is available|
|Process attempts to write to full pipe|write() blocks until sufficient data has been read from pipe|

#### Case-1: Parent waiting read() on pipe from child, child Dies.
  - Write end of pipe is closed, parent will exit
#### Case-2: Parent waiting read() on pipe from child, and child closes write close(`fd[1]`)
  - Still child has not exited hence parent will wait on waitpid() for child to exit.
