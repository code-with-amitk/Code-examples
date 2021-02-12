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
- *1.On System Boot:* Root filesystem(Eg: ext2) gets regitered with VFS.

