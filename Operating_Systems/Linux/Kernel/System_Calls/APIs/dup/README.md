## dup / Duplicate
- All dup() system calls create copy of file descriptor.
- After a successful return of API, the old and new file descriptors may be used interchangeably.
  - Both refers to same open file description and thus share file offset and file status flags; 
- _header file_ `#include <unistd.h>`

### int dup(int oldfd)
- Creates a copy of oldfd, using the lowest-numbered unused file descriptor & returns new descriptor.

### int dup2(int oldfd, int newfd)
- dup2() system call performs the same task as dup(), but instead of using the lowest-numbered unused file descriptor, it uses the file descriptor number specified in newfd.
