## Pipe
- System call create a pipe for one-way communication between parent and child
- **[How Pipe works?](How_pipe_works.md)**
- **[Advantages of pipes over files](Advantages_of_Pipes)**

### [Code](Code)
### Cases
> See code 1st

|Case|Result|
|---|---|
|Process reading from empty pipe|read() blocks until data is available|
|Process attempts to write to full pipe|write() blocks until sufficient data has been read from pipe|

#### Case-1: Parent waiting read() on pipe from child, child Dies.
  - Write end of pipe is closed, parent will exit
#### Case-2: Parent waiting read() on pipe from child, and child closes write close(`fd[1]`)
  - Still child has not exited hence parent will wait on waitpid() for child to exit.
