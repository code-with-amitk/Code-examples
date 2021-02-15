# Inode/I Node
- Data structure maintained by kernel containing file, directory information.

## 1. File Inode
- Each file have separate inode structure containing following information of that file: size, change time, group, Permissions, number of blocks, each block address. 
- Every time user writes to file, new block is stored at new disk location and addresses is added.
- **What information is not in Inode?** File name(stored on heap), file content(stored on disk blocks).
```c
     struct inode File_A{
        attributes{size, change time, group, permissions, number of blocks};
        uint64_t Block_Addresses[] = {4, 7, 2, 10};            //Addresses of blocks of file_A on Disk
    };
```
- **Advantage:** Whole FAT table need not to be bought into RAM. Only inode structures of files which are opened need to be bought in RAM. if k files are opened of size=n, then kn RAM is occupied.

<img src="https://i.ibb.co/6FymhXC/inode.png" width=1400 />

## 2. Directory Inode
- File entry inside Directory contains filename(allocated on heap) and file's inode no. 
- **Why Filename is allocated on Heap?**
  - If we allocate bigger filename on disk ie in directory and later file is deleted it will leave a hole same problem as in contigious disk allocation(See Above).
