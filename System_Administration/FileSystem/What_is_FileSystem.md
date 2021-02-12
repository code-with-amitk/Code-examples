## File System
- **What?** Format of storing data on Hard disk or usb. Every resource in Linux is treated as File, you can read/write on them. 
- **Examples:**  
  - IBM's OS: HPFS(High Performance File System)
  
### 1. Windows File system  
- Examples
  - FAT16(File allocation table):Used by MSDoS, Windows 3 (216=4GB)
  - FAT32(232=16TB)
  - exFAT(Extended FAT): Wndows XP, Windows Vista
  - NTFS:Windows NT, 
- **Architecture**
```c
    | PBS |  File Table | Root Dir | Clusters |
```    
  - PBS(Parititon Boot Sector)/MBR: Location of BIOS, other OS details(sector size, ptr to file table)
  - File Table: ptrs to clusters. OS uses clusters to store files.    Root Dir: Metadata of files stores in each directory.    Clusters: Actual data storage
        
### 2. Linux File System 
- Examples
  - Ext2(extended file system),ext3,ext4
  - xfs
  - gfs(Gluster)
- **Architecture**

<img src = src="https://i.ibb.co/SfF0xwG/filesystem.png" width = 600 />

    MBR(Master boot record): See kernel boot process above.
    PARTITION TABLE: Lies at end of MBR. Contains start, end address of  each partitions. 1 of partitions is marked ACTIVE.
   STORING DATA? Disk stores MBR(Master Boot Record contains bootloader), PARTITION TABLE() and Actual Partitions itself.
