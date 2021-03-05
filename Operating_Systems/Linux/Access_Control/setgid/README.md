## setgid / (g+s)/2XXX /Execute Permission
- This Special Group Permissions
- Read setuid 1st in order to understand this.
- **(On Files)** File executes as the group that owns the file. 
- **(On dir)** Files newly created in the directory have their group owner set to match the group owner of the directory. 
- This is ie execute bit is set to s.
```c
amit@server$ ls -ltr test.txt
- rw- --- ---   amit    amit
amit@server$ chmod g+s test.txt
- rw- --S ---   amit    amit        //If file does not have execute permissions. Upper case S else s
```

### Directory setgid
- When the bit is set for a directory, the set of files in that directory will have the same group as the group of the parent directory, and not that of the user who created those files. This is used for file sharing since they can be now modified by all the users who are part of the group of the parent directory.
```c
# chmod g+s <dir>    OR    chmod 2--- <dir>        //If Directory does not have execute permissions. Upper case S
```
