- **File System**
  - [1. Windows FS](#wfs)
  - [2. Linux FS](#lfs)
  - [3. Virtual File System](#vfs)
  - [4. HDFS(Hadoop Distributed Filesystem)]
- **Inode**
  - [1. File Inode](#fi)
  - [2. Directory Inode](#di)
- [File Descriptor Table](#fdt)
- **File Consistency Check**
  - [1. Block Consistency Check](#bcc)
  - [2. File Consistency Check](#bcc)
- **File System Tree**
  - [/proc/interrupts](#pi)
  - [/proc/stat](#ps)


## Filesystem
Format of storing data on Hard disk or usb. Every resource in Linux is treated as File, we can read/write on them. Eg: IBM's OS: HPFS(High Performance File System)

<a name=wfs></a>
### 1. Windows File system  
```c
Examples:
              FS             |    Used By
-----------------------------|-------------
FAT16(File allocation table) |  MsDOS
exFAT(Extended FAT)          | Windows Vista, XP
NTFS                         | Windows NT
```
#### Architecture
```c
    | PBS |  File Table | Root Dir | Clusters |
    
  PBS(Parititon Boot Sector)/MBR: Location of BIOS, other OS details(sector size, ptr to file table)
  File Table: ptrs to clusters. OS uses clusters to store files.    
  Root Dir: Metadata of files stores in each directory.    
  Clusters: Actual data storage    
```

<a name=lfs></a>
### 2. Linux FS
- Examples: Ext2(extended file system),ext3,ext4, xfs, gfs(Gluster)

<img src=images/filesystem.PNG width = 500/>

 - **MBR(Master boot record):** Present at sector=0 of disk. MBR locates Active partition and reads parition's 1st block(called boot block). Boot block contains boot loader. Every partition's 1st block is Boot block(even it contains bootable OS or not).
- **PARTITION TABLE:** Lies at end of MBR. Contains start, end address of each partitions. 1 of partitions is marked ACTIVE.
- **STORING DATA?** Disk stores MBR(Master Boot Record contains bootloader), PARTITION TABLE() and Actual Partitions itself.
- **Partition(Only 1 is marked Active):** Each partition has separate OS installed. 
  - Boot Block: Contains program to load OS(**ie Bootloader**) present on this partition.
  - Superblock: Contains all key parameters about file system
  - Free Blocks: Array of pointers pointing to free blocks
  - [I-Nodes(info about files)](#fi): array of structure (1 per file) containing all info of file
  - Root-Dir: This is top of file system tree
  - Files & Directories: Reminder of disk contains other files and directories.

<a name=vfs></a>
### 3. Virtual File System/VFS
Integrating multiple/incompatible file systems into a single structure. But User will see only 1 file-system hierarchy.
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
- All system calls(from user space eg: open(),read(),write()) relating to files are directed to the virtual file system for initial processing.
- **VFS Interface?** VFS can make API calls to each file system to get work done. Also every file system should provide APIs to VFS

<img src=images/virtual_file_system.PNG width = 400 />

#### Example Flow
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

## Inode / I Node
Data structure maintained by kernel containing file, directory information.
<a name=fi></a>
#### 1. File Inode
- Each file have separate inode structure containing following information of that file: size, change time, group, Permissions, number of blocks, each block address. 
- Every time user writes to file, new block is stored at new disk location and addresses is added.
- **What information is not in Inode?** File name(stored on heap), file content(stored on disk blocks).
```c
     struct inode File_A{
        attributes{size, change time, group, permissions, number of blocks};
        uint64_t Block_Addresses[] = {4, 7, 2, 10};            //Addresses of blocks of file_A on Disk
    };
```
**Advantage:** Whole FAT table need not to be bought into RAM. Only inode structures of files which are opened need to be bought in RAM. if k files are opened of size=n, then kn RAM is occupied.

<img src=images/inode.png width=1300 />

<a name=di></a>
#### 2. Directory Inode
- File entry inside Directory contains filename(allocated on heap) and file's inode no. 
- **Why Filename is allocated on Heap?**
  - If we allocate bigger filename on disk ie in directory and later file is deleted it will leave a hole same problem as in contigious disk allocation(See Above).

<a name=fdt></a>
## File Descriptor Table
- Every opened file has a entry inside FDT.
- Mapping of opened file descriptors to [File inode](/Operating_Systems/Linux/FileSystem/I_Node_IndexNode.md).
- When user opens a file(using system call open()) a file descriptor is provided, Entry is created in file Descriptor table which points to inode of opened file.
```c
int fd = open("/home/test", O_RDONLY | O_CREAT);  //fd=3


File descriptor table
..| inode=50(/home/test) |stderr | stdout  | stdin  |
        3                   2         1         0       <-File descriptors

50 points to inode of file=/home/test
```

<a name=fcsk></a>
## File System Consistency / fcsk
- Consistency means file system is valid/correct or not.
- **When can filesystem become inconsistent?** Many filesystems read blocks, modify them, and write them out **later**. If the system crashes before all the modified blocks have been written out, the file system can be left in an inconsistent state.
- **Utilities for checking Filesystem consistency:** Unix: fcsk, Windows: sfc

### Checking File Consistency
<a name=bcc></a>
#### 1. Block Consistency Check
> 1 file will have multiple blocks.
- **A. Check blocks in Files**
  - *1. Building occupied,free block tables*
  - fsck will read all [file inodes]() and builds 2 tables. Initially both tables are memset(0).
    - Table-1: How many times each block is present in a file
    - Table-2: how often each block is present in the free list

<img src=images/filesystem-consistency-check-fsck.jpg width=700 />

- **2. Findings from Tables**
  - *table-a.* CONSISTENT_FILESYSTEM. if filesystem is consistent each block will have a 1 either in the first table or in the second table.
  - *table-b.* INCOSISTENT_FILESYSTEM. After crash there would be a block that does not occur in either table. This is a missing block.
    - Solution: file system checker adds them to the free list.
  - *table-c.* INCOSISTENT_FILESYSTEM. Block number 4, that occurs twice in the free list.
    - Solution: rebuild the free list.
  - *table-d.* INCOSISTENT_FILESYSTEM. Block 5, same data block is present in two or more files.
    - Solution:  allocate a free block, copy the contents of block 5 into it, and insert the copy into one of the files

<a name=fcc></a>
#### 2. File Consistency Check
- **How to use fsck?** We must unmout file system before running fsck command.
```bash
# init 1              //Goto single user mode:
# umount /dev/sdb1    //Unmount file system (for example /dev/sdb1 under Linux or under FreeBSD use /dev/ad0s1f etc)
# fsck /dev/sdb1      //Now run fsck command:
# mount -a            //Now mount filesystem
# init 2              //Go backto multiuser mode 2/3
```

### File system Tree
<a name=pi></a>
#### /proc/interrupts
- Only interrupts corresponding to installed handlers are shown.
  - if no [handler/ISR] for interrupt is defined, CPU cannot handle the interrupt, also that is not listed in /proc/interrupts.
- Col-2: how many interrupts have been delivered to each CPU-0
- Col-4: Interrupt controller/handler that handles the interrupt 
```c
# cat /proc/interrupts
interrupt_number	CPU0 	  CPU1
 0:             4848108    34 		IO-APIC-edge timer
 2:                 0      0 		XT-PIC cascade
 8:                 3      1 		IO-APIC-edge rtc
 10:              4335     1 		IO-APIC-level aic7xxx
 11:              8903     0 		IO-APIC-level uhci_hcd
 12:                49     1 		IO-APIC-edge i8042
NMI:                 0     0
LOC:            4848187   4848186
ERR:                0
MIS:                0
```

<a name=ps></a>
#### /proc/stat
- Contains information about total interrupts recieved on System and no of interrupts on each line
  - 99990109: Total interrupts received on system
  - 5154006: Interrupts recieved on line 0
  - 4096: Interrupts recieved on line 4
```c
# cat /proc/stat
intr 99990109 5154006 2 0 2 4907 0 2 68 4 0 4406 9291 50 0 0
```

