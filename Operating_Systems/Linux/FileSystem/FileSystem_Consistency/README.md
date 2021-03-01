## File System Consistency / fcsk
- **What?** Consistency means file system is valid/correct or not.
- **When can filesystem become inconsistent?** Many filesystems read blocks, modify them, and write them out **later**. If the system crashes before all the modified blocks have been written out, the file system can be left in
an inconsistent state.
- **Utilities for checking Filesystem consistency**
  - *Unix:* fcsk
  - *Windows:* sfc
- **Methods of Checking Consistency**
  - *1.* Block Consistency Check
  - *2.* File Consistency Check
