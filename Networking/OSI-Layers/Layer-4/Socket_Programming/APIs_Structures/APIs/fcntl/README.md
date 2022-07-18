**fcntl**
- [Making socket Non-Blocking](#s)


### fcntl / file control
For performing various operations on open file descriptors.
```c
  int fcntl(int fildes, int cmd, ...);
```
- Exact arguments depends on command given.
- Commands
```c
F_DUPFD Duplicate a file descriptor.
F_GETFD Get file descriptor flags.
F_GETLK Get record locking information.
F_SETFD Set file descriptor flags.
F_GETFL Get file status flags.
F_SETFL Set file status flags.
F_SETLK Set record locking information.
F_SETLKW Set record locking information; wait if blocked.
```

<a name=s></a>
#### Making socket Non-Blocking
- [select](..) goes over all sockets from FD_SET even when there is no data, which is bad idea.
- How about not waiting on any of socket when no data is present (async)?
```c
  sockfd = socket(PF_INET, SOCK_STREAM, 0);
  flags = fcntl(fildes,F_GETFD);           //read the flags
  flags |= O_NONBLOCK;                    //set desired bits
  
  //This preserves any implementation-defined flags. The normal open flags, such as O_CREAT, are also preserved by this technique
  fcntl(sockfd, F_SETFL, O_NONBLOCK);     //reset the flags
```
