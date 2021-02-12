# Virtual File System/VFS
- **What** Integrating multiple/incompatible file systems into a single structure. But User will see only 1 file-system hierarchy.
- **Example**
  - Linux system could have ext2 as the root file system  //from hard-disk-1
  - ext3 partition mounted on /usr    //From HD-1
  - Reiser file system mounted on /home //From HD-2
  - xfs mounted on /test    //Using NFS
```c
                      /(root) [ext2]//HD1
                         |
  -------------------------------------------------------------------------------------
  |                         |                              |                          |(remote NFS)
 /usr[ext3]//HD1          /home[ReiserFS]//HD2          /mnt[ISO 9660 CD-ROM]       /test
```

## Architecture
- All system calls(from user space eg: open(),read(),write()) relating to files are directed to the virtual file system for initial processing.
- **VFS Interface?** VFS can make API calls to each file system to get work done. Also every file system should provide APIs to VFS

<img src = "https://i.ibb.co/qmwt1XM/virtual-file-system.png" width = 500 />

## Example Flow
- **1. Registration** Root or other filesystem(permanent fs) gets regitered with VFS. As any file system is mounted it gets registered with VFS.
  - *Information provided at registration to VFS by file-system*
    - *a.* list of callbacks which VFS should call to communicate with file system.
- *2.* User opens are file from `/usr` which is mounted using `/ext3`, call reaches VFS
- *3.* VFS searches [Superblock](/Operating_Systems/Linux/FileSystem/What_is_FileSystem.md) of mounted filesystems and finds root dir of mounted file system and finds `include/unistd.h` there.
```c
                    VFS               File-System-1(ext2)
                     | <--Register-------|                         //1
                     |                                 File-System-2(ext3)
                     |<---------Register-----------------|
     User
open("/usr/include/unistd.h", O RDONLY)   //2
  |
  |-system call--> VFS
                Search superblock of mounted filesystems      //3
                Find root dir of mounted File system
                Find include/unistd.h there
```

