- **Links**
  - [Hard link](#h)
  - [Soft link / Symbolic link](#s)
  - [Hard vs Soft Link](#vs)

## Links
<a name=h></a>
### Hard Link
- if original file is moved to new location, hard link still points to that and can be worked on.
- If Original file is deleted. Hard link does not gets deleted And stores the contents of file. 
- **Limitations**
  - Cannot be used for directories, Special files.
  - hard links cannot be created on files on different filesystems.
```c
$ ls -ltr test
        -rw-r--r--.  1  test                //1 means no hard link
$ cat test
  hello
$ ln   test    hardlink              //ln <src-file> <dst-file>
$ ls -ltr test
  -rw-r--r--.  2  test               //2 means there is one hard link. if we delete hardlink, count will decrease by 1.
  -rw-r--r--.  2  hardlink
$ rm -rf test
$ ls -ltr hardlink
  -rw-r--r--.  1   hardlink                //1 means no hard link
$ cat hardlink
        hello
```

<a name=s></a>
### Soft Link / Symbolic Link
- Pointer to location of a file OR directory. If original file is removed. Soft-link still exits but does not holds any content(this is called dangling softlink).
- **Advantages**: 
  - Can be created for directories, special files.  
  - Can be created for different file systems.
```c
$ cat test
  hello
$  ln -s  test  softlink           //ln -s    <src-file>    <soft-link-name>
$ ls -ltr softlink
  lrwxrwxrwx 1  softlink -> test
$ rm -rf test
$ cat softlink        //Dangling softlink
    <--empty-->
$ touch file1         //Again softlink will start pointing to same file, Since it points to filepath(not inode)
```

<a name=vs></a>
### Hard vs Soft
```c
                                | Soft Link/Symbolic Link                 |      Hard link
--------------------------------|-----------------------------------------|----------------------
What?                           | Linkfile contains path to sharedfile    | Copy of inode. Separate copy of file
Reside on Different file system?| yes                                     | no
Deleting original file          | SL gets inactive                        | Original file can be accessed
For Directories                 | Can be created                          | Cannot be created
```
