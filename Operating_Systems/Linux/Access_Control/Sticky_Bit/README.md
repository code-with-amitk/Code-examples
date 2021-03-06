## Sticky Bit / 1XXX / chmod o+t / chmod 1--- `<dir>`
- **(On Files)** No effect    
- **(On Dir)** Setted on directory, Only file owner and root can delete files within directory. What?    If setted on Directory, it tells all users can read other user's Files, but cannot DELETE the files. Eg: /tmp. Only root & owner of file can delete the files regardless who has RX permissions. This is very useful for Shared Spaces.
- **Example-1**
  - *1.* user=amit has directory=test(permissions 777(group=other=rwx)) and file=test(permissions 770(group=rwx))
```c
amit@server$ ls -ltr
d rwx rwx rwx     amit amit   test
amit@server$ ls -ltr test/
- rwx rwx ---     amit amit file1
```
  - *2.* if User=vivek is member of group amit, He can delete file1 successfully.
```c
# usermod -aG amit vivek
# cat /etc/group
amit:x:1002:vivek
```
  - *3.* Setting sticky bit on directory=test will prevent user=vivek from deleting anything inside test(even vivek is member of group=amit)
```c
amit@server$ chmod o+t -R test
amit@server$ ls -ltr test
d rwx rwx rwT   amit    amit    test            //If others on Directory does not have Execute permissions its replaced by upper case Letter T

vivek@server$ rm -rf /home/amit/test/file1
permission denied
```

- **Example-2: tmp directory**
  - only owner of file or root can delete file inside /tmp directory.
```c
# ls -ld /tmp
 d rwx rwx rwt   root root  /tmp/                       
```
