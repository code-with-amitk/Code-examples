## IOCTL((sockfd, command, data_arguments)
- It is command to do any of following operations on file descriptor:
  - Make sockfd non-blocking
  - Pass messages to device driver. Example
```c
  User Application                   User Space                  Device Driver{Kernel Space}
fd = open("/dev/pkp", 0);             Device File                 struct file_operations fops{
char msg[100];                       mknod 125 0 /dev/pkp            .read = device_read,;
ioctl(fd, IOCTL_GET_MSG, msg);                                        .write=device_write,
                                                                      .ioctl=device_ioctl
                                                                   }
                                                                  device_ioctl(....){
                                                                   switch(ioctl_num){
                                                                    case IOCTL_GET_MSG:--
                                                                    case IOCTL_SET_MSG:--
                                                                  }
```
