# Inode/I Node
- Data structure maintained by kernel containing file, directory information.

## FILE INODE
- Each file have separate inode structure containing following information of that file
  - size
  - change time
  - group
  - Permissions
  - number of blocks
  - each block address. 
- Every time user writes to file, new block is stored at new disk location and addresses is added. 
```c
     struct inode File_A{
        attributes{size, change time, group, permissions, number of blocks};
        uint64_t Block_Addresses[] = {4, 7, 2, 10};            //Addresses of blocks of file_A on Disk
    };
```
- **Advantage:** Whole FAT table need not to be bought into RAM. Only inode structures of files which are opened need to be bought in RAM. if k files are opened of size=n, then kn RAM is occupied.

<img src="https://i.ibb.co/6FymhXC/inode.png" width=900 />
