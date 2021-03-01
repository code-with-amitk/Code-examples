## File System Consistency / fcsk
- **What?** Consistency means file system is valid/correct or not.
- **When can filesystem become inconsistent?** Many filesystems read blocks, modify them, and write them out **later**. If the system crashes before all the modified blocks have been written out, the file system can be left in
an inconsistent state.
- **Utilities for checking Filesystem consistency**
  - *Unix:* fcsk
  - *Windows:* sfc
- **Methods of Checking Consistency**
  - *1.* [Block Consistency Check](Block_Consistency_Check.md)
  - *2.* File Consistency Check
- **How to use fsck?** We must unmout file system before running fsck command.
```bash
# init 1              //Goto single user mode:

# umount /dev/sdb1    //Unmount file system (for example /dev/sdb1 under Linux or under FreeBSD use /dev/ad0s1f etc)

# fsck /dev/sdb1      //Now run fsck command:

# mount -a            //Now mount filesystem

# init 2              //Go backto multiuser mode 2/3
```

