## [dup() / Duplicate](https://man7.org/linux/man-pages/man2/dup2.2.html)
- All dup() system calls create copy of file descriptor.
- After a successful return of API, the old and new file descriptors may be used interchangeably.
  - Both refers to same open file description and thus share file offset and file status flags; 
- _header file_ `#include <unistd.h>`

### int dup(int oldfd)
- Creates a copy of oldfd, using the lowest-numbered unused file descriptor & returns new descriptor.

### int dup2(int oldfd, int newfd)
- dup2() also creates copy of oldfd, but instead of using the lowest-numbered unused file descriptor (as dup()), it uses the file descriptor number specified in newfd.
- If newfd **was already opened, it is silently closed and reused**. Closing and reusing the file descriptor done atomically.
- **Example: How redirection `$ cat a>b` is implemented in kernel**
```c
#include<unistd.h>
int main(){
  int oldfd = creat("file.txt", 0644);    //1. Create a file and open it
  dup2 (oldfd, STDOUT_FILENO);            //2. Create newfd(STDOUT) as duplicate of "file.txt".
                                          //   Now if somewrite on STDOUT, it will be written to "file.txt"
  printf("Be excited");
}
$ gcc test.c
$ cat file.txt
  Be excited
```

### int dup3(int oldfd, int newfd, int flags)
> flags = O_CLOEXEC
- same as dup2() except caller can force **close-on-exec flag** to be set for new file descriptor by specifying [O_CLOEXEC](https://man7.org/linux/man-pages/man2/open.2.html).
