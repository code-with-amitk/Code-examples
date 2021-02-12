## File Descriptor Table
- **What** Mapping of opened file descriptors to [File inode](/Operating_Systems/Linux/FileSystem/I_Node_IndexNode.md).
- **How it works**
  - When user opens a file using any system call that provides file descriptor (Eg: open()), Entry is created in file Descriptor table which points to inode of opened file.
```c
int fd = open("/home/test", O_RDONLY | O_CREAT);  //fd=3


File descriptor table
..| inode=50(/home/test) |stderr | stdout  | stdin  |
        3                   2         1         0       <-File descriptors

50 points to inode of file=/home/test
```
