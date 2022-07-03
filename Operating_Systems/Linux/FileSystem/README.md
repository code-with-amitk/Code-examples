- **File System**
  - [1. Windows FS](#w)
  - [2. Linux FS](#l)
- **Inode**
  - [1. File Inode](#fi)
  - [2. Directory Inode](#di)



## Filesystem
Format of storing data on Hard disk or usb. Every resource in Linux is treated as File, we can read/write on them. Eg: IBM's OS: HPFS(High Performance File System)

<a name=w></a>
### 1. Windows File system  
**Examples**
```c
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

<a name=l></a>
### 2. Linux FS
- **Examples:** Ext2(extended file system),ext3,ext4, xfs, gfs(Gluster)
#### Architecture
<img src="https://i.ibb.co/SfF0xwG/filesystem.png" width = 600 />

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

<img src="https://i.ibb.co/6FymhXC/inode.png" width=1400 />

<a name=di></a>
#### 2. Directory Inode
- File entry inside Directory contains filename(allocated on heap) and file's inode no. 
- **Why Filename is allocated on Heap?**
  - If we allocate bigger filename on disk ie in directory and later file is deleted it will leave a hole same problem as in contigious disk allocation(See Above).

